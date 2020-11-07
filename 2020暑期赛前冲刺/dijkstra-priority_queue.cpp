struct element{
	int id,value; //起点到id点距离为value 
	element(int id_,int value_):
		id(id_),value(value_){}; //默认赋值函数，可以通过(id,value)的方式给element变量赋值 
};
bool operator< (const element &other) const{
	return value>other.value;//重载小于号运算符，堆默认建立为"小"根堆 
}

void dijkstra(){
    memset(dis,127/3,sizeof(dis));//初始化为+∞ 
    v[1]=1;
    dis[1]=0;
    for(int i=1;i<=n;++i){
        int k=0;
        for(int j=1;j<=n;++j)//找出距离最近的点
            if(!v[j]&&(k==0||dis[j]<dis[k]))
                k=j;
        v[k]=1;//加入集合
        for(int j=1;j<=n;++j)//松弛
            if(!v[j]&&dis[k]+a[k][j]<dis[j])
                dis[j]=dis[k]+a[k][j];
    }
}

void dijkstra(){ // 堆优化 
    priority_queue<element> q;//优先队列
    q.push(element(1,0));//默认起点是1,最近距离是0 
    while(!q.empty()){//不空就说明还有点没搜完
        element k=q.top(); q.pop();//取出队首
        if(vis[k.node]) continue;//如果已经在集合中（被搜到过）,扔掉
        vis[k.node]=1;//标记
        dis[k.node]=k.value;//存下最短路（由于优先队列的排序已经相当于完成了松弛，所以这就是答案）
        for(vector<edge>::iterator it=v[k.node].begin();it!=v[k.node].end();++it)//用指针遍历邻接表
            q.push(element(it->node,it->weight+k.value));//松弛
    }
}
