#include "Screen.h"

namespace caveofprogramming
{
Screen::Screen():
    m_app(), m_event(), m_pixel1(sf::Points, WIDTH * HEIGHT)
{

}
void Screen::boxblurr()
{
    int a;
    for(int y=0; y<HEIGHT; y++) {
            a = y * HEIGHT;
		for(int x=0; x<WIDTH; x++) {

            /*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */

			int redTotal=0;
			int greenTotal=0;
			int blueTotal=0;

			for(int row=-1; row<=1; row++) {
				for(int col=-1; col<=1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < WIDTH && currentY >= 0 && currentY < HEIGHT) {

						sf::Uint8 red = m_pixel1[currentY*HEIGHT + currentX].color.r;
						sf::Uint8 green = m_pixel1[currentY*HEIGHT + currentX].color.g;
						sf::Uint8 blue = m_pixel1[currentY*HEIGHT + currentX].color.b;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}

				}

			}

			sf::Uint8 red = redTotal/9;
			sf::Uint8 green = greenTotal/9;
			sf::Uint8 blue = blueTotal/9;

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
