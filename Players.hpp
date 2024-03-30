#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

 
using namespace sf;
using namespace std; 

class Bullet;
class All {
public:
	//vector<Bullet> obj;
	bool life;
	float x, y, w, h; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт

	All(String F, float X, float Y, float W, float H);

	virtual void update(float time, Event event, int lvl, Sound shoot, float Time) = 0;
};

class Cat : public All { //класс кота
public:
	float dx, dy, speed;
	float X1, Y1;
	int dir;
	int Level;
	float CurrentFrame2;

	Cat(String F, float X, float Y, float W, float H, int lvl);  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту

	void update(float time, Event event, int lvl, Sound shoot, float Time); //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.

    void interactionWithMap1(float Dx, float Dy, float time);

	void interactionWithMap2(float Dx, float Dy, float time);

	void interactionWithMap3(float Dx, float Dy, float time);

	void interactionWithMap4(float Dx, float Dy, float time);

	bool checkCollisionWithDog(float X, float Y);

	void move(Vector2f& direct, float Dx, float Dy, float time, float X, float Y, bool stop, float Time);

	float getplayercoordinateX();

	float getplayercoordinateY();

	void StartPosition(float time);
};
 

class Dog : public All { // класс собаки
public:
	//enum { left, right, up, down } state;
	int state;
	bool Stop;
	bool isShoot;
	int Count;
	int Level;
	int dir;
	vector <int> Bone;
	int BoneCount;
	float dx, dy, speed;
	Dog(String F, float X, float Y, float W, float H, int lvl);  

	void update(float time, Event event, int lvl, Sound shoot, float Time); //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.

	void interactionWithMap1(Event event);

	void interactionWithMap2(Event event);

	void interactionWithMap3(Event event);

	void interactionWithMap4(Event event);

	bool CheckCPassedLevel1();

	bool CheckCPassedLevel2();

	bool CheckCPassedLevel3();

	bool CheckCPassedLevel4();

	float getplayercoordinateX();	//этим методом будем забирать координату Х	

	float getplayercoordinateY();	//этим методом будем забирать координату Y 	

	void drawMap1(RenderWindow &window, Sprite s_map);

	void drawMap2(RenderWindow &window, Sprite s_map);

	void drawMap3(RenderWindow &window, Sprite s_map);

	void drawMap4(RenderWindow &window, Sprite s_map);

	int LevelSizeKost(int Level);
};

class Bullet : public All{//класс пули
public:
	vector<Bullet> obj;
	String name;
	int Level;
	int direction; 
	float speed, dx, dy;
	bool life;

	Bullet(int lvl, String Name, String F, float X, float Y, int W, int H, int dir);

	void update(float time, Event event, int lvl, Sound shoot, float Time);

	void interactionWithMap1();

	void interactionWithMap2();

	void interactionWithMap3();

	void interactionWithMap4();
	
};