vector<int> G[maxn]; // ���
int pre[maxn];     // ��¼ƥ���
bool vis[maxn];    // ����Ƿ�ƥ���
int n,m;           // n���� m����
bool dfs(int x){
	for(int i=0;i<G[x].size();i++){
		int v = G[x][i];
		if(vis[v] == false){       // �ж��Ƿ��ǹ�
    		vis[v] = true;
    		if(pre[v] == -1 || dfs(pre[v])){      // �жϵ�ǰ���Ƿ�ƥ��� dfsΪ�ж�������ܲ��ܺ������ĵ�ƥ��
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
		memset(vis,false,sizeof(vis));     // ÿ�α�������Ҫ��ʼ��
		if(dfs(i)) sum ++;
	}
	return sum;
}
