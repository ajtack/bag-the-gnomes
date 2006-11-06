#include "bag_the_gnome.h"
#include "game.h"

#include <allegro.h>

int main()
{
	allegro_init();
	install_keyboard();
	
	// Create the Game
	int ret = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (ret != 0)	{
		allegro_message(allegro_error);
		return 1;
	}
	Game theGame(screen);
	
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
