//awan-ur-rahman
//CSE,2K15,KUET
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
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
main()
{
    int n,a,b,ans,sum,maxi,cas=0;
    priority_queue<pair <int,int > >Q;
    while(cin>>n,n) {
        rep(i,0,n) {
            cin>>a>>b;
            Q.push(mp(b,a));
        }
        sum=maxi=0;
        while(!Q.empty()) {
            int x=Q.top().xx;
            int y=Q.top().yy;
            Q.pop();
            if(y>maxi) {
                sum+=(y-maxi)+x;
                maxi=x;
            }
            else {
                maxi-=y;
                if(x>maxi){
                    sum+=(x-maxi);
                    maxi=max(x,maxi);
                }
            }
        }
        printf("Case %d : %d\n",++cas,sum);
    }
}


