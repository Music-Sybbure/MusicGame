#ifndef OBJECT_H
#define OBJECT_H

#include <cmath>
#include <stdio.h>
#include "fns.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <map>
#include "sfml.h"
#include <iostream>

using namespace std;

class Object {
  public:
    sf::Texture texture;
    sf::Sprite picture;

    sf::Vector2i windowPos(sf::RenderTarget&);

    std::string name;
    bool focused;
	int x, y;

    virtual void render(sf::RenderWindow&);
    virtual int update(double dt);

    Object(xmlNode*);
	~Object();
	map<string, string> mapper;
};

/* sf::Vector2i wpos(sf::RenderTarget& window, float x, float y); */
/* sf::Vector2f wpos(sf::RenderTarget& window, sf::Vector2f v); */

/* sf::Vector2f gpos(sf::RenderTarget& window, int x, int y); */


#endif
