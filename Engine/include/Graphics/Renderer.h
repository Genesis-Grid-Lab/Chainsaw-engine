#pragma once
#include "Common/Core.h"

namespace CSE {
    class GraphicsRenderer
    {
        public:
        CSE_INLINE GraphicsRenderer()
        {

        }

        CSE_INLINE void BeginDraw()
        {
            BeginDrawing();
        }

        CSE_INLINE void EndDraw()
        {
            EndDrawing();
        }
    };
}
