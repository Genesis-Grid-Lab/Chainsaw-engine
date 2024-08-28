#pragma once
#include "Auxiliaries/Assets.h"
#include "Auxiliaries/ECS.h"
#include "Common/Core.h"
#include "IControl.h"
#include "Vendors/imgui/imgui.h"
#include "raylib.h"

struct SpriteControl : IControl<SpriteComponent> {
  CSE_INLINE SpriteControl(GuiContext *context) : IControl(context) {
    SetTitle(ICON_FA_VIDEO "\tSprite");
  }

  CSE_INLINE void OnBody(GuiContext *context, Entity &entity) {
    auto &data = entity.template Get<SpriteComponent>().Sprite;

    // Texture2D m_IconImage = LoadTexture(data.Source.c_str());
    // data.Source = "test";

    if (ImGui::BeginPopup("listSprite")) {
      context->AssetView([&](auto *asset) {
        m_Icon = (ImTextureID)&asset->Data;
        if (ImGui::ImageButtonEx(asset->UID, m_Icon,
                                 ImVec2(ASSET_SIZE, ASSET_SIZE), ImVec2(0, 1),
                                 ImVec2(1, 0), ImVec4(0, 0, 0, 1),
                                 ImVec4(1, 1, 1, 1))) {
          entity.template Detach<SpriteComponent>();
          entity.Attach<SpriteComponent>().Sprite.Data = asset->Data;
          entity.Attach<SpriteComponent>().Sprite.Name = asset->Name;
          entity.Attach<SpriteComponent>().Sprite.Source = asset->Source;
          entity.Attach<SpriteComponent>().Sprite.UID = asset->UID;

          ImGui::CloseCurrentPopup();
        }
      });
      ImGui::EndPopup();
    }
    m_Icon = (ImTextureID)&data.Data;
    if (ImGui::ImageButtonEx(data.UID, m_Icon, ImVec2(ASSET_SIZE, ASSET_SIZE),
                             ImVec2(0, 1), ImVec2(1, 0), ImVec4(0, 0, 0, 1),
                             ImVec4(1, 1, 1, 1))) {
      ImGui::OpenPopup("listSprite");
    }

    ImGui::SameLine();
    // InputText("", file.data(), data.Source.data(), 64);

    InputText("", data.Name.data(), "Untitled", 64);
  }

  CSE_INLINE void OnMenu(GuiContext *context, Entity &entity) {
    if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset")) {
      entity.template Get<SpriteComponent>() = {};
    }
    if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove")) {
      entity.template Detach<SpriteComponent>();
    }
  }
  std::shared_ptr<TextureAsset> m_IconImage;
  std::string file;
  ImTextureID m_Icon;
};
