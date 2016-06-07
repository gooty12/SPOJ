#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int Rep(int n, vi& rep);

int main(){

	int t;
	int N;
	int C;
	
	//cin>>t;
	scanf("%d", &t);
	int T = 1;
	while(t--){
		//cin>>N>>C;
		scanf("%d %d", &N, &C);
		vi rep(N+1, 0);
		vi sex(N+1);
		vi counterpart(N+1);

		int a, b, is_suspicious = 0;
		if(C>0){
			//cin>>a>>b;
			scanf("%d %d", &a, &b);
			sex[min(a, b)] = 0;
			sex[max(a, b)] = 1;
			counterpart[a] = b;
			counterpart[b] = a;
			rep[a] = a;
			rep[b] = b;
			C--;
		}

		while(C--){
			//cout<<C<<endl;
			//cin>>a>>b;
			scanf("%d %d", &a, &b);
			if(is_suspicious){
				continue;
			}
			int rep_a = Rep(a, rep);
			int rep_b = Rep(b, rep);
			int sex_a = sex[rep_a];
			int sex_b = sex[rep_b];

			//cout<<a<<b<<rep_a<<rep_b<<endl;
			//case-1
			if(rep_a && rep_b){
				//same reps==> sex
				if(rep_a == rep_b){
					is_suspicious = 1;
					continue;
				}
				else{
					if(sex_a<=1 && sex_b<=1){
						continue;
					}

					int is_same_sex;
					
					/***** Is same sex***/
					if(sex_a==sex_b || abs(sex_a-sex_b)==2){
						is_same_sex = 1;
					}
					else{
						is_same_sex = 0;
					}
					
					/******End of is_same_sex()***/
					
					int m1 = min(rep_a, counterpart[rep_a]);
					int f1 = max(rep_a, counterpart[rep_a]);

					int m2 = min(rep_b, counterpart[rep_b]);
					int f2 = max(rep_b, counterpart[rep_b]);

					int rep_new_m;
					if(sex_a<=1){
						rep_new_m = m1;
					}
					else if(sex_b<=1){
						rep_new_m = m2;
					}
					else{
						if(m1+f1 < m2+f2){
							rep_new_m = m1;
						}
						else if (m1+f1 > m2+f2){
							rep_new_m = m2;
						}
						else{
							if(m1<m2){
								rep_new_m = m1;
							}
							else{
								rep_new_m = m2;
							}
						}
					}
					
					/**find new rep***/

					/**Union**/
					
					/***Cross-Align***/
					
					if(is_same_sex){
						if(rep_new_m == m1){
							rep[m2] = f1;
							rep[f2] = m1;
						}
						else{
							rep[m1] = f2;
							rep[f1] = m2;
						}
					}/***End of Cross-Align**/
					else{
						if(rep_new_m == m1){
							rep[m2] = m1;
							rep[f2] = f1;
						}
						else{
							rep[m1] = m2;
							rep[f1] = f2;
						}
					}

					/**End of union**/

					/**End of find new rep**/
				}//different reps/sex

			}//case-1
			else if(rep_a){
				//cout<<"In rep_a "<<a<<b<<rep_a<<rep_b<<endl;
				rep[b] = counterpart[rep_a];

			}
			else if(rep_b){
				rep[a] = counterpart[rep_b];
			}
			else{
				if(a < b){
					sex[a] = 2;
					sex[b] = 3;
				}
				else{
					sex[a] = 3;
					sex[b] = 2;
				}
				counterpart[a] = b;
				counterpart[b] = a;
				rep[a] = a;
				rep[b] = b;
			}
		}

		//cout<<"Scenario #"<<T<<":"<<endl;
		printf("Scenario #%d:\n", T);
		T++;
		if(is_suspicious){
			//cout<<"Suspicious bugs found!"<<endl;
			printf("Suspicious bugs found!\n");
		}
		else{
			printf("No suspicious bugs found!\n");
			//cout<<"No suspicious bugs found!"<<endl;
		}

		/*for(int r: rep){
			cout<<r<<endl;
		}*/


	}


	return 0;
}

int Rep(int n, vi& rep){

	int tmp = n;
	while(n != rep[n]){
		n = rep[n];
	}

	//cout<<"rep of "<<tmp<<" is "<<n<<endl;

	return n;

}