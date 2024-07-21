#pragma once
#include "Window/Window.h"
#include "../Scripts/Context.h"
#include "Graphics/Renderer.h"

namespace CSE
{
    //forward declaration
    class AppInterface;

    // application context
    class AppContext
    {
      public:
        CSE_INLINE AppContext(){
            Window = std::make_unique<AppWindow>(&Dispatcher, SCRNWIDTH, SCRNHEIGHT, "ChainSaw Engine");
            Scripts = std::make_unique<ScriptContext>(&Scene, Window.get());
            Renderer = std::make_unique<GraphicsRenderer>();
            Assets = std::make_unique<AssetRegistry>();
        }

        CSE_INLINE ~AppContext(){
            for(auto layer : Layers)
            {
                CSE_DELETE(layer);
            }
        }

        std::unique_ptr<AppWindow> Window;
        std::unique_ptr<GraphicsRenderer> Renderer;
        std::unique_ptr<ScriptContext> Scripts;
        std::unique_ptr<AssetRegistry> Assets;
        std::vector<AppInterface*> Layers;
        EventDispatcher Dispatcher;
        EntityRegistry Scene;
    };
}
