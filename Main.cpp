#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	glfwInit();

	// these tell the version of opengl we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//this is just the core profile of opengl we want, so only modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//describe the window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Aprendizado", NULL, NULL);

	//if it fails to make the window
	if ( window == NULL) 
	{
		std::cout << "A criação da janela falhou" << std::endl;

		return -1;
	}

	//context is like an object that hold an object	and we put our window in it
	glfwMakeContextCurrent(window);

	//when we load glad it configures our opengl
	gladLoadGL();

	//this sets out opengl viewport and its parameters
	glViewport(0, 0, 800, 800);

	//here we specify the color clear the back buffer and assign it then swap the front buffer with the back one to display the color.
	glClearColor(0.07f, 0.13f, 0.07f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
	{
		//this take care of the window events and by doing so make it so it is responding (not respond problem in windows)
		glfwPollEvents();
	}
	// delete de window and then terminate glfw before as we close it
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}