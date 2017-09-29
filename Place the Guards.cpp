

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
#define mp make_pair
#define till(a) while(a--)
#define MS(a,b) memset(a,b,sizeof(a))
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
typedef queue<int>qi;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int visited[205],color[205];
qi Q;
main()
{
    int n,v,e,a,b,ans;
    cin>>n;
    while(n--)
    {
        ans=0;
        cin>>v>>e;
        vi adjacent[v+3];
        bool is_safe=true;
        rep(i,0,e)
        {
            cin>>a>>b;
            adjacent[a].pb(b);
            adjacent[b].pb(a);
        }
        MS(visited,0);
        MS(color,0);
        rep(i,0,v)
        {
            map<int,int>cal;
            if(adjacent[i].size()==0) ans++;
            else if(!visited[i])
            {
                color[i]=0;
                Q.push(i);
                cal[0]++;
                visited[i]=1;
                while(!Q.empty())
                {
                    int x=Q.front();
                    Q.pop();
                    rep(j,0,adjacent[x].size())
                    {
                        int u=adjacent[x][j];
                        if(!visited[u])
                        {
                            color[u]=1-color[x];
                            visited[u]=1;
                            cal[color[u]]++;
                            Q.push(u);
                        }
                        else if(color[u]==color[x]) is_safe=false;

                    }
                }
            }
            ans+=min(cal[0],cal[1]);

        }
        if(e==0) cout<<v<<endl;
        else if(is_safe) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}
