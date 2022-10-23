#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
struct Snake
{
	int hang;
	int lie;
	struct Snake *next;
};

struct Snake *head = NULL;
struct Snake *tail = NULL;

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

	move(0,0);
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
	struct Snake *p;

	if(head != NULL)
	{
		p = head;
		head = head->next;
		free(0);
	
	}

	head = (struct Snake *)malloc(sizeof(struct Snake));
	head->hang = 2;
	head->lie = 2;
	head->next = NULL;


	tail = head;
        addnote(number);


}
void delnote()
{
	struct Snake *p;
	p = head;

	head = head->next;

	free(p);


}
void movesnake()
{
	addnote(1);
	delnote();

	if(tail->hang == 0 || tail->lie == 0 || tail->hang == 19 || tail->lie == 19)
	{
		initsnake(2);

	}

}
void* ui_refresh()
{
	while(1)
	{
			movesnake();
			printgame();
			refresh();
			usleep(100000);
	}

}
void* changedir()
{
	int key;
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
}
int main()
{
	pthread_t t1;
	pthread_t t2;
	
	init();
	
	initsnake(2);

	printgame();


	pthread_create(&t1,NULL,changedir,NULL);
	pthread_create(&t2,NULL,ui_refresh,NULL);
	while(1);

	getch();
	endwin();

	return 0;

}
