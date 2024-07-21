#pragma once
#include "Events.h"
#include "GLFW/glfw3.h"

namespace CSE {
    class AppWindow
    {
      public:
        CSE_INLINE AppWindow(EventDispatcher* dispatcher, int width, int height, const char *title):
            m_Dispatcher(dispatcher)
        {
            InitWindow(width, height, title);
            SetTargetFPS(60);
            GLFWwindow *handle = (GLFWwindow*)GetWindowHandle();
            // set window user data
            glfwSetWindowUserPointer(handle, this);
            //m_Dispatcher->PostEvent<WindowResizeEvent>(SCRNWIDTH, SCRNWIDTH);
            //SetKeyPressedCallback(OnKey);
            // creating the window
            glfwSetWindowMaximizeCallback(handle, OnMaximize);
            glfwSetFramebufferSizeCallback(handle, OnResize);
            glfwSetWindowIconifyCallback(handle, OnIconify);
            glfwSetMouseButtonCallback(handle, OnMouse);
            glfwSetWindowCloseCallback(handle, OnClose);
            glfwSetCursorPosCallback(handle, OnMotion);
            glfwSetScrollCallback(handle, OnWheel);
            glfwSetKeyCallback(handle, OnKey);
            glfwSetErrorCallback(OnError);

        }

        CSE_INLINE ~AppWindow(){
            CloseWindow();
        }

        CSE_INLINE bool PollEvents()
        {
            glfwPollEvents();
            m_Dispatcher->PollEvents();
            return (!WindowShouldClose());
        }

        CSE_INLINE bool IsMouse(int32_t button)
        {
            if(button >= 0 && button <= GLFW_MOUSE_BUTTON_LAST)
                return m_Inputs.Mouse.test(button);
            return false;
        }

        CSE_INLINE bool IsKey(int32_t key)
        {
            if(key >= 0 && key <= GLFW_KEY_LAST)
                return m_Inputs.Keys.test(key);
            return false;
        }
        private:
        CSE_INLINE static void OnKey(GLFWwindow* window, int32_t key, int32_t, int32_t action, int32_t)
        {
            AppWindow* self = GetUserData(window);

            if(key >= 0 && key <= GLFW_KEY_LAST)
            {
                switch (action)
                {
                    case GLFW_RELEASE:
                        self->m_Dispatcher->PostEvent<KeyReleaseEvent>(key);
                        self->m_Inputs.Keys.reset(key);
                    break;

                    case GLFW_PRESS:
                        self->m_Dispatcher->PostEvent<KeyPressEvent>(key);
                        self->m_Inputs.Keys.set(key);
                    break;

                    case GLFW_REPEAT:
                        self->m_Dispatcher->PostEvent<KeyRepeatEvent>(key);
                        self->m_Inputs.Keys.set(key);
                    break;
                }
                return;
            }
            CSE_ERROR("invalid key code detected: %d\n", key);
        }

        CSE_INLINE static void OnMouse(GLFWwindow* window, int32_t button, int32_t action, int32_t)
        {
            AppWindow* self = GetUserData(window);

            if(button >= 0 && button <= GLFW_MOUSE_BUTTON_LAST)
            {
                switch (action)
                {
                    case GLFW_PRESS:
                        self->m_Dispatcher->PostEvent<MouseDownEvent>(button);
                        self->m_Inputs.Mouse.set(button);
                    break;

                    case GLFW_RELEASE:
                        self->m_Dispatcher->PostEvent<MouseReleaseEvent>(button);
                        self->m_Inputs.Mouse.reset(button);
                    break;
                }
                return;
            }
            CSE_ERROR("Invalid key code detected: %d\n", button);
        }

        CSE_INLINE static void OnResize(GLFWwindow* window, int32_t width, int32_t height)
        {
            GetUserData(window)->m_Dispatcher->PostEvent<WindowResizeEvent>(width, height);
        }

        CSE_INLINE static void OnMotion(GLFWwindow* window, double x, double y)
        {
            AppWindow* self = GetUserData(window);
            self->m_Dispatcher->PostEvent<MouseMotionEvent>(x, y);

            if (self->m_Inputs.Mouse.test(GLFW_MOUSE_BUTTON_LEFT))
            {
                self->m_Dispatcher->PostEvent<MouseDragEvent>(
                    (self->m_Inputs.MouseX - x),
                    (self->m_Inputs.MouseY - y)
                );
            }

            self->m_Inputs.MouseX = x;
            self->m_Inputs.MouseY = y;
        }

        CSE_INLINE static void OnWheel(GLFWwindow* window, double x, double y)
        {
            GetUserData(window)->m_Dispatcher->PostEvent<MouseWheelEvent>(x, y);
        }

        CSE_INLINE static void OnMaximize(GLFWwindow* window, int32_t action)
        {
            if (action)
            {
                GetUserData(window)->m_Dispatcher->PostEvent<WindowMaximizeEvent>();
            }
            else
            {
                GetUserData(window)->m_Dispatcher->PostEvent<WindowRestoreEvent>();
            }
        }

        CSE_INLINE static void OnIconify(GLFWwindow* window, int32_t action)
        {
            if (action)
            {
                GetUserData(window)->m_Dispatcher->PostEvent<WindowIconifyEvent>();
            }
            else
            {
                GetUserData(window)->m_Dispatcher->PostEvent<WindowRestoreEvent>();
            }
        }

        CSE_INLINE static void OnError(int32_t code, const char* msg)
        {
            CSE_ERROR("[GLFW]: %d %s", code, msg);
        }

        CSE_INLINE static AppWindow* GetUserData(GLFWwindow* window)
        {
            return static_cast<AppWindow*>(glfwGetWindowUserPointer(window));
        }

        CSE_INLINE static void OnClose(GLFWwindow* window)
        {
            GetUserData(window)->m_Dispatcher->PostEvent<WindowCloseEvent>();
        }
        private:
        EventDispatcher* m_Dispatcher;
        WindowInputs m_Inputs;
    };
}
