#include<bits/stdc++.h>
#define pp push_back
using namespace std;
main()
{
    int n,p,q;
    vector<int>awan;
    vector<int>aawan;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>p;
            awan.pp(p);
        }
         for(int i=1;i<n;i++)
        {
            p=abs(awan[i]-awan[i-1]);
            aawan.pp(p);
        }
        sort(aawan.begin(),aawan.end());
        for(int i=1;i<=n-1;i++)
        {
            awan.pp(i);
        }
        for(int i=1;i<=n-1;i++)
        {
            q=0;
            for(int j=0;j<n-1;j++)
            {
                if(i==aawan[j]) {
                   q=-1;break;
                }
            }
            if(q==0) {
                cout<<"Not jolly"<<endl;
                goto sd;
            }
        }
        cout<<"Jolly"<<endl;
       sd: awan.erase(awan.begin(),awan.end());
        aawan.erase(aawan.begin(),aawan.end());
    }
}

