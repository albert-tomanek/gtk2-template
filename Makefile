TARGET = template
LIBS = `pkg-config gtkmm-2.4 --cflags --libs` `pkg-config --cflags --libs sigc++-2.0`
CC = g++
CXXFLAGS = -g $(LIBS)

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = main.o
HEADERS = main.hpp

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
