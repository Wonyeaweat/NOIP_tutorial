struct element{
	int id,value; //��㵽id�����Ϊvalue 
	element(int id_,int value_):
		id(id_),value(value_){}; //Ĭ�ϸ�ֵ����������ͨ��(id,value)�ķ�ʽ��element������ֵ 
};
bool operator< (const element &other) const{
	return value>other.value;//����С�ں����������Ĭ�Ͻ���Ϊ"С"���� 
}

void dijkstra(){
    memset(dis,127/3,sizeof(dis));//��ʼ��Ϊ+�� 
    v[1]=1;
    dis[1]=0;
    for(int i=1;i<=n;++i){
        int k=0;
        for(int j=1;j<=n;++j)//�ҳ���������ĵ�
            if(!v[j]&&(k==0||dis[j]<dis[k]))
                k=j;
        v[k]=1;//���뼯��
        for(int j=1;j<=n;++j)//�ɳ�
            if(!v[j]&&dis[k]+a[k][j]<dis[j])
                dis[j]=dis[k]+a[k][j];
    }
}

void dijkstra(){ // ���Ż� 
    priority_queue<element> q;//���ȶ���
    q.push(element(1,0));//Ĭ�������1,���������0 
    while(!q.empty()){//���վ�˵�����е�û����
        element k=q.top(); q.pop();//ȡ������
        if(vis[k.node]) continue;//����Ѿ��ڼ����У����ѵ�����,�ӵ�
        vis[k.node]=1;//���
        dis[k.node]=k.value;//�������·���������ȶ��е������Ѿ��൱��������ɳڣ���������Ǵ𰸣�
        for(vector<edge>::iterator it=v[k.node].begin();it!=v[k.node].end();++it)//��ָ������ڽӱ�
            q.push(element(it->node,it->weight+k.value));//�ɳ�
    }
}
