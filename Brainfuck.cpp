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
main()
{
    int n,cell,cas=1;
    cin>>n;
    string str;
    int arr[101];
    while(n--) {
        cin>>str;
        int l=str.length();
        MS(arr,0);
        cell=0;
        rep(i,0,l) {
            if(str[i]=='>') {
                    cell++;
                    if(cell==100) cell=0;
            }
            else if(str[i]=='<') {
                    cell--;
                    if(cell==-1) cell=99;
            }
            else if(str[i]=='+') {
                    ++arr[cell];
                    if(arr[cell]==256) arr[cell]=0;
            }
            else if(str[i]=='-') {
                    --arr[cell];
                    if(arr[cell]==-1) arr[cell]=255;
            }
        }
        cout<<"Case "<<cas++<<':';
        rep(i,0,100) {
           // cout<<setw(2)<< hex<< uppercase <<arr[i];
            printf(" %02X", arr[i]);
        }
        cout<<endl;



    }
}










