#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "GameMenu.hpp"


using namespace sf;
using namespace std;

class Engine
{


public:
    RenderWindow windowLevel3;

    Music musicFon;//создаем объект музыки
  
    Engine();

    void run();
    // функция играть 
    void GameStart(RenderWindow &windowMenu);

    // функция об игре
    void Info();

    // функция настройки текста
    void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60, Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

    void GameMenu(RenderWindow &window);

    void Exit(RenderWindow &window2);

    void level(RenderWindow &windowLevel1, int lvl, float timer);

    void LevelPassed(RenderWindow &windowPassed2);

    void LevelFailed(RenderWindow &windowFailed2, int lvl, float timer);
	
};