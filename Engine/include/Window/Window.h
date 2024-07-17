#pragma once
#include "Common/Core.h"

namespace CSE {
    class AppWindow
    {
      public:
        CSE_INLINE AppWindow(int width, int height, const char *title){
            InitWindow(width, height, title);
            SetTargetFPS(60);
        }

        CSE_INLINE ~AppWindow(){
            CloseWindow();
        }
      private:
    };
}
