EXENAME = Bag\ The\ Gnomes
OBJS = \
	bag_the_gnome.o \
	character.o \
	game.o \
	gardener.o \
	gnome.o \
	map_reader.o \
	square_map.o \
	square_tile.o \
	tile.o
	
CC = g++
CCOPTS = -c -g

all : $(OBJS)
	g++ -o $(EXENAME) $(OBJS) `allegro-config --libs`
	
run : all
	./$(EXENAME)
	
clean : Makefile
	rm -f $(EXENAME) *.o

bag_the_gnome.o : bag_the_gnome.cxx bag_the_gnome.h game.h
	$(CC) $(CCOPTS) bag_the_gnome.cxx

character.o : character.cxx character.h entity.h sprite.h
	$(CC) $(CCOPTS) character.cxx
	
game.o : game.cxx game.h character.h gardener.h sprite.h
	$(CC) $(CCOPTS) game.cxx
	
gardener.o : gardener.cxx gardener.h character.h sprite.h
	$(CC) $(CCOPTS) gardener.cxx
	
gnome.o : gnome.cxx gnome.h character.h sprite.h
	$(CC) $(CCOPTS) gnome.cxx
	
map_reader.o : map_reader.cxx map_reader.h map.h square_tile.h
	$(CC) $(CCOPTS) map_reader.cxx
	
map.o : map.cxx map.h square_tile.h images.h
	$(CC) $(CCOPTS) map.cxx

square_tile.o : square_tile.cxx square_tile.h tile.h images.h
	$(CC) $(CCOPTS) square_tile.cxx
	
tile.o : tile.cxx tile.h
	$(CC) $(CCOPTS) tile.cxx
