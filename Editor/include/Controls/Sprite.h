#pragma once
#include "Auxiliaries/Assets.h"
#include "Auxiliaries/ECS.h"
#include "Common/Core.h"
#include "IControl.h"
#include "Vendors/imgui/imgui.h"
#include "raylib.h"

struct SpriteControl : IControl<SpriteComponent>
{
    CSE_INLINE SpriteControl(GuiContext* context): IControl(context)
    {
        SetTitle(ICON_FA_VIDEO "\tSprite");
    }

    CSE_INLINE void OnBody(GuiContext* context, Entity& entity)
    {
        auto& data = entity.template Get<SpriteComponent>().Sprite;

        //Texture2D m_IconImage = LoadTexture(data.Source.c_str());
        //data.Source = "test";

        ImTextureID m_Icon = (ImTextureID)&data.Data;
        ImGui::ImageButtonEx(data.UID,
            m_Icon, ImVec2(ASSET_SIZE, ASSET_SIZE), ImVec2(0, 1),
            ImVec2(1, 0), ImVec4(0, 0, 0, 1), ImVec4(1, 1, 1, 1));
        ImGui::SameLine();
        if(InputText("", file.data(), data.Source.data(), 64))
        {
            //context->AssetView([&] (auto* asset)
              //  {
                    //CSE_ERROR("SOurce %s\n", asset->Source.data());
                    //CSE_ERROR("SOurce file %s\n", file.data());
                    if(file.data() != data.Source.data()){
                        m_IconImage = context->GetContext()->Assets->AddTexture(RandomU64(), file.data());
                        data.Data = m_IconImage->Data;
                        data.Source = m_IconImage->Source;
                        data.UID = m_IconImage->UID;
                        data.Type = m_IconImage->Type;
                    }
                    //else {
                      //  CSE_ERROR("ELSE\n");
                      //}
                    //  });
        }

        //InputText("", data.Name.data(), "Untitled", 64);

    }

    CSE_INLINE void OnMenu(GuiContext* context, Entity& entity)
    {
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset"))
		{
            entity.template Get<SpriteComponent>() = {};
        }
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove"))
		{
            //entity.Erease<SpriteComponent>();
        }
    }
    std::shared_ptr<TextureAsset> m_IconImage;
    std::string file;
};
