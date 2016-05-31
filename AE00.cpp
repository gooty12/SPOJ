#include<iostream>

using namespace std;

int main(){

	int N;
	cin>>N;
	int res = 0; 
	for(int len=1; len<=N; len++){
		int max_width = N/len;
		if(max_width<len)
			break;
		res += max_width-len+1;
	}
	cout<<res<<endl; //if WA...remove endl and try
	return 0;
}