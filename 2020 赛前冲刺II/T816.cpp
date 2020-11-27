#include<cstdio>
#include<iostream>
using namespace std;
long long n,m;
long long st[61]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648ll,4294967296ll,8589934592ll,17179869184ll,34359738368ll,68719476736ll,137438953472ll,274877906944ll,549755813888ll,1099511627776ll,2199023255552ll,4398046511104ll,8796093022208ll,17592186044416ll,35184372088832ll,70368744177664ll,140737488355328ll,281474976710656ll,562949953421312ll,1125899906842624ll,2251799813685248ll,4503599627370496ll,9007199254740992ll,18014398509481984ll,36028797018963968ll,72057594037927936ll,144115188075855872ll,288230376151711744ll,576460752303423488ll,1152921504606846976ll};
int d(int k,long long x,long long y)
{
	if(k==1) 
	{
		if(x==1&&y==1) return 1;
		if(x==1&&y==2) return 2;
		if(x==2&&y==1) return 3; 
	}	
	long long m=st[k-1];
	long long r=st[k];
	if(x==1&&y==m) return 1;
	if(x==m&&y==m+1) return 2;
	if(x==r&&y==m+1) return 3;
	if(x>=1&&x<=m&&y>=1&&y<=m)
	{
		long long xx=m-y+1;
		long long yy=x;
		xx=m-xx+1;
		long long t=d(k-1,xx,yy);
		if(t==2) t=4;
		else if(t==4) t=2;
		t++;
		if(t==5) t=1;
		return t;
	}
	if(x>m&&x<=r&&y>=1&&y<=m)
	{
		long long xx=y;
		long long yy=r-x+1;
		xx=m-xx+1;
		long long t=d(k-1,xx,yy);
		if(t==2) t=4;
		else if(t==4) t=2;
		t--;
		if(t==0) t=4;
		return t;
	}
	if(x>=1&&x<=m&&y>m&&y<=r)	return d(k-1,x,y-m); 
	if(x>m&&x<=r&&y>m&&y<=r)	return d(k-1,x-m,y-m);
}
int main()
{
	long long n,m,x,y;
	while(scanf("%d %d",&n,&m))
	{
		if(m==0) break;
		for(int i=1;i<=m;i++)
		{	
			scanf("%lld %lld",&x,&y);
			long long t=d(n,x,y);
			if(t==1) printf("Up\n");
			else if(t==2) printf("Right\n");
			else if(t==3) printf("Down\n");
			else if(t==4) printf("Left\n");
		}
    }
	return 0;
} 
