# 初赛资料与真题模拟 · 读程序写结果

```C++
#include <stdio.h>
char st[100];

int main() {
	scanf("%s", st);
	for (int i = 0; st[i]; ++i) {
		if (‘A’ <= st[i] && st[i] <= ‘Z’) st[i] += 1;
	}
	printf("%s\n", st);
	return 0;
}
```

+ 输入：QuanGuoLianSai
+ 输出：

---

```C++
#include <stdio.h>
int main() {
	int x;
    scanf("%d", &x);
    int res = 0;
    for (int i = 0; i < x; ++i) {
      	if (i * i % x == 1) {
      		++res;
      	}
    }
    printf("%d", res);
    return 0;
}
```

+ 输入：15
+ 输出：


---

```C++
#include <iostream>
using namespace std;
int n, m;

int findans(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n % 3;
    return findans(n - 1, m) - findans(n, m - 1) + findans(n - 1, m - 1);
}

int main(){
    cin >> n >> m;
    cout << findans(n, m) << endl;
    return 0;
}
```

+ 输入：5 6
+ 输出：

---

```C++
#include <stdio.h>
int n, d[100];
bool v[100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", d + i);
        v[i] = false;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
        	for (int j = i; !v[j]; j = d[j]) {
        		v[j] = true;
        	}
        	++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
```

+ 输入：10 7 1 4 3 2 5 9 8 0 6
+ 输出：

---

```C++
#include <iostream>
using namespace std;
string s;

long long magic(int l, int r) {
    long long ans = 0;
        for (int i = l; i <= r; ++i) {
        ans = ans * 4 + s[i] - ‘a’ + 1;
    }
return ans;
}

int main() {
    cin >> s;
    int len = s.length();
    int ans = 0;
    for (int l1 = 0; l1 < len; ++l1) {
        for (int r1 = l1; r1 < len; ++r1) {
            bool bo = true;
            for (int l2 = 0; l2 < len; ++l2) {
                for (int r2 = l2; r2 < len; ++r2) {
                    if (magic(l1, r1) == magic(l2, r2) 
                    	&& (l1 != l2 || r1 != r2)) 
                    	bo = false;
                }
            }
            
            if (bo) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
```

+ 输入：abacaba
+ 输出：


---


```C++
#include <iostream>
using namespace std;
const int N = 110;
bool isUse[N];
int n, t;
int a[N], b[N];
bool isSmall() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i]) return a[i] < b[i];
    return false;
}
bool getPermutation(int pos) {
    if (pos > n) {
        return isSmall();
    }
    for (int i = 1; i <= n; ++i) {
        if (!isUse[i]) {
            b[pos] = i; isUse[i] = true;
            if (getPermutation(pos + 1)) {
                return true;
            }
            isUse[i] = false;
        }
    }
    return false;
}
void getNext() {
    for (int i = 1; i <= n; ++i) {
        isUse[i] = false;
    }
    getPermutation(1);
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i];
    }

}
int main() {
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= t; ++i) {
        getNext();
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d", a[i]);
        if (i == n) putchar(’\n’); else putchar(’ ');
    }
    return 0;
}
```
+ 输入1：6 10 1 6 4 5 3 2
+ 输出1：
+ 输入2：6 200 1 5 3 4 2 6
+ 输出2：

---

```C++
#include<iostream>
using namespace std;
int main()
{
    int t[256];
    string s;
    int i;
    cin >> s;
    for (i = 0; i < 256; i++)
        t[i] = 0;
    for (i = 0; i < s.length(); i++)
        t[s[i]]++;
    for (i = 0; i < s.length(); i++)
        if (t[s[i]] == 1)
        {
            cout << s[i] << endl;
            return 0;
        }
    cout << "no" << endl;
    return 0;
}
```

+ 输入：xyzxyw
+ 输出：

---

```C++
#include<iostream>
using namespace std;
int g(int m, int n, int x)
{
    int ans = 0;
    int i;
    if (n == 1)
        return 1;
    for (i = x; i <= m / n; i++)
        ans += g(m - i, n - 1, i);
    return ans;
}
int main()
{
    int t, m, n;
    cin >> m >> n;
    cout << g(m, n, 0) << endl;
    return 0;
}
```

+ 输入：7 3
+ 输出：


---

```C++
#include<iostream>
using namespace std;
int main()
{
    string ch;
    int a[200];
    int b[200];
    int n, i, t, res;
    cin >> ch;
    n = ch.length();
    for (i = 0; i < 200; i++)
        b[i] = 0;
    for (i = 1; i <= n; i++)
    {
        a[i] = ch[i - 1] - '0';
        b[i] = b[i - 1] + a[i];
    }
    res = b[n];
    t = 0;
    for (i = n; i > 0; i--)
    {
        if (a[i] == 0)
            t++;
        if (b[i - 1] + t < res)
            res = b[i - 1] + t;
    }
    cout << res << endl;
    return 0;
}
```

+ 输入：1001101011001101101011110001
+ 输出：


---

```C++
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int x = 1;
    int y = 1;
    int dx = 1;
    int dy = 1;
    int cnt = 0;
    while (cnt != 2)
    {
        cnt = 0;
        x = x + dx;
        y = y + dy;
        if (x == 1 || x == n)
        {
            ++cnt;
            dx = -dx;
        }
        if (y == 1 || y == m)
        {
            ++cnt;
            dy = -dy;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}
```

+ 输入1：4 3
+ 输出1：
+ 输入2：2017 1014
+ 输出2：
+ 输入3：987 321
+ 输出3：


---



```C++

#include <iostream>
using namespace std;
int main() {
    int n, i, j, x, y, nx, ny;
    int a[40][40];
    for (i = 0; i < 40; i++)
        for (j = 0; j < 40; j++)
            a[i][j] = 0;
    cin >> n;
    y = 0;
    x = n - 1;
    n = 2 * n - 1;
    for (i = 1; i <= n * n; i++) {
        a[y][x] = i;
        ny = (y - 1 + n) % n;
        nx = (x + 1) % n;
        if ((y == 0 && x == n - 1) || a[ny][nx] != 0)
            y = y + 1;
        else {
            y = ny; x = nx;
        }
    }
    for (j = 0; j < n; j++)
        cout << a[0][j] << " ";
    cout << endl;
    return 0;
}
```

+ 输入：3
+ 输出：


---

```C++
#include <iostream>
using namespace std;
int n, s, a[100005], t[100005], i;
void mergesort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    int p = l;
    int i = l;
    int j = mid + 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    while (i <= mid && j <= r)
    {
        if (a[j] < a[i])
        {
            s += mid - i + 1;
            t[p] = a[j];
            p++;
            j++;
        }
        else
        {
            t[p] = a[i];
            p++;
            i++;
        }
    }
    while (i <= mid)
    {
        t[p] = a[i];
        p++;
        i++;
    }
    while (j <= r)
    {
        t[p] = a[j];
        p++;
        j++;
    }
    for (i = l; i <= r; i++)
        a[i] = t[i];
}
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    mergesort(1, n);
    cout << s << endl;
    return 0;
}
```

+ 输入：6 2 6 3 4 5 1
+ 输出：

---


```C++
#include <iostream>
using namespace std;
int main()
{
    int max, min, sum, count = 0;
    int tmp;
    cin >> tmp;
    if (tmp == 0)
        return 0;
    max = min = sum = tmp;
    count++;
    while (tmp != 0)
    {
        cin >> tmp;
        if (tmp != 0)
        {
            sum += tmp;
            count++;
            if (tmp > max)
                max = tmp;
            if (tmp < min)
                min = tmp;
        }
    }
    cout << max << "," << min << "," << sum / count << endl;
    return 0;
}
```

+ 输入：1 2 3 4 5 6 0 7
+ 输出：

---

```C++
#include <iostream>
using namespace std;

int main()
{
	int i = 100, x = 0, y = 0;
	while (i > 0)
	{
		i--;
		x = i % 8;
		if (x == 1)
			y++;
	}
	cout << y << endl;
	return 0;
}
```

+ 输入：无
+ 输出：


---


```C++
#include <iostream>
using namespace std;

int main(){
	int a[6] = {1, 2, 3, 4, 5, 6};
	int pi = 0;
	int pj = 5;
	int t, i;
	while (pi < pj)
	{
		t = a[pi];
		a[pi] = a[pj];
		a[pj] = t;
		pi++;
		pj--;
	}
	for (i = 0; i < 6; i++)
		cout << a[i] << ",";
	cout << endl;
	return 0;
}
```

+ 输入：无
+ 输出：


---

```C++
#include <iostream>
using namespace std;
int main()
{
	int i, length1, length2;
	string s1, s2;
	s1 = "I have a dream.";
	s2 = "I Have A Dream.";
	length1 = s1.size();
	length2 = s2.size();
	for (i = 0; i < length1; i++)
		if (s1[i] >= 'a' && s1[i] <= 'z')
			s1[i] -= 'a' - 'A';
	for (i = 0; i < length2; i++)
		if (s2[i] >= 'a' && s2[i] <= 'z')
			s2[i] -= 'a' - 'A';
	if (s1 == s2)
		cout << "=" << endl;
	else if (s1 > s2)
		cout << ">" << endl;
	else
		cout << "<" << endl;
	return 0;
}
```

+ 输入：无
+ 输出：


---

```C++
#include <iostream> 
using namespace std;
int main()
{
    char a[100][100], b[100][100];
    string c[100];
    string tmp;
    int n, i = 0, j = 0, k = 0, total_len[100], length[100][3];
    cin >> n;
    getline(cin, tmp);
    for (i = 0; i < n; i++)
    {
        getline(cin, c[i]);
        total_len[i] = c[i].size();
    }
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (c[i][j] != ':')
        {
            a[i][k] = c[i][j];
            k = k + 1;
            j++;
        }
        length[i][1] = k - 1;
        a[i][k] = 0;
        k = 0;
        for (j = j + 1; j < total_len[i]; j++)
        {
            b[i][k] = c[i][j];
            k = k + 1;
        }
        length[i][2] = k - 1;
        b[i][k] = 0;
        k = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (length[i][1] >= length[i][2])
            cout << "NO,";
        else
        {
            k = 0;
            for (j = 0; j < length[i][2]; j++)
            {
                if (a[i][k] == b[i][j])
                    k = k + 1;
                if (k > length[i][1])
                    break;
            }
            if (j == length[i][2])
                cout << "NO,";
            else
                cout << "YES,";
        }
    }
    cout << endl;
    return 0;
}
```

+ 输入：
3
AB:ACDEbFBkBD
AR:ACDBrT
SARS:Severe Atypical Respiratory Syndrome
+ 输出：

---

```C++
#include <iostream>
using namespace std;
int lps(string seq, int i, int j)
{
    int len1, len2;
    if (i == j)
        return 1;
    if (i > j)
        return 0;
    if (seq[i] == seq[j])
        return lps(seq, i + 1, j - 1) + 2;
    len1 = lps(seq, i, j - 1);
    len2 = lps(seq, i + 1, j);
    if (len1 > len2)
        return len1;
    return len2;
}
int main()
{
    string seq = "acmerandacm";
    int n = seq.size();
    cout << lps(seq, 0, n - 1) << endl;
    return 0;
}
```

+ 输入：无
+ 输出：

---

```C++
#include <iostream>
#include <cstring>
using namespace std;
int map[100][100];
int sum[100], weight[100];
int visit[100];
int n;
void dfs(int node)
{
    visit[node] = 1;
    sum[node] = 1;
    int v, maxw = 0;
    for (v = 1; v <= n; v++)
    {
        if (!map[node][v] || visit[v])
            continue;
        dfs(v);
        sum[node] += sum[v];
        if (sum[v] > maxw)
            maxw = sum[v];
    }
    if (n - sum[node] > maxw)
        maxw = n - sum[node];
    weight[node] = maxw;
}
int main()
{
    memset(map, 0, sizeof(map));
    memset(sum, 0, sizeof(sum));
    memset(weight, 0, sizeof(weight));
    memset(visit, 0, sizeof(visit));
    cin >> n;
    int i, x, y;
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    dfs(1);
    int ans = n, ansN = 0;
    for (i = 1; i <= n; i++)
        if (weight[i] < ans)
        {
            ans = weight[i];
            ansN = i;
        }
    cout << ansN << " " << ans << endl;
    return 0;
}
```

+ 输入：
11
1 2
1 3
2 4
2 5
2 6
3 7
7 8
7 11
6 9
9 10
+ 输出： 