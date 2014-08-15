objects = Card.o Game.o Player.o test.o
headers = Card.h Game.h Player.h defs.h 
cc = g++

client : $(objects)
	$(cc) -o client $(objects)

$(objects) : defs.h
Card.o Game.o Player.o test.o: $(headers)

.PHONY : clean
clean :
	rm edit $(objects)
