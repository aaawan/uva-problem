/* 0-1 knapsack */
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
int wt[22];
int arr[101];
bool knapSack(int W, int n) {
   for(int i=0;i<=W;i++) arr[i]=0;
   for(int i=1;i<=n;i++) {
       for(int j=W;j>0;j--) {
        if(wt[i]<=j) arr[j]=max(arr[j],wt[i]+arr[j-wt[i]]);
       }

   }
   if(arr[W]==W) return true;
       else return false;
}
main() {
    int m,a;

    //freopen("input.txt","r",stdin);
    cin>>m;
    stringstream ss;
    string str;
    getline(cin,str);
    while(m--) {

        getline(cin,str);
        ss.clear();
        ss<<str;
        int i=0,sum=0;
        while(ss>>a) {
            wt[++i]=a;
            sum+=a;
        }
        if(sum%2!=0) cout<<"NO"<<endl;
        else {
            int z=sum/2;
            bool flag=knapSack(z,i);
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

}
