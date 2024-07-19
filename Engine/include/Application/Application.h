#pragma once
#include "Auxiliaries/Assets.h"
#include "Auxiliaries/ECS.h"
#include "Common/Core.h"
#include "Interface.h"
#include "Window/Events.h"
#include "raylib.h"

namespace CSE {
    class Application : public AppInterface
    {
      public:
        // runs application main loop
        CSE_INLINE void RunContext(bool showFrame)
        {
            // application main loop
            while(m_Context->Window->PollEvents())
            {
                // set delta time
                UpdateDeltaTime();

                // update scene
                UpdateScene();

                // start new frame
                m_Context->Renderer->BeginDraw();
                // render scene
                RenderScene();

                //DrawTexture(m_Context->Renderer->GetFrame().texture, 0, 0, WHITE);

                for (auto layer : m_Context->Layers)
                {
                    layer->OnUpdate();
                }

                // end frame
                m_Context->Renderer->EndDraw();

                // show only for game
                m_Context->Renderer->ShowFrame(showFrame);
            }
        }

        // destroy application context
        CSE_INLINE ~Application()
        {
            CSE_DELETE(m_Context);
        }

        // create application context
        CSE_INLINE Application()
        {
            // create application context
            m_LayerID = TypeID<Application>();
            m_Context = new AppContext();

            // register callbacks
            RegisterCallbacks();

            // start scene
            StartScene();
        }
      private:
        // register event callback function
        CSE_INLINE void RegisterCallbacks()
        {
            //attach window resize event callback
            AttachCallback<WindowResizeEvent>([this] (auto e)
                {

                });
        }

        // computes frame delta time value
        CSE_INLINE void UpdateDeltaTime()
        {

        }

        // create entities with components
        CSE_INLINE void CreateEntities()
        {
            // load assets
            auto spriteAsset = m_Context->Assets->AddTexture(RandomU64(), "Resources/Ship.png");
            auto spriteScript = m_Context->Assets->AddScript(RandomU64(), "Resource/Scripts/TestScipt.lua");
            // create scene camera
            auto camera = CreateEntt<Entity>();
            camera.Attach<InfoComponent>().Name = "Camera";
            camera.Attach<TransformComponent>();
            //camera.Attach<CameraComponent>();
            camera.Attach<Camera2DComponent>();

            // create sprite
            auto sprite = CreateEntt<Entity>();
            sprite.Attach<InfoComponent>().Name = "Sprite";
            sprite.Attach<TransformComponent>();
            sprite.Attach<SpriteComponent>().Sprite = spriteAsset->UID;
            sprite.Attach<ScriptComponent>().Script = spriteScript->UID;
        }

        // update
        CSE_INLINE void UpdateScene()
        {

        }

        // render
        CSE_INLINE void RenderScene()
        {
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            // set camera
            EnttView<Entity, CameraComponent>([this] (auto entity, auto& comp)
                {
                    auto& transform = entity.template Get<TransformComponent>().Transform;
                    m_Context->Renderer->SetCamera(comp.Camera, transform);
                });

            EnttView<Entity, Camera2DComponent>([this] (auto entity, auto& comp)
                {
                    auto& transform = entity.template Get<TransformComponent>().Transform;
                    m_Context->Renderer->SetCamera2D(comp.Camera, transform);
                });

            // render sprites
            EnttView<Entity, SpriteComponent>([this] (auto entity, auto& comp)
                {
                    //retrieve assets
                    //auto& transform = entity.template Get<TransformComponent>().Transform;
                    auto& Sprite = m_Context->Assets->Get<TextureAsset>(comp.Sprite);
                    auto& transform = entity.template Get<TransformComponent>().Transform;
                    comp.Position.Translate.x = transform.Translate.x;

                    //render sprite
                    m_Context->Renderer->Draw2D(Sprite, transform);
                });
            //DrawTexture(Texture2D texture, int posX, int posY, Color tint)
            //DrawCube(Vector3({0,0,0}), 2.0f, 2.0f, 2.0f, RED);
            //DrawGrid(10, 1.0f);
            m_Context->Renderer->EndMode();
        }

        // start
        CSE_INLINE void StartScene()
        {
            // create scene entities
            CreateEntities();
        }
    };
}
