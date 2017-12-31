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
int n,m;
string arr[60];
int d1[4]= {1,0,-1,0};
int d2[4]= {0,1,0,-1};
int ans;
bool safe(int i,int j) {
    if(i>=m or j>=n or i<0 or j<0 ) return false;
    if(arr[i][j]=='.' or arr[i][j]=='#') return false;
    return true;
}
void dfs1(int i,int j) {
    if(!safe(i,j)) return ;
    arr[i][j]='#';

    rep(a,0,4) {
        int x=i+d1[a];
        int y=j+d2[a];
         if(arr[x][y]=='X')  dfs1(x,y);

    }
    return ;


}
void dfs(int i,int j) {
   if(!safe(i,j)) return ;
   if(arr[i][j]=='X'){
    ans++;
    dfs1(i,j);
   }
   else if(arr[i][j]=='*') arr[i][j]='#';
   rep(a,0,4) dfs(i+d1[a],j+d2[a]);



}
main() {
    int cas=1;
    while(cin>>n>>m,n&&m) {
        rep(i,0,m) {
            cin>>arr[i];
        }
        vector<int>V;
        rep(i,0,m) {
            rep(j,0,n) {
                 ans=0;
                if(arr[i][j]=='X') {
                        dfs(i,j);
                        V.pb(ans);
                }
            }
        }
        sort(V.begin(),V.end());
        cout<<"Throw "<<cas++<<endl;
        cout<<V[0];
        rep(i,1,V.size()) cout<<' '<<V[i];
        cout<<endl<<endl;








    }

}
