#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
char a[10][10];
int n,k,ans=0,visit[10];
void dfs(int cnt,int x,int y){
	/*
	cnt:当前已经放置了cnt个棋子
	x,y:目前在考虑(x,y)位置摆放棋子 
	*/
    if(cnt==k) {
		// 当前已经放置了k个棋子，满足题目要求
		// ans++,返回即可 
        ans++;
        return ;
    } 
    visit[y]=1;
    // visit数组：visit[i]表示第i列有无棋子放置
	// =1表示有棋子， =0 表示没有棋子
	// 当前位置 (x,y) 放置一枚棋子 
	
    for(int i=x+1;i<n;i++){
    	// 枚举接下来所有可以摆放棋子的位置，其中i是行j是列
		// 因为必须棋子不能在同一行，(x,y) 的棋子 说明x行不能再放置了
		// 所以i从x+1开始 到n-1行结束 （从0开始） 
        for(int j=0;j<n;j++){
            if(visit[j]==0&&a[i][j]=='#') {
            	// visit[j]==0 说明第j列还没有棋子
				// a[i][j]=='#' 说明该位置是在棋盘上而非空白处 
                dfs(cnt+1,i,j);
                // 向下搜索 
            }
        }
    }
    visit[y]=0;
    // 注意：dfs时，本层程序结束后，
	// 所有的中间数组必须恢复一开始进入当层的状态
	// 这样确保在后续时，不会因为本层而产生影响 
}
int main(){
    while(~scanf("%d%d",&n,&k)){
    	//用的是scanf，不是cin
		// (scanf("%d %d",&n,&k)!=EOF)
        if(n==-1&&k==-1) break;
        for(int i=0;i<n;i++) 
            scanf("%s",a[i]);
        ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='#') {
                	// 枚举第一个棋子摆放的位置 
                    memset(visit,0,sizeof(visit));
                    dfs(1,i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
}
