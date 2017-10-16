
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

int d1[]={1,0,-1,0};
int d2[]={0,-1,0,1};

int N,M,startx,starty,endx,endy;
bool obstacle[52][52],visited[52][52][4];
struct node {
    int x,y,dir,time;
    node(int a,int b,int c,int d) {
        x=a,y=b,dir=c,time=d;
    }

};
bool valid(int x,int y) {
    if(x>=N || y>=M || x<=0 || y<=0) return false;
     if(obstacle[x-1][y-1]) return false;
     if(obstacle[x-1][y]) return false;
     if(obstacle[x][y-1]) return false;
     if(obstacle[x][y]) return false;
    return true;
}
int bfs(int dir) {
    queue<node>Q;
    if(valid(startx,starty)) {
        visited[startx][starty][dir]=true;
        Q.push(node(startx,starty,dir,0));
    }
    while(!Q.empty()) {
        node v=Q.front();
        Q.pop();
        if(v.x==endx && v.y==endy) return v.time;
        if(!visited[v.x][v.y][(v.dir+1)%4]) {
            Q.push(node(v.x,v.y,(v.dir+1)%4,v.time+1));
            visited[v.x][v.y][(v.dir+1)%4]=true;
        }
        if(!visited[v.x][v.y][(v.dir+3)%4]) {
            Q.push(node(v.x,v.y,(v.dir+3)%4,v.time+1));
            visited[v.x][v.y][(v.dir+3)%4]=true;
        }
        rep(i,1,4) {
            if(valid(v.x+d1[v.dir]*i,v.y+d2[v.dir]*i)) {
                if(!visited[v.x+d1[v.dir]*i][v.y+d2[v.dir]*i][v.dir]){
                    visited[v.x+d1[v.dir]*i][v.y+d2[v.dir]*i][v.dir]=true;
                    Q.push(node(v.x+d1[v.dir]*i,v.y+d2[v.dir]*i,v.dir,v.time+1));
                }
            }
            else break;
        }
    }
    return -1;
}
main()
{
    string str;
    int dir;
    while(cin>>N>>M, N && M) {
        rep(i,0,N) {
            rep(j,0,M) {
                cin>>obstacle[i][j];
            }
        }
        MS(visited,0);
        cin>>startx>>starty>>endx>>endy>>str;
        if(str[0]=='s') dir=0;
        else if(str[0]=='w') dir=1;
        else if(str[0]=='n') dir=2;
        else dir=3;
        cout<<bfs(dir)<<endl;
    }
}


