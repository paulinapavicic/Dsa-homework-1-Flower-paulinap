#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow* window): window(window)
{
	this->window = window;
	this->color = sf::Color::Blue;
	this->firstChange = false;
	this->returnToBlue = false;
	this->secondcolor = sf::Color::Red;
	this->secondChange = false;
	this->returnToRed = false;
	this->thirdcolor = sf::Color::Magenta;
	this->thirdChange = false;
	this->returnToMagenta = false;
	

}

void Cvijet::draw()
{
	//sky
	sf::RectangleShape sky(sf::Vector2f(800, 400));
	sky.setFillColor(sf::Color(80, 185, 255));

	//grass
	sf::RectangleShape grass(sf::Vector2f(800, 200));
	grass.setFillColor(sf::Color(155, 255, 80));
	grass.setPosition(0, 400);
	
	sf::CircleShape centre(25);  //Centre of flower
	centre.setFillColor(sf::Color::Yellow);
	centre.setOutlineThickness(4);
	centre.setOutlineColor(sf::Color::Black);
	centre.setPosition(sf::Vector2f(window->getSize().x/2-centre.getRadius(),window->getSize().y/2-centre.getRadius()));
	
	sf::CircleShape triangle(54, 3); //first small triangle
	triangle.setFillColor(thirdcolor);
	triangle.setOutlineThickness(5);
	triangle.setOutlineColor(sf::Color::Red);
	triangle.setPosition(sf::Vector2f(window->getSize().x / 2 - triangle.getRadius(), window->getSize().y / 2 - triangle.getRadius()));

	sf::CircleShape mtriangle(54, 3); //second small triangle rotated
	mtriangle.setRotation(180);
	mtriangle.setFillColor(thirdcolor);
	mtriangle.setOutlineThickness(5);
	mtriangle.setOutlineColor(sf::Color::Red);
	mtriangle.setPosition(454, 356);

	sf::CircleShape octagon(63,8); //blue octagon
	octagon.setFillColor(color);
	octagon.setOutlineThickness(3);
	octagon.setOutlineColor(sf::Color::Cyan);
	octagon.setPosition(sf::Vector2f(window->getSize().x / 2 - octagon.getRadius(), window->getSize().y / 2 - octagon.getRadius()));

	sf::CircleShape ttriangle(100, 3); //big triangle
	ttriangle.setRotation(180);
	ttriangle.setFillColor(secondcolor);
	ttriangle.setOutlineThickness(5);
	ttriangle.setOutlineColor(sf::Color::Magenta);
	ttriangle.setPosition(499,400);
	
	sf::CircleShape ltriangle(100, 3); //big rotated triangle
	ltriangle.setFillColor(secondcolor);
	ltriangle.setOutlineThickness(5);
	ltriangle.setOutlineColor(sf::Color::Magenta);
	ltriangle.setPosition(sf::Vector2f(window->getSize().x / 2 - ltriangle.getRadius(), window->getSize().y / 2 - ltriangle.getRadius()));

	
	sf::RectangleShape stem(sf::Vector2f(250.f, 5.f));  //stem of flower
	stem.rotate(90.f);
	stem.setFillColor(sf::Color(11, 99, 30));
	stem.setPosition(800 / 2, 600 / 2);


	sf::CircleShape square(40, 4); // leaf of flower
	square.setFillColor(sf::Color(11, 99, 30));
	square.setRotation(55);
	square.setPosition(443, 460);


	window->draw(sky);
	window->draw(grass);
	
	window->draw(square);
	
	window->draw(ltriangle);
	window->draw(stem);
	window->draw(ttriangle);
	window->draw(octagon);
	window->draw(mtriangle);
	window->draw(triangle);
	window->draw(centre);



	if (color == sf::Color::Blue||firstChange) {
		color += (color, sf::Color(0, 1, 0, 0));       // red blue green alpha
		color -= (color, sf::Color(0, 0, 1, 0));
		firstChange = true;
		returnToBlue = false;
	}
	if (color == sf::Color::Green || returnToBlue) {
		color += (color, sf::Color(0, 0, 1, 0));
		color -= (color, sf::Color(0, 1, 0, 0));
		firstChange = false;
		returnToBlue = true;

	}	
	
	if (secondcolor == sf::Color::Red || secondChange) {
		secondcolor += (secondcolor, sf::Color(1, 1, 1, 0));
		secondcolor -= (secondcolor, sf::Color(1, 0, 0, 0));
		secondChange = true;
		returnToRed = false;
		
	}
	if (secondcolor == sf::Color::White || returnToRed) {
		secondcolor += (secondcolor, sf::Color(1, 0, 0, 0));
		secondcolor -= (secondcolor, sf::Color(1, 1, 1, 0));
		secondChange = false;
		returnToRed = true;
		

	}


	if (thirdcolor == sf::Color::Magenta || thirdChange) {
		thirdcolor += (thirdcolor, sf::Color(1, 0, 0, 0));
		thirdcolor -= (thirdcolor, sf::Color(1, 0, 1, 0));
		thirdChange = true;
		returnToMagenta = false;
	
	}
	if (thirdcolor == sf::Color::Red || returnToRed) {
		thirdcolor += (thirdcolor, sf::Color(1, 0, 1, 0));
		thirdcolor -= (thirdcolor, sf::Color(1, 0, 0, 0));
		thirdChange = false;
		returnToMagenta = true;
		
	}


	
	
}
