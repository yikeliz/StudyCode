#include <ncurses.h>
int main()
{
	int key;
	initscr();

	keypad(stdscr,1);

	while(1)
	{
		key = getch();
		switch(key)
		{
			case KEY_DOWN:
				printw("down\n");
				break;
			case KEY_UP:
				printw("up\n");
				break;	
			case KEY_LEFT:
				printw("left\n");
				break;	
			case KEY_RIGHT:
				printw("right\n");
				break;
		}
	
	}

	endwin();

	return 0;
}
