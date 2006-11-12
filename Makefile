EXENAME = Bag\ The\ Gnomes
OBJS = \
	bag_the_gnome.o \
	character.o \
	game.o \
	gardener.o \
	gnome.o
	
CCOPTS = -c -g

all : $(OBJS)
	g++ -o $(EXENAME) $(OBJS) `allegro-config --libs`
	
run : all
	./$(EXENAME)
	
clean : Makefile
	rm -f $(EXENAME) *.o

bag_the_gnome.o : bag_the_gnome.cxx bag_the_gnome.h game.h
	g++ $(CCOPTS) bag_the_gnome.cxx

character.o : character.cxx character.h entity.h sprite.h
	g++ $(CCOPTS) character.cxx
	
game.o : game.cxx game.h character.h gardener.h sprite.h
	g++ $(CCOPTS) game.cxx
	
gardener.o : gardener.cxx gardener.h character.h sprite.h
	g++ $(CCOPTS) gardener.cxx
	
gnome.o : gnome.cxx gnome.h character.h sprite.h
	g++ $(CCOPTS) gnome.cxx
