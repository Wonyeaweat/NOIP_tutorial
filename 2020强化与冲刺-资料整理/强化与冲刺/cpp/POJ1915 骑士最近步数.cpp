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
    //��ʼ������
	//node(int x,int y) ������node�ͱ���ʱ������ͨ�������֣����֣�����ʽ
	//�����������ֵ 
};
node st, en;
int vis[330][330];//vis[i][j]��ʾ������ ��i�� ��j�� ��û�з��ʹ� 
int step[330][330]; // step[i][j]��ʾ ������   ��i�� ��j�� ��Ҫ���ٲ� 
int n;
queue<node> Q;
queue<node> P;//��˫������ 
 
bool in(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n) // �ж��Ƿ��������� 
        return false;
    return true;
}
//in��������true ˵������������ 
int BFS(){
    if (st.x == en.x && st.y == en.y) // ˵���� ����ص��غϣ����貽�� 
        return 0;
    while (!Q.empty()) Q.pop(); //����������
    while (!P.empty()) P.pop(); //����������
    //.pop() �������׶�ͷ 
    // push�� pull�� 
    // pop ���е�/���Ե� 
    // pushѹ����� 
    Q.push(st);
    P.push(en);
    vis[st.x][st.y] = 1;// ����㿪ʼ��BFS�����ʵ��ˣ����Ϊ1 
    vis[en.x][en.y] = 2;// ���յ㿪ʼ��BFS�����ʵ��ˣ����Ϊ2 
    while (!Q.empty() || !P.empty()){
        if (!Q.empty()){// �������㿪ʼ������չ�ɷ��ʵĵ� 
            node now = Q.front(); // �������ȡ��ͷ 
            Q.pop();
            for (int i=0; i<8; i++)
                if (in(now.x+dx[i],now.y+dy[i])){
	                node New = node(now.x+dx[i], now.y+dy[i]);
	                //new �� ��һ�ֿ���չ��8���� 
	                if (vis[New.x][New.y] == 2)  //����
	                //==2 ˵��new����㣬֮ǰ�����յ㿪ʼ�����ʹ��ˣ������Ϊ2
					//�������ڣ�new����㣬�Ǵ���㿪ʼ������չ�ġ�
					//����˵�����൱�ڣ����� 
	                    return step[now.x][now.y] + step[New.x][New.y] + 1;
	                else if (vis[New.x][New.y] == 0){ // ˵�������֮ǰû�����ʹ� 
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
	                if (vis[New.x][New.y] == 1)  //����
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
        st = node(sx,sy);en = node(tx,ty);//�����յ� 
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        printf("%d\n",BFS());
    }
    return 0;
}
