

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
int height[10001];
main()
{
    int n,m,x,y,a,b,c;
    bool flag=true;

    //freopen("input.txt","r",stdin);
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        //if(cin.eof()) break;
        for(int i=a; i<c; i++)
            if(height[i]<b) { height[i]=b;}
    }
    for(int i=0; i<10001; i++)
    {
        if(height[i]!=height[i-1])
        {
            if(flag)
            {
                cout<<i<<' '<<height[i];
                flag=false;
            }
            else cout<<' '<<i<<' '<<height[i];

        }

    }
    cout<<endl;
    return 0;

}
