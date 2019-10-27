OBJ=Color.o Raster.o Vector.o Triangle.o Matrix.o main.o
DEPS=Color.h Raster.h Vector.h Triangle.h Matrix.h
CC=g++
CFLAGS=-I.
LIBS=

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o *~
