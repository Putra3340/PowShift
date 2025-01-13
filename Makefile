CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/encryption.c
OBJ = build/main.o build/encryption.o
TARGET = bin/encryption

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/main.o: src/main.c include/encryption.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/encryption.o: src/encryption.c include/encryption.h
	$(CC) $(CFLAGS) -c src/encryption.c -o build/encryption.o

run: $(TARGET)
	./$(TARGET) -i build/example.txt -o build/example.enc --decrypt

clean:
	rm -f $(OBJ) $(TARGET)
