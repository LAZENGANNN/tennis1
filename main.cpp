#include "settings.h"
using namespace sf;

int main()
{

	float cposX = 380.f;
	float cposY = 280.f;
	
	//создание обьектов

	//bat
	RectangleShape batL(Vector2f(BATheight, BATwidth));
	RectangleShape batR(Vector2f(BATheight, BATwidth));
	batL.setSize(batsize);
	batR.setSize(batsize);
	batL.setPosition(batoffset, Wwidth - BATwidth/2);
	batR.setPosition(Wheight - batoffset, 260);
	batL.setFillColor(Color::Red);
	batR.setFillColor(Color::Blue);

	//ball
	CircleShape c1(ballrad);
	c1.setPosition(cposX, cposY);

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(Wheight, Wwidth), "SFML Works!");



	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//1 очистка
		window.clear();

	

		//2  отрисовка
		window.draw(batL);
		window.draw(batR);
		window.draw(c1);

		cposX += speed;
		cposY -= speed;

	    //3 вывод на экран
		window.display();


	}

	return 0;
}