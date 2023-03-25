# Pinpoint Engine

## Context
Pinpoint Engine is a game engine I am (trying) to develop to further my graphical programming, rendering, and C++ skills for a purely educational experience. 

## Pre-reqs
- GLAD headers
- GLFW headers
- CMake

## Instructions
1. Clone repo
2. Open in VSCode
3. If first time opening, wait for CMake to finish building (Skip step if not)
4. Open the Pinpoint-Engine.sln in the `build` directory
5. In Visual Studio, set the PinpointEngine project as the default start-up project
6. Make sure run-mode (solution-configuration) is set on Debug, 64x
7. Click on "Local Windows Debugger", wait for VS to compile and enjoy!

## Troubleshooting
- Remember that the `build` directory is in the .gitignore, so use cmake to build the directory again for new clones

## Special Thanks
Thank you to reddit user 0xIsho for providng an awesome template for OpenGL projects. Original template can be found [here](https://gitlab.com/0xIsho/BasicGL).