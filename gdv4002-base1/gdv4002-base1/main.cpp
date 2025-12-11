#include "Engine.h"
#include "Keys.h"
#include <bitset>
#include "Player.h"
#include "Enemy.h"
#include "Emitter.h"
//#include "glPrint.h"

	

// Function prototypes

//global vars
glm::vec2 gravity = glm::vec2(0.0f, -0.005f);

bool wPressed;
bool aPressed;
bool sPressed;
bool dPressed;

 
std::bitset<5> keys;

//glm::vec2 gravity = glm::vec2(0.0f, -1.0f);
	
Player* mainPlayer;

GLuint myFontNormal = 0;
GLuint myFontUnderline = 0;

//void myRender(GLFWwindow* window);

	
	
	
	
	
void deleteSnowflakes(GLFWwindow* window, double tDelta) {

}



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
			keys[0] = 1;
			break;

		case GLFW_KEY_A:
			printf("a pressed\n");
			aPressed = true;

			keys[1] = 1;
			break;

		case GLFW_KEY_S:
			printf("s pressed\n");
			sPressed = true;

			keys[2] = 1;
			break;

		case GLFW_KEY_D:
			printf("d pressed\n");
			dPressed = true;

			keys[3] = 1;
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

			keys[0] = 0;
			break;

		case GLFW_KEY_A:
			printf("a released\n");
			aPressed = false;

			keys[1] = 0;
			break;

		case GLFW_KEY_S:
			printf("s released\n");
			sPressed = false;

			keys[2] = 0;
			break;

		case GLFW_KEY_D:
			printf("d released\n");
			dPressed = false;

			keys[3] = 0;
			break;

		}
	}

	mainPlayer->updateKeys(keys);
}



int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024, 10.0f);
	
	//myFontNormal = glBuildFont(L"Consolas", 24);
	//myFontUnderline = glBuildFont(L" Aptos", 24, GLFONT_STYLE::BOLD | GLFONT_STYLE::UNDERLINE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed

	}
	
	

	//
	// Setup game scene objects here
	//


	GLuint playerTexture =loadTexture("Resources\\Textures\\player1_ship.png");

	mainPlayer =new Player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);

	addObject("player", mainPlayer);

	//1. load enemy texture
	GLuint enemyTexture = loadTexture("Resources\\Textures\\asteroid.png");

	// 2. Create enemy objects
	Enemy* enemy1 = new Enemy(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(45.0f));

	Enemy* enemy2 = new Enemy(glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(90.0f));

	Enemy* enemy3 = new Enemy(glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(60.0f));

	// Add enemy objects to the engine
	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);

	Emitter* emitter = new Emitter(glm::vec2(0.0f, getViewplaneHeight() / 2.0f * 1.2f), glm::vec2(getViewplaneWidth() / 2.0f, 0.0f), 0.05f);
	addObject("emitter", emitter);



	setKeyboardHandler(myKeyboardHandler);
	setUpdateFunction(deleteSnowflakes, false);
	//setRenderFunction(myRender);
	// Enter main loop - this handles update and render calls
	
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

//void myRender(GLFWwindow* window) {
	//Render code goes here...

	//glSetCurrentFont(myFontUnderline);

	//glColor3f(1.0f, 1.0f, 1.0f);

	//glRasterPos2f(0.0f, 0.0f);

	//glPrint("Hello, World!");

//}