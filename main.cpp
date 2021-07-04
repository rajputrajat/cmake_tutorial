#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>
#include <cmk_config.h>

int main(int argc, char * argv[]) {
    std::cout << "hello cmake!" << "\n";
    std::cout << add(10.0f, 20.2f) << "\n";

    std::cout << argv[0] << " version " << CMK_VERSION_MAJOR << "." << CMK_VERSION_MINOR << "\n";

    GLFWwindow *window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        // draw();

        // Update animation
        // animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Terminate GLFW
    glfwTerminate();
}
