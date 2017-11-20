//awan-ur-rahman
//CSE,2k15,KUET

//problem type-2D segment tree

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
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<ll> vl;
typedef priority_queue<int> pq;
typedef priority_queue<int, std::vector<int>, std::greater<int> > pqs;
int min_tree[503][2000],max_tree[503][2000],arr[503][503];
int MAX,MIN;

void make_tree(int Q,int node,int b,int e) {
    if(b==e) {
        min_tree[Q][node]=max_tree[Q][node]=arr[Q][b];
        return ;
    }
    int left=node*2;
    int mid=(b+e)/2;
    make_tree(Q,left,b,mid);
    make_tree(Q,left+1,mid+1,e);
    min_tree[Q][node]=min(min_tree[Q][left],min_tree[Q][left+1]);
    max_tree[Q][node]=max(max_tree[Q][left],max_tree[Q][left+1]);
    return ;
}

void update(int Q,int node,int b,int e,int i,int value) {
    if(i<b || i>e) return ;
    if(i==b && i==e) {
        max_tree[Q][node]=min_tree[Q][node]=value;
        return ;
    }
    int left=node*2;
    int mid=(b+e)/2;
    update(Q,left,b,mid,i,value);
    update(Q,left+1,mid+1,e,i,value);
    min_tree[Q][node]=min(min_tree[Q][left],min_tree[Q][left+1]);
    max_tree[Q][node]=max(max_tree[Q][left],max_tree[Q][left+1]);
    //return ;
}

void query(int Q ,int node,int b,int e,int i,int j) {
    if(i > e || j < b) return ;
    if(b >= i && e <= j) {
        MAX=max(MAX,max_tree[Q][node]);
        MIN=min(MIN,min_tree[Q][node]);
        return ;
    }
    int left=node*2;
    int mid=(b+e)/2;
    query(Q,left,b,mid,i,j);
    query(Q,left+1,mid+1,e,i,j);
}

main() {
    int n,q,u,v,x,y,w;
    char ch;
    while(cin>>n) {
        rep(i,1,n+1) {
            rep(j,1,n+1) cin>>arr[i][j];
            make_tree(i,1,1,n);
        }
        cin>>q;
        //getchar();
        while(1) {
           if(!q) return 0;
            q--;
            cin>>ch;

            if(ch=='q') {
                cin>>x>>u>>y>>v;
                MIN=inf,MAX=-inf;
                rep(i,x,y+1) query(i,1,1,n,u,v);
                cout<<MAX<<" "<<MIN<<endl;


            }
             else {
                cin>>x>>y>>w;
                update(x,1,1,n,y,w);
                //getchar();

            }




        }




    }


}
