#include<iostream>
#include<string>
#include<cctype>

using namespace std;

#define is_underscore(c) (c) == '_'

int main(){

	string s;
	while(cin>>s){
		int is_java = 0, is_cplusplus = 0, is_neither = 0;
		if(!islower(s[0])){
			cout<<"Error!"<<endl;
			continue;
		}
		int sz = s.size();
		int i;
		for(i=1; i<sz; i++){
			if(is_underscore(s[i])){
				is_cplusplus = 1;
				break;
			}
			else if(isupper(s[i])){
				is_java = 1;
				break;
			}
			else if(!(isalpha(s[i]))){
				is_neither = 1;
				break;
			}
		}

		if(is_neither){
			cout<<"Error!"<<endl;
			continue;
		}
		else if(i == sz){
			cout<<s<<endl;
			continue;
		}
		else{
			
			if(is_cplusplus){
				for(; i<sz-1; i++){
					if(!islower(s[i])){
						if(is_underscore(s[i]) && islower(s[i+1])){
							i++;
							continue;
						}
						is_cplusplus = 0;
						//cout<<"char is "<<s[i+1]<<endl;
						break;
					}
				}

				if(!is_cplusplus || !islower(s[sz-1])){
					cout<<"Error!"<<endl;
					continue;
				}
			}
			else{
				for(; i<sz; i++){
					if(!isalpha(s[i])){
						is_java = 0;
						break;
					}
				}
				if(!is_java){
					cout<<"Error!"<<endl;
					continue;
				}

			}

			if(is_cplusplus){
				for(int i=0; i<sz-1; i++){
					if(is_underscore(s[i])){
						s[i+1] = toupper(s[i+1]);
						s.erase(i, 1);
						sz--;
					}
				}
			}
			else{
				for(int i=0; i<sz; i++){
					if(isupper(s[i])){
						s[i] = tolower(s[i]);
						s.insert(i, 1, '_');
						sz++;
					}
				}
			}

			cout<<s<<endl;
		}
	}

	return 0;
}