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
int visited[10000];
int dest;
int fl[2]={1,-1};

struct node {
    int time,a,b,c,d;
    node(int x1,int x2,int x3,int x4,int x5) {
        time=x1,a=x2,b=x3,c=x4,d=x5;
    }
};

int bfs(int x1,int x2,int x3,int x4 ) {
    queue <node > Q;
    Q.push(node(0,x1,x2,x3,x4));
    while(!Q.empty()) {
        node point=Q.front();
        Q.pop();
        int sum=point.a*1000 + point.b*100 + point.c*10 +point.d;
        //cout<<sum<<" "<<dest<<endl;
        if(sum==dest) return point.time;
        int d[4];
        d[0]=point.a,d[1]=point.b,d[2]=point.c,d[3]=point.d;
        rep(i,0,4) {
            rep(j,0,2) {
                if(d[i]+fl[j]>=0 && d[i]+fl[j]<=9) {
                    d[i]=d[i]+fl[j];
                    int res=d[0]*1000 + d[1]*100 +d[2]*10 +d[3];
                    if(!visited[res]) {
                        visited[res]=1;
                        Q.push(node(point.time +1,d[0],d[1],d[2],d[3]));
                    }
                    d[i]=d[i]-fl[j];
                }
                else if(d[i]+fl[j] < 0) {
                    d[i]=9;
                    int res=d[0]*1000 + d[1]*100 +d[2]*10 +d[3];
                    if(!visited[res]) {
                        visited[res]=1;
                        Q.push(node(point.time +1,d[0],d[1],d[2],d[3]));
                    }
                    d[i]=0;
                }
                else if(d[i]+fl[j]>9) {
                    d[i]=0;
                    int res=d[0]*1000 + d[1]*100 +d[2]*10 +d[3];
                    if(!visited[res]) {
                        visited[res]=1;
                        Q.push(node(point.time +1,d[0],d[1],d[2],d[3]));
                    }
                    d[i]=9;
                }
            }
        }

    }

    return -1;

}
main()
{
    int t,sum,x1,x2,x3,x4,n,a,b,c,d;
    cin>>t;
    while(t--) {
        MS(visited,0);
        cin>>x1>>x2>>x3>>x4;
        sum=x1*1000+ x2*100 + x3*10 + x4;
        visited[sum]=1;
        cin>>a>>b>>c>>d;
        dest=a*1000+ b*100 + c*10 + d;
        cin>>n;
        rep(i,0,n) {
            cin>>a>>b>>c>>d;
            sum=a*1000+ b*100 + c*10 + d;
            visited[sum]=1;
        }
       cout<<bfs(x1,x2,x3,x4)<<endl;


    }
}










