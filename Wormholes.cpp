#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   input(a)       scanf("%d",&a)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
#define   xx              first
#define   yy              second
#define   inf             100000200
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
    int t,n,m,w,a,b;
    input(t);
    while(t--) {
        cin>>n>>m;
        int dist[n+2];
        vector<ii>adjacent[n+1];
        rep(i,0,m) {
            cin>>a>>b>>w;
            adjacent[a].pb(mp(b,w));
        }
        MS(dist,inf);
        dist[0]=0;
        rep(i,0,n-1) {
            rep(j,0,n) {
                rep(k,0,adjacent[j].size()) {
                    ii v=adjacent[j][k];
                    dist[v.first]=min(dist[v.first],dist[j]+v.second);
                }

            }

        }
        bool infinite=false;
        rep(i,0,n) {
            rep(j,0,adjacent[i].size()) {
                ii v=adjacent[i][j];
                if(dist[v.first] >dist[i]+v.second) infinite=true;

            }
        }
        if(infinite) puts("possible");
        else puts("not possible");



    }
}


