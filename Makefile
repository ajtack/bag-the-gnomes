EXENAME = Bag\ The\ Gnomes
OBJS = \
	bag_the_gnome.o \
	character.o \
	coord.o \
	entity.o \
	game.o \
	gardener.o \
	gnome.o \
	map.o \
	map_reader.o \
	map_position.o \
	sprite.o \
	square_tile.o \
	tile.o
	
CC = g++
CCOPTS = -c -g

all: $(OBJS)
	g++ -o $(EXENAME) $(OBJS) `allegro-config --libs`
	
run: all
	./$(EXENAME)
	
clean: Makefile
	rm -f $(EXENAME) *.o

bag_the_gnome.o: bag_the_gnome.cxx bag_the_gnome.h game.h
	$(CC) $(CCOPTS) bag_the_gnome.cxx

character.o: character.cxx character.h entity.h sprite.h
	$(CC) $(CCOPTS) character.cxx
	
coord.o: coord.cxx coord.h
	$(CC) $(CCOPTS) coord.cxx
	
entity.o: entity.cxx entity.h map_position.h coord.h
	$(CC) $(CCOPTS) entity.cxx
	
game.o: game.cxx game.h character.h map_position.h coord.h map.h \
        square_tile.h tile.h entity.h sprite.h gardener.h gnome.h
	$(CC) $(CCOPTS) game.cxx
	
gardener.o: gardener.cxx gardener.h character.h map_position.h coord.h \
            map.h square_tile.h tile.h entity.h sprite.h
	$(CC) $(CCOPTS) gardener.cxx
	
gnome.o: gnome.cxx gnome.h character.h map_position.h coord.h map.h \
         square_tile.h tile.h entity.h sprite.h
	$(CC) $(CCOPTS) gnome.cxx
	
map_reader.o: map_reader.cxx map_reader.h map.h square_tile.h tile.h
	$(CC) $(CCOPTS) map_reader.cxx
	
map.o: map.cxx map.h square_tile.h images.h
	$(CC) $(CCOPTS) map.cxx

map_position.o: map_position.cxx map_position.h bag_the_gnome.h coord.h map.h tile.h
	$(CC) $(CCOPTS) map_position.cxx

sprite.o: sprite.cxx sprite.h coord.h
	$(CC) $(CCOPTS) sprite.cxx

square_tile.o: square_tile.cxx square_tile.h tile.h images.h
	$(CC) $(CCOPTS) square_tile.cxx
	
tile.o: tile.cxx tile.h
	$(CC) $(CCOPTS) tile.cxx
