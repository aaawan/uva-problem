
#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   input(a)       scanf("%d",&a)
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
struct node
{
    int next,fuel,cost;
    node(int a,int b,int c)
    {
        next=a,fuel=b,cost=c;
    }
};
bool operator < (node a,node b)
{
    return a.cost > b.cost;
}
int ind[1000][105],p[1005];

main()
{
    int n,m,u,v,w,q,c,s,d,ans;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        rep(i,0,n) input(p[i]);
        vector< vector <node > > adjacent(n);
        rep(i,0,m)
        {
            cin>>u>>v>>w;
            adjacent[u].pb(node(v,w,0));
            adjacent[v].pb(node(u,w,0));
        }
        cin>>q;
        while(q--)
        {
            cin>>c>>s>>d;
            priority_queue<node>Q;
            MS(ind,-1);
            Q.push(node(s,0,0));
            ans=-1;
            while(!Q.empty())
            {
                //u-> destination v->fuel w->cost
                u=Q.top().next;
                v=Q.top().fuel;
                w=Q.top().cost;
                Q.pop();
                if(u==d)
                {
                    ans=w;
                    break;
                }
                if(ind[u][v]!=-1) continue;
                ind[u][v]=w;
                if(v<c) Q.push(node(u,v+1,w+p[u]));
                rep(i,0,adjacent[u].size())
                {
                    int u1=adjacent[u][i].next;
                    int v1=adjacent[u][i].fuel;
                    int w1=adjacent[u][i].cost;
                    if(v>=v1) Q.push(node(u1,v-v1,w));
                }

            }
            if(ans==-1) cout<<"impossible"<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;

}

