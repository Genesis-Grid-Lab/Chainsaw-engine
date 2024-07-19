#pragma once
#include "Auxiliaries/ECS.h"
#include "Context.h"

namespace CSE {
    class AppInterface
    {
      public:
        CSE_INLINE ~AppInterface() = default;

        // create entity
        template <typename Entt, typename... Args>
        CSE_INLINE Entt CreateEntt(Args&&... args)
        {
            CSE_STATIC_ASSERT(std::is_base_of<Entity, Entt>::value);
            return std::move(Entt(&m_Context->Scene, std::forward<Args>(args)...));
        }

        // convert id to entity
        template<typename Entt>
        CSE_INLINE Entt ToEntt(EntityID entity)
        {
            CSE_STATIC_ASSERT(std::is_base_of<Entity, Entt>::value);
            return std::move(Entt(&m_Context->Scene, entity));
        }

        // loop through entities
        template<typename Entt, typename Comp, typename Task>
        CSE_INLINE void EnttView(Task&& task)
        {
            CSE_STATIC_ASSERT(std::is_base_of<Entity, Entt>::value);
            m_Context->Scene.view<Comp>().each([this, &task]
            (auto entity, auto& comp)
            {
                task(std::move(Entt(&m_Context->Scene, entity)), comp);
            });
        }

        //loop through entities
        template<typename Task>
        CSE_INLINE void AssetView(Task&& task)
        {
            m_Context->Assets->View([&] (auto asset) { task(asset);});
        }

        //----------
        // attach event callback
        template<typename Event, typename Callback>
        CSE_INLINE void AttachCallback(Callback&& callback)
        {
            m_Context->Dispatcher.AttachCallback<Event>(std::move(callback), m_LayerID);
        }

        // post event
        template<typename Event, typename... Args>
        CSE_INLINE void PostEvent(Args&&...args)
        {
            m_Context->Dispatcher.PostEvent<Event>(std::forward<Args>(args)...);
        }

        // post task event
        template<typename Task>
        CSE_INLINE void PostTask(Task&& task)
        {
            m_Context->Dispatcher.PostTask(std::move(task));
        }

        // detach callback
        template<typename Event>
        CSE_INLINE void DetachCallback()
        {
            m_Context->Dispatcher.DetachCallback<Event>(m_LayerID);
        }

        //----------
        //attach layer
        template<typename Layer, typename... Args>
        CSE_INLINE Layer* AttachLayer(Args&&... args)
        {
            // check layer's type compliance
            CSE_STATIC_ASSERT(std::is_base_of<AppInterface, Layer>::value);

            // check if layer allready exist
            if(GetLayer<Layer>() != nullptr)
            {
                CSE_ERROR("Layer allready attached!");
                return nullptr;
            }

            // create layer and add to collection
            auto layer = new Layer(std::forward<Args>(args)...);
            m_Context->Layers.push_back(layer);
            layer->m_LayerID = TypeID<Layer>();
            layer->m_Context = m_Context;
            layer->OnStart();
            return layer;
        }

        // detach layer
        template<typename Layer>
        CSE_INLINE void DetachLayer()
        {
            CSE_STATIC_ASSERT(std::is_base_of<AppInterface, Layer>::value);
            m_Context->Dispatcher.PostTask([this]
                {
                    m_Context->Layers.erase(std::remove_if(m_Context->Layers.begin(),
                    m_Context->Layers.end(), [this] (auto& layer)
                    {
                        if(layer->m_LayerID == TypeID<Layer>())
                        {
                            m_Context->Dispatcher.EraseListener(layer->m_LayerID);
                            CSE_DELETE(layer);
                            return true;
                        }
                        return false;
                    }),
                    m_Context->Layers.end());
                });
        }

        // retreive layer
        template<typename Layer>
        CSE_INLINE Layer* GetLayer()
        {
            CSE_STATIC_ASSERT(std::is_base_of<AppInterface, Layer>::value);

            auto itr = std::find_if(m_Context->Layers.begin(),
            m_Context->Layers.end(),[this] (auto layer)
            {
                return (layer->m_LayerID == TypeID<Layer>());
            });

            if(itr != m_Context->Layers.end())
            {
                return static_cast<Layer*>(*itr);
            }

            return nullptr;
        }

        CSE_INLINE RenderTexture &GetSceneFrame()
        {
            //return m_Context->Renderer->GetFrame();
            return m_Context->Renderer->ViewTexture;
        }
      protected:
        CSE_INLINE virtual void OnUpdate() {}
        CSE_INLINE virtual void OnStart() {}
      private:
        friend class Application;
        AppContext* m_Context;
        uint32_t m_LayerID;
    };
}
