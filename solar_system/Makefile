CXX=g++

EXEC=solarsystem

SOURCES = $(wildcard *.cpp)

OBJECTS=$(SOURCES:.cpp=%.o)

LDFLAGS=-lglut -lGL -lGLU

all:
	$(CXX) $(SOURCES) $(LDFLAGS) -o $(EXEC)

clean:
	rm -f $(EXEC) *.gdb *.o
