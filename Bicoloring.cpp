
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
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
vi adjacent[205];
queue<int>Q;
int color[205],visited[205];
main()
{
    int n,m,a,b;
    while(scanf("%d",&n),n) {
        cin>>m;
        rep(i,0,m) {
            cin>>a>>b;
            adjacent[a].pb(b);
            adjacent[b].pb(a);
        }
        MS(color,0);
        MS(visited,0);
        bool isbipartite=true;
        Q.push(0);
        color[0]=0;
        visited[0]=1;
        while(!Q.empty()) {
            int x=Q.front();
            Q.pop();

            rep(i,0,adjacent[x].size()) {
                if(!visited[adjacent[x][i]]) {
                    visited[adjacent[x][i]]=1;
                    color[adjacent[x][i]]=1-color[x];
                    Q.push(adjacent[x][i]);
                }
                else if(color[adjacent[x][i]]==color[x]) isbipartite=false;
            }
        }
        if(!isbipartite) cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;
        rep(i,0,n) adjacent[i].clear();

    }
}
