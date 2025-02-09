#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Renderer/OpenGL/ShaderOpenGL.hpp>
#include <Renderer/OpenGL/LayoutObjectOpenGL.hpp>
#include <Renderer/OpenGL/VertexArrayOpenGL.hpp>
#include <Renderer/OpenGL/VertexBufferOpenGL.hpp>
#include <Renderer/BufferLayout.hpp>
#include <Core/Window/WindowGLFW.hpp>
#include <Core/Window.hpp>


#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main() {
   
    PEPE::WindowGLFW::init("PEPE", SCR_WIDTH, SCR_HEIGHT);

    glfwSetFramebufferSizeCallback(static_cast<GLFWwindow *>(PEPE::Window::get_native_window()), framebuffer_size_callback);

    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

   
    PEPE::ShaderOpenGL ourShader(
        "assets/shader.vs",
        "assets/shader.fs"); 

  
    float vertices[] = {
        // positions         // colors
        0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top
    };

    uptr<PEPE::BufferLayout> layout = uptr<PEPE::BufferLayout>(
        new PEPE::BufferLayout({
            new PEPE::LayoutObjectOpenGL{PEPE::LayoutObjectType::Float3},
            new PEPE::LayoutObjectOpenGL{PEPE::LayoutObjectType::Float3}
            }
        )
    );

    uptr<PEPE::VertexBufferOpenGL> vertex_buffer = uptr<PEPE::VertexBufferOpenGL>(
        new PEPE::VertexBufferOpenGL(std::move(layout))
    );

    vertex_buffer->setData(vertices, sizeof(vertices));

    sptr<PEPE::VertexArrayOpenGL> vertex_array = sptr<PEPE::VertexArrayOpenGL>(new PEPE::VertexArrayOpenGL());
    vertex_array->addVertexBuffer(std::move(vertex_buffer));


    while (!PEPE::Window::should_close()) {
   
        processInput(static_cast<GLFWwindow *>(PEPE::Window::get_native_window()));
    
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();
       
        vertex_array->bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        PEPE::Window::swap();
        PEPE::Window::poll_events();
    }

    return 0;
}


void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
