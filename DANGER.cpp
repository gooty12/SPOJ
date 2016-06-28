#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#define LOG(A, B) log(A)/log(B)

int main(){

	string str;
	while(1){
		cin>>str;
		if(str == "00e0"){
			break;
		}
		int n = 0;
		n += str[1]-'0';
		n += (str[0]-'0')*10;
		int p = str[3]-'0';
		n = n*pow(10, p);

		if(n<=2){
			cout<<1<<endl;
		}
		else{
			int p = LOG(n, 2);
			int m = pow(2, p);
			if(n%2 == 1){
				m++;
				int d = (n-m)/2;
				cout<<3+4*d<<endl;
			}
			else{
				int d = (n-m)/2;
				cout<<1+4*d<<endl;
			}
		}
	}

	return 0;
}