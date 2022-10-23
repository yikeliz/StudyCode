#include<ncurses.h>

void init()
{
	initscr();
	keypad(stdscr,1);
}

void printgame()
{
	int lie;
	int hang;

	for(hang=0;hang<20;hang++)
	{
		if(hang == 0)
		{
			for(lie=0;lie<19;lie++)
			{
				printw("--");
			}
			printw("\n");
		}
		for(lie=0;lie<20;lie++)
		{
			if(lie == 0 || lie == 19)
			{
				printw("|");
			}
			else{
				printw("  ");
			}
		}

		printw("\n");

		if(hang == 19)
		{
			for(lie=0;lie<19;lie++)
			{
				printw("--");
			}
			printw("\n");
		}
	}
}
int main()
{
	init();
	printgame();

	getch();
	endwin();


	return 0;

}
