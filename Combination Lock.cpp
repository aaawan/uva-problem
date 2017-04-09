#include<bits/stdc++.h>
using namespace std;
main()
{
    int i,j,k,l,sum,a,b,c;;
    while(1)
    {
        cin>>i>>j>>k>>l;
        sum=1080;
        if(i==0 && j==0 && k==0 && l==0) return 0;
        sum+=j>i? (40-(j-i))*9:(i-j)*9;
        sum+=k>j?(k-j)*9:(40-(j-k))*9;
        sum+=l>k? (40-(l-k))*9:(k-l)*9;

        cout<<sum<<endl;
    }
}
