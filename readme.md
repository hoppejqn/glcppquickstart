# OpenGLExample

A minimal OpenGL project template integrating GLFW 3.4 and GLAD, configured for Linux/X11 platforms.  
This project serves as a foundation for developing OpenGL applications with GLFW window/context management and GLAD function loading.

## Features

- GLFW 3.4 source integrated for fine control and customization  
- GLAD loader for OpenGL functions  
- Linux platform support using X11 and related extensions  
- CMake-based build system with C++17 standard  
- Modular and extensible source structure

## Requirements

- CMake (≥ 3.10)  
- GCC or compatible C++17 compiler  
- X11 development libraries (`libx11-dev`, `libxrandr-dev`, `libxi-dev`, etc.)  
- OpenGL development headers

## Build Instructions

```bash
mkdir build
cd build
cmake ..
make
```

- by hoppejqn, gpt
