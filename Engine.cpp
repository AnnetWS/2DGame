#include "Engine.hpp"
#include <iostream>
#include "view.hpp"
#include "Players.hpp"
#include <sstream>
#include <cmath>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace sf;
using namespace std;

Engine::Engine()
{
    RenderWindow window(VideoMode(800,800), L"Моoooooooя игра", Style::Default); 
}

void Engine::run()
{
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), L"Dog's Adventures", Style::Fullscreen);
    GameMenu(window);  
    
}

void Engine::GameMenu(RenderWindow &window)
{
    musicFon.openFromFile("audio/fon.wav");//загружаем файл
    musicFon.play();
    musicFon.setLoop(true);

    // размер экрана
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    // фон
    RectangleShape background(Vector2f(width, height));

    Texture texture_window;
    texture_window.loadFromFile("image/photo1700648276.jpeg");
    background.setTexture(&texture_window);

    // шрифт экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf"));
    // текст сверху
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 120, 50, L"Dog's Adventures", 150, Color(237, 147, 0), 3);

    //названия пунктов меню
    vector<String> name_menu{L"Играть", L"Выход", L"Об игре"};
     // обЪект меню
    game::GameMenu mymenu(window, 725, 245, 100, 145,name_menu);
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black); // цвет меню
    mymenu.AlignMenu(2); // чтобы пункты по центру были 

    while (window.isOpen()) 
    {
        if (Keyboard::isKeyPressed(Keyboard::W)) 
	    { 
            if (musicFon.getStatus() == sf::SoundSource::Status::Playing) 
            {
                musicFon.stop();
            }
            else if (musicFon.getStatus() == sf::SoundSource::Status::Stopped)
            {
                musicFon.play();
            }
        }

        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::KeyReleased)
            {
                // события выбора пункта меню
                if (event.key.code == Keyboard::Up) 
                { 
                    mymenu.MoveUp();  // вверх
                } 

                if (event.key.code == Keyboard::Down) 
                { 
                    mymenu.MoveDown(); // вниз
                } 
                
                if (event.key.code == Keyboard::Return)                                    
                { 
                    // переход на пункт
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:GameStart(window);  break;
                    case 1:window.close(); GameMenu(window); break;
                    case 2:Info(); break;
                    }
                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();  
    }
}

// настройка текста
void Engine::InitText(Text& mtext, float xpos, float ypos, String str, int size_font, Color menu_text_color, int bord, Color border_color)
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);
}


void Engine::GameStart(RenderWindow &window) 
{

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    RectangleShape background(Vector2f(width, height));

    Texture texture_window;
    if (!texture_window.loadFromFile("image/level.jpeg"));
    background.setTexture(&texture_window);
	
    // Шрифт для названия экрана
    Font font;
    font.loadFromFile("font/troika.otf");
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 525, 100, L"Уровни", 100, Color(220, 130, 0), 3);

    // пункты меню
    vector <String> name_menu{L"Уровень 1", L"Уровень 2", L"Уровень 3", L"Уровень 4", L"Выход"};
    game::GameMenu mymenu(window, 700, 270, 50, 80,name_menu);
    mymenu.setColorTextMenu(Color(220, 130, 0), Color::Red, Color::Black);
    mymenu.AlignMenu(2); 

    while (window.isOpen()) 
    {
        if (Keyboard::isKeyPressed(Keyboard::W)) 
		{ 
            if (musicFon.getStatus() == sf::SoundSource::Status::Playing) 
            {
                musicFon.stop();
            }
            else if (musicFon.getStatus() == sf::SoundSource::Status::Stopped)
            {
                musicFon.play();
            }
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up) 
                { 
                    mymenu.MoveUp(); 
                }  

                if (event.key.code == Keyboard::Down) 
                { 
                    mymenu.MoveDown(); 
                }  

                if (event.key.code == Keyboard::Return)                                   
                { 
                    // переход на пункт меню
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:level(window, 1, 1.4f); break;
                    case 1:level(window, 2, 1.5f); break;
                    case 2:level(window, 3, 1.5f); break;
                    case 3:level(window, 4, 1.7f); break;
                    case 4:GameMenu(window); break;
                    }
                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();  
    }
}

// функция "об игре"
void Engine::Info()
{
    RenderWindow About(VideoMode(1200,700), L"History", Style::Default);
    RectangleShape background_ab(Vector2f(1200, 700));
    Texture texture_ab;
    texture_ab.loadFromFile("image/history.jpeg");
    background_ab.setTexture(&texture_ab);

    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) 
            {
                About.close();
            }

            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) About.close();
            }
        }
        About.clear();
        About.draw(background_ab);
        About.display();
    }
}

void Engine::level(RenderWindow &windowLevel, int lvl, float timer) 
{

    int level = lvl; // передали уровень
    view.reset(sf::FloatRect(0, 0, 1000, 800)); //размер камеры вида  

    int xCat;
    int yCat;

    if (level == 1) {
        xCat = 200; yCat = 360;
    } else if (level == 2)
    {
        xCat = 200; yCat = 360;
    } else if (level == 3)
    {
        xCat = 750; yCat = 380;
    } else if (level == 4)
    {
        xCat = 200; yCat = 320;
    }

	Dog dog("dog2.png",120,120,90.0, 90.0, level); // объект игрока
    Cat cat("cat2.png", xCat, yCat, 93.0,90.0, level); //объект врага

    Font font; //шрифт для вывода количества собранных косточек
	font.loadFromFile("font/troika.otf");
	Text text("", font, 20); //строка, шрифт, размер 
	text.setStyle(Text::Bold); //жирный текст.

    //карта
    Image map_image;
	if(!(map_image.loadFromFile("image/map.jpeg"))) {
        cout << "failed" << endl;
    }
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map; //спрайт для карты
	s_map.setTexture(map);

    Font font2; // аналогично сверху только для вывода таймера
	font2.loadFromFile("font/troika.otf");
    Text timerText("", font2, 20); 
	timerText.setStyle(Text::Bold);

    SoundBuffer shootBuffer;//создаём буфер для звука
    shootBuffer.loadFromFile("audio/shoot.ogg");
    Sound shoot;
    shoot.setBuffer(shootBuffer);//создаем звук и загружаем в него звук из буфера 
    //shoot.setLoop(true); //постоянное воспроизведение зацикливание
	
    Music musicP;//создаем объект музыки
    musicP.openFromFile("audio/pogonya.wav");//загружаем файл

    float CurrentFrame = 0; //хранит текущий кадр
    Clock clock;
    
    Clock clock2;
    Time gameTime = seconds(timer);
    int minutes = 0;
    int seconds = 0;

    list<Bullet*>  B;//создаю список, сюда буду кидать объекты.например врагов.
	list<Bullet*>::iterator it;

 	while (windowLevel.isOpen())
	{
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры
         	
		Event event;
		while (windowLevel.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {	
			    windowLevel.close();
            }
		}

        if (Keyboard::isKeyPressed(Keyboard::W)) 
		{ 
            if (musicFon.getStatus() == sf::SoundSource::Status::Playing) 
            {
                musicFon.stop();
            }
            else if (musicFon.getStatus() == sf::SoundSource::Status::Stopped)
            {
                musicFon.play();
            }
        }

        // обновление таймера
        Time elapsedTime = clock.restart();
        gameTime -= elapsedTime;

        // завершаем игру, если кончился таймер
        if (gameTime <= Time::Zero)
        {
            LevelFailed(windowLevel, level, timer);
        }  

        //стрельба
        if (Keyboard::isKeyPressed(Keyboard::S)) 
		{
			shoot.play(); 
            int SizeDo = B.size();
            B.push_back(new Bullet(level,"Bullet","bullet.png", dog.getplayercoordinateX() + 30, dog.getplayercoordinateY() + 30, 6, 6, dog.state));
            int SizeAfter = B.size();
            if ((SizeAfter - SizeDo) == 1) {
                continue;
            }
        }
        for (it = B.begin(); it != B.end();)//говорим что проходимся от начала до конца
		{
			Bullet *b = *it;//для удобства, чтобы не писать (*it)
			b->update(time, event, level, shoot, time);//вызываем ф-цию update для всех объектов (по сути для тех, кто жив)
            if (b->life == false)	{ it = B.erase(it); delete b; }// если этот объект мертв, то удаляем его
			else it++;//и идем курсором (итератором) к след объекту. так делаем со всеми объектами списка
		}

        //windowLevel1.draw(Bull.sprite);
        if (Keyboard::isKeyPressed(Keyboard::Left))
        { //если нажата клавиша влево
        dog.Stop = false;
            dog.dir = 1; dog.speed = 0.1;
            dog.state = 1;
            CurrentFrame += 0.005*time; //проходит по кадрам персонажа, она доходит до 4 кадров 
			if (CurrentFrame > 4) CurrentFrame -= 4; // 4 кадр - то в начало
			dog.sprite.setTextureRect(IntRect(85 * int(CurrentFrame), 255, 70, 80)); 
        dog.Stop = true;
		}

        if (Keyboard::isKeyPressed(Keyboard::Right)) //дальше аналогично
        {
            dog.Stop = false;
			dog.dir = 0; dog.speed = 0.1;
            dog.state = 0;
            CurrentFrame += 0.005*time; 
			if (CurrentFrame > 4) CurrentFrame -= 4; 
			dog.sprite.setTextureRect(IntRect(85 * int(CurrentFrame), 95, 74, 80)); 
            dog.Stop = true;
        }
			
			
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
        {
        dog.Stop = false;
			dog.dir = 3; dog.speed = 0.1;
            dog.state = 3;
            CurrentFrame += 0.005*time; 
			if (CurrentFrame > 4) CurrentFrame -= 4; 
			dog.sprite.setTextureRect(IntRect(85 * int(CurrentFrame), 170, 60, 75)); 
            dog.Stop = true;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Down)) 
        {
            dog.Stop = false;
			dog.dir = 2; dog.speed = 0.1;
            dog.state = 2;
            CurrentFrame += 0.005*time; 
			if (CurrentFrame > 4) CurrentFrame -= 4; 
			dog.sprite.setTextureRect(IntRect(85 * int(CurrentFrame), 0, 70, 80)); 
            dog.Stop = true;
        }

        if (Keyboard::isKeyPressed(Keyboard::Q)) 
        {
            musicP.stop();
            Exit(windowLevel);
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) 
        {
            windowLevel.close();
            RenderWindow windowLevel2;
            windowLevel2.create(VideoMode::getDesktopMode(), L"Dog's Adventures", Style::Fullscreen);
            GameStart(windowLevel2);
        }

        getplayercoordinateforview(dog.getplayercoordinateX(), dog.getplayercoordinateY()); //координаты игрока в функцию управления камерой
 
        // видимость
        Vector2f DogPos(dog.getplayercoordinateX(),dog.getplayercoordinateY());
        Vector2f CatPos(cat.getplayercoordinateX(),cat.getplayercoordinateY());

        float distance = sqrt(pow(DogPos.x - CatPos.x,2) + pow(DogPos.y - CatPos.y,2));
        if (distance <= 150.0f) {
            Vector2f direction = DogPos - CatPos;
            float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
            Vector2f normalizedDir = direction / length;

            // Движение врага к игроку
            cat.move(normalizedDir, dog.dx, dog.dy, time, dog.x, dog.y, dog.Stop, time);
            if (cat.checkCollisionWithDog(dog.x, dog.y)) {
                musicP.stop();
                LevelFailed(windowLevel, level, timer);
            }

        } else {
            musicP.play();//воспроизводим музыку
            cat.update(time, event, level, shoot, time);
        }
        if (level == 1) {
            if (dog.CheckCPassedLevel1())
            {
                LevelPassed(windowLevel);
            }
        } else if (level == 2)
        {
            if (dog.CheckCPassedLevel2())
            {
                LevelPassed(windowLevel);
            }
        } else if (level == 3)
        {
            if (dog.CheckCPassedLevel3())
            {
                LevelPassed(windowLevel);
            }
        } else if (level == 4)
        {
            if (dog.CheckCPassedLevel4())
            {
                LevelPassed(windowLevel);
            }
        }

        dog.update(time,event, level, shoot, time); //оживляем объект класса с помощью времени - персонаж может двигаться

		windowLevel.setView(view); //камера в окне sfml

		windowLevel.clear(); 

        if (level == 1) 
        {
            dog.drawMap1(windowLevel, s_map);
        } else if (level == 2)
        {
            dog.drawMap2(windowLevel, s_map);
        } else if (level == 3)
        {
            dog.drawMap3(windowLevel, s_map);
        } else if (level == 4)
        {
            dog.drawMap4(windowLevel, s_map);
        }

        ostringstream KamenCountString;   
		KamenCountString << dog.BoneCount;	
		text.setString("BoneCount:" + KamenCountString.str()); // получаем строчку 
		text.setPosition(view.getCenter().x - 500, view.getCenter().y - 400);//задаем позицию текста от центра камеры
		windowLevel.draw(text);


        std::string timerString = std::to_string(gameTime.asMicroseconds()).substr(0, 3);
        // вывод таймера на экран
        //timerText.setString("Timer: " + std::to_string(gameTime.asSeconds()) + "s");
        timerText.setString("Timer: " + timerString + " Seconds");
        timerText.setPosition(view.getCenter().x - 300, view.getCenter().y - 400);

        windowLevel.draw(timerText); // все отрисовываем
        windowLevel.draw(cat.sprite);

        //windowLevel1.draw(Bull.sprite);
        for (it = B.begin(); it != B.end(); it++){
			windowLevel.draw((*it)->sprite); 
		}

		windowLevel.draw(dog.sprite);
		windowLevel.display();
	}
}

void Engine::LevelPassed(RenderWindow &windowPassed2) 
{
    windowPassed2.close();
    RenderWindow windowPassed;
    windowPassed.create(VideoMode::getDesktopMode(), L"Dog's Adventures", Style::Fullscreen);

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    RectangleShape background_ab(Vector2f(width, height));
	Texture texture_ab;
	texture_ab.loadFromFile("image/passed.jpeg");
	background_ab.setTexture(&texture_ab);

	// шрифт экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf"));
    // текст сверху
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 100, 50, L"Уровень пройден!", 100, Color(237, 147, 0), 3);

    //названия пунктов меню
    vector<String> name_menu{L"Пройти заново", L"Уровни"};
     // обЪект меню
    game::GameMenu mymenu(windowPassed, 930, 560, 70, 100, name_menu);
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black); // цвет меню
    mymenu.AlignMenu(2); // чтобы пункты по центру были 

	while (windowPassed.isOpen())
	{
		Event event;
		while (windowPassed.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				windowPassed.close();
			} 
				
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape) 
				{
					windowPassed.close();
				}
			}
			if (event.type == Event::KeyReleased)
        	{
                // события выбора пункта меню
                if (event.key.code == Keyboard::Up) 
                { 
                    mymenu.MoveUp();  // вверх
                } 

                if (event.key.code == Keyboard::Down) 
                { 
                    mymenu.MoveDown(); // вниз
                } 
                
                if (event.key.code == Keyboard::Return)                                    
                { 
                    // переход на пункт
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:windowPassed.close();  break;
                    case 1:GameStart(windowPassed);  break;
                    }
                }
            }
		}
		windowPassed.clear();
        windowPassed.draw(background_ab);
        windowPassed.draw(Titul);
        mymenu.draw();
		windowPassed.display();
	}
}

void Engine::LevelFailed(RenderWindow &windowFailed2, int lvl, float timer) 
{
    windowFailed2.close();
    RenderWindow windowFailed;
    windowFailed.create(VideoMode::getDesktopMode(), L"Dog's Adventures", Style::Fullscreen);

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    RectangleShape background_ab(Vector2f(width, height));
	Texture texture_ab;
	texture_ab.loadFromFile("image/failed.jpeg");
	background_ab.setTexture(&texture_ab);

	// шрифт экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf"));
    // текст сверху
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 240, 50, L"Уровень не пройден!", 100, Color(237, 147, 0), 3);

    //названия пунктов меню
    vector<String> name_menu{L"Пройти заново", L"Уровни"};
     // обЪект меню
    game::GameMenu mymenu(windowFailed, 730, 190, 60, 100, name_menu);
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black); // цвет меню
    mymenu.AlignMenu(2); // чтобы пункты по центру были 

	while (windowFailed.isOpen())
	{
		Event event_play;
		while (windowFailed.pollEvent(event_play))
		{
			if (event_play.type == Event::Closed)
			{
				windowFailed.close();
			} 
				
			if (event_play.type == Event::KeyPressed)
			{
				if (event_play.key.code == Keyboard::Escape) 
				{
					windowFailed.close();
				}
			}
			if (event_play.type == Event::KeyReleased)
        	{
                // события выбора пункта меню
                if (event_play.key.code == Keyboard::Up) 
                { 
                    mymenu.MoveUp();  // вверх
                } 

                if (event_play.key.code == Keyboard::Down) 
                { 
                    mymenu.MoveDown(); // вниз
                } 
                
                if (event_play.key.code == Keyboard::Return)                                    
                { 
                    // переход на пункт
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:level(windowFailed, lvl, timer);  break;
                    case 1:GameStart(windowFailed);  break;
                    }
                }
            }
		}
		windowFailed.clear();
        windowFailed.draw(background_ab);
        windowFailed.draw(Titul);
        mymenu.draw();
		windowFailed.display();
	}
}

void Engine::Exit(RenderWindow &window2)
{
    RenderWindow window3;
    window3.create(VideoMode::getDesktopMode(), L"Dog's Adventures", Style::Default);

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    RectangleShape background_ab(Vector2f(width, height));
	Texture texture_ab;
	texture_ab.loadFromFile("image/level.jpeg");
	background_ab.setTexture(&texture_ab);

	// шрифт экрана
    Font font;
    if (!font.loadFromFile("font/troika.otf"));
    // текст сверху
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 490, 120, L"Хотите выйти?", 60, Color(237, 147, 0), 3);

    //названия пунктов меню
    vector<String> name_menu{L"Да", L"Нет"};
     // обЪект меню
    game::GameMenu mymenu(window3, 715, 290, 60, 105, name_menu);
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black); // цвет меню
    mymenu.AlignMenu(2); // чтобы пункты по центру были 

	while (window3.isOpen())
	{
		Event event_play;
		while (window3.pollEvent(event_play))
		{
			if (event_play.type == Event::Closed)
			{
				window3.close();
			} 
				
			if (event_play.type == Event::KeyPressed)
			{
				if (event_play.key.code == Keyboard::Escape) 
				{
					window3.close();
				}
			}
			if (event_play.type == Event::KeyReleased)
        	{
                // события выбора пункта меню
                if (event_play.key.code == Keyboard::Up) 
                { 
                    mymenu.MoveUp();  // вверх
                } 

                if (event_play.key.code == Keyboard::Down) 
                { 
                    mymenu.MoveDown(); // вниз
                } 
                
                if (event_play.key.code == Keyboard::Return)                                    
                {   
                    // переход на пункт
                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:window2.close();
                        windowLevel3.create(VideoMode::getDesktopMode(), L"Dog's Adventures", Style::Fullscreen);
                        window3.close();
                        GameStart(windowLevel3); break;
                    case 1:window3.close();  break;
                    }
                }
            }
		}
		window3.clear();
        window3.draw(background_ab);
        window3.draw(Titul);
        mymenu.draw();
		window3.display();
	}
}
