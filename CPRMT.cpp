#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

	string a;
	string b;
	while(cin>>a){
		cin>>b;
		int count[26] ={0};
		for(char c : a){
			count[c-'a']++;
		}
		string x;
		for(char c: b){
			if(count[c-'a']){
				x += c;
				count[c-'a']--;
			}
		}
		sort(x.begin(), x.end());
		cout<<x<<endl;
	}

	return 0;
}