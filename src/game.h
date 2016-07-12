#ifndef GAME_H
#define GAME_H

#include <map>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "sfml.h"
#include <glm/vec2.hpp>
#include <glm/geometric.hpp>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "fns.h"
#include "screen.h"

const int GAME_WIDTH = 400;
const int GAME_HEIGHT = 300;

class Game {
    const int FPS = 30;
	

  public:
    static Screen* current_screen;
    Game(int, int);
    ~Game();
   sf::RenderWindow window;
    static sf::RenderWindow* cur_window;
    void loop();

 private:
	void loadScreens(string);
	std::vector<Screen*> screens;
};

#endif
