#pragma once
#include "Auxiliaries/Assets.h"
#include "Common/Core.h"
#include "Graphics/Utilities/Data.h"
#include "raylib.h"

namespace CSE {
    class GraphicsRenderer
    {
        public:
        CSE_INLINE GraphicsRenderer()
        {
            ViewTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
            PlayTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
        }

        CSE_INLINE void BeginDraw()
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            if(IsWindowResized())
            {
                UnloadRenderTexture(ViewTexture);
                ViewTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
                UnloadRenderTexture(PlayTexture);
                PlayTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());;
            }

        }

        CSE_INLINE void EndDraw()
        {
            EndDrawing();
        }

        CSE_INLINE void EndMode()
        {
            EndMode2D();
            EndMode3D();
            EndTextureMode();
        }

        CSE_INLINE void SetCamera(Camera3D& camera, Transform3D& transform)
        {
            camera.position = (Vector3){ transform.Translate.x, transform.Translate.y, transform.Translate.z }; // Camera position
            camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
            camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
            camera.fovy = 45.0f;                                // Camera field-of-view Y
            camera.projection = CAMERA_PERSPECTIVE;

            //UpdateCamera(&camera, CAMERA_FREE);

            BeginMode3D(camera);
            //EndMode3D();

        }

        CSE_INLINE void SetMainCamera(Camera2D& camera, Transform3D& transform)
        {

        }

        CSE_INLINE void SetCamera2D(Camera2D& camera, Transform3D& transform)
        {
            Vector2 WorldPos = GetScreenToWorld2D(Vector2({(float)GetScreenWidth(), (float)GetScreenHeight()}), camera);
            camera.target = (Vector2){transform.Translate.x,transform.Translate.y};

            //camera.target = WorldPos;
            camera.offset = (Vector2){SCRNWIDTH / 2.0f, SCRNHEIGHT / 2.0f};
            camera.rotation = 0.0f;
            camera.zoom = transform.Translate.z;

            BeginMode2D(camera);
        }

        CSE_INLINE void Draw2D(TextureAsset& sprite, Transform3D& transform, Rectangle Source, Rectangle Dest)
        {
            Vector2 center = { static_cast<float>(sprite.Data.width / 2.0), static_cast<float>(sprite.Data.height / 2.0) };
            Source.x = 0.0f;
            Source.y = 0.0f;
            Source.width = sprite.Data.width;
            Source.height = sprite.Data.height;
            DrawTextureRec(sprite.Data, Source, Vector2({transform.Translate.x, transform.Translate.y}), WHITE);
            //DrawRectangleRec(Source, GREEN);

            Dest.x = GetScreenWidth();
            Dest.y = GetScreenHeight();
            Dest.width = Source.width;
            Dest.height = Source.height;

            //DrawTexturePro(sprite.Data, Source, Dest, center, transform.Rotation.x, WHITE);
        }

        CSE_INLINE RenderTexture &GetFrame(){
            return ViewTexture;
        }

        CSE_INLINE RenderTexture &GetPlayFrame(){
            return PlayTexture;
        }

        CSE_INLINE void ShowFrame(bool show){
            if(show){
                DrawTexturePro(PlayTexture.texture, (Rectangle){0, SCRNHEIGHT, SCRNWIDTH, -SCRNHEIGHT}, (Rectangle){0, 0, SCRNWIDTH, SCRNHEIGHT}, (Vector2){0, 0}, 0, WHITE);
            }
        }

        RenderTexture ViewTexture;
        RenderTexture PlayTexture;
        private:
        Camera3D camera = {0};
    };
}
