# Pinpoint Engine

**Table of Contents**
1. [Context](#context)
2. [Pre-reqs](#pre-reqs)
3. [Setup](#setup-instructions)
4. [Troubleshooting](#troubleshooting)
5. [Special Thanks](#special-thanks)

## Context
Pinpoint Engine is a game engine I am (trying) to develop to further my graphical programming, rendering, and C++ skills for a purely educational experience. 

## To Do
* Link headers and cpp files correctly
   * Currently can't implement CPP code in respective CPP files

## Pre-reqs
- GLAD headers
- GLFW headers
- CMake

## Setup Instructions
1. Clone repo
2. Open in VSCode
3. Select variant via `ctrl + shift + p`, search `Variant` and choose `Release`
4. Build the project by doing `ctrl + shift + p` then `CMake: Build`
5. Open the `Pinpoint-Engine.exe` in the `Build` directory

## Troubleshooting
- Remember that the `build` directory is in the .gitignore, so use cmake to build the directory again for new clones

## Proctoring the Project Structure
```
pinpoint-engine
├─ .vscode
│  ├─ settings.json
│  └─ tasks.json
├─ CMakeLists.txt
├─ LICENSE.txt
├─ README.md
├─ src
│  ├─ main.cpp
│  └─ shaders
│     ├─ fragmentShader.GLSL
│     └─ vertexShader.GLSL
└─ vendor
   ├─ CMakeLists.txt
   ├─ glad
   │  ├─ ...
   └─ glfw
      ├─ ...

```


## Special Thanks
Thank you to reddit user 0xIsho for providng an awesome template for OpenGL projects. Original template can be found [here](https://gitlab.com/0xIsho/BasicGL).