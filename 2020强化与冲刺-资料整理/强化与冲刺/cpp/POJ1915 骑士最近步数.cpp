#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int dx[8] = {-1,-2,-2,-1,1,2,2,1};
const int dy[8] = {-2,-1,1,2,2,1,-1,-2};
struct node{
    int x, y;
    node() {}
    node(int x, int y):x(x), y(y) {}
    //初始化函数
	//node(int x,int y) 在声明node型变量时，可以通过（数字，数字）的形式
	//给这个变量赋值 
};
node st, en;
int vis[330][330];//vis[i][j]表示棋盘上 第i行 第j列 有没有访问过 
int step[330][330]; // step[i][j]表示 棋盘上   第i行 第j列 需要多少步 
int n;
queue<node> Q;
queue<node> P;//做双向搜索 
 
bool in(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n) // 判断是否在棋盘内 
        return false;
    return true;
}
//in函数返回true 说明是在棋盘内 
int BFS(){
    if (st.x == en.x && st.y == en.y) // 说明： 起点重点重合，无需步数 
        return 0;
    while (!Q.empty()) Q.pop(); //清空正向队列
    while (!P.empty()) P.pop(); //清空逆向队列
    //.pop() 弹出队首队头 
    // push推 pull拉 
    // pop 流行的/弹性的 
    // push压入队列 
    Q.push(st);
    P.push(en);
    vis[st.x][st.y] = 1;// 从起点开始的BFS，访问到了，标记为1 
    vis[en.x][en.y] = 2;// 从终点开始的BFS，访问到了，标记为2 
    while (!Q.empty() || !P.empty()){
        if (!Q.empty()){// 处理从起点开始向外扩展可访问的点 
            node now = Q.front(); // 正向队列取队头 
            Q.pop();
            for (int i=0; i<8; i++)
                if (in(now.x+dx[i],now.y+dy[i])){
	                node New = node(now.x+dx[i], now.y+dy[i]);
	                //new 是 下一轮可扩展的8个点 
	                if (vis[New.x][New.y] == 2)  //相遇
	                //==2 说明new这个点，之前（从终点开始被访问过了），标记为2
					//但是现在，new这个点，是从起点开始向外扩展的。
					//所以说，这相当于，相遇 
	                    return step[now.x][now.y] + step[New.x][New.y] + 1;
	                else if (vis[New.x][New.y] == 0){ // 说明这个点之前没被访问过 
	                    vis[New.x][New.y] = 1;
	                    step[New.x][New.y] = step[now.x][now.y] + 1;
	                    Q.push(New);
	                }
            	}
        }
        if (!P.empty()){
            node now = P.front();
            P.pop();
            for (int i=0; i<8; i++)
                if (in(now.x+dx[i],now.y+dy[i])){
	                node New = node(now.x+dx[i], now.y+dy[i]);
	                if (vis[New.x][New.y] == 1)  //相遇
	                    return step[now.x][now.y] + step[New.x][New.y] + 1;
	                else if (vis[New.x][New.y] == 0){
	                    vis[New.x][New.y] = 2;
	                    step[New.x][New.y] = step[now.x][now.y] + 1;
	                    P.push(New);
	                }
            	}
        }
    }
}
 
int main(){
    int t,sx, sy, tx, ty; 
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
        st = node(sx,sy);en = node(tx,ty);//起点和终点 
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        printf("%d\n",BFS());
    }
    return 0;
}
