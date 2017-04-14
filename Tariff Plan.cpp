#include<bits/stdc++.h>
#define pp push_back
using namespace std;
main()
{
    int t,n,p,sum1,sum2,_case;
    while(cin>>t)
    {
        _case=1;
        while(t--)
        {
            cin>>n;
            sum1=0,sum2=0;
            for(int i=1;i<=n;i++)
            {
                cin>>p;

                sum1+=((p/30)+1)*10;
                sum2+=((p/60)+1)*15;
            }
            cout<<"Case "<<_case<<": ";
            _case++;
            if(sum1>sum2) cout<<"Juice "<<sum2<<endl;
            else if(sum1==sum2) cout<<"Mile Juice "<<sum1<<endl;
            else cout<<"Mile "<<sum1<<endl;
        }
    }
}
