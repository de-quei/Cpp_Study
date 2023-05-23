#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

using namespace sf;

int main(void) 
{
	const int WIDTH = 1000;
	const int HEIGHT = 800;
	const int BLOCK_SIZE = 50;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	//컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다.
	//Frame per Second를 6으로 조절.
	window.setFramerateLimit(60);

	RectangleShape snake;
	snake.setFillColor(Color::White);
	snake.setPosition(100, 300);
	snake.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	RectangleShape apple;
	apple.setFillColor(Color::Red);
	apple.setPosition(rand() % (WIDTH - BLOCK_SIZE), rand() % (HEIGHT - BLOCK_SIZE));
	apple.setSize(Vector2f(50, 50));

	while (window.isOpen()) 
	{
		Event e;
		while (window.pollEvent(e)) 
		{
			//window의 close를 눌렀을 때 창을 닫는다.
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
			snake.move(5, 0);
		else if (Keyboard::isKeyPressed(Keyboard::Left))
			snake.move(-5, 0);
		else if (Keyboard::isKeyPressed(Keyboard::Up))
			snake.move(0, -5);
		else if (Keyboard::isKeyPressed(Keyboard::Down))
			snake.move(0, 5);

		//뱀이 사과를 먹었을 때,
		if (snake.getGlobalBounds().intersects(apple.getGlobalBounds())) {
			apple.setPosition(rand() % (WIDTH - BLOCK_SIZE), rand() % (HEIGHT - BLOCK_SIZE));
		}

		window.clear();

		window.draw(apple);
		window.draw(snake);

		window.display();
	}
	return 0;
}