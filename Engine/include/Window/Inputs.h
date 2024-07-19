#pragma once
#include "Common/Event.h"
#include "raylib.h"

namespace CSE {

    struct WindowInputs
    {
      std::bitset<MOUSE_BUTTON_BACK> Mouse;
      std::bitset<KEY_LEFT_SUPER> Keys;
      double MouseX = 0.0;
      double MouseY = 0.0;
    };
}
