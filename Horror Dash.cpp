#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a,b,_max,i=1;;
    while(cin>>n)
    {
        i=1;
        while(n--)
        {
            cin>>a;
            _max=0;

            while(a--)
            {
                cin>>b;
                _max=max(_max,b);

            }
            cout<<"Case "<<i<<": "<<_max<<endl;
            i++;
        }
    }
}
