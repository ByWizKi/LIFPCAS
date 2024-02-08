TARGET = thread.out
CC = g++
CFLAGS = -Wall -std=c++11 -pthread

# La cible 'all' compile le programme
all: $(TARGET)

# Compilation du programme
$(TARGET): lancement.cpp
	$(CC) $(CFLAGS) lancement.cpp -o $(TARGET)

# Nettoyage des fichiers compilés
clean:
	rm -f $(TARGET)

.PHONY: all clean
