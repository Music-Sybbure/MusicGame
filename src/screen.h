#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "sfml.h"
#include <glm/vec2.hpp>
#include <glm/geometric.hpp>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "fns.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "object.h"

using namespace std;

#define keydown(key) sf::Keyboard::isKeyPressed(sf::Keyboard::key)

class Screen {
  public:
    void render(sf::RenderWindow&);
	sf::Sprite bg;
    int update(double);

    Screen(xmlNode*);
	//	Screen(&Screen);
	~Screen();
 private:
	vector<Object*> objects;
};

#endif
