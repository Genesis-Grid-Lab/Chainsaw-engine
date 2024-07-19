#pragma once
#include "IControl.h"

struct SpriteControl : IControl<SpriteComponent>
{
    CSE_INLINE SpriteControl(GuiContext* context): IControl(context)
    {
        SetTitle(ICON_FA_VIDEO "\tSprite");
    }

    CSE_INLINE void OnBody(GuiContext* context, Entity& entity)
    {
        auto& data = entity.template Get<SpriteComponent>().Sprite;

    }

    CSE_INLINE void OnMenu(GuiContext* context, Entity& entity)
    {
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset"))
		{
            entity.template Get<SpriteComponent>() = {};
        }
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove"))
		{
            entity.template Detach<SpriteComponent>();
        }
    }
};
