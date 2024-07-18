#pragma once
#include "Context/Context.h"
#include "Vendors/imgui/imgui.h"
#include "raylib.h"

struct ResourceWindow : IWidget
{
    CSE_INLINE ResourceWindow(GuiContext* context): IWidget(context)
    {
        //m_IconImage.Load("Resources/Icons/asset.png");
        //m_Icon = (ImTextureID)m_IconImage.ID();
    }

    CSE_INLINE void OnShow(GuiContext* context) override
    {
        if(ImGui::Begin(ICON_FA_FOLDER "\tResources"))
        {
            int nbrColumn = (ImGui::GetContentRegionAvail().x/ASSET_SIZE) + 1;
            int columnCounter = 1;
            int rowCounter = 1;
            if(ImGui::BeginTable("", nbrColumn))
            {
                ImGui::EndTable();
            }
        }
        ImGui::End();
    }

    private:
    Texture2D m_IconImage;
    ImTextureID m_Icon;
};
