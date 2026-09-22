#pragma once
#include "Play.h"

// ============================================================================
// Rigidbody  (ABSTRACT BASE CLASS)
// ----------------------------------------------------------------------------

class Rigidbody
{
public:
    // Construct with a starting position and radius (used for collisions).
    Rigidbody(Play::Point2D position, float radius);

    // A base class with virtual methods MUST have a virtual destructor,
    
    virtual ~Rigidbody();

    // Virtual: subclasses may override, but there is a default 
    // Advance the physics by one time step 
    virtual void Simulate(float timeStep);

    // Resolve a collision against another rigid body. 
    // 'other' can be any subclass. Default does nothing; Ship overrides it.
    virtual void Collide(Rigidbody* other);

    virtual void Draw() = 0;   // <- this "= 0" is what makes the class abstract

    
    Play::Point2D GetPosition() const { return m_position; }
    float         GetRadius()   const { return m_radius; }

    // Returns true if this body overlaps 'other' (circle vs circle).
    bool IsCollidingWith(const Rigidbody* other) const;

protected:
    // Physics state shared by all rigid bodies (protected = visible to subclasses).
    Play::Point2D  m_position     { 0.0f, 0.0f };
    Play::Vector2D m_velocity     { 0.0f, 0.0f };
    Play::Vector2D m_acceleration { 0.0f, 0.0f };
    float          m_rotation     = 0.0f;   // in RADIANS
    float          m_radius       = 0.0f;   // for collision detection
};
