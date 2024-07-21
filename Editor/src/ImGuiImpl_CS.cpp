// #include "GLFW/glfw3.h"
// #include "Vendors/imgui/imgui.h"
// #include "raylib.h"
// #include <map>

// static ImGuiMouseCursor CurrentMouseCursor = ImGuiMouseCursor_COUNT;
// static MouseCursor MouseCursorMap[ImGuiMouseCursor_COUNT];

// ImGuiContext* GlobalContext = nullptr;

// static std::map<KeyboardKey, ImGuiKey> RaylibKeyMap;

// static bool LastFrameFocused = false;

// static bool LastControlPressed = false;
// static bool LastShiftPressed = false;
// static bool LastAltPressed = false;
// static bool LastSuperPressed = false;

// static void SetupGlobals(void)
// {
//     LastFrameFocused = IsWindowFocused();
//     LastControlPressed = false;
//     LastShiftPressed = false;
//     LastAltPressed = false;
//     LastSuperPressed = false;
// }

// static void SetupKeymap(void)
// {

// }

// static void SetupMouseCursors(void)
// {
//     //MouseCursorMap[ImGuiMouseCursor_Arrow] = GLFW_MOUSE_BUTTON_1;
//     MouseCursorMap[ImGuiMouseCursor_TextInput] = MOUSE_CURSOR_IBEAM;
//     MouseCursorMap[ImGuiMouseCursor_Hand] = MOUSE_CURSOR_POINTING_HAND;
//     MouseCursorMap[ImGuiMouseCursor_ResizeAll] = MOUSE_CURSOR_RESIZE_ALL;
//     MouseCursorMap[ImGuiMouseCursor_ResizeEW] = MOUSE_CURSOR_RESIZE_EW;
//     MouseCursorMap[ImGuiMouseCursor_ResizeNESW] = MOUSE_CURSOR_RESIZE_NESW;
//     MouseCursorMap[ImGuiMouseCursor_ResizeNS] = MOUSE_CURSOR_RESIZE_NS;
//     MouseCursorMap[ImGuiMouseCursor_ResizeNWSE] = MOUSE_CURSOR_RESIZE_NWSE;
//     MouseCursorMap[ImGuiMouseCursor_NotAllowed] = MOUSE_CURSOR_NOT_ALLOWED;
// }


// bool ImGui_ImplChainSaw_init(void)
// {
//     SetupGlobals();

//     SetupKeymap();

//     SetupMouseCursors();

//     //SetupBackend();

//     return true;
// }
