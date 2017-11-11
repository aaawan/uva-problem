
//awan-ur-rahman
//CSE,2k15,KUET
#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
#define   xx              first
#define   yy              second
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
long long fib[805][2003];
void fibonacci()
{
    fib[0][0]=1;
    fib[1][0]=0;
    fib[2][0]=1;
    for(ll i=3; i<802; i++)
    {
        for(ll j=0; j<2000; j++)
        {
            fib[i][j]+=((fib[i-1][j]+fib[i-2][j])*(i-1));
            if(fib[i][j]>9)
            {
                fib[i][j+1]=fib[i][j]/10;
                fib[i][j]%=10;
            }
        }
    }


}
main()
{


    fibonacci();
    ll n;
    while(cin>>n,n!=-1)
    {
        if(n==1) cout<<0<<endl;
        else
        {
            int i=2000;
            while(!fib[n][i]) i--;
            for(; i>=0; i--) cout<<fib[n][i];
            cout<<endl;
        }
    }

}










