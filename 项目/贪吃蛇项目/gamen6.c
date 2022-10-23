#include<ncurses.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>



#define RIGHT 1
#define LEFT -1
#define DOWN  2
#define UP   -2

struct Snake
{
	int hang;
	int lie;
	struct Snake *next;
};

struct Snake *head = NULL;
struct Snake *tail = NULL;
int dir;
struct Snake food;
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
int printfood(int x,int y)
{

       	if(x == food.hang && y == food.lie)
       	{
        	return 1;
       	}
	return 0;
}
void init()
{
	initscr();
	keypad(stdscr,1);
	noecho();
}


void initfood()
{
	static int x = 7;
	static int y = 7;

	food.hang = x;
	food.lie  = y;

}
void printgame()
{
	int lie;
	int hang;

	move(0,0);
	printw("Eat foodSnake\n");
	for(hang=1;hang<21;hang++)
	{
		
		if(hang == 1)
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
			else if(printsnake(hang,lie))
			{
				printw("[]");			
			}   
	 		else if(printfood(hang,lie))
			{
				printw("##");
			}	
			else{
			printw("  ");
			}
		}
		printw("\n");
		if(hang == 20)
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

		new->next = NULL;
		switch(dir)
		{
			case RIGHT:	
				new->hang = tail->hang;
				new->lie = tail->lie + 1;
				break;
			case UP:	
				new->hang = tail->hang - 1;
				new->lie = tail->lie;
				break;
			case DOWN:	
				new->hang = tail->hang + 1;
				new->lie = tail->lie;
				break;
			case LEFT:	
				new->hang = tail->hang;
				new->lie = tail->lie - 1;
				break;
			}
    		tail->next = new;
		tail = new;
	}

}


void initsnake(int number)
{
	struct Snake *p;
        dir = RIGHT;
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

void creatfood()
{
	srand((unsigned int)time(NULL));

	food.hang = rand()%19+2;
	food.lie  = rand()%18+1;


}
void movesnake()
{
	addnote(1);
	if(printfood(tail->hang,tail->lie))
	{
		addnote(1);
		creatfood();
	}
	else{
		delnote();
	}
	if(tail->hang == 0 || tail->lie == 0 || tail->hang == 21 || tail->lie == 19)
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
			usleep(120000);
	}

}

void turn(int dir_2)
{
	if(abs(dir) != abs(dir_2))
	{
		dir = dir_2;
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
				turn(DOWN);
				break;
			case KEY_UP:
				turn(UP);
				break;	
			case KEY_LEFT:
				turn(LEFT);
				break;	
			case KEY_RIGHT:
				turn(RIGHT);
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
	initfood();

	printgame();


	pthread_create(&t1,NULL,changedir,NULL);
	pthread_create(&t2,NULL,ui_refresh,NULL);
	while(1);

	getch();
	endwin();

	return 0;

}
