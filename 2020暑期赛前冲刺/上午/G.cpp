#include<cstdio>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100100;

int in[maxn], out[maxn];
int main()
{
	int q, n;
	scanf("%d", &q);
	while (q--)
	{
		stack<int> sta;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &in[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &out[i]);
		
		int A = 1, B = 1;
		bool ok=true;
		while (B <= n)
		{
			if (in[A] == out[B]) {A++; B++;}
			else if (!sta.empty() && sta.top() == out[B]) {sta.pop(); B++;}
			else if (A <= n) sta.push(in[A++]);
			else {ok = false; break;}
		}
		if (ok) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

