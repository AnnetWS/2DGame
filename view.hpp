#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
 
sf::View view;//объявили sfml объект "вид", который и является камерой
 
void getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края
 
	if (x < 500) tempX = 500;//убираем из вида левую сторону
	if (x > 1457) tempX = 1457;
	if (y < 400) tempY = 400;//верхнюю сторону
	if (y > 1000) tempY = 1000;//нижнюю сторону	
 
	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
}
