#pragma once
#include "IControl.h"

struct Camera2DControl : IControl<Camera2DComponent>
{
    CSE_INLINE Camera2DControl(GuiContext* context): IControl(context)
    {
        SetTitle(ICON_FA_VIDEO "\tCamera2D");
    }

    CSE_INLINE void OnBody(GuiContext* context, Entity& entity)
    {
        auto& data = entity.template Get<Camera2DComponent>().Camera;
        InputFloat("Zoom", &data.zoom);
        Vector3 offset = {data.offset.x, data.offset.y, 0};
        Vector3 target = {data.target.x, data.target.y, 0};
        InputVec3("Offset", &offset);
        InputVec3("Target", &target);
        InputFloat("Rotation", &data.rotation);
    }

    CSE_INLINE void OnMenu(GuiContext* context, Entity& entity)
    {
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset"))
		{
            entity.template Get<Camera2DComponent>() = {};
        }
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove"))
		{
            //entity.template Detach<Camera2DComponent>();
            entity.template Remove<Camera2DComponent>();
        }
    }
};
