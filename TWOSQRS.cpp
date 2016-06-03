#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

int main(){

	int C;
	cin>>C;
	while(C--){
		ll N;
		cin>>N;
		int is_possible = 0;
		int L = ceil(sqrt(N/2.0));
		for(int a=0; a<=L; a++){
			int b = N-a*a;
			double s = sqrt(b*1.0);
			if(trunc(s) == s){
				is_possible = 1;
				break;
			}
		}

		if(is_possible){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}