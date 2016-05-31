#include<cstdio>

using namespace std;

int main(){

	double L;
	const double PI = 3.141592;
	while(1){
		//cout << setprecision (2) << diff << endl;
		scanf("%lf", &L);
		if(L == 0)
			break;
		
		printf("PI is %-08.2f\n", 10.0345);
		printf("%.2lf\n", (L*L)/(2*PI));

	}
	return 0;
}