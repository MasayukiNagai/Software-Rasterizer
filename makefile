SRC_DIR=./src
CC=g++
CFLAGS=-I.
OUT=main

DEPS = $(wildcard $(SRC_DIR)/*.h)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(SRCS))

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~

run: $(OUT)
	./$(OUT)