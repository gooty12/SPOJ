#include<iostream>
#include<string>
#include<vector>

using namespace std;

int gcd(int a, int b);

int main(){

	int t;
	cin>>t;
	while(t--){
		int a;
		string b;
		cin>>a;
		cin>>b;
		if(a==0){
			cout<<b<<endl;
		}
		else{
			
			vector<int> rems(251);
			rems[0] = 1%a;
			for(int i=1; i<=250; i++){
				rems[i] = (rems[i-1]*10)%a;
			}
			int rem = 0;
			int p=0;
			for(string::reverse_iterator it=b.rbegin(); 
					it!=b.rend(); it++, p++){
				int d = *it - '0';
				rem += (d*rems[p])%a;
			}

			cout<<gcd(a, rem)<<endl;
		}
	}

	return 0;
}

int gcd(int a, int b){

	if(b==0)
		return a;
	else{
		return gcd(b, a%b);
	}
}