#include<iostream>
using namespace std;
int map[10][10]; //�Ź���
bool row[10][10];    //row[i][x]  ����ڵ�i��������x�Ƿ������
bool col[10][10];    //col[j][x]  ����ڵ�j��������x�Ƿ������
bool grid[10][10];   //grid[k][x] ����ڵ�k��3*3�Ӹ�������z�Ƿ������

bool DFS(int x,int y){ // ע��bool����ֵ�����޽� 
	if(x==10) return true;
	bool flag=false;
	if(map[x][y]){ // (x,y)�Ѿ��������� 
		if(y==9) return DFS(x+1,1);
		else return DFS(x,y+1);
	}
	else{
		int k=3*((x-1)/3)+(y-1)/3+1;// ��(x,y)ת���ɶ�Ӧ�ĵ�k����� 
		for(int i=1;i<=9;i++)   //ö������1~9���
			if(!row[x][i] && !col[y][i] && !grid[k][i]){
				map[x][y]=i;
				row[x][i]=true;
				col[y][i]=true;
				grid[k][i]=true;
				if(y==9) flag=DFS(x+1,1);
				else flag=DFS(x,y+1);
				if(!flag){//���ݣ�����ö��
					map[x][y]=0;
					row[x][i]=false;
					col[y][i]=false;
					grid[k][i]=false;
				}
				else
					return true;
			}
	}
	return false;
}
 
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		memset(grid,false,sizeof(grid));
		char MAP[10][10];
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++){
				cin>>MAP[i][j];
				map[i][j]=MAP[i][j]-'0';
				if(map[i][j]){
					int k=3*((i-1)/3)+(j-1)/3+1;
					row[i][ map[i][j] ]=true;
					col[j][ map[i][j] ]=true;
					grid[k][ map[i][j] ]=true;
				}
			}
		DFS(1,1);
		for(i=1;i<=9;i++){
			for(j=1;j<=9;j++)
				cout<<map[i][j];
			cout<<endl;
		}
	}
	return 0;
}
