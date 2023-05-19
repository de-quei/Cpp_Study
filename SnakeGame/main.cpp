#include <SFML/Graphics.hpp>

using namespace sf;

int main(void) 
{
	RenderWindow window(VideoMode(640, 480), "Snake Game");

	RectangleShape snake;
	snake.setFillColor(Color::White);
	snake.setPosition(100, 300);
	snake.setSize(Vector2f(50, 50));

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

		window.draw(snake);

		window.display();
	}
	return 0;
}