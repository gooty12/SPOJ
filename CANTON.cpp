#include<iostream>
#include<cmath>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int n = pow(2.0*N, 0.5);
		while(n*(n+1) <= 2*N){
			n++;
		}
		n--;
		//cout<<n<<endl;;
		int b = N - (n*(n+1))/2;
		int num, den;
		if(b==0){
			if(n%2){
				num = 1;
				den = n;
			}
			else{
				num = n;
				den = 1;
			}
		}
		else if(n%2){
			num = 1 + (b-1);
			den = (n+1) - (b-1);

		}
		else{
			num = (n+1) - (b-1);
			den = 1 + (b-1);
		}
		cout<<"TERM "<< N<< " IS "<<num<<"/"<<den<<endl;

	}
	return 0;
}