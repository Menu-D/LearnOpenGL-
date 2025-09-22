#include <iostream> 
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// This is what initializes GLFW 
	glfwInit();

	// This is what tells GLFW the version of OpenGL we are using
	// And in this case we are using OpenGL 3.4 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	// This tells GLFW we are using the CORE profile (if your remember the glad version we installed thats what it is) 
	// So that means we only have the modern functions 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// This creates a GLFWwindow of 800 by 800 pixels and it has been named "Gothic".
	GLFWwindow* window = glfwCreateWindow(800, 800, "Gothic", NULL, NULL); 
	// This error check if window fails to create 
	if (window == NULL)
	{
		std::cout << "Failed to create the GLFW window" << std::endl; 
		glfwTerminate(); 
		return -1; 
	}
	// Introduce the window to the current context 
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL 
	gladLoadGL(); 

	// Specify the viewport of OpenGl in the Window 
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800); 

	// Specify the color of the background 
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); 
	// Clean the back buffer and assign the new color to it 
	glClear(GL_COLOR_BUFFER_BIT);
	// Swapping the buffer with the front buffer 
	glfwSwapBuffers(window); 

	// Main game loop 
	while (!glfwWindowShouldClose(window))
	{
		// Take cares of all the GLFW events 
		glfwPollEvents(); 
	}
	// Delete the window before ending the program 
	glfwDestroyWindow(window); 
	// Terminate GLFW before ending the program 
	glfwTerminate(); 
	return 0; 

}