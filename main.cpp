#include "settings.h"
using namespace sf;

int main()
{

	float cposX = 380.f;
	float cposY = 280.f;
	
	//�������� ��������

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

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(Wheight, Wwidth), "SFML Works!");



	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//1 �������
		window.clear();

	

		//2  ���������
		window.draw(batL);
		window.draw(batR);
		window.draw(c1);

		cposX += speed;
		cposY -= speed;

	    //3 ����� �� �����
		window.display();


	}

	return 0;
}