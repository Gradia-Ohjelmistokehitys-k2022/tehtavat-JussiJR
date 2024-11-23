/**
/**
*  _____                                                               _____
* ( ___ )                                                             ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | ############################################################# |   |
*  |   | #███╗###███╗#█████╗#██╗███╗###██╗####██████╗██████╗#██████╗## |   |
*  |   | #████╗#████║██╔══██╗██║████╗##██║###██╔════╝██╔══██╗██╔══██╗# |   |
*  |   | #██╔████╔██║███████║██║██╔██╗#██║###██║#####██████╔╝██████╔╝# |   |
*  |   | #██║╚██╔╝██║██╔══██║██║██║╚██╗██║###██║#####██╔═══╝#██╔═══╝## |   |
*  |   | #██║#╚═╝#██║██║##██║██║██║#╚████║██╗╚██████╗██║#####██║###### |   |
*  |   | #╚═╝#####╚═╝╚═╝##╚═╝╚═╝╚═╝##╚═══╝╚═╝#╚═════╝╚═╝#####╚═╝###### |   |
*  |   | ############################################################# |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                                             (_____)
*
* SUMMARY: 
* 
* Main.cpp is file what includes program's main entry point and gameloop.
* I needed to make some more or less Questionable modifications to headers in order to get this up and running.
* Funny right?
* 
* And for addition it also handles initialization
* 
* EXTERNAL INCLUDES:
*	- https://www.glfw.org/ - GLFW Open source Window manager well atleast used for it in this project
*	- https://glad.dav1d.de/ - GLAD OpenGL Api 
*	- https://www.wikihow.com/Set-Up-OpenGL%E2%80%90GLFW%E2%80%90GLAD-on-a-Project-with-Visual-Studio - To get needed library includes for Linker
*	- https://www.live2d.com/en/sdk/about/ - for some Anime Girl picture rendering stuff lol just kidding for rendering Live2D models
*	- https://github.com/VictorGordan/opengl-tutorials/tree/main/YoutubeOpenGL%200%20-%20Install . to Get GLFW3.Lib file without needing to compile and glad init
* 
* Used Websites for research:
*	- https://www.indeed.com/career-advice/career-development/normalization-formula - for normalizing the Color of back buffer for OpenGL
*	- https://www.asciiart.eu/text-to-ascii-art - For Ascii art up
*	- https://rgbacolorpicker.com/hex-to-rgba - For finding nice looking color 
*	- https://www.symbolab.com/solver/algebra-calculator - As a calculator 
* 
* Used Websites for ideas:
*	- https://stackoverflow.com/questions/20013566/c-typedef-stdfunction-how-to-use - idea for Debug print
* 
*  WASTED HOURS: 0 // Increment till you go crazy
*/

//NOTE: Includes
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


//NOTE: Usings
using namespace std;

//NOTE: Defines

//	WINDOW PROPERTIES
#define WINDOW_NAME_STRING "WEE" // Window name
#define WINDOW_SIZE_WIDTH 800 // Window width
#define WINDOW_SIZE_HEIGHT 540 // Window Height

//	OPENGL STUFF
//		Red 
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_RED 0xAF
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_RED_NORMALIZED 0.69f

//		Green
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_GREEN 0x85
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_GREEN_NORMALIZED 0.52f

//		Blue
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_BLUE 0xFF
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_BLUE_NORMALIZED 1.0f

//		Alpha
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_ALPHA 0xAF
#define OPENGL_BUFFERS_COLOR_RESET_COLOR_ALPHA_NORMALIZED 0.69f

//	Main Entrypoint Error Codes 

//		OpenGL
#define ERROR_CODE_CUSTOM_OPENGL_HEXADECIMAL_INITIALIZATION_FAILURE 0xB1

//		GLFW
#define ERROR_CODE_CUSTOM_GLFW_HEXADECIMAL_INITIALIZATION_FAILURE 0xA1

//NOTE: Typedefs


int main(int argv,char** argc){
	if (!glfwInit()) { // glfw initialization
		cout << "Failed to load GLFW" << endl;
		return ERROR_CODE_CUSTOM_OPENGL_HEXADECIMAL_INITIALIZATION_FAILURE;
	}
	
	GLFWwindow* window = glfwCreateWindow(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, WINDOW_NAME_STRING, NULL, NULL);
	glfwMakeContextCurrent(window); //Context

	if (!gladLoadGL()) { //OpenGL API initialization
		cout << "Failed to load openGL bindings" << endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return ERROR_CODE_CUSTOM_GLFW_HEXADECIMAL_INITIALIZATION_FAILURE;
	}



	//last resort initializations 

	glClearColor(OPENGL_BUFFERS_COLOR_RESET_COLOR_RED_NORMALIZED, OPENGL_BUFFERS_COLOR_RESET_COLOR_GREEN_NORMALIZED,
		OPENGL_BUFFERS_COLOR_RESET_COLOR_BLUE_NORMALIZED, OPENGL_BUFFERS_COLOR_RESET_COLOR_ALPHA_NORMALIZED); // Clear color

	while (!glfwWindowShouldClose(window)) { // Main Loop
		glfwWaitEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}