#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//const int로 선언해도 상관 없음.
#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_RIGHT	2
#define DIR_LEFT	3

using namespace sf;

class Snake {
public :
	int dir_;
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};
int main(void) 
{
	const int WIDTH = 1000;						//픽셀 너비
	const int HEIGHT = 800;						//픽셀 높이
	const int BLOCK_SIZE = 50;					//한 칸이 가지고 있는 픽셀
	const int G_WIDTH = WIDTH / BLOCK_SIZE;		//그리드의 너비
	const int G_HEIGHT = HEIGHT / BLOCK_SIZE;	//그리드의 높이

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	//컴퓨터가 1초 동안 처리하는 횟수를 60으로 제한한다.
	//Frame per Second를 30으로 조절.
	window.setFramerateLimit(15);

	Snake snake;
	snake.x_ = 1, snake.y_ = 2;	//뱀의 그리드 좌표 
	snake.dir_ = DIR_DOWN;		//뱀이 이동하는 방향
	snake.sprite_.setFillColor(Color::White);
	snake.sprite_.setPosition(snake.x_ * BLOCK_SIZE, snake.y_ * BLOCK_SIZE);
	snake.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	Apple apple;
	apple.x_ = rand() % G_WIDTH , apple.y_ = rand() % G_HEIGHT;
	apple.sprite_.setFillColor(Color::Red);
	apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
	apple.sprite_.setSize(Vector2f(50, 50));

	while (window.isOpen()) 
	{
		Event e;
		while (window.pollEvent(e)) 
		{
			//window의 close를 눌렀을 때 창을 닫는다.
			if (e.type == Event::Closed)
				window.close();
		}

		//input 
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.dir_ = DIR_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.dir_ = DIR_LEFT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.dir_ = DIR_UP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.dir_ = DIR_DOWN;
		}

		//update
		if (snake.dir_ == DIR_UP) {
			snake.y_--;
		}
		else if (snake.dir_ == DIR_DOWN) {
			snake.y_++;
		}
		else if (snake.dir_ == DIR_LEFT) {
			snake.x_--;
		}
		else if (snake.dir_ == DIR_RIGHT) {
			snake.x_++;
		}
		snake.sprite_.setPosition(snake.x_ * BLOCK_SIZE, snake.y_ * BLOCK_SIZE);

		//뱀이 사과를 먹었을 때,
		if (snake.x_ == apple.x_ && snake.y_ == apple.y_) {
			apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
			apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
		}

		//render(draw / display)
		window.clear();

		window.draw(apple.sprite_);
		window.draw(snake.sprite_);

		window.display();
	}
	return 0;
}