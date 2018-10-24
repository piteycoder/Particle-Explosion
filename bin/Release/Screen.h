#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include "Swarm.h"

namespace caveofprogramming
{
class Screen
{
public:
    const static int HEIGHT = 600;
    const static int WIDTH = 600;

private:
    sf::RenderWindow m_app;
    sf::Event m_event;
    sf::VertexArray m_pixel1;

public:
    Screen();
    bool init();
    void update();
    void setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
    bool processEvents();
    void boxblurr();
};
}
#endif // SCREEN_H
