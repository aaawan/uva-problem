/*can be done with bfs && DSU
here is DSU SOLUTION*/
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
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int parent[30010];
int group[30010];
int findParent(int x) {
    if(parent[x]==x) return x;
    parent[x]=findParent(parent[x]);
    return parent[x];

}
void union_set(int x,int y) {
    int u=findParent(x);
    int v=findParent(y);
    if(u==v) return ;
    if(u<v) {
        parent[v]=u;
        group[u]+=group[v];
    }
    else {
        parent[u]=v;
        group[v]+=group[u];
    }
    return ;


}
main() {
    int n,m,x,a,b;
    while(cin>>n>>m,n||m) {
        rep(i,0,n+2) parent[i]=i;
        MS(group,0);
        //cout<<group[0]<<endl;
        group[0]=1;
        rep(i,0,m) {
            cin>>x;
            cin>>a;
            if(!group[a]) group[a]=1;
            rep(j,1,x) {
               cin>>b;
               if(!group[b]) group[b]=1;
               union_set(a,b);
            }
            //cout<<"hello"<<endl;

        }
        cout<<group[0]<<endl;


    }

}
