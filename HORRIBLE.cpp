#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, long> pii;

#define pb push_back

int main(){

	ll T;
	cin>>T;

	while(T--){
		ll N, C;
		cin>>N>>C;
		vector<ll> v(N+1, 0);
		vector< pair<int, pii> > queries_0;
		vector<pii> queries_1;

		for(ll i=0; i<C; i++){
			ll type;
			cin>>type;
			ll p, q;
			cin>>p>>q;
			if(type==1){
				queries_1.pb(pii(p, q));
			}
			else{
				long long val;
				cin>>val;
				queries_0.pb(pair<int, pii>(p, pii(0, val)));
				queries_0.pb(pair<int, pii>(q, pii(1, val)));
			}
		}

		sort(queries_0.begin(), queries_0.end());

		if(!queries_0.empty()){
			auto it = queries_0.begin();
			ll start = (*it).first;
			ll sum = (*it).second.second;
			it++;
			ll end = (*it).first;
			while(1){
				for(ll i=start; i<end; i++){
					v[i] += sum;
					//cout<<"value at "<<i<<" is "<<v[i]<<endl;
				}
				
				it++;
				if(it == queries_0.end()){
					v[end] += sum;
					break;
				}
				else{
					start = end;
					
					ll ptype = (*(it-1)).second.first;
					if(ptype == 1){
						v[end] += (*(it-1)).second.second;
						sum -= (*(it-1)).second.second;
					}
					else{
						sum += (*(it-1)).second.second;
					}
					end = (*it).first;
					//cout<<"Start and end, sum are "<<start<<" "<<end<<" "<<sum<<endl;
				}
			}

			for(ll i=1; i<=N; i++){
				v[i] += v[i-1];
			}
		}

		for(auto query: queries_1){
			ll p = query.first;
			ll q = query.second;
			cout<<v[q]-v[p-1]<<endl;
		}
	}

	return 0;
}