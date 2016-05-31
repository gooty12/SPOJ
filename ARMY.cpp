#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
class Greater{
	private:
		T x;
	public:
		Greater(T x){
			this->x = x;
		}
		bool operator()(T y){
			return y>x;
		}
};

int main(){

	int T;
	int NG, NM;
	
	cin>>T;
	while(T--){
		
		cin>>NG>>NM;
		vector<int> Godzilla(NG), MechaGodzilla(NM);
		for(int i=0; i<NG; i++){
			int strength;
			cin>>strength;
			Godzilla.push_back(strength);
		}
		for(int i=0; i<NM; i++){
			int strength;
			cin>>strength;
			MechaGodzilla.push_back(strength);
		}
		
		sort(Godzilla.begin(), Godzilla.end());
		sort(MechaGodzilla.begin(), MechaGodzilla.end());

		vector<int>::iterator g, m;
		for(g=Godzilla.begin(), m=MechaGodzilla.begin(); g!=Godzilla.end() 
						&& m!=MechaGodzilla.end(); ){
			if(*g < *m){
				g = find_if(g, Godzilla.end(), Greater<int>(*m - 1));
			}
			else{
				m = find_if(m, MechaGodzilla.end(), Greater<int>(*g));
			}
		}
		if(g==Godzilla.end())
			cout<<"MechaGodzilla"<<endl;
		if(m==MechaGodzilla.end())
			cout<<"Godzilla"<<endl;


	}

	return 0;
}