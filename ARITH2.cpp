#include<iostream>
#include<string>

using namespace std;
long long  calculate(long long op1, long long op2, char op);

int main(){

	long long t;
	string num;
	getline(cin, num);
	t = stoll(num);
	while(t--){
		string expr;
		string blank_line;
		getline(cin, blank_line);
		getline(cin, expr);
		//cout<<expr<<endl;
		
		long long op1 = -1, op2, val=0;
		char op = 0;
		for(char c: expr){
			if(c>='0' && c<='9'){
				val = val*10 + (c-'0');
			}
			else if(c == ' '){
				continue;
			}
			else{
				if(op1 == -1){
					op1 = val;
					//cout<<val<<endl;
					val = 0;
					if(c != '='){
						op = c;
					}
				}
				else{
					op2 = val;
					//cout<<val<<endl;
					val = 0;
					op1 = calculate(op1, op2, op);
					if(c != '='){
						op = c;
					}
				}
			}
		}
		
		
		cout<<op1<<endl;
		

	}
	return 0;
}

long long  calculate(long long op1, long long op2, char op){
	switch(op){
		case '/':
			return op1/op2;
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
	}
}