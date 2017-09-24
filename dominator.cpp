#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <ctime>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define MS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define till(a) while(a--)
#define SI scanint()
#define gc getchar
#define pc putchar

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
vi nodes[103];
int visited[103],connected[105];
int dominate[103][103];
int root;
int dfs(int x)
{
    visited[x]=1;
    rep(i,0,nodes[x].size())
    {
        if(!visited[nodes[x][i]] && nodes[x][i]!=root) dfs(nodes[x][i]);
    }
}
int dfss(int x) {
    connected[x]=1;
    rep(i,0,nodes[x].size()) {
        if(!connected[nodes[x][i]]) dfss(nodes[x][i]);

    }


}
main()
{
    int t,k,n,cas=1;
    cin>>t;
    while(t--)
    {

        cin>>n;
        int x;
        MS(connected,0);
        rep(i,0,n) nodes[i].clear();
        //adjacency list creating......
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                cin>>x;
                if(x)
                {
                    nodes[i].pb(j);
                }
            }
        }
        MS(dominate,0);
        dfss(0);
        rep(i,0,n) if(connected[i]) dominate[0][i]=1;
        //for(int i=0;i<n;i++) cout<<dominate[0][i]<<" ";
        rep(i,1,n)
        {
            MS(visited,0);
            root=i;
            dfs(0);
            rep(j,0,n)
            {
                if(!visited[j] && connected[j]) dominate[i][j]=1;
            }
        }
        cout<<"Case "<<cas++<<":"<<endl;
        rep(i,0,n)
        {
            cout<<"+";
            rep(i,0,2*n-1) cout<<"-";
            cout<<"+"<<endl;
            rep(j,0,n)
            {
                if(dominate[i][j]) cout<<"|Y";
                else cout<<"|N";
            }
            cout<<"|\n";
        }

        cout<<"+";
        rep(i,0,2*n-1) cout<<"-";
        cout<<"+"<<endl;



    }
}


