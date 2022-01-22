#include <SFML/Graphics.hpp>

void printMainMenu(sf::RenderWindow& window)
{
	sf::Texture t1, t2, t3, t4;

	t1.loadFromFile("Images and Fonts/background.jpg");
	t2.loadFromFile("Images and Fonts/logo.png");
	t3.loadFromFile("Images and Fonts/button.png");

	sf::Sprite background(t1);
	sf::Sprite logo(t2);
	sf::Sprite button(t3);

	window.draw(background);
	logo.setPosition(157, 40);
	window.draw(logo);


	//sf::Texture logo, enterButton, searchButton, lastButton;
}

void setMenu(int &stage)
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "History Notes", sf::Style::Close);

	while (window.isOpen())
	{
		sf::Event event1;

		
		printMainMenu(window);
		//switch (stage)
		/*{
		case 1:
			window.clear(sf::Color(179, 122, 76));
			break;
		case 2:
			window.clear(sf::Color(179, 122, 76));
			break;
		case 3:
			window.clear(sf::Color(179, 122, 76));
			break;
		}*/
		window.display();
		window.clear();
	}

}	