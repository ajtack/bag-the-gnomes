#include "bag_the_gnome.hxx"
#include "game.hxx"
#include "map.hxx"
#include "map_reader.hxx"

#include <allegro.h>
#include <fstream>
#include <string>
#include <sstream>


int main()
{
	allegro_init();
	install_keyboard();
	
	
	
	// Prepare the Screen
	set_color_depth(24);
	int ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (ret != 0)	{
		allegro_message(allegro_error);
		return 1;
	}
	// Ready the map
	Map* map = map_for_level(1);
	ManhattanDistance mapSize(map->getPixelDimensions());
	
	Game theGame(screen, map);
	
	// TODO: Should use timers to control game loop speed
	//	and take consistent keyboard input.  Threading?
	while(!key[KEY_ESC])
	{
		rest(GAME_LOOP_PERIOD);
		theGame.loop();
	}
	
	allegro_exit();
	return 0;
}
END_OF_MAIN()	// a.k.a. Allegro performs voodoo magic.


Map* map_for_level(int level)
{
	std::stringstream filename;
	filename << "./maps/level_" << level << ".map";	
	
	std::ifstream file(filename.str().c_str());
	Map* map = MapReader::MakeMap(file);
	file.close();
	
	return map;
}
