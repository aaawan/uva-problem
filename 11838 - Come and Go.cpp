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
int section=2003;
vi edge[2003];
vi dfs_num,dfs_low,visited;
int num_scc,unvisited=0,ans;
stack<int> S;
void tarjanscc(int u) {
    dfs_low[u]=dfs_num[u]=num_scc++;
    S.push(u);
    visited[u]=1;
    for(int i=0;i<edge[u].size();i++) {
        int v=edge[u][i];
        if(dfs_num[v]==unvisited) tarjanscc(v);
        if(visited[v]) dfs_low[u]=min(dfs_low[v],dfs_low[u]);
    }
    if(dfs_low[u]==dfs_num[u]) {
        ans++;
        while(1) {
            int v=S.top();
            S.pop(),visited[v]=0;
            if(u==v) break;
        }
    }
}

main() {
    int n,m,a,b,c;
    while(cin>>n>>m,n&&m) {
        for(int i=0;i<section ;i++) edge[i].clear();
        for(int i=0;i<m;i++) {
            cin>>a>>b>>c;
            if(c==1) edge[a].pb(b);
            else {
                edge[a].pb(b);
                edge[b].pb(a);
            }
        }
        dfs_num.assign(n+1,0),dfs_low.assign(n+1,0),visited.assign(n+1,0);
        num_scc=ans=0;
        for(int i=1;i<=n;i++) if(dfs_num[i]==unvisited) tarjanscc(1);
        if(ans!=1) cout<<0<<endl;
        else cout<<1<<endl;



    }


}
