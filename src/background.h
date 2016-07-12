#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "object.h"
#include <map>
#include "fns.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "sfml.h"
#include <sstream>


class Background : public Object {
 public:
  Background(xmlNode*);
  ~Background();
void render(sf::RenderWindow&);
  string filename;
  int r,g,b;
  bool color;
};

   
#endif
