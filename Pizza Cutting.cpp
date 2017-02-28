#include<iostream>
using namespace std;
typedef long long ll;
main()
{
    ll n,sum;
    while(1)
    {
        cin>>n;
        if(n<0) return 0;
        sum=n*(n-1);
        sum/=2;
        sum+=(n+1);
        cout<<sum<<endl;
    }
}
