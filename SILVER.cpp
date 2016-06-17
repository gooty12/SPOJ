#include<iostream>
#include<cmath>

using namespace std;

int main(){

	int n;
	while(1){
		cin>>n;
		if(n == 0){
			break;
		}
		int res = log(n)/log(2);
		cout<<res<<endl;
	}

	return 0;

}