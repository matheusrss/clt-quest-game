build:
	g++ -std=c++17 -I src/includes -o bin/main src/impl/*.cpp src/utils/*.cpp main.cpp
start: 
	./bin/main