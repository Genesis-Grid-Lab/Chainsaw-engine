#include "ChainSaw.h"
#include "Context/Context.h"
#include "Context/Events.h"
#include "Windows/Hierarchy.h"
#include "Windows/Inspector.h"
#include "Windows/MenuBar.h"
#include "Windows/Playport.h"
#include "Windows/Resource.h"
#include "Windows/Viewport.h"

class Editor : public GuiContext
{
  public:
    CSE_INLINE void OnGuiStart()
    {
        PostEvent<SelectEvent>((EntityID)4);

        AttachWindow<HierarchyWindow>();
        AttachWindow<InspectorWindow>();
        AttachWindow<ResourceWindow>();
        AttachWindow<ViewportWindow>();
        AttachWindow<PlayportWindow>();
        AttachWindow<MenuBarWindow>();
    }

    CSE_INLINE void OnGuiFrame()
    {

    }
  private:
};
