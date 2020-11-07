vector<int> G[maxn];  // �ڽӱ� ��� G[i]��ʾ���Ϊi�ı���Ϣ 
int col[maxn];        // col[i]��ʾ��i����ɫ
bool bfs(){
    queue<int> q; q.push(1);     // �����һ����
    col[1] = 1;    // 0��ʾδȾɫ����1��-1��ʾ���ֲ�ͬ��ɫ 
    while(!q.empty()){
	    int v = q.front(); q.pop(); // ȡ���� 
	    for(int i=0;i<G[v].size();i++){
	        int xx = G[v][i]; 
	        if(col[xx] == 0){ col[xx] = -col[v]; q.push(xx);}
		    // �ж�������Ƿ�Ⱦɫ����û��Ⱦɫ���ͱ������v�෴����ɫ
	        else if(col[v] == col[xx]) return false;    // Ⱦɫì�ܣ�˵�����Ƕ���ͼ 
	    }
	}
	return true;
}

