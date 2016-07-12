#include "game.h"
using namespace std;

Screen* Game::current_screen;
sf::RenderWindow* Game::cur_window;

Game::Game(int w, int h): window(sf::VideoMode(w, h), "game", sf::Style::Fullscreen & 0), screens(10) {
  cout << "start" << endl;

  loadScreens("file.xml");
  cout << "xml loaded" << endl;
  current_screen = screens.at(1);
  cur_window = &window;
  srand(time(NULL));
  dbpf("game init finished.\n");
}

Game::~Game() {
}


void Game::loadScreens(string filename) {
  xmlDoc *doc = NULL;
  xmlNode *root_element = NULL;

  if ((doc = xmlReadFile(filename.c_str(), NULL, 0)) == NULL){
	cout << "error: could not parse file " << filename << endl;
    exit(-1);
  }

  root_element = xmlDocGetRootElement(doc);
  xmlNode* cur_node = NULL;
  for(cur_node = root_element; cur_node; cur_node = cur_node->next) {
	if(cur_node->type == XML_ELEMENT_NODE) {
	  stringstream s;
	  s << cur_node->name;
	  if(s.str() =="Screen") {

		int id;
		s.str(std::string());
		s << xmlGetProp(cur_node, (const xmlChar*) "id");
		s >> id;
		cout << "screen: " << id << endl;
		screens[id] = new Screen(cur_node->children);
		cout << "finished screen" << endl;
		break;

		
	  }
	}
  }

  xmlFreeDoc(doc);   
  xmlCleanupParser();
  
}



void Game::loop() {
    // in this loop we handle input, process events, draw all things, update
    // the window, and wait until the next frame
    int dts = 0;
    double dttot = 0.0;
    
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;

    sf::View view(sf::FloatRect(0.0f, 0.0f, GAME_WIDTH, GAME_HEIGHT));
    window.setView(view);
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
                dbpf("Received exit signal\n");
            }
        }

        double dt = clock.getElapsedTime().asSeconds();
		
		int status = current_screen->update(dt);
		//		if(status < 10 || status > 0) current_screen = screens.at(status);
		
        window.clear();
        current_screen->render(window);
        window.setView(view);
        window.display();
        dts++;
        dttot += dt;
        clock.restart();
        sf::sleep(sf::seconds(1.0 / FPS - dt));
    }
    dbpf("avg dt: %.6f\n", dttot / dts);
    dbpf("total updates: %d\n", dts);
}
