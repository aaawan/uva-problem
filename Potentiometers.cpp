//awan-ur-rahman
//CSE,2k15,KUET
//problem category- BIT
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

void create_tree(int tree[],int arr[],int n) {
    int ind;
    //cout<<arr[1]<<' '<<arr[2]<<' '<<arr[3]<<endl;
    rep(i,1,n+1) {
        ind=i;
        while(ind<=n) {
            tree[ind]+=arr[i];
            ind+=(ind & -ind );
        }
    }
}
void update(int tree[],int ind,int r,int n) {
    while(ind<=n) {
        tree[ind]+=r;
        ind+=(ind & -ind );
    }
}
int query(int tree[],int ind) {
    int sum=0;

    while(ind>0) {
        sum+=tree[ind];
        ind-=(ind & -ind);
    }
//    while(ind1>0) {
//        sum2+=tree[ind1];
//        ind1-=(ind1 & -ind1);
//    }
    return sum;

}


main() {

   int n,cas=0,flag=0;
   while(cin>>n,n) {
        int arr[n+3];
        int tree[n+3]={0};
        rep(i,1,n+1) {
            cin>>arr[i];
        }
        string s;
        int a,b;
        create_tree(tree,arr,n);
        //cout<<tree[1]<<' '<<tree[2]<<endl;
        if(flag) printf("\n");
        printf("Case %d:\n",++cas);
        flag=1;

        while(1) {
            cin>>s;
            if(s[0]=='E') break;
            else{
                cin>>a>>b;
                if(s[0]=='S') {
                        update(tree,a,b-arr[a],n);
                        arr[a]=b;
                }
                else printf("%d\n",query(tree,b)-query(tree,a-1));
            }




        }


   }

}
