#include <GLFW/glfw3.h>
#include <iostream>

void error_callback(int error, const char* description)
{
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

int main()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Crear ventana GLFW de 640x480 con título "GLFW Test"
    GLFWwindow* window = glfwCreateWindow(640, 480, "GLFW Test", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Hacer el contexto OpenGL actual
    glfwMakeContextCurrent(window);

    // Habilitar sincronización vertical (vsync)
    glfwSwapInterval(1);

    // Bucle principal
    while (!glfwWindowShouldClose(window))
    {
        // Procesar eventos
        glfwPollEvents();

        // Comprobar si la tecla Escape está presionada para cerrar la ventana
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);

        // Renderizado: limpiar pantalla con color azul oscuro
        glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Intercambiar buffers (doble buffering)
        glfwSwapBuffers(window);
    }

    // Limpiar y salir
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
