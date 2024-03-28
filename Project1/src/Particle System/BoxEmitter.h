#pragma once
#include "BaseEmitterShape.h"

class BoxEmitter : public BaseEmitterShape
{

public:
	BoxEmitter();


	// Inherited via BaseEmitterShape
	void DrawProperties() override;

	void SceneDraw() override;
	void GetParticlePosAndDir(glm::vec3& pos, glm::vec3& dir) override;
	void Render(glm::vec3& pos) override;
};

