#pragma once
#include "GameObject2D.h"
#include <bitset>

class Player : public GameObject2D {

private:
	float mass;
	glm::vec2 velocity;


public:
	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass);

	void update(double tDelta) override;

	void updateKeys(std::bitset<5> newKeys);

};
