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

bag_the_gnome.o: bag_the_gnome.cxx bag_the_gnome.hxx map.hxx coord.hxx \
                 square_tile.hxx tile.hxx game.hxx character.hxx map_position.hxx \
                 entity.hxx sprite.hxx gardener.hxx map_reader.hxx
	$(CC) $(CCOPTS) bag_the_gnome.cxx

character.o: character.cxx character.hxx map_position.hxx coord.hxx \
             map.hxx square_tile.hxx tile.hxx entity.hxx sprite.hxx
	$(CC) $(CCOPTS) character.cxx
	
coord.o: coord.cxx coord.hxx
	$(CC) $(CCOPTS) coord.cxx
	
entity.o: entity.cxx entity.hxx map_position.hxx coord.hxx map.hxx \
          square_tile.hxx tile.hxx
	$(CC) $(CCOPTS) entity.cxx
	
game.o: game.cxx game.hxx character.hxx map_position.hxx coord.hxx \
        map.hxx square_tile.hxx tile.hxx entity.hxx sprite.hxx gardener.hxx \
        gnome.hxx
	$(CC) $(CCOPTS) game.cxx
	
gardener.o: gardener.cxx gardener.hxx character.hxx map_position.hxx \
            coord.hxx map.hxx square_tile.hxx tile.hxx entity.hxx sprite.hxx
	$(CC) $(CCOPTS) gardener.cxx
	
gnome.o: gnome.cxx gnome.hxx character.hxx map_position.hxx coord.hxx \
         map.hxx square_tile.hxx tile.hxx entity.hxx sprite.hxx
	$(CC) $(CCOPTS) gnome.cxx
	
map.o: map.cxx images.hxx map.hxx coord.hxx square_tile.hxx tile.hxx
	$(CC) $(CCOPTS) map.cxx

map_position.o: map_position.cxx bag_the_gnome.hxx map.hxx coord.hxx \
                square_tile.hxx tile.hxx map_position.hxx
	$(CC) $(CCOPTS) map_position.cxx
	
map_reader.o: map_reader.cxx map_reader.hxx map.hxx coord.hxx \
              square_tile.hxx tile.hxx
	$(CC) $(CCOPTS) map_reader.cxx

sprite.o: sprite.cxx sprite.hxx coord.hxx
	$(CC) $(CCOPTS) sprite.cxx

square_tile.o: square_tile.cxx square_tile.hxx tile.hxx
	$(CC) $(CCOPTS) square_tile.cxx
	
tile.o: tile.cxx tile.hxx
	$(CC) $(CCOPTS) tile.cxx
