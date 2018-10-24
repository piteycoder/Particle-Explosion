#include <iostream>
#include <ctime>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "Screen.h"


using namespace caveofprogramming;

int main()
{
    srand(time(NULL));
    const unsigned int halfHeight = Screen::HEIGHT / 2;
    const unsigned int halfWidth = Screen::WIDTH / 2;

    Screen screen; // setting up the window
    if (!(screen.init()))
        return 1;

    Swarm swarm;
    const Particle * const pParticles = swarm.getParticles();

    bool quit = false;

    sf::Clock tick; //declaring variables managing pixel colors
    sf::Time elapsed;
    unsigned char red;
    unsigned char blue;
    unsigned char green;

    int x, y;
    while (!quit)
    {

        elapsed = tick.getElapsedTime();

        swarm.update();

        red = (unsigned char)((1 + sin(elapsed.asMilliseconds()*0.0001)) * 128);
        green = (unsigned char)((1 + sin(elapsed.asMilliseconds()*0.0002)) * 128);
        blue = (unsigned char)((1 + sin(elapsed.asMilliseconds()*0.0003)) * 128);


        for (int i = 0; i < Swarm::NPARTICLES; i++)
        {
            Particle particle = pParticles[i];

            x = (particle.m_x + 1) * halfWidth;
            y = particle.m_y * halfWidth + halfHeight;

            screen.setPixel(x, y, red, green, blue);

        }
        screen.boxblurr();

        screen.update();

        if (!screen.processEvents())
            break;
    }
    return 0;
}
