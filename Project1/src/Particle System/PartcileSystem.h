#pragma once
#include <iostream>
#include "../model.h"


enum class Shapes
{
	CONE = 0,
	SPHERE = 1,
	BOX = 2
};

struct Particle
{
	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 velocity = glm::vec3(0.0f);
	glm::vec3 acceleration = glm::vec3(4.0f, 0.0f, 0.0f);
	float lifetime = 0.0f;
};

struct ConeEmmitterInfo
{
	ConeEmmitterInfo() {};


	glm::vec3 emitterPosition = glm::vec3(0.0f);

	glm::vec3 positionOffsetMin = glm::vec3(0.0f);
	glm::vec3 positionOffsetMax = glm::vec3(0.0f);
	unsigned int minNumParticlesPerUpdate = 0;
	unsigned int maxNumParticlesPerUpdate = 0;

	float minLifetime = 0.0f;
	float maxLifetime = 0.0f;
	glm::vec3 initVelocityMin = glm::vec3(0.0f);
	glm::vec3 initVelocityMax = glm::vec3(0.0f);

	glm::vec3 orientationChangeMinRadians = glm::vec3(0.0f);
	glm::vec3 orientationChangeMaxRadians = glm::vec3(0.0f);

	float uniformScaleChangeMin = 0.0f;
	float uniformScaleChangeMax = 0.0f;

	
	glm::vec3 constantForce = glm::vec3(0.0f);
	int maxParticless = 0;

};




class PartcileSystem : public Model
{
public:


	PartcileSystem();
	PartcileSystem(Shapes emitShape);
	PartcileSystem(Shapes emitShape, Model* desiredModel);
	~PartcileSystem();

	void InitializeParticles();



	void DrawProperties() override;
	void SceneDraw() override;

	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;

	void SetupConeEmmitter();
	void UpdateConeEmmitter(float deltaTime);
	void RenderConeEmmitterParticles();

	


	void DefaultEmitterValues();
	

private:
	
	Shapes emmitterShape = Shapes::CONE;
	Model* defaultModel = nullptr;
	ConeEmmitterInfo* coneEmmitterInfo = nullptr;

	std::vector<Particle> m_Particles;
	std::vector<Model*> m_ParticleModels;

	const double MAX_DELTATIME = 1.0 / 60.0;



	unsigned int m_getRandomInt(unsigned int min, unsigned int max);
	

	float m_getRandFloat(float a, float b);
	


	glm::vec3 m_getRandVec3Float(glm::vec3 min, glm::vec3 max);
	

};

