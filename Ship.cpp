#include "Ship.h"
#include "Asteroid.h"   // needed for the dynamic_cast in Collide()


Ship::Ship()
    : Rigidbody(Play::Point2D{ 640.0f, 360.0f }, 30.0f)  
{
    m_spriteId = Play::GetSpriteId("ship");
}

Ship::~Ship()
{
}

// [POLYMORPHISM] This overrides Rigidbody::Simulate(). When the game loop calls
// Simulate() through a Rigidbody*
void Ship::Simulate(float timeStep)
{
    const float turnSpeed = 3.0f; 

    
   
    if (Play::KeyDown(Play::KEY_LEFT))
        m_rotation += turnSpeed * timeStep;
    if (Play::KeyDown(Play::KEY_RIGHT))
        m_rotation -= turnSpeed * timeStep;

    if (Play::KeyDown(Play::KEY_SPACE))
    {
        m_acceleration.x -= m_thrust * sin(m_rotation) * timeStep;
        m_acceleration.y += m_thrust * cos(m_rotation) * timeStep;
    }

    
    Rigidbody::Simulate(timeStep);
}

void Ship::Collide(Rigidbody* other)
{
    // 'other' is a base Rigidbody*, 
    // dynamic_cast inspects the true run-time type: it returns a valid pointer
    // if 'other' is an Asteroid, or nullptr if it is anything else. This is
    // polymorphism used to make a type-specific decision safely.
    if (dynamic_cast<Asteroid*>(other) != nullptr)
    {
        Reset();
    }
}


void Ship::Draw()
{
    
    Play::DrawSpriteRotated(m_spriteId, m_position, 0, m_rotation, 1.0f);
}

void Ship::Reset()
{
  
    m_position     = { 640.0f, 360.0f };
    m_velocity     = { 0.0f, 0.0f };
    m_acceleration = { 0.0f, 0.0f };
    m_rotation     = 0.0f;
}
