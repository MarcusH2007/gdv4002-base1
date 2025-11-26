#include "Engine.h"

int main(void) {
	//main function body
	
}

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta); {
	float player1RotationSpeed = glm::radians(90.0f);
}
setUpdateFunction(myUpdate);




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
	//addObject("player",glm::vec2(1.0f,1.0f),45.0f * 3.14/180.0f);
	addObject("player1",glm::vec2(1.0f,1.0f),glm::radians(45.0f),glm::vec2(0.5f,1.0f));
	addObject("player2", glm::vec2(1.0f, 1.0f), glm::radians(45.0f), glm::vec2(1.0f, 0.5f));
	
	GameObject2D* player2Object = getObject("player2");
	if (player2Object != nullptr) {

		//update player2 here
		player2Object->position = glm::vec2(-1.5f, 1.0f);
		player2Object->orientation = glm::radians(45.0f);
		player2Object->textureID = loadTexture("Resources\\Textures\\danny.png");
		
	}

	GameObject2D* player1Object = getObject("player1");
	if (player1Object != nullptr) {

		//update player1 here
		player1Object->position = glm::vec2(-1.0f, 1.0f);
		player1Object->orientation = glm::radians(-30.0f);
		player1Object->textureID = loadTexture("Resources\\Textures\\freddy fazbeaer.png");
	}

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


