
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
#define   num             100010
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
ll n,k;
int arr[num];
int tree[num*4+5];
void make_tree(int node,int i, int j) {
    if(i==j) {
        tree[node]=arr[i];
        return ;
    }
    int left=node<<1;
    int mid=(i+j)/2;
    make_tree(left,i,mid);
    make_tree(left+1,mid+1,j);
    tree[node]=tree[left]*tree[left+1];
    return ;
}
void tree_update(int node,int b,int e,int i,int value) {
    if(i<b || i>e) return ;
    if(b==e) {
        tree[node]=value;
        return ;
    }
    int left=node<<1;
    int mid=(b+e)>>1;
    tree_update(left,b,mid,i,value);
    tree_update(left+1,mid+1,e,i,value);
    tree[node]=tree[left]*tree[left+1];
    return ;

}
int query(int node,int b,int e,int i,int j) {
    if(i>e || j<b ) return 1;
    if(b>=i && e<=j) return tree[node];
    int left=node<<1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j);
    int p2=query(left+1,mid+1,e,i,j);
    return p1*p2;

}
main() {
    int x,y,v;
    char ch;
    freopen("input.txt","r",stdin);
    while(cin>>n>>k) {
        string str;
        for(int i=1;i<=n;i++) {
                cin>>arr[i];
                if(arr[i]>0) arr[i]=1;
                else if(arr[i]<0) arr[i]=-1;
        }
        make_tree(1,1,n);
        for(int i=0;i<k;i++) {
            cin>>ch>>x>>y;
            if(ch=='C') {
                    if(y>0) y=1;
                    else if(y<0) y=-1;
                    tree_update(1,1,n,x,y);
            }
            else if(ch=='P') {
                int sum=query(1,1,n,x,y);
                if(sum<0) str.append("-");
                else if(sum>0) str.append("+");
                else str.append("0");
            }

        }
        cout<<str<<endl;
    }

}
