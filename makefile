AsciiPunk: main.o Animation.o
	g++ -std=c++11 -lncurses main.o Animation.o -o AsciiPunk

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Animation.o: Animation.h Animation.cpp
	g++ -std=c++11 -c Animation.cpp

clean:
	rm -f *.o AsciiPunk
