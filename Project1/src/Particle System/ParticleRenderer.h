#pragma once
#include "EmitterProperty.h"
#include "../model.h"
class ParticleRenderer : public EmitterProperty
{
public:
	ParticleRenderer();
	~ParticleRenderer();

	float minParticleSize = 0.0f;
	float maxParticleSize = 1.0f;

	Model* particleModel = nullptr;


	// Inherited via EmitterProperty
	void DrawProperties() override;

	void SceneDraw() override;

};

