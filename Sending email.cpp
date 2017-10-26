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
#define   inf             100000
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
typedef priority_queue<ii, std::vector<ii>, std::greater<ii> > pqs;
main()
{
    int t,n,m,s,d,a,b,w,cas=0;
    cin>>t;

    while(t--) {
        cin>>n>>m>>s>>d;
         vi dist(n,inf);
         vector< ii >adj[n+1];
        rep(i,0,m) {
            cin>>a>>b>>w;
            adj[a].pb(mp(b,w));
            adj[b].pb(mp(a,w));
        }
        dist[s]=0;
        pqs Q;
        Q.push(mp(0,s));
        while(!Q.empty()) {
            int d=Q.top().first;
            int v=Q.top().second;
            Q.pop();
            if(d>dist[v]) continue;
            rep(i,0,adj[v].size()) {
                int v1=adj[v][i].first;
                int w1=adj[v][i].second;
                if(dist[v1]> dist[v]+w1) {
                    dist[v1]=dist[v]+w1;
                    Q.push(mp(dist[v1],v1));

                }

            }
        }

        if(dist[d]==inf) cout<<"Case #"<<++cas<<": unreachable"<<endl;
        else cout<<"Case #"<<++cas<<": "<<dist[d]<<endl;





    }
}


