#include<bits/stdc++.h>
using namespace std;
main()
{
    vector< int > awan;
    vector< string > awan1;
    string s;
    int i,_max=0,n,_case;

    while(cin>>n)
    {
        _case=1;
        while(n--)
        {
            _max=0;
            for(int j=0;j<10;j++){
            cin>>s>>i;
            awan1.push_back(s);
            awan.push_back(i);
            if(i>_max) _max=i;

            }
            cout<<"Case #"<<_case<<":"<<endl;
            _case++;
            for(int i=0;i<10;i++)
            {
                if(awan[i]==_max) cout<<awan1[i]<<endl;
            }
            awan.erase(awan.begin(),awan.end());
            awan1.erase(awan1.begin(),awan1.end());
        }

    }

}
