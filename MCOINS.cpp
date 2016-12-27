#include<iostream>
#include<string>

using namespace std;

int main(){

	int K, L, m, N;
	//string str="";
	cin>>K>>L>>m;
	while(m--){
		cin>>N;
		if(N%4 == 0){
			//str += 'B';
			cout<<'B';
		}
		else{
			//str += 'A';
			cout<<'A';
		}
	}

	//cout<<str<<endl;
	return 0;
}