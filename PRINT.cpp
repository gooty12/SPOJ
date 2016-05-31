#include<iostream>
#include<limits>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<cmath>

int* sieve(int);
int no_of_primes = 0;

using namespace std;
const int N = 2147483647;

int main(){
	int t;
	
	int* primes;
	primes = sieve(ceil(sqrt(N)));
	//sieve(1000000);
	//cout<<no_of_primes<<endl;
	//exit(0);
	cin>>t;

	while(t--){
		int m, n;
		//cin>>m>>n;
		scanf("%d %d", &m, &n);

		list<int> primes_mn;
		if(m==1)
			m++;
		
		if(m==2 && m<=n){
			primes_mn.push_back(2);
		}
		
		if(m%2 == 0)
			m++;
		for(int i=m; i<=n; i+=2)
			primes_mn.push_back(i);

		int max_prime_factor = ceil(sqrt(n));
		for(int i=0; i<no_of_primes && primes[i]<=max_prime_factor; i++){
			//cout<<"i is "<<i<<endl;
			for (auto it = primes_mn.begin(); it != primes_mn.end(); ){
				//cout<<*it<<endl;
				if( *it != primes[i] && (*it)%primes[i] == 0){
					it = primes_mn.erase(it);
					//cout<<"erased "<<*it<<endl;
					//it++;
				}
				else
					++it;
			}
			
			/*list<int>::iterator it = primes_mn.begin();
			while(it != primes_mn.end()){
				if (*it != primes[i] && (*it)%primes[i]==0){
					it = primes_mn.erase(it);
				}
				else{
					it++;
				}
			}*/
		}
		//exit(0);

		for(list<int>::iterator it= primes_mn.begin(); it != primes_mn.end(); it++){
			//cout<<*it<<endl;
			printf("%d\n", *it);
		}

		//cout<<endl;

	}
	free(primes);
	return 0;
}

int* sieve(int N){
	
	if (N<=1){
		return NULL;
	}
	
	int* primes = (int*)calloc(N+1, sizeof(int));
	no_of_primes = 1;
	for(int next_prime=3; next_prime<=N ; ){
		//int tmp;
		if(!primes[next_prime] && next_prime%2)
			no_of_primes++;

		for( int i = 3; next_prime*i <= N; i+=2){
				primes[next_prime*i] = 1;
		}

		next_prime+=2;

		while(next_prime<=N && primes[next_prime]){
			next_prime+=2;
		}
		//cout<<next_prime<<endl;
	}

	int* p_primes = (int*)malloc(sizeof(int)*no_of_primes); 
	int ind=0;
	p_primes[ind++]=2;
	for(int i=3; i<=N; i+=2){
		if(primes[i] == 0)
			p_primes[ind++]=i;
	}

	free(primes);
	return p_primes;

}