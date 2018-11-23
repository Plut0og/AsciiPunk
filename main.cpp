#include <curses.h>
#include <iostream>
#include <math.h>
#include <string>
#include "Animation.h"

using namespace std;

void initcurses(){

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	return;
}

void cleanup(){
	echo();
	nocbreak();
	endwin();

	return;
}


int main(){

	initcurses();

	int ch;
	nodelay(stdscr, TRUE);

	//mainloop
	bool isRunning = true;
	Animation anim("anim1.txt",2);
	anim.start();
	while(isRunning){

		anim.step();
		addstr(anim.getFrame().c_str());
		//input handling
		if((ch = getch())){
			if(ch == 'q'){
				isRunning = false;
			}
		}

		move(0, 0);
		refresh();

	}

	cleanup();

	return 0;

}
