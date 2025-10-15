CC=gcc
CFLAGS = -Wall -Wextra -nostdlib -static
INC_DIR=include
SRC_DIR=src
BLD_DIR=build
EXE=mystd

all: $(build)/$(EXE)

$(build)/$(EXE): $(BLD_DIR)/main.o $(BLD_DIR)/mystd.o $(BLD_DIR)/mystring.o
	$(CC) $(CFLAGS) $(BLD_DIR)/main.o $(BLD_DIR)/mystd.o $(BLD_DIR)/mystring.o -o $(BLD_DIR)/$(EXE)

$(BLD_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) -c $(CFLAGS) -I$(INC_DIR) $(SRC_DIR)/main.c -o $(BLD_DIR)/main.o

$(BLD_DIR)/mystd.o: $(SRC_DIR)/mystd.c
	$(CC) -c $(CFLAGS) -I$(INC_DIR) $(SRC_DIR)/mystd.c -o $(BLD_DIR)/mystd.o

$(BLD_DIR)/mystring.o: $(SRC_DIR)/mystring.c
	$(CC) -c $(CFLAGS) -I$(INC_DIR) $(SRC_DIR)/mystring.c -o $(BLD_DIR)/mystring.o

clean:
	rm -f $(BLD_DIR)/*.o
	rm -f $(BLD_DIR)/*.txt
	rm -f $(BLD_DIR)/$(EXE)