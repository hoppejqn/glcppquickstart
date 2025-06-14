cmake_minimum_required(VERSION 3.10)
project(OpenGLExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definir macro para compilar soporte X11
add_definitions(-D_GLFW_X11)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/glad/include
    ${PROJECT_SOURCE_DIR}/src
)

set(GLFW_SOURCES
    # Archivos comunes GLFW
    src/context.c
    src/init.c
    src/input.c
    src/monitor.c
    src/window.c
    src/platform.c
    src/posix_module.c
    src/vulkan.c

    # Archivos X11
    src/x11_init.c
    src/x11_monitor.c
    src/x11_window.c
    src/xkb_unicode.c

    src/linux_joystick.c          # <-- agregar este
    src/posix_poll.c
    src/posix_thread.c
    src/posix_time.c

    # Contextos de OpenGL
    src/glx_context.c
    src/egl_context.c
    src/osmesa_context.c

    # Plataforma Null
    src/null_init.c
    src/null_monitor.c
    src/null_window.c
    src/null_joystick.c
)

add_executable(OpenGLExample
    main/main.cpp
    glad/glad.c
    ${GLFW_SOURCES}
)

find_package(OpenGL REQUIRED)

target_link_libraries(OpenGLExample
    ${OPENGL_LIBRARIES}
)

if(UNIX AND NOT APPLE)
    target_link_libraries(OpenGLExample
        dl
        pthread
        X11
        Xrandr
        Xi
        Xxf86vm
        Xinerama
        Xcursor
    )
endif()
