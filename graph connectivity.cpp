
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
#define MAX 1000010
#define pi 3.1416
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
vector<int>adjacent[27];
int visited[26];
int dfs(int x) {
    visited[x]=1;
    rep(i,0,adjacent[x].size()) {
        if(!visited[adjacent[x][i]]) dfs(adjacent[x][i]);
     }
}

main()
{
    int cas,n,ans;
    string s;
    scanf("%d\n\n",&cas);
    rep(t,1,cas+1) {
        ans=0;
        getline(cin,s);
        n=s[0]-65+1;
        while(1) {
            if(!getline(cin,s) || s.empty()) break;
            adjacent[s[0]-65].pb(s[1]-65);
            adjacent[s[1]-65].pb(s[0]-65);
        }
        MS(visited,0);
        rep(i,0,n) {
            if(!visited[i]) {
              ans++;
              dfs(i);
            }
        }
        if(t!=1) cout<<endl;
        cout<<ans<<endl;
        rep(i,0,26) adjacent[i].clear();

    }
}
