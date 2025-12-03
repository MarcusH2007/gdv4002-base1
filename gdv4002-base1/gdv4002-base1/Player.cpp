#include "Player.h"
#include "Keys.h"
#include "bitset"

extern std::bitset<5> keys;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed) :
	GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	playerSpeed = initialPlayerSpeed;

	void Player::update(double tDelta) {
		//unlike our myUpdate function, we're already 'in' the player object, so no need to call getObject as we did before

		if (wPressed == true) {
			position.y += playerSpeed*(float)tDelta
		}

		if (aPressed == true) {
			position.x -= playerSpeed * (float)tDelta

		}

		if (sPressed == true) {
			position.y += playerSpeed * (float)tDelta
		}

		if (dPressed == true) {
			position. += playerSpeed * (float)tDelta
		}

	}
}