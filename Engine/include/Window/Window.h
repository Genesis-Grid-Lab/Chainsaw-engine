#pragma once
#include "Events.h"

namespace CSE {
    class AppWindow
    {
      public:
        CSE_INLINE AppWindow(EventDispatcher* dispatcher, int width, int height, const char *title):
            m_Dispatcher(dispatcher)
        {
            InitWindow(width, height, title);
            SetTargetFPS(60);
            //m_Dispatcher->PostEvent<WindowResizeEvent>(SCRNWIDTH, SCRNWIDTH);
        }

        CSE_INLINE ~AppWindow(){
            CloseWindow();
        }

        CSE_INLINE bool PollEvents()
        {
            m_Dispatcher->PollEvents();
            return (!WindowShouldClose());
        }
      private:
        EventDispatcher* m_Dispatcher;
        WindowInputs m_Inputs;
    };
}
