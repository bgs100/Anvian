CC=g++
OPTS=-Wall
LIBS=-lglut -lGLEW -lGL -lSDL -lSDL_image
SOURCES=main.cpp util.cpp chunk.cpp
HEADERS=util.h chunk.h

all: $(SOURCES) $(HEADERS)
	$(CC) $(OPTS) $(LIBS) -o main $(SOURCES)