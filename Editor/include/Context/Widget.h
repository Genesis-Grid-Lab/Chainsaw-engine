#pragma once

#include "Events.h"
#include "Inputs.h"
#include "Auxiliaries/ECS.h"

//foward decl
class GuiContext;

// widget interface
struct IWidget
{
    CSE_INLINE IWidget(GuiContext*) {};
    CSE_INLINE virtual ~IWidget() = default;
    CSE_INLINE virtual void OnSelect(Entity) {}
    CSE_INLINE virtual void OnShow(GuiContext*) {}
    CSE_INLINE virtual void SetTitle(const char*) {}
};

//widget type definition
using Widget = std::unique_ptr<IWidget>;
