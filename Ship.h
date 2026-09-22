#pragma once
#include "Rigidbody.h"

// ============================================================================
// Ship : public Rigidbody          <-- [INHERITANCE]
// ----------------------------------------------------------------------------             

// [POLYMORPHISM] Simulate(), Collide() and Draw() are marked 'override'.
class Ship : public Rigidbody
{
public:
    Ship();
    ~Ship() override;   // 'override' of the base virtual destructor

    // [POLYMORPHISM] Override the base physics: 
    void Simulate(float timeStep) override;

    void Collide(Rigidbody* other) override;

    void Draw() override;

private:
    void Reset();   

    // ---- Members that belong ONLY to Ship (not in the base class) 
    float m_thrust   = 700.0f;  
    int   m_spriteId = 0;      
};
