# Nom du compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Nom du fichier exécutable
TARGET = program.out

# Détecter tous les fichiers .cpp dans le répertoire courant
SRC = $(wildcard *.cpp)

# Transformer les fichiers .cpp en .o pour la compilation
OBJ = $(SRC:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Comment lier
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(OBJ) $(TARGET)

# Règle pour les fichiers .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean
