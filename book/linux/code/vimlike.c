#include<unistd.h>
#include<curses.h>
#include<stdlib.h>

void readAfile(char * fileName, WINDOW * win);
int main(){
	WINDOW * fwin;
	WINDOW * swin;
	char * fileName;
	fileName = (char *) malloc(32);
	fwin=initscr();
//add some colors
	if(has_colors()){
		start_color();
		init_pair(1,COLOR_GREEN,COLOR_BLACK);
		attron(COLOR_PAIR(1));
	}
//give some tips
	addstr("choose an option:\nO for open a file\nQ for quit");
//detect the keypress
	while(1){
		int key=getch();
		char key_press=(char)key;
		switch(key_press){
			case 'Q':
				endwin();
				free(fileName);
				exit(0);
			case 'O':
				swin = subwin(fwin,3,50,20,30);
				box(swin,'#','#');
				wmove(swin,1,2);
				waddstr(swin,"Input the file name:");
				wgetstr(swin,fileName);	
				wrefresh(swin);
				readAfile(fileName,fwin);
				delwin(swin);
				//waddstr(fwin,fileName);

		}
	}
	refresh();
	sleep(5);
	free(fileName);
	endwin();
	exit(0);
}
void readAfile(char * fileName,WINDOW * win){
	FILE * file = fopen(fileName,"r");
	int ch= fgetc(file);
	while(ch!=EOF){
		waddch(win,(char)ch);
		wrefresh(win);
		ch= fgetc(file);
	}	
	fclose(file);
}
