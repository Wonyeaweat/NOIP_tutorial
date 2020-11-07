#include <bits/stdc++.h>
using namespace std;
int rand_32()
{
	return (rand()&0x3)<<30 | rand()<<15 | rand();
}
int main() {
	freopen("10.in","w",stdout); 
	srand(time(NULL));
	int n=95871;
	cout<<n<<endl;
	for(int x=0;x<n;x++){
		int a=rand_32();
		printf("%d ",a);
	}
	return 0;
}

