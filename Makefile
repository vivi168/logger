CC=gcc
SRC=example.c logger.c 
DEP=logger.h
FLAGS=-Wall -Wextra
EXEC=logger

$(EXEC): $(SRC) $(DEP)
	$(CC) -o $@ $(SRC) $(FLAGS)

.PHONY: clean

clean:
	rm $(EXEC)
