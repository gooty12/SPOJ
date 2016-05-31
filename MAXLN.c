#include<stdio.h>

int main(){
	int t;
	double r;
	int i=1;
	scanf("%d", &t);
	while(t--){
		scanf("%lf", &r);
		printf("Case %d: %.2lf\n", i++, 0.25+4*r*r);
	}
	return 0;
}
