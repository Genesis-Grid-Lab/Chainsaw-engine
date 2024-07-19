#pragma once
#include "Context/Widget.h"
#include "IControl.h"

struct CameraControl : IControl<CameraComponent>
{
    CSE_INLINE CameraControl(GuiContext* context): IControl(context)
    {
        SetTitle(ICON_FA_VIDEO "\tCamera");
    }

    CSE_INLINE void OnBody(GuiContext* context, Entity& entity)
    {
        auto& data = entity.template Get<CameraComponent>().Camera;
        InputFloat("position.x", &data.position.x);
        InputFloat("position.y", &data.position.y);
        InputFloat("position.z", &data.position.z);
        InputVec3("position", &data.position);
    }

    CSE_INLINE void OnMenu(GuiContext* context, Entity& entity)
    {
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset"))
		{
            entity.template Get<CameraComponent>() = {};
        }
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove"))
		{
            entity.template Detach<CameraComponent>();
        }
    }
};
