#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,b,h,w,x,a,i,budjet,sum=0;
    set<int>awan;
    while(cin>>n>>b>>h>>w)
    {
        while(h--)
        {
            cin>>budjet;
            x=w;i=0;sum=0;
            while(x--)
            {
                cin>>a;
                if(a>=n) awan.insert(n*budjet);
            }

        }
        if(!awan.size()) cout<<"stay home"<<endl;
        else if(*(awan.begin())>b) cout<<"stay home"<<endl;
        else cout<<*(awan.begin())<<endl;
        awan.erase(awan.begin(),awan.end());
    }
}
