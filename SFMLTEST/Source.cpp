#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
int main()
{
	bool bu = 0, col = 1;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Game from scratch!");

	////// Circle
	sf::CircleShape collision(50.f),bullet(10.f);
	collision.setPosition({ 200.f, 200.f });
	collision.setFillColor(sf::Color::Red);
	bullet.setFillColor(sf::Color::Red);
	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("res/img/healer_f.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	////// Sprite
	sf::Sprite shapeSprite,edge;
	shapeSprite.setTexture(playerTexture);
	shapeSprite.setTextureRect(sf::IntRect(0, 0, 32, 38));
	edge.setTextureRect(sf::IntRect(-200, 0, 1480, 1));
	while (window.isOpen())
	{
		window.draw(shapeSprite);
		if (!col)
		{
			sf::Vector2f a = { (float)((rand() % 880)+100),(float)((rand() % 400)+100) };
			collision.setPosition(a);
			col = 1;
		}
		if (col)window.draw(collision);
		if (bu)
		{
			window.draw(bullet);
			bullet.move(.0f, -0.5f);
			if (bullet.getGlobalBounds().intersects(collision.getGlobalBounds()))
			{
				bu = 0;
				col = 0;
			}
			else if (bullet.getGlobalBounds().intersects(edge.getGlobalBounds()))
			{
				bu = 0;
			}
		}
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				shapeSprite.move(.0f, -0.2f);
			else shapeSprite.move(.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				shapeSprite.move(-0.2f, .0f);
			else shapeSprite.move(-0.1f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				shapeSprite.move(.0f, 0.2f);
			else shapeSprite.move(.0f, .1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				shapeSprite.move(.2f, 0.f);
			shapeSprite.move(.1f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)&&!bu)
		{
			bullet.setPosition(shapeSprite.getPosition());
			bullet.move(7.f, -2.f);
			bu = 1;
		}
		window.clear();
	}
	return 0;
}