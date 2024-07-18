#pragma once
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
        }

        CSE_INLINE void BeginDraw()
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            if(IsWindowResized())
            {
                UnloadRenderTexture(ViewTexture);
                ViewTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());;
            }
            BeginTextureMode(ViewTexture);
            ClearBackground(SKYBLUE);
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

        CSE_INLINE void SetCamera2D(Camera2D& camera, Transform3D& transform)
        {
            Vector2 WorldPos = GetScreenToWorld2D(Vector2({(float)GetScreenWidth(), (float)GetScreenHeight()}), camera);
            camera.target = (Vector2){transform.Translate.x,transform.Translate.y};
            //camera.target = WorldPos;
            camera.offset = (Vector2){SCRNWIDTH / 2.0f, SCRNHEIGHT / 2.0f};
            camera.rotation = 0.0f;
            camera.zoom = 1.0f;

            BeginMode2D(camera);
        }

        CSE_INLINE RenderTexture &GetFrame(){
            return ViewTexture;
        }

        CSE_INLINE void ShowFrame(bool show){
            if(show){
                DrawTexturePro(ViewTexture.texture, (Rectangle){0, SCRNHEIGHT, SCRNWIDTH, -SCRNHEIGHT}, (Rectangle){0, 0, SCRNWIDTH, SCRNHEIGHT}, (Vector2){0, 0}, 0, WHITE);
            }
        }

        RenderTexture ViewTexture;
        private:
        Camera3D camera = {0};
    };
}
