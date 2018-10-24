#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace caveofprogramming
{
class Swarm
{
public:
    const static int NPARTICLES = 3000;
private:
    Particle * m_pParticles;
public:
    Swarm();
    virtual ~Swarm();

    const Particle * const getParticles() {return m_pParticles; };
    void update();
};
}
#endif // SWARM_H
