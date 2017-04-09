#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a,b,c;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>c;
            if(a>20 || b>20 || c>20) cout<<"Case "<<i<<":"<<" bad"<<endl;
            else cout<<"Case "<<i<<":"<<" good"<<endl;
        }
    }
}
