#include <SFML/Graphics.hpp>

using namespace sf;

int main(void) 
{
	RenderWindow window(VideoMode(640, 480), "Snake Game");
	while (window.isOpen()) 
	{
		Event e;
		while (window.pollEvent(e)) 
		{
			//window의 close를 눌렀을 때 창을 닫는다.
			if (e.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
	return 0;
}