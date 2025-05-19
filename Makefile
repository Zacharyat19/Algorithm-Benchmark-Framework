CXX = g++
CXXFLAGS = -std=c++17 -IInc -Wall -Wextra
SRC = src/Main.cpp src/BubbleSortBenchmark.cpp src/SelectionSortBenchmark.cpp
OUT = benchmark.exe

all: 
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)