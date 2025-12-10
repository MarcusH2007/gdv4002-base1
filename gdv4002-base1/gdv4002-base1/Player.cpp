#include "Player.h"
#include "Keys.h"
#include "bitset"
#include "Engine.h"

extern std::bitset<5> keys;
extern glm::vec2 gravity;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) :
	GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;

	velocity = glm::vec2(0.0f, 0.0f); //default to 0 velocity

	
}

void Player::update(double tDelta) {
	//unlike our myUpdate function, we're already 'in' the player object, so no need to call getObject as we did before

	glm::vec2 F = glm::vec2(0.0f, 0.0f);

	const float thrust = 2.0f;

	if (keys[0]) {

		F += glm::vec2(0.0f, thrust);

	}
	
	if (keys[2]) {

		F += glm::vec2(0.0f,- thrust);
	}

	if (keys[1]) {

		F += glm::vec2(-thrust, 0.0f);
	}

	if (keys[3]) {

		F += glm::vec2(thrust, 0.0f);
	}

	//gravity to the player
	F += gravity;

	//add impulse forces
	if (position.y < -getViewplaneHeight() / 2.0f) {

		F += glm::vec2(0.0f, 20.0f);
	}

	//2. calculate acceleration. if f=ma, a=f/m
	glm::vec2 a = F * (1.0f / mass);

	//3. integrate to get new velocity
	velocity = velocity + (a * (float)tDelta);

	//4. integrate to get a new position
	position = position + (velocity * (float)tDelta);


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