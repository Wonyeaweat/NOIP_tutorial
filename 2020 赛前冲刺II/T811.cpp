#include"stdio.h"
#include"string.h"
bool list[1050][1050];
int x,y=1;
void move(int direction)
{
	switch(direction)
	{
		case 0:y+=2;list[x][y-1]=true;break;
		case 1:x+=2;list[x-1][y]=true;break;
		case 2:y-=2;list[x][y+1]=true;break;
		case 3:x-=2;list[x+1][y]=true;break;
	}
	list[x][y]=true;
}
void hilbert(int angle,int direction,int floor)
{
	if(floor==0)
		return;
	direction=(direction+angle+2)%4;
	hilbert(0-angle,direction,floor-1);
	move(direction);
	direction=(direction-angle+2)%4;
	hilbert(angle,direction,floor-1);
	move(direction);
	hilbert(angle,direction,floor-1);
	direction=(direction-angle+2)%4;
	move(direction);
	hilbert(0-angle,direction,floor-1);
	direction=(direction+angle+2)%4;
}
int main()
{
	memset(list,false,sizeof(list));
	int floor;
	scanf("%d",&floor);
	x=(2<<floor)-1;
	list[x][1]=true;
	hilbert(1,0,floor);
	for(int i=(2<<floor)-1;i>0;i--)
	{
		for(int j=1;j<2<<floor;j++)
			printf("%d",list[j][i]);
		printf("\n");
	}
	return 0;
}

