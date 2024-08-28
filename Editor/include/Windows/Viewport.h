#pragma once
#include "Auxiliaries/ECS.h"
#include "Context/Context.h"
#include "Context/Widget.h"
#include "Vendors/FA.h"
#include "Vendors/imgui/imgui.h"
#include "Vendors/imgui/rlImGui.h"
#include "raylib.h"

struct ViewportWindow : IWidget
{
    CSE_INLINE ViewportWindow(GuiContext* context): IWidget(context){
        //RenderTexture test = context->GetSceneFrame();
        //m_Frame = &test;
    }

    CSE_INLINE void OnShow(GuiContext* context) override {


        if(ImGui::Begin(ICON_FA_IMAGE "\tViewport")){
			ImGui::BeginChild("Frame");
           	{
				// show scene frame
				const ImVec2 size = ImGui::GetWindowContentRegionMax();
				//ImGui::Image(m_Frame, size, ImVec2(0, 1), ImVec2(1, 0));
				rlImGuiImageRenderTextureFit(&context->GetSceneFrame(), true);;

				// get imgui io
				auto& io = ImGui::GetIO();

				if(ImGui::IsWindowHovered())
				{
                    // handle zoom in/out
					if(io.MouseWheel <= 1)
					{
						float sensibility = 50;

						context->EnttView<Entity, MainCamera2DComponent>([&] (auto entity, auto& comp)
						{
							auto& transform = entity.template Get<TransformComponent>().Transform;
							transform.Translate.z -= (io.MouseWheel * io.DeltaTime * sensibility);
							//comp.Camera.zoom -= (io.MouseWheel * io.DeltaTime * sensibility);
						});
					}

					bool selected = false;
					// handle dragging
					if(ImGui::IsMouseDragging(ImGuiMouseButton_Left))
					{
						float sensibility = 50;

						context->EnttView<Entity, MainCamera2DComponent>([&] (auto entity, auto& comp)
						{
							auto& transform = entity.template Get<TransformComponent>().Transform;
							if(selected == false)
							{
							    transform.Translate.x += (io.MouseDelta.x * io.DeltaTime * sensibility);
								transform.Translate.y += (io.MouseDelta.y * io.DeltaTime * sensibility);
							}
						});
					}

					context->EnttView<Entity, SpriteComponent>([&] (auto entity, auto comp)
					{
					    auto& transform = entity.template Get<TransformComponent>().Transform;
						Vector2 point = {io.MousePos.x, io.MousePos.y};

						// if(CheckCollisionPointRec(point, comp.Source))
						// {
						//     selected = true;
						//     transform.Translate.x = GetMousePosition().x;
						// 	transform.Translate.y = GetMousePosition().y;
						// 	CSE_ERROR("Herse\n");
						// }
						// else {
						//   selected = false;
						// }

					});
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
