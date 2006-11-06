EXENAME = Bag\ The\ Gnomes
OBJS = \
	bag_the_gnome.o \
	character.o \
	game.o \
	gardener.o

all : $(OBJS)
	g++ -o $(EXENAME) $(OBJS) `allegro-config --libs`
	
run : all
	./$(EXENAME)
	
clean :
	rm -f $(EXENAME) *.o

bag_the_gnome.o : bag_the_gnome.cxx bag_the_gnome.h game.h
	g++ -c bag_the_gnome.cxx

character.o : character.cxx character.h entity.h
	g++ -c character.cxx
	
game.o : game.cxx game.h character.h gardener.h
	g++ -c game.cxx
	
gardener.o : gardener.cxx gardener.h character.h
	g++ -c gardener.cxx
	

