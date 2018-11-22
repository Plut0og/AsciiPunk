#include <curses.h>
#include <iostream>
#include <chrono>
#include <math.h>

void initcurses(){

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	return 
}

void cleanup(){
	echo();
	endwin();
}

int main(){
	
	initcurses();

	int ch;
	nodelay(stdscr, TRUE); 
	
	//init time features
	std::chrono::high_resolution_clock::time_point start, c_time; //two time points start, and changing c-time

	int frames = 30; //number of frames
	double delta_frame = (double) 1 / frames; //number of ms per frame

	long unsigned int c_frame = 0; //c-frame
	std::chrono::duration<double> delta_start; //time since start

	start = std::chrono::high_resolution_clock::now();

	//mainloop 
	bool isRunning = true;
	while(isRunning){

		//handling game frames
		c_time = std::chrono::high_resolution_clock::now();
		delta_start = std::chrono::duration_cast< std::chrono::duration<double> >(c_time - start);
		if(delta_start.count() > (delta_frame * c_frame)){			
			//alternating "X" and "O" every second(30 frames)
			if(((int)floor(c_frame / 30) % 2) == 0){
				addstr("O");
			} else {
				addstr("X");
			}
			c_frame++;
		}

		//input handling
		if((ch = getch())){
			if(ch == 'q'){
				isRunning = false;
			}
		}

		move(0, 0);
		refresh();
		
	}

	return 0;

}