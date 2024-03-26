#include "PartcileSystem.h"
#include "../GraphicsRender.h"
#include <random>

PartcileSystem::PartcileSystem()
{
	
}

PartcileSystem::PartcileSystem(Shapes emitShape)
{

	defaultModel = new Model("Models/DefaultQuad/DefaultQuad.fbx");
	//GraphicsRender::GetInstance().AddModelAndShader(defaultModel, GraphicsRender::GetInstance().defaultShader);
	this->emmitterShape = emitShape;
	DefaultEmitterValues();
	InitializeParticles();
	InitializeEntity(this);

}

PartcileSystem::PartcileSystem(Shapes emitShape, Model* desiredModel)
{

	defaultModel = new Model(*desiredModel);
	//GraphicsRender::GetInstance().AddModelAndShader(defaultModel, GraphicsRender::GetInstance().defaultShader);
	this->emmitterShape = emitShape;
	DefaultEmitterValues();
	InitializeParticles();
	InitializeEntity(this);
}

PartcileSystem::~PartcileSystem()
{


}

void PartcileSystem::InitializeParticles()
{

	switch (emmitterShape)
	{
	case Shapes::CONE:
		SetupConeEmmitter();

		break;
	case Shapes::SPHERE:


		break;
	case Shapes::BOX:
		

		break;
	default:
		break;
	}
}



void PartcileSystem::Start()
{
}

void PartcileSystem::Update(float deltaTime)
{
	switch (emmitterShape)
	{
	case Shapes::CONE:
		UpdateConeEmmitter(deltaTime);
		RenderConeEmmitterParticles();


		break;
	case Shapes::SPHERE:


		break;
	case Shapes::BOX:
		

		break;
	default:
		break;
	}
	
}

void PartcileSystem::Render()
{

}

void PartcileSystem::OnDestroy()
{
}

void PartcileSystem::DrawProperties()
{

}

void PartcileSystem::SceneDraw()
{
}

void PartcileSystem::SetupConeEmmitter()
{
	this->m_Particles.clear();
	this->m_Particles.reserve(coneEmmitterInfo->maxParticless);

	// Assume the particles start invisible and dead.
	for (unsigned int count = 0; count != coneEmmitterInfo->maxParticless; count++)
	{
		Particle newParticle;
		Model* tempModel = new Model(*defaultModel);
		GraphicsRender::GetInstance().AddModelAndShader(tempModel, GraphicsRender::GetInstance().defaultShader);
		tempModel->isVisible = false;
		this->m_ParticleModels.push_back(tempModel);
		this->m_Particles.push_back(newParticle);
	}



}

void PartcileSystem::UpdateConeEmmitter(float deltaTime)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	

	if (deltaTime > MAX_DELTATIME)
	{
		deltaTime = MAX_DELTATIME;
	}

	for (Particle& curParticle : m_Particles)
	{
		if (curParticle.lifetime <= 0.0)
		{
			curParticle.lifetime = this->m_getRandFloat(this->coneEmmitterInfo->minLifetime,
				this->coneEmmitterInfo->maxLifetime);

			std::cout << "Current Liftime : " << curParticle.lifetime << std::endl;

			curParticle.position = this->coneEmmitterInfo->emitterPosition;
			curParticle.position += this->m_getRandVec3Float(this->coneEmmitterInfo->positionOffsetMin,
				this->coneEmmitterInfo->positionOffsetMax);

			curParticle.velocity = this->m_getRandVec3Float(this->coneEmmitterInfo->initVelocityMin,
				this->coneEmmitterInfo->initVelocityMax);
			
			
		}

	}

	for (Particle &curParticle : m_Particles)
	{
		if (curParticle.lifetime > 0.0)
		{

			curParticle.velocity += curParticle.acceleration * (float)deltaTime;

			curParticle.position += curParticle.velocity * (float)deltaTime;

			curParticle.lifetime -= (float)deltaTime;
		}

	}


}

void PartcileSystem::RenderConeEmmitterParticles()
{
	int i = 0;
	for (Particle& curParticle : m_Particles)
	{
		if (curParticle.lifetime > 0.0)
		{

			m_ParticleModels[i]->transform.position = curParticle.position;
			m_ParticleModels[i]->isVisible = true;
			i++;
			            
		}

	}

}


void PartcileSystem::DefaultEmitterValues()
{
	coneEmmitterInfo = new ConeEmmitterInfo();
	coneEmmitterInfo->emitterPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	
	coneEmmitterInfo->initVelocityMin = glm::vec3(-3.0f, 0.0f, -3.0f);
	coneEmmitterInfo->initVelocityMax = glm::vec3(3.0f, 0.0f, 3.0f);

	
	coneEmmitterInfo->orientationChangeMinRadians = glm::vec3(0.0f, 0.0f, -0.1f);
	coneEmmitterInfo->orientationChangeMaxRadians = glm::vec3(0.0f, 0.0f, 0.1f);

	coneEmmitterInfo->uniformScaleChangeMin = 0.001f;
	coneEmmitterInfo->uniformScaleChangeMax = 0.003f;

	coneEmmitterInfo->constantForce = glm::vec3(-4.0f, 0.0f, 0.0f);
	coneEmmitterInfo->minLifetime = 1.0f;
	coneEmmitterInfo->maxLifetime = 5.0f;

	coneEmmitterInfo->maxParticless = 100;
	

}

unsigned int PartcileSystem::m_getRandomInt(unsigned int min, unsigned int max)
{
	
		// Got this from: https://stackoverflow.com/questions/5008804/how-do-you-generate-uniformly-distributed-random-integers
		unsigned int output = min + (rand() % static_cast<unsigned int>(max - min + 1));

		return output;
	
}

float PartcileSystem::m_getRandFloat(float a, float b)
{
	
		// https://stackoverflow.com/questions/5289613/generate-random-float-between-two-floats
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	
}

glm::vec3 PartcileSystem::m_getRandVec3Float(glm::vec3 min, glm::vec3 max)
{

		glm::vec3 randPoint;
		randPoint.x = this->m_getRandFloat(min.x, max.x);
		randPoint.y = this->m_getRandFloat(min.y, max.y);
		randPoint.z = this->m_getRandFloat(min.z, max.z);

		return randPoint;
	
}


