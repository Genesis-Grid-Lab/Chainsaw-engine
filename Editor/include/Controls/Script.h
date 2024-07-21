#pragma once
#include "Auxiliaries/ECS.h"
#include "Context/Widget.h"
#include "IControl.h"

struct ScriptControl : IControl<ScriptComponent>
{
    CSE_INLINE ScriptControl(GuiContext* context): IControl(context)
	{
		SetTitle(ICON_FA_PENCIL "\tScript");
	}

    CSE_INLINE void OnBody(GuiContext* context, Entity& entity)
	{
        auto& data = entity.template Get<ScriptComponent>().Source;
        /*InputFloat("Near", &data.NearPlane);
        InputFloat("Far", &data.FarPlane);
        InputFloat("FOV", &data.FOV);  */
        InputText("Souce", data.data());
    }

    CSE_INLINE void OnMenu(GuiContext* context, Entity& entity)
	{
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset"))
		{
            //entity.template Get<ScriptComponent>() = {};
        }
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove"))
		{
            entity.template Detach<ScriptComponent>();
        }
    }
};
