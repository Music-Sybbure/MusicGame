#ifndef _PANEL_H_
#define _PANEL_H_

#include "object.h"
#include <map>
#include "fns.h"
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "sfml.h"
#include <sstream>


class Panel : public Object {
 public:
  Panel(xmlNode*);
  ~Panel();
void render(sf::RenderWindow&);
  string filename;
  int w,h, x,y;
  bool color;
};

   
#endif
