# ghrender

fun home project  
Main purpose is just going to be able to import 3D models and simply view them.  
The reason I am writing an unnecessary API for this is so that I have some experience in doing so.

### Currently reevaluating requirements and planning OpenGL
decided imgui is best to integrate AFTER I push in OpenGL  
refer to [this branch](https://github.com/ghendersonnc/ghrender/tree/opengl3_1.0) for latest commits involving OpenGL (and a cool imgui message box)

## Todo

1. ~~Keyboard events~~
2. ~~Mouse events~~
3. Window events
    * Resize
    * Focus
    * Position
4. ImGui
    * Events
5. Finally OpenGL (Possibly more ImGui changes)
    * Assimp

## Some things I wanna do in the future (tentative)

* Able to add lights
    * Materials
* Able to add primitives (quads, cubes, etc)
    * Materials

## build

* Make sure CMake is installed
* (windows) Make sure path/to/cmake/bin is added to PATH
* (windows) will work on powershell, git-bash

```
$ git clone --recursive https://github.com/ghendersonnc/ghrender.git
$ cd ghrender
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```
