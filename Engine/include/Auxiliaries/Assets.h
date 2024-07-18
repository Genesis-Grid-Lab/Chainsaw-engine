#pragma once
#include "Common/Core.h"

namespace CSE {

    // define the AssetOD type as a 64-bit unsigned interger
    using AssetID = uint64_t;
    const AssetID EMPTY_ASSET = 0u;

    //asset type
    enum class AssetType : uint8_t
    {
        UNKNOWN = 0,
        TEXTURE,
        SPRITE,
        SCENE,
    };

    // define the base Asset Structure
    struct Asset
    {
        // generate unique asset id
        AssetID UID = EMPTY_ASSET;

        // file path of asset
        std::string Source;

        // name of the asset
        std::string Name;

        //asset type
        AssetType Type;
    };

    struct TextureAsset : Asset
    {
        Texture2D Data;
    };

    struct SceneAsset : Asset
    {

    };

    // define an unordered map to store assets based on their type and UID
    using SharedAsset = std::shared_ptr<Asset>;
    using AssetMap = std::unordered_map<AssetID, SharedAsset>;

    // asset registry to manage the addition and retrielval of assets
    struct AssetRegistry
    {
        CSE_INLINE AssetRegistry()
        {
            // ass default asset for each type
            AddEmpty<TextureAsset>();
        }

        CSE_INLINE auto AddTexture(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<TextureAsset>();
            asset->Data = LoadTexture(source.c_str());
            asset->Type = AssetType::TEXTURE;
            Add(uid, source, asset);

            return asset;
        }

        CSE_INLINE auto AddScene(AssetID uid, const std::string& source)
        {
            auto asset = std::make_shared<SceneAsset>();
            asset->Type = AssetType::SCENE;
            Add(uid, source, asset);
        }

        //retrieve asset based ont its uid
        template<typename T>
        CSE_INLINE T& Get(AssetID uid)
        {
            const uint32_t type = TypeID<T>();
            if (m_Registry[type].count(uid))
                return (T&)(*m_Registry[type][uid]);
            return (T&)(*m_Registry[type][EMPTY_ASSET]);
        }

        // helps loop through all assets
        template <typename F>
        CSE_INLINE void View(F&& func)
        {
            for(auto& [_, assetMap] : m_Registry)
            {
                for(auto& [uid, asset] : assetMap)
                {
                    if(uid != EMPTY_ASSET)
                    {
                        func(asset.get());
                    }
                }
            }
        }

        // return collection of asset
        template <typename T>
        CSE_INLINE auto& GetMap()
        {
            return m_Registry[TypeID<T>()];
        }

        CSE_INLINE void Clear()
        {
            m_Registry.clear();
        }

        private:
        // adds a new asset to the registry
        template <typename T>
        CSE_INLINE void Add(
            AssetID uid,
            const std::string& source,
            std::shared_ptr<T>& asset
        )
        {
            asset->UID = uid;
            asset->Source = source;
            std::filesystem::path path(source);
            asset->Name = path.stem().string();
            m_Registry[TypeID<T>()][asset->UID] = asset;
        }

        template <typename T>
        CSE_INLINE void AddEmpty()
        {
            m_Registry[TypeID<T>()][EMPTY_ASSET] = std::make_shared<T>();
        }

    private:
        std::unordered_map<uint32_t, AssetMap> m_Registry;
    };
}
