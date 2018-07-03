#include<stdio.h>
#define HEIGHT 20
#define WIDTH 18 
#define WIN_NUM 4 

char map[HEIGHT][WIDTH];
int x,y;

void init_map();
void print_map();
void input(char id);
int is_win(char id);
int count(char id,int xx,int yy);

int main()
{
	init_map(); 
	print_map();
	while(1)
	{
		input('A');
		print_map();
		if(is_win('A') == 1)
		{
			printf("A wins!\n");
			break;
		}
		input('B');
		print_map();
		if(is_win('B') == 1)
		{
			printf("B wins!\n");
			break;
		}
	}
}
void init_map()
{
	int i,j;
	for(i = 0;i < HEIGHT;i++)
	{
		for(j = 0;j < WIDTH;j++)
		{
			map[i][j] = '.';
		}
	}
}
void print_map()
{
	int i,j;
	for(i = 0;i < HEIGHT;i++)
	{
		for(j = 0;j < WIDTH;j++)
		{
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}
}
void input(char id)
{
	do
	{
		printf("%c input x,y:\n",id);
		scanf("%d%d",&x,&y);
	}while(map[y][x] != '.');
	map[y][x] = id;
}
int is_win(char id)
{
	if(count(id,-1,0)+count(id,1,0) >= WIN_NUM)
	{
		return 1;
	}
	else if(count(id,0,-1)+count(id,0,1) >= WIN_NUM)
	{
		return 1;
	}
	else if(count(id,-1,-1)+count(id,1,1) >= WIN_NUM)
	{
		return 1;
	}
	else if(count(id,1,-1)+count(id,-1,1) >= WIN_NUM)
	{
		return 1;
	}
	return 0;
}
int count(char id,int xx,int yy)
{
	int i,j,sum = 0;
	for(i=y+yy,j=x+xx;i>=0&&i<HEIGHT&&j>=0&&j<WIDTH;i+=yy,j+=xx)
	{
		if(map[i][j] == id)
			sum++;
		else 
			break;
	}
	return sum;
}
