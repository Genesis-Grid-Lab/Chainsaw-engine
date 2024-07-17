# Install script for directory: /home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/AudioDevice.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/AudioStream.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/AutomationEventList.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/BoundingBox.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Camera2D.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Camera3D.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Color.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/FileData.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/FileText.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Font.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Functions.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Gamepad.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Image.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Keyboard.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Material.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Matrix.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Mesh.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/MeshUnmanaged.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Model.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/ModelAnimation.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Mouse.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Music.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Ray.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/RayCollision.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/RaylibException.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/raylib-cpp-utils.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/raylib-cpp.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/raylib.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/raymath.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Rectangle.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/RenderTexture.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Shader.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Sound.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Text.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Texture.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/TextureUnmanaged.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Touch.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Vector2.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Vector3.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Vector4.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/VrStereoConfig.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Wave.hpp"
    "/home/nesmy/Playground/Chainsaw-engine/vendor/raylib-cpp/include/Window.hpp"
    )
endif()

