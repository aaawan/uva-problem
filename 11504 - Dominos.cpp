


#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
#define   xx              first
#define   yy              second
#define   MAX             100002
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
vi edge[100002],dfs,visited;
int ans=0,indegree[100002],num_scc,z;

void DFS(int u) {
    visited[u]=1;
    for(int i=0;i<edge[u].size();i++) {
        if(!visited[edge[u][i]]) DFS(edge[u][i]);
    }
    dfs.pb(u);
}

main() {
    int test,n,m,a,b;
//    freopen("input (3).txt","r",stdin);
//    freopen("output(3).txt","w",stdout);
    cin>>test;
    while(test--) {
        cin>>n>>m;
        rep(i,0,n+3) edge[i].clear();
        MS(indegree,0);
        rep(i,0,m) {
            cin>>a>>b;
            edge[a].pb(b);
        }
       visited.assign(n+1,0);
       for(int i=1;i<=n;i++) {
        if(!visited[i]) DFS(i);
       }
       visited.assign(n+1,0);
       ans=0;
       for(int i=dfs.size()-1;i>=0;i--) {
            if(!visited[dfs[i]]) {
                ans++;
                DFS(dfs[i]);
            }
       }
       cout<<ans<<endl;
    }



}


