EXENAME = Bag\ The\ Gnomes
OBJS = \
	character.o \
	game.o \
	gardener.o

all : $(OBJS)

character.o : character.cxx character.h entity.h
	g++ -c character.cxx
	
game.o : game.cxx game.h character.h gardener.h
	g++ -c game.cxx
	
gardener.o : gardener.cxx gardener.h character.h
	g++ -c gardener.cxx
	

