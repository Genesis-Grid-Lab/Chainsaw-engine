#pragma once
#include "Auxiliaries/Assets.h"
#include "Common/Core.h"
#include "Context/Context.h"
#include "Context/Helpers.h"
#include "Vendors/imgui/imgui.h"
#include "raylib.h"

struct ResourceWindow : IWidget
{
    CSE_INLINE ResourceWindow(GuiContext* context): IWidget(context)
    {
        m_IconImage = LoadTexture("Resources/Icons/asset.png");

    }

    CSE_INLINE void OnShow(GuiContext* context) override
    {
        if(ImGui::Begin(ICON_FA_FOLDER "\tResources"))
        {
            int nbrColumn = (ImGui::GetContentRegionAvail().x/ASSET_SIZE) + 1;
            int columnCounter = 1;
            int rowCounter = 1;
            if(ImGui::BeginTable("open", nbrColumn))
            {
                context->AssetView([&] (auto* asset)
                    {
                        {
                            //CSE_ERROR("RESOUCE\n");
                            //m_IconImage = LoadTexture(asset->Source.c_str());
                            /*if(asset)
                                m_Icon = (ImTextureID)&asset->Data;
                            else*/
                                m_Icon = (ImTextureID)&m_IconImage;
                            // show asset icon
                            bool iSClicked = ImGui::ImageButtonEx(asset->UID,
                                m_Icon, ImVec2(ASSET_SIZE, ASSET_SIZE), ImVec2(0, 1),
                                ImVec2(1, 0), ImVec4(0, 0, 0, 1), ImVec4(1, 1, 1, 1));
                            ImGui::Text(asset->Name.c_str());
                            ImGui::TableNextColumn();
                        }
                    });
                ImGui::EndTable();
            }
        }
        ImGui::End();
    }

    private:
    Texture2D m_IconImage;
    ImTextureID m_Icon;
    std::string file;
    AssetID m_Selected;
};
