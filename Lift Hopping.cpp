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
#define   inf             1000000
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
    int n,k;
    int elev[6];
    int node[102];
    string str;
    stringstream ss;

    while(cin>>n>>k) {
        vector< ii > adj[102];
        rep(i,0,n) cin>>elev[i];
        getline(cin,str);
        rep(i,0,n) {
            getline(cin,str);
            ss.clear();
            ss<<str;
            int ind=0;
            while(ss>>node[ind++]);
            ind--;

            rep(j,0,ind) {
                rep(k,j+1,ind) {
                    adj[node[j]].pb(mp((node[k]-node[j])*elev[i],node[k]));
                    adj[node[k]].pb(mp((node[k]-node[j])*elev[i],node[j]));
                }
            }
        }
        int dist[101];
        MS(dist,-1);
        dist[0]=0;
        pqs Q;
        Q.push(mp(0,0));
        while(!Q.empty()) {
            int d=Q.top().xx;
            int v=Q.top().yy;
            Q.pop();
            if(d>dist[v]) continue;
            rep(i,0,adj[v].size()) {
                int u=adj[v][i].yy;
                int w=adj[v][i].xx;
                if(dist[u] > d+w+60 || dist[u]==-1) {
                    dist[u]=d+w+60;
                    Q.push(mp(dist[u],u));
                }
            }
        }
        if(dist[k]==-1) cout<<"IMPOSSIBLE"<<endl;
        else {
            if(k) cout<<dist[k]-60<<endl;
            else cout<<dist[k]<<endl;


        }

    }
}


