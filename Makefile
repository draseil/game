CC=cc
FLAGS=-std=c99 -lSDL2 -lSDL2_ttf
FILES=main.c entity.c game.c
OUT=game

build: $(FILES)
	$(CC) -g -Wall $(FLAGS) -o bin/$(OUT) $(FILES)
