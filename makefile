OBJ=Color.o Raster.o Vector2.o Triangle2D.o main.o
DEPS=Color.h Raster.h Vector2.h Triangle2D.h
CC=g++
CFLAGS=-I.
LIBS=

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o *~
