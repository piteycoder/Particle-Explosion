#include "Particle.h"
#include <cmath>
#include <cstdlib>

namespace caveofprogramming
{
Particle::Particle(): m_x(0), m_y(0)
{
    init();
}
Particle::~Particle()
{

}
void Particle::init()
{
    m_x = 0;
    m_y = 0;
    m_direction = 2 * 3.14159 * rand()/RAND_MAX;
    m_speed = 0.09 * rand()/RAND_MAX;
    m_speed *= m_speed;
}
void Particle::update()
{
    m_direction += 0.005;

    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed;
    m_y += yspeed;

    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
        init();
    }

    if (rand() < RAND_MAX/1000)
        init();
}
}
