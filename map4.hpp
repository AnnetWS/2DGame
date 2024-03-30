#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const int HEIGHT_MAP4 = 25;//размер карты высота
const int WIDTH_MAP4 = 35;//размер карты ширина 
sf::String TileMap4[HEIGHT_MAP4] = {
"00000000000000000000000000000000000",
"0     d                           0",
"0     d s       dddd        s     0",
"0     d                           0",
"0                                 0",
"0                                 0",
"0dddddddd                         0",
"0                                 0",
"0s                                0",
"0                                 0",
"0zzzzzzz             d        zzzz0",
"0zcccccz             d           s0",
"0zcccccz             d            0",
"0zzzzzzz             d         zzz0",
"0                    d            0",
"0                                 0",
"0                                 0",
"0   ddddddd                s      0",
"0   d                             0",
"0   d                             0",
"0   d          dddd      ddddddddd0",
"0   d      d                      0",
"0   d      d                  qwt 0",
"0 s d   s  d                  ery 0",
"00000000000000000000000000000000000",
};