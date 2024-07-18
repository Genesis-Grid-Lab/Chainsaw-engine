#pragma once
#include "Auxiliaries/Assets.h"
#include "Common/Core.h"
#include "Graphics/Utilities/Data.h"
#include "raylib.h"

namespace CSE
{
    // transform component
    struct TransformComponent
    {
        CSE_INLINE TransformComponent(const TransformComponent&) = default;
        CSE_INLINE TransformComponent() = default;
        Transform3D Transform;
    };
    // camera component
    struct CameraComponent
    {
      CSE_INLINE CameraComponent(const CameraComponent&) = default;
      CSE_INLINE CameraComponent() = default;
      Camera3D Camera = {0};
    };

    // camera2d component
    struct Camera2DComponent
    {
        CSE_INLINE Camera2DComponent(const Camera2DComponent&) = default;
        CSE_INLINE Camera2DComponent() = default;
        Camera2D Camera = {0};
    };

    // sprite component
    struct SpriteComponent
    {
        CSE_INLINE SpriteComponent(const SpriteComponent&) = default;
        CSE_INLINE SpriteComponent() = default;
        AssetID Sprite = EMPTY_ASSET;
    };

    // common component
    struct InfoComponent
    {
        CSE_INLINE InfoComponent(const InfoComponent&) = default;
        CSE_INLINE InfoComponent() = default;
        AssetID Parent = EMPTY_ASSET;
        std::string Name = "Entity";
        AssetID UID = RandomU64();
    };
    // base entity
    struct Entity
    {
        CSE_INLINE Entity(EntityRegistry* registry, EntityID entity):
            m_Registry(registry), m_EnttID(entity)
            {}

        CSE_INLINE Entity(EntityRegistry* registry):
            m_Registry(registry)
            {
                m_EnttID = m_Registry->create();
            }

        CSE_INLINE virtual ~Entity() = default;
        CSE_INLINE Entity() = default;

        CSE_INLINE operator EntityID()
        {
            return m_EnttID;
        }

        CSE_INLINE operator bool()
        {
            return m_Registry != nullptr && m_Registry->valid(m_EnttID);
        }

        CSE_INLINE EntityID ID()
        {
            return m_EnttID;
        }

        //-------
        template<typename T, typename...Args>
        CSE_INLINE T& Attach(Args&&...args)
        {
            return m_Registry->get_or_emplace<T>(m_EnttID, std::forward<Args>(args)...);;
        }

        template<typename T>
        CSE_INLINE void Detach()
        {
            m_Registry->remove<T>(m_EnttID);
        }

        CSE_INLINE void Destroy()
        {
            if(m_Registry)
            {
                m_Registry->destroy(m_EnttID);
            }
        }

        template<typename T>
        CSE_INLINE bool Has()
        {
            return m_Registry != nullptr && m_Registry->all_of<T>(m_EnttID);
        }

        template<typename T>
        CSE_INLINE T& Get()
        {
            return m_Registry->get<T>(m_EnttID);
        }

        protected:
            EntityRegistry* m_Registry = nullptr;
            EntityID m_EnttID = NENTT;
    };
}