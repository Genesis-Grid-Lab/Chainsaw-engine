#pragma once

#include "Context/Widget.h"
#include "Controls/EnttInfo.h"
struct InspectorWindow : IWidget
{
    CSE_INLINE InspectorWindow(GuiContext* context): IWidget(context)
    {
        m_Widgets.push_back(context->CreateWidget<InfoControl>());
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