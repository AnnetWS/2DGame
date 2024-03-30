#include <SFML/Graphics.hpp>
//#include "GameMenu.hpp"
//#include "Dog.hpp"
#include "Engine.hpp"
//#include "map1.hpp"
 

using namespace sf;
using namespace std;

int main() {

    auto game = make_unique<Engine>();
    game->run();

    return 0;
};

