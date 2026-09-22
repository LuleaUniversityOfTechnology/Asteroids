#include "Asteroid.h"


static float RandRange(float min, float max)
{
    float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    return min + t * (max - min);
}

// [INHERITANCE] Forward to the BASE constructor to set the inherited start

Asteroid::Asteroid()
    // Start in the top-left corner, radius roughly matches the sprite size.
    : Rigidbody(Play::Point2D{ 50.0f, 50.0f }, 40.0f)
{
    m_spriteId = Play::GetSpriteId("asteroid");

    // Randomize velocity within a reasonable amount (m_velocity is INHERITED).
    m_velocity = { RandRange(-100.0f, 100.0f), RandRange(-100.0f, 100.0f) };

    // Randomize the asteroid-only members: scale and spin.
    m_scale         = RandRange(0.5f, 1.5f);
    m_rotationSpeed = RandRange(-2.0f, 2.0f);   // radians / second

    // Keep the INHERITED collision radius roughly in step with the visual scale.
    m_radius = 40.0f * m_scale;
}

Asteroid::~Asteroid()
{
}

// [POLYMORPHISM] Overrides Rigidbody::Simulate();
void Asteroid::Simulate(float timeStep)
{
    
    Rigidbody::Simulate(timeStep);

    m_rotation += m_rotationSpeed * timeStep;
}
void Asteroid::Draw()
{
    
    Play::DrawSpriteRotated(m_spriteId, m_position, 0, m_rotation, m_scale);
}
