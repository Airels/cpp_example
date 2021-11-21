CC = g++
EXEC = out
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf *.o $(EXEC) *.txt
