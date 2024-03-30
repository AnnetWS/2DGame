#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

namespace game
{
	class GameMenu
	{
		float menu_X;                                    
		float menu_Y;				                      
		int menu_Step;                                    
		int max_menu;                                     
		int size_font;                                    
		int mainMenuSelected;                             
		Font font;                                    
		vector<Text> mainMenu;                   

		Color menu_text_color = Color::White;      
		Color chose_text_color = Color::Yellow;    
		Color border_color = Color::Black;        

		void setInitText(Text& text, const String& str, float xpos, float ypos) const;

		RenderWindow& mywindow;                       
	public:

		GameMenu(sf::RenderWindow& window, float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name);

		void draw();                                    

		void MoveUp();                                  

		void MoveDown();                                 

		void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

		void AlignMenu(int posx);      

		int getSelectedMenuNumber() const     
		{
			return mainMenuSelected;
		}
	};
}