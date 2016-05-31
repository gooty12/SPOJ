#include<iostream>
#include<stack>

using namespace std;

int main(){

	int k = 1;
	while(1){
		string s;
		getline(cin, s);
		if(s[0] == '-'){
			break;
		}
		stack<char> st;
		int op = 0;
		for(char c: s){
			if(c == '}'){
				if(st.empty()){
					op++;
					st.push('{');
				}
				else{
					st.pop();
				}
			}
			else{
				st.push(c);
			}
		}

		op = op+(st.size()/2);

		cout<<k<<". "<<op<<endl;
		k++;
	}
	return 0;
}