#pragma once
#include "Context/Context.h"
#include "Context/Widget.h"
#include "Vendors/imgui/imgui.h"

struct MenuListWindow : IWidget
{
    CSE_INLINE MenuListWindow(GuiContext* context): IWidget(context)
    {

    }

    CSE_INLINE void OnShow(GuiContext* context) override
    {
        ImGui::OpenPopup("my_select_popup");
        ImGui::SameLine();

        if(ImGui::BeginPopup("my_select_popup"))
        {
            ImGui::EndPopup();
        }
    }
};
