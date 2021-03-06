# 初赛资料与真题模拟 · 程序填空


完善程序

（最大公约数之和）下列程序想要求解整数𝑛的所有约数两两之间最大公约数的和对 10007 求余后的值，试补全程序。（第一空2 分，其余 3 分）举例来说，4 的所有约数是 1, 2, 4 。1 和 2 的最大公约数为 1 ；2 和 4 的最大公约数为 2 ；1 和 4 的最大公约数为 1 。于是答案为1 + 2 + 1 = 4。

要求getDivisor 函数的复杂度为𝑂(√𝑛)，gcd 函数的复杂度为𝑂(log max(𝑎, 𝑏))。

```C++
#include <iostream>
using namespace std;

const int N = 110000, P = 10007;
int n;
int a[N], len;
int ans;

void getDivisor() {
    len = 0;
    for (int i = 1; ___________ <= n; ++i)
        if (n % i == 0) {
          a[++len] = i;
          if ( _________ != i) a[++len] = n / i;
        }
}

int gcd(int a, int b) {
    if (b == 0) { __________________ ;  }
    return gcd(b, ______________);
}

int main() {
    cin >> n;
    getDivisor();
    ans = 0;
    for (int i = 1; i <= len; ++i) 
        for (int j = i + 1; j <= len; ++j) 
        	ans = ( __________ ) % P;
    cout << ans << endl;
    return 0;
}

```

---

对于一个 1 到 n 的排列 P（即 1 到 n 中每一个数在 P 中出现了恰好一次），令 q[i] 为第 i 个位置之后第一个比 P[i] 值更大的位置，如果不存在这样的位置，则 q[i] = n + 1。举例来说，如果 n = 5 且 P 为 1 5 4 2 3 ，则 q 为2 6 6 5 6。

下列程序读入了排列 P ，使用双向链表求解了答案。试补全程序。

```C++
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int L[N], R[N], a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        _______________ ;
    }
    for (int i = 1; i <= n; ++i) {
        R[i] = _______________ ;
        L[i] = i - 1;
    }
    for (int i = 1; i <= n; ++i) {
        L[ ____________ ] = L[a[i]];
        R[L[a[i]]] = R[ ____________ ];
    }
    for (int i = 1; i <= n; ++i) 
    	cout << ______________ << " ";
    cout << endl;
    return 0;
}
```

---

一只小猪要买 N 件物品（N 不超过 1000）。

它要买的所有物品在两家商店里都有卖。第 i 件物品在第一家商店的价格是 a[i] ，在第二家商店的价格是 b[i] ，两个价格都不小于 0 且不超过 10000。如果在第一家商店买的物品的总额不少于 50000，那么在第一家店买的物品都可以打 95 折(价格变为原来的 0.95 倍)。

求小猪买齐所有物品所需最少的总额。

输入：第一行一个数 N。接下来N 行，每行两个数。第 i 行的两个数分别代表 a[i]，b[i]。
输出：输出一行一个数，表示最少需要的总额，保留两位小数。

试补全程序。

```C++
#include <cstdio>
#include <cstdlib>
using namespace std;

const int Inf = 1000000000;
const int threshold = 50000;
const int maxn = 1000;

int n, a[maxn], b[maxn];
bool put_a[maxn];
int total_a, total_b;

double ans;
int f[threshold];

int main() {
    scanf("%d", &n);
    total_a = total_b = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", a + i, b + i);
        if (a[i] <= b[i]) total_a += a[i];
        else total_b += b[i];
    }
    ans = total_a + total_b;
    total_a = total_b = 0;
    for (int i = 0; i < n; ++i) {
        if (______________) {
            put_a[i] = true;
            total_a += a[i];
        } else {
            put_a[i] = false;
            total_b += b[i];
        }
    }
    if ( _______________ ) {
        printf("%.2f", total_a * 0.95 + total_b);
        return 0;
    }
    f[0] = 0;
    for (int i = 1; i < threshold; ++i)
        f[i] = Inf;
    int total_b_prefix = 0;
    for (int i = 0; i < n; ++i)
        if (!put_a[i]) {
            total_b_prefix += b[i];
            for (int j = threshold - 1; j >= 0; --j) {
                if ( ____________ >= threshold && f[j] != Inf)
                    ans = min(ans, (total_a + j + a[i]) * 0.95 +___________);
                f[j] = min(f[j] + b[i], j >= a[i] ? _________________: Inf);
            }
        }
    printf("%.2f", ans);
    return 0;
}
```

---


（快速幂） 请完善下面的程序，该程序使用分治法求$x^p mod m$ 的值。（第一空 2 分，其余 3 分）

输入：三个不超过 10000 的正整数 x，p，m。
输出：$x^p mod m $的值。
提示：若 $p$ 为偶数，$x^p=(x^2) ^{p/2}$；若 p 为奇数，$ x^p = x * (x^2) ^{ (p-1)/2 } $

```C++
#include<iostream>
using namespace std;
int x, p, m, i, result;
int main(){
	cin >> x >> p >> m;
	result = ________________;
	while (_____________________){
		if (p % 2 == 1)
			result = _________________;
		p /= 2;
		x = _______________;
	}
	cout << __________________ << endl;
	return 0;
}
```

---

（切割绳子） 有 n 条绳子，每条绳子的长度已知且均为正整数。绳子可以以任意正整数长度切割，但不可以连接。现在要从这些绳子中切割出 m 条长度相同的绳段，求绳段的最大长度是多少。（第一、二空 2.5 分，其余 3 分）

输入：第一行是一个不超过 100 的正整数 n，第二行是 n 个不超过$10^{6}$的正整数，表示每条绳子的长度，第三行是一个不超过$10^8$的正整数 m。 输出：绳段的最大长度，若无法切割，输出 Failed。

```C++
#include<iostream>
using namespace std;
int n, m, i, lbound, ubound, mid, count;
int len[100]; // 绳子长度
int main(){
    cin >> n;
    count = 0;
    for (i = 0; i < n; i++){
        cin >> len[i];
        _________________________;
    }
    cin >> m;
    if (________________________){
        cout << "Failed" << endl;
        return 0;
    }
    lbound = 1;
    ubound = 1000000;
    while (_______________________){
        mid = __________________;
        count = 0;
        for (i = 0; i < n; i++)
            ___________________;
        if (count < m) ubound = mid - 1;
        else lbound = mid;
    }
    cout << lbound << endl;
    return 0;
}
```

---

（大整数除法）给定两个正整数p和q，其中p不超过$10^{100}$， q不超过100000， 求 p 除以 q 的商和余数。（第一空 2 分，其余 3 分） 输入：第一行是 p 的位数 n，第二行是正整数 p，第三行是正整数 q。 输出：两行，分别是 p 除以 q 的商和余数。

```C++
#include <iostream>
using namespace std;
int p[100];
int n, i, q, rest;
char c;
int main(){
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> c;
        p[i] = c - '0';
    }
    cin >> q;
    rest = ____________________;
    i = 1;
    while (________________ && i < n){
        rest = rest * 10 + p[i];
        i++;
    }
    if (rest < q) cout << 0 << endl;
    else{
        cout << _____________________;
        while (i < n){
            rest = ____________________;
            i++;
            cout << rest / q;
        }
        cout << endl;
    }
    cout << ____________________ << endl;
    return 0;
}
```

---

（最长路径）给定一个有向无环图，每条边长度为 1，求图中的最长路径长度。（第五空 2 分，其余 3 分） 输入：第一行是结点数 n（不超过 100）和边数 m，接下来 m 行，每行两个整数 a， b，表示从结点 a 到结点 b 有一条有向边。结点标号从 0 到(n-1)。 输出：最长路径长度。 提示：先进行拓扑排序，然后按照拓扑序计算最长路径。


```C++
#include <iostream>
using namespace std;
int n, m, i, j, a, b, head, tail, ans;
int graph[100][100]; // 用邻接矩阵存储图
int degree[100];     // 记录每个结点的入度
int len[100];        // 记录以各结点为终点的最长路径长度
int queue[100];      // 存放拓扑排序结果
int main(){
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = 0;
    for (i = 0; i < n; i++)
        degree[i] = 0;
    for (i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b] = 1;
        _________________________;
    }
    tail = 0;
    for (i = 0; i < n; i++)
        if (________________________){
            queue[tail] = i;
            tail++;
        }
    head = 0;
    while (tail < n - 1){
        for (i = 0; i < n; i++)
            if (graph[queue[head]][i] == 1){
                _______________________;
                if (degree[i] == 0){
                    queue[tail] = i;
                    tail++;
                }
            }
        ________________________;
    }
    ans = 0;
    for (i = 0; i < n; i++){
        a = queue[i];
        len[a] = 1;
        for (j = 0; j < n; j++)
            if (graph[j][a] == 1 && len[j] + 1 > len[a])
                len[a] = len[j] + 1;
        if (______________________)
            ans = len[a];
    }
    cout << ans << endl;
    return 0;
}
```

---
读入整数。请完善下面的程序，使得程序能够读入两个 int 范围内的整数， 并将这两个整数分别输出，每行一个。（第一、五空 2.5 分，其余 3 分）
输入的整数之间和前后只会出现空格或者回车。输入数据保证合法。
例如：
输入：
123 -789
输出： 132
-789

```C++
#include <iostream>
using namespace std;

int readint(){
	int num = 0;	      // 存储读取到的整数
	int negative = 0;    // 负数标识
	char c;	              // 存储当前读取到的字符
	c = cin.get();
	while ((c < '0' || c > '9') && c != '-')
		c = __________________;
	if (c == '-') negative = 1;
	else _____________________;
	c = cin.get();
	while (___________________){
		_________________;
		c = cin.get();
	}
	if (negative == 1) _____________________;
	return num;
}
int main(){
	int a, b;
	a = readint();
	b = readint();
	cout << a << endl << b << endl;
	return 0;
}
```

---

（郊游活动）有 n 名同学参加学校组织的郊游活动，已知学校给这 n 名同学 的郊游总经费为 A 元，与此同时第 i 位同学自己携带了 Mi 元。为了方便郊 游，活动地点提供 B(≥n)辆自行车供人租用，租用第 j 辆自行车的价格为 Cj 元，每位同学可以使用自己携带的钱或者学校的郊游经费，为了方便账务管 理，每位同学只能为自己租用自行车，且不会借钱给他人，他们想知道最多 有多少位同学能够租用到自行车。（第四、五空 2.5 分，其余 3 分）
本题采用二分法。对于区间[l, r]，我们取中间点 mid 并判断租用到自行 车的人数能否达到 mid。判断的过程是利用贪心算法实现的。

```C++
#include <iostream>
using namespace std;
#define MAXN 1000000

int n, B, A, M[MAXN], C[MAXN], l, r, ans, mid;

bool check(int nn) {
	int count = 0, i, j;
	i = ____________________;
	j = 1;
	while (i <= n) {
		if(______________)
			count += C[j] - M[i];
		i++;
		j++;
	}
	return ___________________;
}
	
void sort(int a[], int l, int r) {
	int i = l, j = r, x = a[(l + r) / 2], y;
	while (i <= j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			y = a[i]; a[i] = a[j]; a[j] = y;
			i++; j--;
		}
	}
if (i < r) sort(a, i, r);
if (l < j) sort(a, l, j);
}

int main() {
	int i;
	cin >> n >> B >> A;
	for (i = 1; i <= n; i++)
		cin >> M[i];
	for (i = 1; i <= B; i++)
		cin >> C[i];
	sort(M, 1, n);
	sort(C, 1, B);
	l = 0;
	r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if(_________________){
            ans = mid;
			l = mid + 1;
		}else
			r = ___________________;
	}
	cout << ans << endl;
	return 0;
}
```

---

（交朋友）根据社会学研究表明，人们都喜欢找和自己身高相近的人做朋友。现在有 n 名身高两两不相同的同学依次走入教室，调查人员想预测每个人在 走入教室的瞬间最想和已经进入教室的哪个人做朋友。当有两名同学和这名 同学的身高差一样时，这名同学会更想和高的那个人做朋友。比如一名身高为 1.80 米的同学进入教室时，有一名身高为 1.79 米的同学和一名身高为1.81米的同学在教室里，那么这名身高为 1.80 米的同学会更想和身高为 1.81 米的同学做朋友。对于第一个走入教室的同学我们不做预测。由于我们知道所有人的身高和走进教室的次序，所以我们可以采用离线的做法来解决这样的问题，我们用排序加链表的方式帮助每一个人找到在他之前进入教室的并且和他身高最相近的人。（第一空 2 分，其余 3 分）

```C++
#include <iostream> 
using namespace std; 
#define MAXN 200000
#define infinity 2147483647
int answer[MAXN], height[MAXN], previous[MAXN], next[MAXN];
int rank[MAXN];
int n;
void sort(int l, int r){
    int x = height[rank[(l + r) / 2]], i = l, j = r, temp;
    while (i <= j){
        while (height[rank[i]] < x) i++;
        while (height[rank[j]] > x) j--;
        if ((____________________)){
            temp = rank[i];
            rank[i] = rank[j];
            rank[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r) sort(i, r);
    if (l < j) sort(l, j);
}
int main(){
    cin >> n;
    int i, higher, shorter;
    for (i = 1; i <= n; i++){
        cin >> height[i];
        rank[i] = i;
	}
	sort(1, n);
	for (i = 1; i <= n; i++){
		previous[rank[i]] = rank[i - 1];
		(__________________);
	}
	for (i = n; i >= 2; i--){
		higher = shorter = infinity;
		if (previous[i] != 0)
			shorter = height[i] - height[previous[i]];
		if (next[i] != 0) (____________________);
		if ((____________________)) answer[i] = previous[i];
		else answer[i] = next[i];
		next[previous[i]] = next[i];
		(______________________);
	}
	for (i = 2; i <= n; i++)
		cout << i << ":" << answer[i];
	return 0;
}
```

---


(交通中断）有一个小国家，国家内有 n 座城市和 m 条双向的道路，每条道路连接着两座不同的城市。其中 1 号城市为国家的首都。由于地震频繁可能导致某一个城市与外界交通全部中断。这个国家的首脑想知道，如果只有第i(i>1)个城市因地震而导致交通中断时，首都到多少个城市的最短路径长度会发生改变。如果因为无法通过第 i 个城市而导致从首都出发无法到达某个城市，也认为到达该城市的最短路径长度改变。 对于每一个城市 i，假定只有第 i 个城市与外界交通中断，输出有多少个 城市会因此导致到首都的最短路径长度改变。 我们采用邻接表的方式存储图的信息，其中 head[x]表示顶点 x 的第一条 边的编号，next[i]表示第 i 条边的下一条边的编号，point[i]表示第 i 条边的终点，weight[i]表示第 i 条边的长度。（第一空 2 分，其余 3 分）

```C++
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 6000
#define MAXM 100000
#define infinity 2147483647
int head[MAXN], next[MAXM], point[MAXM], weight[MAXM];
int queue[MAXN], dist[MAXN], visit[MAXN];
int n, m, x, y, z, total = 0, answer;
void link(int x, int y, int z){
    total++;
    next[total] = head[x];
    head[x] = total;
    point[total] = y;
    weight[total] = z;
    total++;
    next[total] = head[y];
    head[y] = total;
    point[total] = x;
    weight[total] = z;
}
int main(){
    int i, j, s, t;
    cin >> n >> m;
    for (i = 1; i <= m; i++){
        cin >> x >> y >> z;
        link(x, y, z);
    }
    for (i = 1; i <= n; i++)
        dist[i] = infinity;
    ________________________;
    queue[1] = 1;
    visit[1] = 1;
    s = 1;
    t = 1;
    // 使用 SPFA 求出第一个点到其余各点的最短路长度
    while (s <= t){
        x = queue[s % MAXN];
        j = head[x];
        while (j != 0){
            if (______________________){
                dist[point[j]] = dist[x] + weight[j];
                if (visit[point[j]] == 0){
                    t++;
                    queue[t % MAXN] = point[j];
                    visit[point[j]] = 1;
                }
            }
            j = next[j];
        }
        _________________________;
        s++;
    }
    for (i = 2; i <= n; i++){
        queue[1] = 1;
        memset(visit, 0, sizeof(visit));
        visit[1] = 1;
        s = 1;
        t = 1;
        while (s <= t){ // 判断最短路长度是否不变
            x = queue[s];
            j = head[x];
            while (j != 0){
                if (point[j] != i && ___________________ && visit[point[j]] == 0){
                    _________________________;
                    t++;
                    queue[t] = point[j];
                }
                j = next[j];
            }
            s++;
        }
        answer = 0;
        for (j = 1; j <= n; j++)
            answer += 1 - visit[j];
        cout << i << ":" << answer - 1 << endl;
    }
    return 0;
}
```