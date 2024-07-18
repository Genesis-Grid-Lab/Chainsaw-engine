#pragma once
#include "Helpers.h"

struct SelectEvent
{
  CSE_INLINE SelectEvent(EntityID entity) : EnttID(entity)
  {}

  EntityID EnttID;
};
