vector<int> G[maxn]; // 存边
int pre[maxn];     // 记录匹配点
bool vis[maxn];    // 标记是否匹配过
int n,m;           // n个点 m条边
bool dfs(int x){
	for(int i=0;i<G[x].size();i++){
		int v = G[x][i];
		if(vis[v] == false){       // 判断是否标记过
    		vis[v] = true;
    		if(pre[v] == -1 || dfs(pre[v])){      // 判断当前点是否匹配过 dfs为判断这个点能不能和其他的点匹配
        		pre[v] = x;
        		return true;
    		}
    	}
	}
	return false;
}
  
int Fun(){
	int sum = 0;
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));     // 每次遍历都需要初始化
		if(dfs(i)) sum ++;
	}
	return sum;
}
