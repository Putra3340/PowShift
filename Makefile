CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/encryption.c
OBJ = src/main.o src/encryption.o
TARGET = encryption

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) $(OBJ) -o $(TARGET)

src/main.o: src/main.c include/encryption.h
    $(CC) $(CFLAGS) -c src/main.c

src/encryption.o: src/encryption.c include/encryption.h
    $(CC) $(CFLAGS) -c src/encryption.c

clean:
    rm -f $(OBJ) $(TARGET)
