#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int k[210],s[210],que[1010];
queue<int> Q; 
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		s[i]=-1;
		cin>>k[i];
	}
	Q.push(a); //que[tail++]=a;
	s[a]=0;
	while(!Q.empty()){
		int head = Q.front(); Q.pop();
		int nextFloor = head+k[head];
		if(nextFloor<=n&&s[nextFloor]==-1){ // 未超出楼层限制 且 该楼层未访问过 
			Q.push(nextFloor); 
			s[nextFloor]=s[head]+1;
			//cout<<"yggdyy";
		}
		nextFloor = head-k[head];
		if(nextFloor>=1&&s[nextFloor]==-1){
			Q.push(nextFloor); 
			s[nextFloor]=s[head]+1;
			//cout<<"yggdyy";
		}
	}cout<<s[b]<<endl;
	return 0;
}
