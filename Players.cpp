#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Players.hpp"
#include "map1.hpp"
#include "map2.hpp"
#include "map3.hpp"
#include "map4.hpp"
#include <cmath>

using namespace sf;
using namespace std;


All::All(String F, float X, float Y, float W, float H) {
	File = F;
	w  = W;
	h = H;
	image.loadFromFile("image/" + File); 
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
}

Dog::Dog(String F, float X, float Y, float W, float H, int lvl) :All(F, X, Y, W, H) {  
	state = 5;
	Level = lvl;
	dir = 0; 
	BoneCount = 0;
	dx = dy = speed = 0;
	isShoot = false;
	sprite.setTextureRect(IntRect(0, 0, w, h));
}
 
void Dog::update(float time, Event event, int lvl, Sound shoot, float Time) //оживление объекта класса 
{
	switch (dir) //поведение в зависимости от направления
	{
		case 0: dx = speed; dy = 0;   break; //идем вправо
		case 1: dx = -speed; dy = 0;   break; //идем влево
		case 2: dx = 0; dy = speed;   break; //идем вниз
		case 3: dx = 0; dy = -speed;   break; //идем вверх
	}
 
	x += dx*time;
	y += dy*time; 
 
	speed = 0; //убираем скорость, чтобы персонаж остановился
	sprite.setPosition(x,y); //задается позиция
	if (Level == 1) 
	{
		interactionWithMap1(event); //для постоянного взаимодействия с картой
	} else if (Level == 2)
	{
		interactionWithMap2(event); //для постоянного взаимодействия с картой
	} else if (Level == 3)
	{
		interactionWithMap3(event); //для постоянного взаимодействия с картой
	} else if (Level == 4)
	{
		interactionWithMap4(event); //для постоянного взаимодействия с картой
	}
}

void Dog::interactionWithMap1(Event event) //взаимодействиe с картой
{
	     
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap1[i][j] == '0') || (TileMap1[i][j] == 'c') || (TileMap1[i][j] == 'z') || (TileMap1[i][j] == 'd'))//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
			{
				if (dy > 0)//если мы шли вниз,
				{
					y = i * 56 - h; //останавливаем персонажа рядом
				}
					
				if (dy < 0) //аналогично в другие стороны
				{
					y = i * 56 + 56;
				}
					
				if (dx > 0)
				{
					x = j * 56 - w;
				}
					
				if (dx < 0)
				{
					x = j * 56 + 56;//аналогично идем влево
				}
			}
			/*if (TileMap[i][j] == 's') 
			{ 
				TileMap[i][j] = 'a'; //коробка становится косточкой
			}*/

			if (event.type == Event::MouseButtonPressed)  //если нажата клавиша мыши
			{
				if (TileMap1[i][j] == 'a') 
				{ 
					
					BoneCount++;
					//Bone.push_back(Count);
					//Count++;
					TileMap1[i][j] = ' '; //забираем косточку
					//shoot.play();
					//shoot.stop();
					//shoot.stop();
				}
			}

		}
	}
}

void Dog::interactionWithMap2(Event event) //взаимодействиe с картой
{     
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap2[i][j] == '0') || (TileMap2[i][j] == 'c') || (TileMap2[i][j] == 'z') || (TileMap2[i][j] == 'd'))//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
			{
				if (dy > 0)//если мы шли вниз,
				{
					y = i * 56 - h; //останавливаем персонажа рядом
				}
					
				if (dy < 0) //аналогично в другие стороны
				{
					y = i * 56 + 56;
				}
					
				if (dx > 0)
				{
					x = j * 56 - w;
				}
					
				if (dx < 0)
				{
					x = j * 56 + 56;//аналогично идем влево
				}
			}
			/*if (TileMap[i][j] == 's') 
			{ 
				TileMap[i][j] = 'a'; //коробка становится косточкой
			}*/

			if (event.type == Event::MouseButtonPressed)  //если нажата клавиша мыши
			{
				if (TileMap2[i][j] == 'a') 
				{ 
					
					BoneCount++;
					//Bone.push_back(Count);
					//Count++;
					TileMap2[i][j] = ' '; //забираем косточку
					//shoot.play();
					//shoot.stop();
					//shoot.stop();
				}
			}

		}
	}
}

void Dog::interactionWithMap3(Event event) //взаимодействиe с картой
{     
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap3[i][j] == '0') || (TileMap3[i][j] == 'c') || (TileMap3[i][j] == 'z') || (TileMap3[i][j] == 'd'))//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
			{
				if (dy > 0)//если мы шли вниз,
				{
					y = i * 56 - h; //останавливаем персонажа рядом
				}
					
				if (dy < 0) //аналогично в другие стороны
				{
					y = i * 56 + 56;
				}
					
				if (dx > 0)
				{
					x = j * 56 - w;
				}
					
				if (dx < 0)
				{
					x = j * 56 + 56;//аналогично идем влево
				}
			}
			/*if (TileMap[i][j] == 's') 
			{ 
				TileMap[i][j] = 'a'; //коробка становится косточкой
			}*/

			if (event.type == Event::MouseButtonPressed)  //если нажата клавиша мыши
			{
				if (TileMap3[i][j] == 'a') 
				{ 
					
					BoneCount++;
					//Bone.push_back(Count);
					//Count++;
					TileMap3[i][j] = ' '; //забираем косточку
					//shoot.play();
					//shoot.stop();
					//shoot.stop();
				}
			}

		}
	}
}

void Dog::interactionWithMap4(Event event) //взаимодействиe с картой
{     
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap4[i][j] == '0') || (TileMap4[i][j] == 'c') || (TileMap4[i][j] == 'z') || (TileMap4[i][j] == 'd'))//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
			{
				if (dy > 0)//если мы шли вниз,
				{
					y = i * 56 - h; //останавливаем персонажа рядом
				}
					
				if (dy < 0) //аналогично в другие стороны
				{
					y = i * 56 + 56;
				}
					
				if (dx > 0)
				{
					x = j * 56 - w;
				}
					
				if (dx < 0)
				{
					x = j * 56 + 56;//аналогично идем влево
				}
			}
			/*if (TileMap[i][j] == 's') 
			{ 
				TileMap[i][j] = 'a'; //коробка становится косточкой
			}*/
			if (TileMap4[i][j] == 'a') {
			if (event.type == Event::MouseButtonPressed)  //если нажата клавиша мыши
			{
				//if (TileMap4[i][j] == 'a') 
				//{ 	
					BoneCount++;
					TileMap4[i][j] = ' '; //забираем косточку

				//}
			}
			}
		}
	}
}

bool Dog::CheckCPassedLevel1()
{
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap1[i][j] == 'q') || (TileMap1[i][j] == 'w') || (TileMap1[i][j] == 'e') || (TileMap1[i][j] == 'r') || (TileMap1[i][j] == 't') || (TileMap1[i][j] == 'y'))
			{
				if (BoneCount == LevelSizeKost(Level)) 
				{
					return true;		
				} else
				{ 
					return false;
				}
			} else 
			{
				return false;
			}
		}
	}
	return false;
}

bool Dog::CheckCPassedLevel2()
{
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap2[i][j] == 'q') || (TileMap2[i][j] == 'w') || (TileMap2[i][j] == 'e') || (TileMap2[i][j] == 'r') || (TileMap2[i][j] == 't') || (TileMap2[i][j] == 'y'))
			{
				if (BoneCount == LevelSizeKost(Level)) 
				{
					return true;		
				} else
				{ 
					return false;
				}
			} else 
			{
				return false;
			}
		}
	}
	return false;
}

bool Dog::CheckCPassedLevel3()
{
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap3[i][j] == 'q') || (TileMap3[i][j] == 'w') || (TileMap3[i][j] == 'e') || (TileMap3[i][j] == 'r') || (TileMap3[i][j] == 't') || (TileMap3[i][j] == 'y'))
			{
				if (BoneCount == LevelSizeKost(Level)) 
				{
					return true;		
				} else
				{ 
					return false;
				}
			} else 
			{
				return false;
			}
		}
	}
	return false;
}

bool Dog::CheckCPassedLevel4()
{
	for (int i = y / 56; i < ((y + h) / 56); i++)
	{
		for (int j = x / 56; j < ((x + w) / 56); j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
		{
			if ((TileMap4[i][j] == 'q') || (TileMap4[i][j] == 'w') || (TileMap4[i][j] == 'e') || (TileMap4[i][j] == 'r') || (TileMap4[i][j] == 't') || (TileMap4[i][j] == 'y'))
			{
				if (BoneCount == LevelSizeKost(Level)) 
				{
					return true;		
				} else
				{ 
					return false;
				}
			} else 
			{
				return false;
			}
		}
	}
	return false;
}

int Dog::LevelSizeKost(int Level)
{
	if (Level == 1) 
	{
		return 4;
	} else if (Level == 2) 
	{
		return 5;
	} else if (Level == 3)
	{
		return 6;
	} else if (Level == 4)
	{
		return 7;
	} else {
		return 0;
	}
}

float Dog::getplayercoordinateX(){	
	return x;
}
float Dog::getplayercoordinateY(){	
	return y;
}

void Dog::drawMap1(RenderWindow &window, Sprite s_map) {
    //отрисовка карты
	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap1[i][j] == ' ')  s_map.setTextureRect(IntRect(93, 0, 56, 56)); // трава
			if (TileMap1[i][j] == 's')  s_map.setTextureRect(IntRect(417, 853, 56, 56)); // коробка
			if (TileMap1[i][j] == '0') s_map.setTextureRect(IntRect(93, 93, 57, 57));// темная трава
			if (TileMap1[i][j] == 'a') s_map.setTextureRect(IntRect(475, 279, 57, 57)); // косточка
			//будка
			if (TileMap1[i][j] == 'q') s_map.setTextureRect(IntRect(372, 675, 57, 57));
			if (TileMap1[i][j] == 'w') s_map.setTextureRect(IntRect(429, 675, 57, 57));
			if (TileMap1[i][j] == 'e') s_map.setTextureRect(IntRect(372, 730, 57, 57));
			if (TileMap1[i][j] == 'r') s_map.setTextureRect(IntRect(429, 730, 57, 57));
			if (TileMap1[i][j] == 't') s_map.setTextureRect(IntRect(486, 675, 57, 57));
			if (TileMap1[i][j] == 'y') s_map.setTextureRect(IntRect(486, 730, 57, 57));

			//препятствия
			if (TileMap1[i][j] == 'z') s_map.setTextureRect(IntRect(186, 93, 57, 57)); // камень
			if (TileMap1[i][j] == 'c') s_map.setTextureRect(IntRect(0, 186, 57, 57)); // вода
			if (TileMap1[i][j] == 'd') s_map.setTextureRect(IntRect(480, 208, 56, 56)); // куст

			s_map.setPosition(j * 56 ,i * 56);
 
			window.draw(s_map);//рисуем квадратики на экран
		}
    }
}

void Dog::drawMap2(RenderWindow &window, Sprite s_map) {
    //отрисовка карты
	for (int i = 0; i < HEIGHT_MAP2; i++)
	{
		for (int j = 0; j < WIDTH_MAP2; j++)
		{
			if (TileMap2[i][j] == ' ')  s_map.setTextureRect(IntRect(93, 0, 56, 56)); // трава
			if (TileMap2[i][j] == 's')  s_map.setTextureRect(IntRect(417, 853, 56, 56)); // коробка
			if (TileMap2[i][j] == '0') s_map.setTextureRect(IntRect(93, 93, 57, 57));// темная трава
			if (TileMap2[i][j] == 'a') s_map.setTextureRect(IntRect(475, 279, 57, 57)); // косточка
			//будка
			if (TileMap2[i][j] == 'q') s_map.setTextureRect(IntRect(372, 675, 57, 57));
			if (TileMap2[i][j] == 'w') s_map.setTextureRect(IntRect(429, 675, 57, 57));
			if (TileMap2[i][j] == 'e') s_map.setTextureRect(IntRect(372, 730, 57, 57));
			if (TileMap2[i][j] == 'r') s_map.setTextureRect(IntRect(429, 730, 57, 57));
			if (TileMap2[i][j] == 't') s_map.setTextureRect(IntRect(486, 675, 57, 57));
			if (TileMap2[i][j] == 'y') s_map.setTextureRect(IntRect(486, 730, 57, 57));

			//препятствия
			if (TileMap2[i][j] == 'z') s_map.setTextureRect(IntRect(186, 93, 57, 57)); // камень
			if (TileMap2[i][j] == 'c') s_map.setTextureRect(IntRect(0, 186, 57, 57)); // вода
			if (TileMap2[i][j] == 'd') s_map.setTextureRect(IntRect(480, 208, 56, 56)); // куст

			s_map.setPosition(j * 56 ,i * 56);
 
			window.draw(s_map);//рисуем квадратики на экран
		}
    }
}

void Dog::drawMap3(RenderWindow &window, Sprite s_map) {
    //отрисовка карты
	for (int i = 0; i < HEIGHT_MAP3; i++)
	{
		for (int j = 0; j < WIDTH_MAP3; j++)
		{
			if (TileMap3[i][j] == ' ')  s_map.setTextureRect(IntRect(93, 0, 56, 56)); // трава
			if (TileMap3[i][j] == 's')  s_map.setTextureRect(IntRect(417, 853, 56, 56)); // коробка
			if (TileMap3[i][j] == '0') s_map.setTextureRect(IntRect(93, 93, 57, 57));// темная трава
			if (TileMap3[i][j] == 'a') s_map.setTextureRect(IntRect(475, 279, 57, 57)); // косточка
			//будка
			if (TileMap3[i][j] == 'q') s_map.setTextureRect(IntRect(372, 675, 57, 57));
			if (TileMap3[i][j] == 'w') s_map.setTextureRect(IntRect(429, 675, 57, 57));
			if (TileMap3[i][j] == 'e') s_map.setTextureRect(IntRect(372, 730, 57, 57));
			if (TileMap3[i][j] == 'r') s_map.setTextureRect(IntRect(429, 730, 57, 57));
			if (TileMap3[i][j] == 't') s_map.setTextureRect(IntRect(486, 675, 57, 57));
			if (TileMap3[i][j] == 'y') s_map.setTextureRect(IntRect(486, 730, 57, 57));

			//препятствия
			if (TileMap3[i][j] == 'z') s_map.setTextureRect(IntRect(186, 93, 57, 57)); // камень
			if (TileMap3[i][j] == 'c') s_map.setTextureRect(IntRect(0, 186, 57, 57)); // вода
			if (TileMap3[i][j] == 'd') s_map.setTextureRect(IntRect(480, 206, 56, 56)); // куст

			s_map.setPosition(j * 56 ,i * 56);
 
			window.draw(s_map);//рисуем квадратики на экран
		}
    }
}

void Dog::drawMap4(RenderWindow &window, Sprite s_map) {
    //отрисовка карты
	for (int i = 0; i < HEIGHT_MAP4; i++)
	{
		for (int j = 0; j < WIDTH_MAP4; j++)
		{
			if (TileMap4[i][j] == ' ')  s_map.setTextureRect(IntRect(93, 0, 56, 56)); // трава
			if (TileMap4[i][j] == 's')  s_map.setTextureRect(IntRect(417, 853, 56, 56)); // коробка
			if (TileMap4[i][j] == '0') s_map.setTextureRect(IntRect(93, 93, 57, 57));// темная трава
			if (TileMap4[i][j] == 'a') s_map.setTextureRect(IntRect(475, 279, 57, 57)); // косточка
			//будка
			if (TileMap4[i][j] == 'q') s_map.setTextureRect(IntRect(372, 675, 57, 57));
			if (TileMap4[i][j] == 'w') s_map.setTextureRect(IntRect(429, 675, 57, 57));
			if (TileMap4[i][j] == 'e') s_map.setTextureRect(IntRect(372, 730, 57, 57));
			if (TileMap4[i][j] == 'r') s_map.setTextureRect(IntRect(429, 730, 57, 57));
			if (TileMap4[i][j] == 't') s_map.setTextureRect(IntRect(486, 675, 57, 57));
			if (TileMap4[i][j] == 'y') s_map.setTextureRect(IntRect(486, 730, 57, 57));

			//препятствия
			if (TileMap4[i][j] == 'z') s_map.setTextureRect(IntRect(186, 93, 57, 57)); // камень
			if (TileMap4[i][j] == 'c') s_map.setTextureRect(IntRect(0, 186, 57, 57)); // вода
			if (TileMap4[i][j] == 'd') s_map.setTextureRect(IntRect(480, 208, 57, 57)); // куст

			s_map.setPosition(j * 56 ,i * 56);
 
			window.draw(s_map);//рисуем квадратики на экран
		}
    }
}

Cat::Cat(String F, float X, float Y, float W, float H, int lvl) :All(F,X,Y,W,H) 
{  
    Level = lvl;
	dx = -0.1; 
	dy = 0;
	speed = 0.06;
	CurrentFrame2 = 0;
	sprite.setTextureRect(IntRect(0, 104, w, h));  
	X1 = X; Y1 = Y;
}

void Cat::StartPosition(float time)
{
		if (y < Y1) 
		{
			dir = 3;
		} 
		else
		{
			dir = 2;
		}

	switch (dir) //поведение в зависимости от направления
	{
		case 2: dx = 0;  dy = speed; sprite.setTextureRect(IntRect(0, 104, 93, 90));   break; //идем вниз
		case 3:  dx = 0; dy = -speed; sprite.setTextureRect(IntRect(0, 305, 93, 83));   break; //идем вверх
	}

	x += dx*time;
	y += dy*time; 

	sprite.setPosition(x,y); //задается позиция
}

void Cat::update(float time, Event event, int lvl, Sound shoot, float Time) 
{	
	if (dx == 0) {
		dx = -0.1; 
	}
	if (lvl == 1)
	{
		interactionWithMap1(dx, 0, time); //взаимодействие с картой по горизонтали
	} else if (lvl == 2)
	{
		interactionWithMap2(dx, 0, time); //взаимодействие с картой по горизонтали
	} else if (lvl == 3)
	{
		interactionWithMap3(dx, 0, time); //взаимодействие с картой по горизонтали
	} else if (lvl == 4)
	{
		interactionWithMap4(dx, 0, time); //взаимодействие с картой по горизонтали
	}
	if (dx > 0) 
	{ 
		CurrentFrame2 += 0.005*Time; //проходит по кадрам персонажа, она доходит до 4 кадров 
		if (CurrentFrame2 > 3) CurrentFrame2 -= 3; 
		sprite.setTextureRect(IntRect(97 * int(CurrentFrame2), 204, 93, 90)); //идем вправо
	}
	if (dx < 0)
	{
		CurrentFrame2 += 0.005*Time; //проходит по кадрам персонажа, она доходит до 4 кадров 
		if (CurrentFrame2 > 3) CurrentFrame2 -= 3;
		sprite.setTextureRect(IntRect(97 * int(CurrentFrame2), 105, 93, 90));//идем влево
	}

	x += dx*time;
	y = Y1;
	sprite.setPosition(x, y); 
}

float Cat::getplayercoordinateX(){	
	return x;
}
float Cat::getplayercoordinateY(){	
	return y;
}

void Cat::move(Vector2f& direct, float Dx, float Dy, float time, float X, float Y, bool stop, float Time) {
	
	if (Dy == 0) {
		if (Dx < 0) {
			if (x > X) {
				if (y < Y) {
					dir = 1; 
				} else {
					dir = 1;
				}
			} else {
				if (y < Y) {
					dir = 2; 
				} else {
					dir = 3;
				}
			}
		}
		if (Dx > 0) {
			if (x > X) {
				if (y < Y) {
					dir = 2; 
				} else {
					dir = 3;
				}
			} else {
				if (y < Y) {
					dir = 0; 
				} else {
					dir = 0;
				}
			}
		}
	}

	if (Dx == 0) 
	{
		if (Dy < 0) {
			if (x > X) {
				if (y < Y) {
					dir = 1; 
				} else {
					dir = 3;
				}
			} else {
				if (y < Y) {
					dir = 0; 
				} else {
					dir = 3;
				}
			}
		}
		if (Dy > 0) {
			if (x > X) {
				if (y < Y) {
					dir = 2; 
				} else {
					dir = 1;
				}
			} else {
				if (y < Y) {
					dir = 2; 
				} else {
					dir = 0;
				}
			}
		}
	}
	if (stop) {
			if (floor(x) > floor(X)) {
					if (floor(y) < floor(Y)) {
						dir = 2; 
					} else {
						dir = 1;
					}
			} else if (floor(x) < floor(X)) {
					if (floor(y) < floor(Y)) {
						dir = 2; 
					} else {
						dir = 0;
					}
			} else if (floor(x) == floor(X)) {
				if (floor(y) < floor(Y)) {
						dir = 2; 
					} else {
						dir = 3;
				}
			}

	}
	

	switch (dir) //поведение в зависимости от направления
	{
		case 0: dx = speed; dy = 0; CurrentFrame2 += 0.005*Time; //проходит по кадрам персонажа, она доходит до 4 кадров 
			if (CurrentFrame2 > 3) CurrentFrame2 -= 3; sprite.setTextureRect(IntRect(97 * int(CurrentFrame2), 204, 93, 90));   break; //идем вправо
		case 1: dx = -speed; dy = 0; CurrentFrame2 += 0.005*Time; //проходит по кадрам персонажа, она доходит до 4 кадров 
			if (CurrentFrame2 > 3) CurrentFrame2 -= 3; sprite.setTextureRect(IntRect(97 * int(CurrentFrame2), 105, 93, 90));   break; //идем влево
		case 2: dx = 0; dy = speed; CurrentFrame2 += 0.005*Time; //проходит по кадрам персонажа, она доходит до 4 кадров 
			if (CurrentFrame2 > 3) CurrentFrame2 -= 3; sprite.setTextureRect(IntRect(97 * int(CurrentFrame2), 5, 93, 90));   break; //идем вниз
		case 3: dx = 0; dy = -speed; CurrentFrame2 += 0.005*Time; //проходит по кадрам персонажа, она доходит до 4 кадров 
			if (CurrentFrame2 > 3) CurrentFrame2 -= 3; sprite.setTextureRect(IntRect(97 * int(CurrentFrame2), 305, 93, 83));   break; //идем вверх
	}

	if (Level == 1)
	{
		interactionWithMap1(dx, 0, time); //взаимодействие с картой по горизонтали
	} else if (Level == 2)
	{
		interactionWithMap2(dx, 0, time); //взаимодействие с картой по горизонтали
	} else if (Level == 3)
	{
		interactionWithMap3(dx, 0, time); //взаимодействие с картой по горизонтали
	} else if (Level == 4)
	{
		interactionWithMap4(dx, 0, time); //взаимодействие с картой по горизонтали
	}

	x += dx*time;
	y += dy*time; 
 
	sprite.setPosition(x,y); //задается позиция


}

bool Cat::checkCollisionWithDog(float X, float Y)
{
	float X2 = abs(X - x);
	float Y2 = abs(Y- y);
	if ((X2 <= 45) && (Y2 <= 45)) {
		return true;
	} else {
		return false;
	}
}

void Cat::interactionWithMap1(float Dx, float Dy, float time)
{
	for (int i = y / 56; i < (y + h) / 56; i++) 
	{
		for (int j = x / 56; j < (x + w) / 56; j++)
		{
			if ((TileMap1[i][j] == '0') || (TileMap1[i][j] == 'z') || (TileMap1[i][j] == 'd')) 
			{
				if (Dx > 0)
				{ 
					x = j * 56 - w; 
					dx = -0.1; 
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 104, 93, 90));
				}
				if (Dx < 0)
				{ 
					x = j * 56 + 56; 
					dx = 0.1;
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 204, 93, 90));	 
				}// с левым краем 
			}
		}
	}
}

void Cat::interactionWithMap2(float Dx, float Dy, float time)
{
	for (int i = y / 56; i < (y + h) / 56; i++) 
	{
		for (int j = x / 56; j < (x + w) / 56; j++)
		{
			if ((TileMap2[i][j] == '0') || (TileMap2[i][j] == 'z') || (TileMap2[i][j] == 'd')) 
			{ 
				if (Dx > 0)
				{ 
					x = j * 56 - w; 
					dx = -0.1; 
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 104, 93, 90));
				}
				if (Dx < 0)
				{ 
					x = j * 56 + 56; 
					dx = 0.1;
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 204, 93, 90));	 
				}// с левым краем 
			}
		}
	}
}

void Cat::interactionWithMap3(float Dx, float Dy, float time)
{
	for (int i = y / 56; i < (y + h) / 56; i++) 
	{
		for (int j = x / 56; j < (x + w) / 56; j++)
		{
			if ((TileMap3[i][j] == '0') || (TileMap3[i][j] == 'z') || (TileMap3[i][j] == 'd')) 
			{
				if (Dx > 0)
				{ 
					x = j * 56 - w; 
					dx = -0.1; 
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 104, 93, 90));
				}
				if (Dx < 0)
				{ 
					x = j * 56 + 56; 
					dx = 0.1;
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 204, 93, 90));	 
				}// с левым краем 
			}
		}
	}
}

void Cat::interactionWithMap4(float Dx, float Dy, float time)
{
	for (int i = y / 56; i < (y + h) / 56; i++) 
	{
		for (int j = x / 56; j < (x + w) / 56; j++)
		{
			if ((TileMap4[i][j] == '0') || (TileMap4[i][j] == 'z') || (TileMap4[i][j] == 'd')) 
			{
				if (Dx > 0)
				{ 
					x = j * 56 - w; 
					dx = -0.1; 
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 104, 93, 90));
				}
				if (Dx < 0)
				{ 
					x = j * 56 + 56; 
					dx = 0.1;
					sprite.setTextureRect(IntRect(93 * int(CurrentFrame2), 204, 93, 90));	 
				}// с левым краем 
			}
		}
	}
}

Bullet::Bullet(int lvl, String Name, String F, float X, float Y, int W, int H, int dir) :All(F,X, Y, W, H)
{
	Level = lvl;
	name = Name;
	direction = dir;
	dx = 0.1;
	speed = 0.6;
	life = true;
	sprite.setTextureRect(IntRect(610, 610, w, h));  
}

void Bullet::update(float time, Event event, int lvl, Sound shoot, float Time)
{
	switch (direction)
	{
		case 0: dx = speed; dy = 0;   break;//интовое значение state = left
		case 1: dx = -speed; dy = 0;   break;//right
		case 2: dx = 0; dy = speed;   break;// up
		case 3: dx = 0; dy = -speed; break;  // 
	}
		
	x += dx*time;//само движение пули по х
	y += dy*time;//по у
 
	if (x <= 0) 
	{
		x = 1;
	}// задержка пули в левой стене чтобы  она случайно не вылетела за предел карты и не было ошибки
	
	if (y <= 0) 
	{
		y = 1;
	}
	if (lvl == 1) 
	{
		interactionWithMap1();
	} else if (lvl == 2)
	{
		interactionWithMap2();
	} else if (lvl == 3)
	{
		interactionWithMap3();
	} else if (lvl == 4)
	{
		interactionWithMap4();
	}
	sprite.setPosition(x, y);
}

void Bullet::interactionWithMap1()
{
		for (int i = y / 56; i < (y + h) /56; i++) 
	{
		for (int j = x / 56; j< (x + w) / 56; j++)
		{
			if ((TileMap1[i][j] == '0') || (TileMap1[i][j] == 's') || (TileMap1[i][j] == 'a') || (TileMap1[i][j] == 'z')  || (TileMap1[i][j] == 'c')  || (TileMap1[i][j] == 'd')) //если этот объект столкнулся с пулей,
			{
				life = false;// то пуля умирает
				if ((TileMap1[i][j] == 's')) {
					life = false;
					TileMap1[i][j] = 'a';
				}
			}
		}
	}
}

void Bullet::interactionWithMap2()
{
		for (int i = y / 56; i < (y + h) /56; i++) 
	{
		for (int j = x / 56; j< (x + w) / 56; j++)
		{
			if ((TileMap2[i][j] == '0') || (TileMap2[i][j] == 's') || (TileMap2[i][j] == 'a') || (TileMap2[i][j] == 'z')  || (TileMap2[i][j] == 'c')  || (TileMap2[i][j] == 'd')) //если этот объект столкнулся с пулей,
			{
				life = false;// то пуля умирает
				if ((TileMap2[i][j] == 's')) {
					life = false;
					TileMap2[i][j] = 'a';
				}
			}
		}
	}
}

void Bullet::interactionWithMap3()
{
	for (int i = y / 56; i < (y + h) /56; i++) 
	{
		for (int j = x / 56; j< (x + w) / 56; j++)
		{
			if ((TileMap3[i][j] == '0') || (TileMap3[i][j] == 's') || (TileMap3[i][j] == 'a') || (TileMap3[i][j] == 'z')  || (TileMap3[i][j] == 'c')  || (TileMap3[i][j] == 'd')) //если этот объект столкнулся с пулей,
			{
				life = false;// то пуля умирает
				if ((TileMap3[i][j] == 's')) {
					life = false;
					TileMap3[i][j] = 'a';
				}
			}
		}
	}
}

void Bullet::interactionWithMap4()
{
		for (int i = y / 56; i < (y + h) /56; i++) 
	{
		for (int j = x / 56; j< (x + w) / 56; j++)
		{
			if ((TileMap4[i][j] == '0') || (TileMap4[i][j] == 's') || (TileMap4[i][j] == 'a') || (TileMap4[i][j] == 'z')  || (TileMap4[i][j] == 'c')  || (TileMap4[i][j] == 'd')) //если этот объект столкнулся с пулей,
			{
				life = false;// то пуля умирает
				if ((TileMap4[i][j] == 's')) {
					life = false;
					TileMap4[i][j] = 'a';
				}
			}
		}
	}
}
