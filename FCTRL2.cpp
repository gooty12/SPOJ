#include<iostream>
#include<list>

using namespace std;

void multiply(list<int>&, int);

int main(){

	int t;

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		list<int> l1, l2;
		int tmp = n;
		while(tmp>0){
			int d = tmp%10;
			l1.push_front(d);
			l2.push_front(d);
			tmp /= 10;
		}
		for( n=n-1; n>=1; n--){
			int d0 = n%10;
			int d1 = n/10;
			if(d1){
				l1.push_back(0);
				multiply(l1, d1);
				/*cout<<"**d1**"<<endl;
				for(auto it=l1.begin(); it!=l1.end(); it++)
					cout<<*it;
				cout<<endl;*/
			}
			multiply(l2, d0);
			/*cout<<"**d2**"<<endl;
			for(auto it=l2.begin(); it!=l2.end(); it++)
				cout<<*it;
			cout<<endl;*/
			if(d1){
				//cout<<"**addition**"<<endl;
				int borrow = 0;
				//list<int>::reverse_iterator 
				for(list<int>::reverse_iterator rev_it2=l2.rbegin(), rev_it1 = l1.rbegin(); 
								 rev_it1!=l1.rend();  rev_it1++){
					int m = borrow + *rev_it1;
					if(rev_it2!=l2.rend()){
						m +=  *rev_it2;	 
						rev_it2++;
					}
					*rev_it1 = m%10;
					borrow = m/10;
					//cout<<"l1 is "<<*rev_it1<<" L2 is "<<*rev_it2 <<" borrow is "<<borrow<<" m is "<<m<<endl;
				}
				if(borrow){
					l1.push_front(borrow);
				}
			}
			if(d1){
				l2 = l1;
			}
			else{
				l1 = l2;
			}

		/*cout<<"**every iteration**"<<endl;
		for(auto it=l1.begin(); it!=l1.end(); it++)
			cout<<*it;
		cout<<endl;
		exit(0);*/
		}
		//cout<<"**result**"<<endl;
		for(auto it=l1.begin(); it!=l1.end(); it++)
			cout<<*it;
		cout<<endl;
	}

	return 0;
}

void multiply(list<int>& l, int d){
	list<int>::reverse_iterator rev_it = l.rbegin();
	int borrow = 0;
	while( rev_it!=l.rend()){
		int m  = (*rev_it)*d + borrow;
		*rev_it = m%10;
		borrow = m/10;
		rev_it++;
	}
	if(borrow)
		l.push_front(borrow);
}