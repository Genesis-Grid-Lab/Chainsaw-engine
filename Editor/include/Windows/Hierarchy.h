#pragma once
#include "Auxiliaries/ECS.h"
#include "Common/Core.h"
#include "Context/Context.h"
#include "Vendors/FA.h"
#include "Vendors/imgui/imgui.h"
#include "Windows/MenuList.h"

struct HierarchyWindow : IWidget {
  CSE_INLINE HierarchyWindow(GuiContext *context) : IWidget(context) {
    m_Window.push_back(context->CreateWidget<MenuListWindow>());
    spriteAsset = context->GetContext()->Assets->AddTexture(
        RandomU64(), "Resources/Icons/asset.png");
  }

  CSE_INLINE void OnShow(GuiContext *context) override {
    if (ImGui::Begin(ICON_FA_CUBE "\tHierarchy")) {
      context->EnttView<Entity, InfoComponent>([&](auto entity, auto &info) {
        bool isSelected = (m_Selected.ID() == entity.ID());

        // makes each selectable unique
        ImGui::PushID((int32_t)entity.ID());

        // compute selectable label
        std::string label = ICON_FA_CUBE "\t" + info.Name;

        // special label with icons
        // if(entity.template Has<DirectLightComponent>())
        // label = ICON_FA_SUN "\t" + info.Name;
        if (entity.template Has<CameraComponent>())
          label = ICON_FA_VIDEO "\t" + info.Name;
        // if(entity.template Has<RigidBodyComponent>())
        // label = ICON_FA_PERSON "\t" + info.Name;
        // if(entity.template Has<SkyboxComponent>())
        // label = ICON_FA_CLOUD_SUN_RAIN "\t" + info.Name;
        if (entity.template Has<Camera2DComponent>())
          label = ICON_FA_VIDEO "\t" + info.Name;

        // show entity selectable
        if (ImGui::Selectable(label.c_str(), &isSelected)) {
          context->PostEvent<SelectEvent>(entity);
        }

        if (ImGui::IsItemHovered()) {
          if (ImGui::IsMouseDoubleClicked(0) && isSelected) {
            ImGui::OpenPopup("ListComp");
          }
          if (ImGui::IsMouseReleased(1) && isSelected) {
            ImGui::OpenPopup("ListComp");
          }
        }

        if (ImGui::BeginPopup("ListComp")) {
          if (ImGui::BeginMenu("##")) {
            if (ImGui::MenuItem(ICON_FA_FORWARD " Add Camera")) {
              entity.template Attach<CameraComponent>();
            }
            if (ImGui::MenuItem(ICON_FA_FORWARD " Add Camera2D")) {
              entity.template Attach<Camera2DComponent>();
            }
            if (ImGui::MenuItem(ICON_FA_FORWARD " Add Sprite")) {
              context->AssetView([&](auto *asset) {
                entity.template Attach<SpriteComponent>().Sprite.Data =
                    spriteAsset->Data;
                entity.template Attach<SpriteComponent>().Sprite.Name =
                    spriteAsset->Name;
                entity.template Attach<SpriteComponent>().Sprite.Source =
                    spriteAsset->Source;
                entity.template Attach<SpriteComponent>().Sprite.UID =
                    spriteAsset->UID;
              });
            }
            if (ImGui::MenuItem(ICON_FA_FORWARD " Add Transform")) {
              entity.template Attach<TransformComponent>();
            }
            ImGui::EndMenu();
          }
          if (ImGui::Selectable(ICON_FA_RECYCLE "\tDelete")) {
            entity.Destroy();
            if (entity.template Has<SpriteComponent>()) {
              CSE_ERROR("DELETE\n");
            }
          }
          ImGui::EndPopup();
        }

        ImGui::PopID();
      });
    }
    ImGui::End();
  }

  CSE_INLINE void OnSelect(Entity entity) override { m_Selected = entity; }

private:
  Entity m_Selected;
  std::vector<Widget> m_Window;
  std::shared_ptr<std::_NonArray<TextureAsset>> spriteAsset;
};
