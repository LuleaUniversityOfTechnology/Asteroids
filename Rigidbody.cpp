#include "Rigidbody.h"

Rigidbody::Rigidbody(Play::Point2D position, float radius)
    : m_position(position), m_radius(radius)
{
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Simulate(float timeStep)
{
    m_position += m_velocity * timeStep;
    m_velocity += m_acceleration * timeStep;
    m_acceleration = { 0.0f, 0.0f };


    const float w = static_cast<float>(Play::GetBufferWidth());
    const float h = static_cast<float>(Play::GetBufferHeight());
    if (m_position.x < 0.0f) m_position.x += w;
    if (m_position.x > w)    m_position.x -= w;
    if (m_position.y < 0.0f) m_position.y += h;
    if (m_position.y > h)    m_position.y -= h;
}

void Rigidbody::Collide(Rigidbody* /*other*/)
{
    // Base bodies do nothing on collision. Ship overrides this.
}

bool Rigidbody::IsCollidingWith(const Rigidbody* other) const
{
    if (other == nullptr || other == this)
        return false;

    Play::Vector2D delta = m_position - other->m_position;
    float distanceSq = delta.x * delta.x + delta.y * delta.y;
    float radii = m_radius + other->m_radius;
    return distanceSq < (radii * radii);
}
