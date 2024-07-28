#pragma once
#include "Auxiliaries/ECS.h"
#include "Context/Context.h"
#include "Context/Widget.h"
#include "Vendors/FA.h"
#include "Vendors/imgui/imgui.h"
#include "Vendors/imgui/rlImGui.h"
#include "raylib.h"

struct PlayportWindow : IWidget
{
    CSE_INLINE PlayportWindow(GuiContext* context): IWidget(context){
        //RenderTexture test = context->GetSceneFrame();
        //m_Frame = &test;
    }

    CSE_INLINE void OnShow(GuiContext* context) override {


        if(ImGui::Begin(ICON_FA_IMAGE "\tPlay")){
			ImGui::BeginChild("Frame");
           	{
				// show scene frame
				const ImVec2 size = ImGui::GetWindowContentRegionMax();
				//ImGui::Image(m_Frame, size, ImVec2(0, 1), ImVec2(1, 0));
				rlImGuiImageRenderTextureFit(&context->GetPlayFrame(), true);;

				// get imgui io
				auto& io = ImGui::GetIO();

				if(ImGui::IsWindowHovered())
				{


				}
			}
			ImGui::EndChild();
        }
        ImGui::End();
    }

  private:
    ImTextureID m_Frame;
    ImVec2 m_Viewport;

};
