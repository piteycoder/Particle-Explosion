#include "Screen.h"

namespace caveofprogramming
{
Screen::Screen():
    m_app(), m_event(), m_pixel1(sf::Points, WIDTH * HEIGHT)
{

}
void Screen::boxblurr()
{
    sf::Uint8 red;
    sf::Uint8 green;
    sf::Uint8 blue;

    sf::Uint8 redb;
    sf::Uint8 greenb;
    sf::Uint8 blueb;

    int redTotal;
    int greenTotal;
    int blueTotal;

    for(int y=0; y<HEIGHT; y++) {
		for(int x=0; x<WIDTH; x++) {

            /*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */

			redTotal=0;
			greenTotal=0;
			blueTotal=0;

			for(int row=-1; row<=1; row++) {
				for(int col=-1; col<=1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < WIDTH && currentY >= 0 && currentY < HEIGHT) {

						redb = m_pixel1[currentY*HEIGHT + currentX].color.r;
						greenb = m_pixel1[currentY*HEIGHT + currentX].color.g;
						blueb = m_pixel1[currentY*HEIGHT + currentX].color.b;

						redTotal += redb;
						greenTotal += greenb;
						blueTotal += blueb;
					}

				}

			}

			red = redTotal/9;
            green = greenTotal/9;
			blue = blueTotal/9;

			setPixel(x, y, red, green, blue);
		}
	}
}
bool Screen::init()
{
    m_app.create(sf::VideoMode(WIDTH, HEIGHT), "Particle Fire Explosion");
    m_app.setFramerateLimit(30);
    for(int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            m_pixel1[(y * HEIGHT) + x].position = sf::Vector2f(x,y);
            m_pixel1[(y * HEIGHT) + x].color = sf::Color::Black;
        }
    }

    return true;
}
void Screen::update()
{
    m_app.clear();
    m_app.draw(m_pixel1);
    m_app.display();
}
void Screen::setPixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue) //algorytm nadawania koloru pikselom
{
    if (x < 0 || x >= Screen::WIDTH || y < 0 || y >= Screen::HEIGHT)
        return;

    m_pixel1[(y * HEIGHT) + x].color = sf::Color(red, green, blue);
}
bool Screen::processEvents()
{
    while (m_app.pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
            return false;
    }
    return true;
}
}
