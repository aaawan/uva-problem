
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
int arr[100005],seq[100005],tree[400005],frequency[100005];

int num_seq,n,q;
void makeseq() {
    num_seq=0;
    seq[0]=1;
    frequency[1]=0;
    int prev=arr[1];
    rep(i,2,n+1) {
        if(arr[i]!=prev) {
            num_seq++;
            seq[num_seq]=i;
            prev=arr[i];
        }
        frequency[i]=num_seq;
    }
    num_seq++;
    seq[num_seq]=n+1;
}
void  maketree(int node , int start,int _end ) {
    if(start  == _end) {
            tree[node]=seq[start+1] - seq[start];
            return ;
    }

    int left=node*2;
    int right=left+1;
    int mid=(start+_end)/2;
    maketree(left,start,mid);
    maketree(right,mid+1,_end);
    tree[node]=max(tree[left],tree[right]);
}

int query(int node ,int b, int e, int i , int j ) {
    if(j<b  || i>e) return 0;
    if(b >= i && e <= j)
        return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
     return max(query(left,b,mid,i,j),query(right,mid+1,e,i,j));

}

main()
{
    int start,_end,ans;
    while(cin>>n,n) {
        cin>>q;
        rep(i,1,n+1) {
            cin>>arr[i];
        }
        makeseq();
        maketree(1,0,num_seq-1);
        //rep(i,1,num_seq+6) cout<<tree[i]<<" ";
        //cout<<endl;
        rep(i,0,q) {
            cin>>start>>_end;
            int x=frequency[start];
            int y=frequency[_end];
            int ans=min(seq[x+1],_end + 1)-start ;

            if(x!=y) {
                ans=max(ans,(_end+1 -seq[y]));

                //cout<<ans<<endl;
                if(y-x > 1)
                ans=max(ans,query(1,0,num_seq-1,x+1,y-1));
            }
            cout<<ans<<endl;

        }



    }

}










