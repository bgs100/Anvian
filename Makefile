CC=g++
OPTS=-Wall
LIBS=-lglut -lGLEW -lGL -lSDL -lSDL_image
SOURCES=main.cpp util.cpp chunk.cpp keyboard.cpp blocks.cpp
HEADERS=util.h chunk.h keyboard.h blocks.h

all: $(SOURCES) $(HEADERS)
	$(CC) $(OPTS) $(LIBS) -o main $(SOURCES)