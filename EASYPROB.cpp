#include<iostream>
#include<string>
#include<cmath>

using namespace std;

#define LOG(a, b) log(a)/log(b)

void str_represent(int n, string& res);

int main(){

	int arr[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int n: arr){
		string res;
		str_represent(n, res);
		cout<<n<<"="<<res<<endl;
	}
	return 0;
}

void str_represent(int n, string& res){	
	while(n){
		int p = LOG(n, 2);
		if(n == 1){
			res += "2(0)";
		}
		else if(n <= 3){
			res += "2";
		}
		else if(n > 3){
			res += "2(";
			str_represent(p, res);
			res += ")";
		}
		n = n - pow(2, p);
		if(n)
			res += "+";

	}
}