#include "Player.h"
#include "Keys.h"
#include "bitset"

extern std::bitset<5> keys;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed) :
	GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	playerSpeed = initialPlayerSpeed;

	
}

void Player::update(double tDelta) {
	//unlike our myUpdate function, we're already 'in' the player object, so no need to call getObject as we did before

	if (keys[0]) {
		position.y += playerSpeed * (float)tDelta;
		//orientation += playerSpeed * (float)tDelta;
	}

	if (keys[1]) {
		position.x -= playerSpeed * (float)tDelta;
		orientation += playerSpeed * (float)tDelta;
	}

	if (keys[3]) {
		position.y -= playerSpeed * (float)tDelta;
		//orientation -= playerSpeed * (float)tDelta;
	}

	if (keys[4]) {
		position.x += playerSpeed * (float)tDelta;
		orientation -= playerSpeed * (float)tDelta;
	}
}

void Player::updateKeys(std::bitset<5> newKeys) {

	if (newKeys[0] != keys[0]) {
		keys[0] = newKeys[0];
	}

	if (newKeys[1] != keys[1]) {
		keys[1] = newKeys[1];
	}

	if (newKeys[2] != keys[2]) {
		keys[2] = newKeys[2];
	}

	if (newKeys[3] != keys[3]) {
		keys[3] = newKeys[3];
	}
	if (newKeys[4] != keys[4]) {
		keys[4] = newKeys[4];
	}
}