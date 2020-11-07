#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	int level = 0, days_of_level = 0;
	int tot = 0;
	while(n--){
		if(++days_of_level > level) {
			level++;
			days_of_level = 1;
		}
		tot += level;
	}
	printf("%d\n", tot);
}
