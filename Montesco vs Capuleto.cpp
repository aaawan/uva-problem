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
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int visited[205],color[205];
queue<int>Q;
main()
{
    int cas,n,a,b,ans;
    scanf("%d",&cas);
    while(cas--)
    {

        scanf("%d",&n);
        vi enemy[n+3];
        rep(i,1,n+1)
        {
            scanf("%d",&a);
            rep(j,0,a)
            {
                scanf("%d",&b);
                if(b>n) continue;
                enemy[i].pb(b);
                enemy[b].pb(i);
            }
        }
        MS(visited,0);
        MS(color,0);
        ans=0;
        bool invalid=false;
        rep(i,1,n+1)
        {
            map<int,int>frnd;
            invalid=false;
            if(!visited[i])
            {
                color[i]=0;
                frnd[0]++;
                Q.push(i);
                visited[i]=1;
                while(!Q.empty())
                {
                    int x=Q.front();
                    Q.pop();
                    rep(j,0,enemy[x].size())
                    {
                        int u=enemy[x][j];
                        if(!visited[u])
                        {
                            color[u]=1-color[x];
                            visited[u]=1;
                            frnd[color[u]]++;
                            Q.push(u);
                        }
                        else if(color[u]==color[x])
                        {
                            invalid=true;
                        }
                    }
                }

            }
            if(!invalid) ans+=max(frnd[0],frnd[1]);

        }
        cout<<ans<<endl;

    }
}

