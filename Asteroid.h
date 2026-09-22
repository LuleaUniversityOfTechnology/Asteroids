#pragma once
#include "Rigidbody.h"

// ============================================================================
// Asteroid : public Rigidbody      <-- [INHERITANCE]
// ----------------------------------------------------------------------------

class Asteroid : public Rigidbody
{
public:
    Asteroid();          // randomizes velocity, scale and spin (see .cpp)
    ~Asteroid() override;

    // [POLYMORPHISM] Override: run the inherited physics AND spin the rock.
    void Simulate(float timeStep) override;

    // [ABSTRACTION] Required implementation of the base's pure virtual Draw().
    void Draw() override;

private:
    // ---- Members that belong ONLY to Asteroid (not in the base class) ------
    float m_scale         = 1.0f;   
    float m_rotationSpeed = 0.0f;   
    int   m_spriteId      = 0;     
};
