#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){

	int N;
	int halfs = 0;
	int quarters = 0;
	int three_fourths = 0;
	int res = 1;
	cin>>N;
	for(int i=0; i<N; i++){
		//string s;
		//cin>>s;
		int a, b;
		scanf("%d/%d", &a, &b);
		if(a==1 && b==2){
			halfs++;
		}
		else if(a==1 && b==4){
			quarters++;
		}
		else if(a==3 && b==4){
			three_fourths++;
		}
	}
	
	int m = min(quarters, three_fourths);
	res += m;
	quarters -= m;
	three_fourths -= m;
	res += three_fourths;

	res += halfs/2;
	halfs = halfs%2;

	if(halfs){
		res++;
		quarters -= 2;
	}

	if(quarters > 0){
		res += quarters/4;
		quarters = quarters%4;
		if(quarters)
			res++;
	}

	cout<<res<<endl;
	return 0;
}