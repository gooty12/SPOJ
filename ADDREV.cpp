#include<iostream>
#include<cmath>

#define max(a, b) a>b?a:b

int reverse(int);

using namespace std;

int main(){

    int N;
    int a, b, sum;

    //Test pow(x, y)
    /*cout<<"0 power of 10 is "<<pow(10.0, 0)<<endl;
    cout<<"2 power of 10 is "<<pow(10.0, 2)<<endl;*/

    cin>>N;
    while(N--){
        cin>>a>>b;
        sum = reverse(a) + reverse(b);
        cout<<reverse(sum)<<endl;
    }
    return 0;
}

int reverse(int n){

    while( n>0 && (n%10 == 0)){
        n/=10;
    }
        
    double ans=0;
    while(n > 0){
        ans = 10*ans + (n%10);
        //cout<<"ans is "<<ans<< " and digit is "<< n%10<<endl;
        n/=10;
    }
    return ans;
}
