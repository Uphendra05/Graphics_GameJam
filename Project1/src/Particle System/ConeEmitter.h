#pragma once
#include "BaseEmitterShape.h"

enum class EmmitFrom
{
	BASE = 0,
	VOLUME = 1
};

class ConeEmitter : public BaseEmitterShape
{

public:

	ConeEmitter();

	float angle = 2;
	float radius = 1;
	float height = 1;

	glm::vec3 endPos = glm::vec3(0);

	EmmitFrom emitFrom = EmmitFrom::BASE;

	void SetEmitFrom(EmmitFrom emmitFrom);
	EmmitFrom GetEmifrom();




	// Inherited via BaseEmitterShape
	void DrawProperties() override;

	void SceneDraw() override;

	void GetParticlePosAndDir(glm::vec3& pos, glm::vec3& dir) override;

	void Render(glm::vec3& pos) override;

private :

	const char* emitStrings[2] = { "Base", "Volume" };

	float topRadius = 0;

	int currentEmitInt = 0;
	float GetRadius(float& heightValue);
	glm::vec3 GetDirection(glm::vec3& up, glm::vec3& xzPlane);
	glm::vec3 CircularRandVec3();
	glm::vec3 GetRandomDirInsideCone( glm::vec3& up);

	
};

