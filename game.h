#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>


namespace game_h {

	class stb {    //shut the box
	public:
		stb();
		void run();
		void create_tiles();
		void create_num();



	private:
		void event();
		void update();
		void render();
		void dice_roll();
		//void player_move();
		//void game1();
	//	void game2();
		//void computer();
		void tile_click(int mouse_x, int mouse_y);

		sf::RectangleShape zone;
		sf::RenderWindow window;   
		sf::Font font;             
		sf::Text dice_text;      
		sf::Text player_text;
		sf::Text number;

		int dice1 = 0, dice2 = 0;
		int num_tile = 0;

		std::vector<sf::RectangleShape> tiles;
		std::vector<sf::Text> numbers;

	};

}


#endif