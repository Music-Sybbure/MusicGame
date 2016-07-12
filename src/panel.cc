#include "panel.h"
#include <iostream>

using namespace std;

Panel::Panel(xmlNode* node) : Object(node) {
  if(mapper["color"] != "") {
	istringstream s(mapper["color"]);
  	s >> r;
  	s >> g;
  	s >> b;
	cout << r << " " << g << " " << b << endl;
  	color = true;
  } else if(mapper["picture"] != "") {
  	texture.loadFromFile(mapper["picture"]);

  	picture.setPosition(x, y);
  	color = false;
  }

}

void Panel::render(sf::RenderWindow& window) {
  if(color) window.clear(sf::Color(r,g,b,255));
  else window.draw(picture);
}

Panel::~Panel() {
  cout << "panel" << endl;
}
