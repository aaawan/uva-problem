#include<bits/stdc++.h>
#define pp push_back
using namespace std;
main()
{
    int n,m,x=1,q,b=1,p;
    vector<int>awan;
    vector<int>aawan;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0) return 0;
        for(int i=0;i<n;i++)
        {
            cin>>p;
            awan.pp(p);
        }

        //cout<<"CASE# "<<x<<":"<<endl;
        for(int j=0;j<m;j++)
        {
            cin>>p;
            aawan.pp(p);
        }
        sort(awan.begin(),awan.end());
        cout<<"CASE# "<<x<<":"<<endl;
        for(int j=0;j<m;j++)
        {

            b=1;
            for(int i=0;i<n;i++)
            {
                if(awan[i]==aawan[j])
                {
                    cout<<aawan[j]<<" found at "<<i+1<<endl;
                    b=0;
                    break;
                }
            }
            if(b) cout<<aawan[j]<<" not found"<<endl;

        }
        awan.erase(awan.begin(),awan.end());
        aawan.erase(aawan.begin(),aawan.end());
        x++;

    }
}

