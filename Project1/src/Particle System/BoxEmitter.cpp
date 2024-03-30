#include "BoxEmitter.h"
#include "../GraphicsRender.h"
#include "../Random.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

BoxEmitter::BoxEmitter()
{


}

void BoxEmitter::DrawProperties()
{
   
	DrawTransformVector3ImGui("Emitter Position ", emitterPos, 0, columnWidth);
	DrawTransformVector3ImGui("Emitter Direction ", particleDir, 0, columnWidth);
	DrawTransformVector3ImGui("Emitter Scale ", boxScale, 1, columnWidth);

}

void BoxEmitter::SceneDraw()
{
}

void BoxEmitter::GetParticlePosAndDir(glm::vec3& pos, glm::vec3& dir)
{
	pos = emitterPos + FindPointInsideBox(glm::vec3(0), boxScale);

	glm::vec3 dirNom = glm::normalize(particleDir);

	dir = dirNom;

}

void BoxEmitter::Render(glm::vec3& pos)
{
	glm::vec3 centre = pos + emitterPos;

	GraphicsRender::GetInstance().DrawBox(centre, boxScale, boxColor,true);
}

glm::vec3 BoxEmitter::FindPointInsideBox(glm::vec3 center, glm::vec3 scale)
{
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate random coordinates within the range [-halfScale, halfScale] for each dimension
    std::uniform_real_distribution<float> distX(-scale.x, scale.x);
    std::uniform_real_distribution<float> distY(-scale.y, scale.y);
    std::uniform_real_distribution<float> distZ(-scale.z, scale.z);

    float x = distX(gen);
    float y = distY(gen);
    float z = distZ(gen);

    // Offset the generated coordinates by the cube's center
    glm::vec3 randomPoint = center + glm::vec3(x, y, z);

    return randomPoint;
}

glm::vec3 BoxEmitter::CalculateDirWithRotation(glm::vec3 rotation)
{
    // Define the default direction vector (e.g., along the positive z-axis)
    glm::vec3 defaultDirection(0.0f, 0.0f, 1.0f);

    // Create a rotation matrix from the euler angles of the emitter
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    // Transform the default direction vector using the rotation matrix
    glm::vec3 rotatedDirection = glm::vec3(rotationMatrix * glm::vec4(defaultDirection, 0.0f));

    // Normalize the resulting direction vector
    glm::vec3 particleDirection = glm::normalize(rotatedDirection);

    return particleDirection;
}
