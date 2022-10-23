#include<ncurses.h>
#include<stdlib.h>
struct Snake
{
	int hang;
	int lie;
	struct Snake *next;
};

struct Snake *head;
struct Snake *tail;

int printsnake(int x,int y)
{
	struct Snake *p;
	p = head;

	while(p != NULL)
	{
        	if(x == p->hang && y == p->lie)
        	{
	        	return 1;
        	}
                p = p->next;
	}
	return 0;
}

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
			else if(printsnake(hang,lie)){
				printw("[]");			
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
void addnote(int number)
{
	for(int i=0;i<number;i++)
	{
 		struct Snake *new = (struct Snake *)malloc(sizeof(struct Snake));

		new->hang = tail->hang;
		new->lie = tail->lie + 1;
		new->next = NULL;
		
    		tail->next = new;
		tail = new;
	}

}
void initsnake(int number)
{
	head = (struct Snake *)malloc(sizeof(struct Snake));
	head->hang = 2;
	head->lie = 2;
	head->next = NULL;


	tail = head;
        addnote(number);


}

int main()
{
	init();
	
	initsnake(2);

	printgame();

	getch();
	endwin();

	return 0;

}
