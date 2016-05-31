#include<iostream>
#include<cstring>

using namespace std;
const int MAX_LEN = 101;

int main(){
	char N[MAX_LEN+1];
	while(cin>>N){
		int len = strlen(N);
		if(len==1 && (N[0]=='0' || N[0]=='1')){
			cout<<N<<endl;
			continue;
		}
		//sub
		for(int i=len-1; i>=0; i--){
			if(N[i] == '0'){
				N[i] = '9';
			}
			else{
				N[i] = '0' + (N[i]-'1');
				break;
			}
		}
		//mul
		int borrow = 0;
		for(int i=len-1; i>=0; i--){
			int d = N[i]-'0';
			d = 2*d + borrow;
			N[i] = '0' + d%10;
			d /= 10;
			borrow = d%10;
		}
		if(borrow){
			char ch = '0' + borrow;
			cout<<ch;
		}
		cout<<N<<endl;

	}
	return 0;
}