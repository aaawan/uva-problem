//awan-ur-rahman
//CSE,2K15,KUET
#include<bits/stdc++.h>
#define   rep(i,a,b)     for(int i=a;i<b;i++)
#define   REP(i,a,b)     for(int i=a;i>b;i--)
#define   MS(a,b)        memset(a,b,sizeof(a))
#define   pb             push_back
#define   xx             first
#define   yy             second
#define   mp(a,b)        make_pair(a,b)
#define   lcm(a,b)       (a*b)/__gcd(a,b)
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
 vi adjacent[105];
 int arr1[105],arr2[105],visited[105];
 queue< pair<int,int> >Q;
 int bfs(int a,int time, int arr[]) {
    visited[a]=1;
    Q.push(mp(a,time));
    arr[a]=time;
    while(!Q.empty()) {
        ii p=Q.front();
        Q.pop();
        arr[p.first]=p.second;
        rep(i,0,adjacent[p.first].size()) {
            int c=adjacent[p.first][i];
            if(!visited[c]) {
                visited[c]=1;
                Q.push(mp(c,p.second+1));
            }

        }


    }


 }
main()
{
    int t,n,r,a,b,cas=0;
    cin>>t;
    while(t--) {
        cin>>n>>r;
        rep(i,0,r) {
            cin>>a>>b;
            adjacent[a].pb(b);
            adjacent[b].pb(a);
        }
        cin>>a>>b;
       MS(visited,0);
       MS(arr1,0);
       MS(arr2,0);
       bfs(a,0,arr1);
       MS(visited,0);
       bfs(b,0,arr2);
       int ans=0;
       rep(i,0,n+1) {
            ans=max(arr1[i]+arr2[i],ans);
       }
       cout<<"Case "<<++cas<<": "<<ans<<endl;
       rep(i,0,n+1) adjacent[i].clear();


    }

}


