CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = a.exe
# SRC ?= none
INPUT ?= input.txt
OUTPUT = output.txt

all: run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET) < $(INPUT) > $(OUTPUT)
	rm -f $(TARGET)

clean:
	rm -f $(TARGET) $(OUTPUT)

.PHONY: all run clean