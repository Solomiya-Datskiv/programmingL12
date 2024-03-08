// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite

	image_width = 124; // the width of the image in pixels
	scaled = false; // the image is not scaled

	int xPos = SCREEN_WIDTH/2;        // place the player object in the centre of the screen
	int yPos = SCREEN_HEIGHT/2;
	setPosition(xPos, yPos);  // set the position of the players sprite

	speed = 5; // the average speed
	direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	lives = 3;
}

void Player::loadImage()
// Loads the image for the player object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	sprite.setTexture(texture);
}



sf::Sprite Player::getBody() // get the player's body
{
	return sprite;
}


void Player::setPosition()  // set the position of the player on the screen
{
	sprite.setPosition(200, 40);
}


void Player::setPosition(int xPos, int yPos)  // set the position of the player on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Player::update()
{
	sf::Vector2f playerPosition = sprite.getPosition();
	
	if (direction == EAST)
	{
		if (playerPosition.x + image_width > SCREEN_WIDTH)
		{
			direction = WEST;
		}
		else
		{
			playerPosition.x += speed;
		}
		
	}
	if (direction == WEST)
		{
		if (playerPosition.x < 0)
		{
			direction = EAST;
		}
		else
		{
			playerPosition.x -= speed;
		}
			
	}

	sprite.setPosition(playerPosition);
	

	

}

void Player::increaseSpeed()
{
	if (speed < 15)
		speed++;
}

void Player::decreaseSpeed()
{

	if (speed > 1)
	{
		speed--;
	}
		
}

void Player::increaseSize()
{
	if (scaled == false)
	{
		sprite.setScale(1.5f, 1.5f);
		image_width = 186;
		scaled = true;
	}
	
}

void Player::changeColour()
{
	int colour;
	colour = (rand() % 5) + 1;
	if (colour == 1)
	{
		sprite.setColor(sf::Color::Red);
	}
	else if (colour == 2)
	{
		sprite.setColor(sf::Color::Blue);
	}
	else if(colour == 3)
	{
		sprite.setColor(sf::Color::Yellow);
	}
	else if (colour == 4)
	{
		sprite.setColor(sf::Color::Green);
	}
	else
	{
		sprite.setColor(sf::Color::White);
	}
}

void Player::changeDirection()
{
	if (direction == WEST)
	{
		direction = EAST;
	}

	if (direction == EAST)
	{
		direction = WEST;
	}
}

