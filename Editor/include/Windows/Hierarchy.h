#pragma once
#include "Auxiliaries/ECS.h"
#include "Context/Context.h"
#include "Vendors/imgui/imgui.h"
#include "Windows/MenuList.h"

struct HierarchyWindow : IWidget
{
    CSE_INLINE HierarchyWindow(GuiContext* context): IWidget(context)
    {
        m_Window.push_back(context->CreateWidget<MenuListWindow>());
    }

    CSE_INLINE void OnShow(GuiContext* context) override
    {
        if(ImGui::Begin(ICON_FA_CUBE "\tHierarchy"))
        {
            context->EnttView<Entity, InfoComponent>([&] (auto entity, auto& info)
                {
                    bool isSelected = (m_Selected.ID() == entity.ID());

                    // makes each selectable unique
                    ImGui::PushID((int32_t)entity.ID());

                    // compute selectable label
    				std::string label = ICON_FA_CUBE "\t" + info.Name;

    				// special label with icons
    				//if(entity.template Has<DirectLightComponent>())
    					//label = ICON_FA_SUN "\t" + info.Name;
    				if(entity.template Has<CameraComponent>())
    					label = ICON_FA_VIDEO "\t" + info.Name;
    				//if(entity.template Has<RigidBodyComponent>())
    					//label = ICON_FA_PERSON "\t" + info.Name;
    				//if(entity.template Has<SkyboxComponent>())
    					//label = ICON_FA_CLOUD_SUN_RAIN "\t" + info.Name;
    				if(entity.template Has<Camera2DComponent>())
    				    label = ICON_FA_VIDEO "\t" + info.Name;

    				// show entity selectable
    				if(ImGui::Selectable(label.c_str(), &isSelected))
    				{
    					context->PostEvent<SelectEvent>(entity);
    				}

                    if (ImGui::IsItemHovered())
    				{
       					if (ImGui::IsMouseDoubleClicked(0) && isSelected)
       					{
      						ImGui::OpenPopup("ListComp");
       					}
       					if (ImGui::IsMouseReleased(1) && isSelected)
       					{
      						ImGui::OpenPopup("ListComp");
       					}
    				}

                    if (ImGui::BeginPopup("ListComp"))
                    {
                        if(ImGui::BeginMenu("##"))
                        {
                            ImGui::EndMenu();
                        }

                        ImGui::EndPopup();
                    }

                    ImGui::PopID();
                });
        }
        ImGui::End();
    }

    CSE_INLINE void OnSelect(Entity entity) override
    {
        m_Selected = entity;
    }

    private:
    Entity m_Selected;
    std::vector<Widget> m_Window;
};
