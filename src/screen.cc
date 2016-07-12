#include "screen.h"
#include "background.h"

const int GAME_WIDTH = 1024;
const int GAME_HEIGHT = 768;


void Screen::render(sf::RenderWindow& window) {
    //objects look like they are in front of others
    //may have to change if we add too many objects


    // MAY CAUSE SEIZURES

    auto ws = window.getSize();
	for(Object* obj : objects) {
	  obj->render(window);
	}
    //     auto mpos = sf::Mouse::getPosition(window);
    //     auto fr = gobj->sprite.getGlobalBounds();
    //     auto gmpos = gpos(window, mpos.x, mpos.y);
    //     if (fr.contains(gmpos)) {
    //         focused = gobj;
    //     }
    // }
    // if (focused != nullptr) {
    //     focused->focused = true;
    // }
  
	//    bg.render(window);
    // for (GameObject* gobj : gobjs) {
    //     gobj->render(window);
    // }
}

int Screen::update(double dt) {
  return -1;
}

Screen::~Screen() {
  cout << "screen gone" << endl;
}

Screen::Screen(xmlNode* node) {
  xmlNode* cur_node = NULL;
  for(cur_node = node; cur_node; cur_node = cur_node->next) {
	if(cur_node->type == XML_ELEMENT_NODE) {
	  stringstream s;
	  s << cur_node->name;
	  if(s.str() == "Background") {
		cout << "found background" << endl;
		objects.push_back(new Background(cur_node->children));
	  } else if(s.str() == "Picture") {
		cout << "picture" << endl;
	  } else if(s.str() == "Text") {
		cout << "text" << endl;
	  } else if(s.str() == "Button") {
		cout << "button" << endl;
	  } else {
		cout << "idk" << endl;
	  }
	  // if(s.str() =="Screen") {
	  // 	int id;
	  // 	s.str(std::string());
	  // 	s << xmlGetProp(cur_node, (const xmlChar*) "id");
	  // 	s >> id;
	  // 	screens[id] = new Screen(cur_node->children);
	  // }
	}
  }
  cur_node = NULL;
  //  rt.create(GAME_WIDTH, GAME_HEIGHT);

}

//Screen::Screen(&Screen rhs) {
  
  
