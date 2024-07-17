#pragma once
#include "Common/Core.h"
#include "Interface.h"

namespace CSE {
    class Application : public AppInterface
    {
      public:
        // runs application main loop
        CSE_INLINE void RunContext(bool showFrame)
        {
            // application main loop
            while(!WindowShouldClose())
            {
                // set delta time
                UpdateDeltaTime();

                // update scene
                UpdateScene();

                // render scene
                RenderScene();

                for (auto layer : m_Context->Layers)
                {
                    layer->OnUpdate();
                }

                // show only for game
                //m_Context->Renderer->ShowFrame(showFrame);
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

        }

        // computes frame delta time value
        CSE_INLINE void UpdateDeltaTime()
        {

        }

        // update
        CSE_INLINE void UpdateScene()
        {

        }

        // render
        CSE_INLINE void RenderScene()
        {
            // start new frame
            m_Context->Renderer->BeginDraw();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            // end frame
            m_Context->Renderer->EndDraw();
        }

        // start
        CSE_INLINE void StartScene()
        {

        }
    };
}
