#include "Engine.h"
#include "Keys.h"
#include <bitset>
#include "Player.h"

	

// Function prototypes

bool wPressed;
bool aPressed;
bool sPressed;
bool dPressed;

 

	
    
	
	
	
	
	
	



void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) {

	//check if the key was just pressed
	if (action == GLFW_PRESS) {
		//now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			//if escape is pressed tell GLFW we want to close the window (and quit)

			glfwSetWindowShouldClose(window, true);
			break;

		case GLFW_KEY_W:
			printf("w pressed\n");
			wPressed = true;
			break;

		case GLFW_KEY_A:
			printf("a pressed\n");
			aPressed = true;
			break;

		case GLFW_KEY_S:
			printf("s pressed\n");
			sPressed = true;
			break;

		case GLFW_KEY_D:
			printf("d pressed\n");
			dPressed = true;
			break;
		}
	}
	//if not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {
		

		//handle key release events
		switch (key)
		{
		case GLFW_KEY_W:
			printf("w released\n"); 
			wPressed = false;
			break;

		case GLFW_KEY_A:
			printf("a released\n");
			aPressed = false;
			break;

		case GLFW_KEY_S:
			printf("s released\n");
			sPressed = false;
			break;

		case GLFW_KEY_D:
			printf("d released\n");
			dPressed = false;
			break;

		}
	}
}

std::bitset<5> keys{ 0x0 };

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//

	GLuint playerTexture =loadTexture("Resources\\Textures\\player1_ship.png");

	Player* mainPlayer =new Player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);

	addObject("player", mainPlayer);

		
}
	
	
	

	
	setKeyboardHandler(myKeyboardHandler);
	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


