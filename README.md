# ghrender

fun home project  
Main purpose is just going to be able to import 3D models and simply view them.  
The reason I am writing an unnecessary API for this is so that I have some experience in doing so.

### [Working on imgui integration](https://github.com/ghendersonnc/ghrender/tree/imgui_1)

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
