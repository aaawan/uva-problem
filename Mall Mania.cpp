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
typedef pair< int , pair < int, int > > iii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
bool mal2[2005][2005];
bool visited[2005][2005];
int d1[4]={1,0,-1,0};
int d2[4]={0,1,0,-1};

int main()
{
    int n,a,b;
    while(1) {

        cin>>n;
        if(!n) return 0;
        queue <iii>Q;
        MS(visited,0);
        rep(i,0,n) {
            cin>>a>>b;
            visited[a][b]=true;
            Q.push(mp(0,mp(a,b)));
        }
        cin>>n;
        MS(mal2,0);
        rep(i,0,n) {
            cin>>a>>b;
//            X1=min(X1,a)  ;
//            X2=max(X2,a);
//            Y1=min(Y1,b);
//            Y2=max(Y2,b);
            mal2[a][b]=true;
        }

        while(!Q.empty()) {
        int time=Q.front().xx;
        int x=Q.front().yy.xx;
        int y=Q.front().yy.yy;
        Q.pop();
        if(mal2[x][y] ) {
            cout<<time<<endl;
            break;
        }

        rep(i,0,4) {
            int a=x+d1[i];
            int b=y+d2[i];
            if(a>=0 && a<=2000 && b>=0 && b<=2000) {
                if(!visited[a][b]) {
                    Q.push(mp(time+1,mp(a,b)));
                    visited[a][b]=true;
                }
            }
        }
    }


    }

}










