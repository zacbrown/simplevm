# Filename : Makefile
# Author   : Zac Brown
# Date     : 11.17.2009

SRC_DIR = ./src
BIN_NAME = simplevm
CFLAGS = -g -Wall

simplevm: $(SRC_DIR)/vm.o $(SRC_DIR)/stack.o
	g++ $(CFLAGS) -o $(BIN_NAME) $(SRC_DIR)/vm.o $(SRC_DIR)/stack.o

$(SRC_DIR)/vm.o: $(SRC_DIR)/vm.cpp
	g++ $(CFLAGS) -o $(SRC_DIR)/vm.o -c $(SRC_DIR)/vm.cpp

$(SRC_DIR)/stack.o: $(SRC_DIR)/stack.cpp
	g++ $(CFLAGS) -o $(SRC_DIR)/stack.o -c $(SRC_DIR)/stack.cpp

clean:
	rm -f $(SRC_DIR)/*.o $(BIN_NAME)
