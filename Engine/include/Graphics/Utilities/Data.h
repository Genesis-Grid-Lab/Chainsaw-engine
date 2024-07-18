#pragma once
#include "Common/Core.h"
#include "raylib.h"

namespace CSE {
    struct Transform3D
    {
      CSE_INLINE Transform3D(const Transform3D&) = default;
      CSE_INLINE Transform3D() = default;

      //CSE_INLINE matrux

      Vector3 Translate = Vector3({0, 0, 0});
      Vector3 Rotation = Vector3({0, 0, 0});
      Vector3 Scale = Vector3({0, 0, 0});
    };
}
