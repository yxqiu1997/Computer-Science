FLAGS = -O2 -Wall -Werror -std=c++17 -Wextra -pedantic -Wfloat-equal -ansi
TARGET = 45
SOURCE = $(TARGET).cpp
LIBS = -lm
CC = g++

all: $(TARGET)

$(TARGET): $(SOURCE)
		$(CC) $(SOURCE) -o $(TARGET) $(FLAGS) $(LIBS)

clean:
		rm -f $(TARGET)

run: all
		./$(TARGET)
