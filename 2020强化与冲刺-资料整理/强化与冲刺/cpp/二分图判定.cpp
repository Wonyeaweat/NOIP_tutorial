vector<int> G[maxn];  // 邻接表法 存边 G[i]表示起点为i的边信息 
int col[maxn];        // col[i]表示点i的颜色
bool bfs(){
    queue<int> q; q.push(1);     // 放入第一个点
    col[1] = 1;    // 0表示未染色，用1、-1表示两种不同颜色 
    while(!q.empty()){
	    int v = q.front(); q.pop(); // 取队首 
	    for(int i=0;i<G[v].size();i++){
	        int xx = G[v][i]; 
	        if(col[xx] == 0){ col[xx] = -col[v]; q.push(xx);}
		    // 判断这个点是否染色过，没有染色过就标记上与v相反的颜色
	        else if(col[v] == col[xx]) return false;    // 染色矛盾，说明不是二分图 
	    }
	}
	return true;
}

