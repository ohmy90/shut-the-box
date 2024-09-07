#include <iostream>
#include "game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace game_h;

stb::stb() : window(sf::VideoMode(1280, 720), "Shut the Box") {
	if (!font.loadFromFile("arial.ttf")){
		std::cout << "Error \n";
	}
	zone.setSize(sf::Vector2f(200, 100));
	zone.setPosition(300, 250);
	zone.setFillColor(sf::Color::Yellow);

	dice_text.setFont(font);
	dice_text.setCharacterSize(32);
	dice_text.setFillColor(sf::Color::White);
	dice_text.setPosition(350,50);
	
	player_text.setFont(font);
	player_text.setCharacterSize(32);
	player_text.setFillColor(sf::Color::White);
	player_text.setPosition(100, 500);
}

void stb::create_tiles() {
	for (int i = 0; i < num_tile; i++) {
		sf::RectangleShape tile(sf::Vector2f(80, 80));
		tile.setPosition(50 + i * 90, 600);
		tile.setFillColor(sf::Color::Transparent);
		tiles.push_back(tile);
			
	}

}


void stb::dice_roll() {
	srand((unsigned int)(time)(NULL));

	int roll = 0;
	int dice = 2;
	
	for (int i = 1; i <= dice; i++) {
		roll = (rand() % 6) + 1;
		if (i == 1)
			stb::dice1 = roll;
		else if (i == 2)
			stb::dice2 = roll;
	}

}
void stb::event() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::FloatRect zoneBounds = zone.getGlobalBounds();

			tile_click(mousePos.x, mousePos.y);

			if (zoneBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				dice_roll();
			}

		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
			game1();
			player_text.setString(" ");
			std::cin >> num_tile;

			if (num_tile != 9 || num_tile != 10 || num_tile != 12)
				std::cin >> num_tile;
			else
				player_text.setString(" ");
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
			game2();
			player_text.setString("How many tiles are we playing with? (9, 10 or 12, enter in the console)");
			std::cin >> num_tile;
			
			if (num_tile != 9||num_tile!=10|| num_tile != 12)
				std::cin >> num_tile;
			else
			player_text.setString(" ");

		}
	}
}
void stb::run() {
	while (window.isOpen()) {
		event();
		update();
		render();
	}
}
void stb::tile_click(int mouse_x, int mouse_y) {
	for 

}
void stb::update() {
	dice_text.setString("Rolled " + std::to_string(dice1) + " and " + std::to_string(dice2));
}

void stb::render() {
	window.clear();
	window.draw(dice_text);
	window.draw(player_text);
	window.draw(zone);
	for (auto& tile : tiles) {
		window.draw(tile);
	}



	window.display();
	

}

void stb::choice() {

	player_text.setString("1 player or 2 players? (press 1 or 2)");

}