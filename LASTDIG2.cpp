#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){

	int t;
	cin>>t;
	int periodicity[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
	while(t--){
		string a;
		string b;
		cin>>a>>b;
		if(b.size()==1 && b[0]=='0')
			cout<<1<<endl;
		else if(*(a.rbegin()) == '0')
			cout<<0<<endl;
		else{
			int base = *(a.rbegin()) - '0';
			int period = periodicity[base];
			int power = *(b.rbegin()) - '0';
			if(period == 4 && b.size() > 1)
				power += (*(b.rbegin()+1)-'0')*10;
			power = power%period;
			power += period;
			cout<<(int)pow(base, power)%10<<endl;
		}
	}
	return 0;
}