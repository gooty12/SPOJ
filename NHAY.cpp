#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

void calculate_partial_match(vector<int>& partial_match, 
								const string& pattern, int n);
const int BUF_SIZE = 1000000;

int main(){


	string s(BUF_SIZE, 0);
	string pattern;
	long long len = 0;
	long long j=0;
	long long num_test_cases = 0;
	long long n;
	vector<int> partial_match;
	while(cin>>s){
		if(isdigit(s[0])){
			if(num_test_cases != 0){
				cout<<endl;
			}
			num_test_cases++;
			n = stoll(s);
			//cout<<n<<endl;
			partial_match = vector<int>(n+1, 0);
			cin>>pattern;
			//cout<<pattern<<endl;
			calculate_partial_match(partial_match, pattern, n);
			len = 0;
			j = 0;
		}
		else{
			int sz = s.size();
			//cout<<"size is "<<sz<<endl;
			for(long long i=0; ;){
				if(i==sz){
					break;
				}
				else{
					if(s[i] == pattern[j]){
						i++;
						j++;
						if(j == n){
							cout<<(len+i -n)<<endl;
						}
					}
					else if(j>0){
						j = partial_match[j];
					}
					else{
						i++;
					}
				}
			}
			len += sz;

		}

	}
		
	return 0;
}

void calculate_partial_match(vector<int>& partial_match, 
								const string& pattern, int n){

	for(int i=2; i<=n; i++){
		int j = partial_match[i-1];
		for(; ;){
			if(pattern[j] == pattern[i-1]){
				partial_match[i] = j+1;
				break;
			}
			else if(j==0){
				partial_match[i] = 0;
				break;
			}
			else{
				j = partial_match[j];
			}
		}
		//cout<<partial_match[i];
	}

}