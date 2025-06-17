CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = a.exe
# SRC ?= none
INIT = init.cpp
INPUT ?= input.txt
OUTPUT = output.txt

all: run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET) < $(INPUT) > $(OUTPUT)
	rm -f $(TARGET)

init: 
	cat $(INIT) > $(SRC)

clean:
	rm -f $(TARGET) $(OUTPUT)

.PHONY: all run clean


# #include <bits/stdc++.h>

# using namespace std;

# void solve () {

# }

# int main () {
#     int t;
#     cin >> t;
#     for(int i = 0; i < t; i++) {
#         solve();
#     }
# }
