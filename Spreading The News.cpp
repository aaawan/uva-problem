//awan
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
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int visited[2505],TIME,people[2500];
vector < int >  V[2505];
int bfs(int x)
{
    visited[x]=1;
    queue<pair<int,int> >Q;
    Q.push(mp(x,0));
    while(!Q.empty())
    {
        int x=Q.front().xx;
        int day=Q.front().yy;
        Q.pop();
        rep(i,0,V[x].size())
        {
            int s=V[x][i];
            if(!visited[s])
            {
                visited[s]=1;
                people[day]++;
                Q.push(mp(s,day+1));
            }

        }
    }
}
main()
{
    int E,n,a;
    cin>>E;
    rep(i,0,E)
    {
        cin>>n;
        rep(j,0,n)
        {
            cin>>a;
            V[i].pb(a);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        MS(people,0);
        MS(visited,0);
        bfs(a);
        int d=distance(people,max_element(people,people+2505));
        if(people[d]!=0)cout<<people[d]<<" "<<d+1<<endl;
        else cout<<0<<endl;
    }

}


