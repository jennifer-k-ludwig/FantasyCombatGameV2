#Makefile for Fantasy Combat Tournament

CXX = g++
CXXFLAGS = -g -Wall -std=c++0x

game: main.o driverFunctions.o Character.o Barbarian.o Vampire.o HarryPotter.o Medusa.o BlueMen.o Queue.o Stack.o
	$(CXX) $(CXXFLAGS) main.o driverFunctions.o Character.o Barbarian.o Vampire.o HarryPotter.o Medusa.o BlueMen.o Queue.o Stack.o -o game

Queue.o: Queue.h
	$(CXX) $(CXXFLAGS) Queue.cpp -c

Stack.o: Stack.h
	$(CXX) $(CXXFLAGS) Stack.cpp -c

driverFunctions.o: driverFunctions.cpp Character.hpp Queue.h
	$(CXX) $(CXXFLAGS) driverFunctions.cpp -c

main.o: main.cpp driverFunctions.hpp
	$(CXX) $(CXXFLAGS) main.cpp -c

Character.o: Character.cpp
	$(CXX) $(CXXFLAGS) Character.cpp -c

Barbarian.o: Barbarian.cpp Character.hpp
	$(CXX) $(CXXFLAGS) Barbarian.cpp -c

Vampire.o: Vampire.cpp Character.hpp
	$(CXX) $(CXXFLAGS) Vampire.cpp -c

HarryPotter.o: HarryPotter.cpp Character.hpp
	$(CXX) $(CXXFLAGS) HarryPotter.cpp -c

Medusa.o: Medusa.cpp Character.hpp
	$(CXX) $(CXXFLAGS) Medusa.cpp -c

BlueMen.o: BlueMen.cpp Character.hpp
	$(CXX) $(CXXFLAGS) BlueMen.cpp -c

clean:
	rm *.o game
