#pragma once
#include "Context/Widget.h"
#include "Controls/Camera.h"
#include "Controls/Camera2D.h"
#include "Controls/EnttInfo.h"
#include "Controls/Sprite.h"
#include "Controls/Transform.h"

struct InspectorWindow : IWidget
{
    CSE_INLINE InspectorWindow(GuiContext* context): IWidget(context)
    {
        m_Widgets.push_back(context->CreateWidget<InfoControl>());
        m_Widgets.push_back(context->CreateWidget<CameraControl>());
        m_Widgets.push_back(context->CreateWidget<TransformControl>());
        m_Widgets.push_back(context->CreateWidget<Camera2DControl>());
        m_Widgets.push_back(context->CreateWidget<SpriteControl>());
    }

    CSE_INLINE void OnShow(GuiContext* context) override
    {
        if(ImGui::Begin(ICON_FA_CIRCLE_INFO "\tInspector"))
        {
            for(auto& widget : m_Widgets)
                widget->OnShow(context);
        }
        ImGui::End();
    }

    CSE_INLINE void OnSelect(Entity entity) override
    {
        for(auto& widget : m_Widgets)
            widget->OnSelect(entity);
    }

    private:
    std::vector<Widget> m_Widgets;
};
