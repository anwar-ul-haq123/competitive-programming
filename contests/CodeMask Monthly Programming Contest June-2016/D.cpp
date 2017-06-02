#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 51
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int arr[MAX], n, dp[900][900][MAX], visited[900][900][MAX], kase = 1;

int call(int a, int b, int c, int indx)
{
    if(indx == n)
        return a == b && b == c;
    if(a >= 900 || b >= 900 || c >= 900)
        return 0;
    int &ret = dp[a][b][indx];
    int &visit = visited[a][b][indx];
    if(visit == kase)
        return ret;
    visit = kase;
    ret = call(a+arr[indx], b, c, indx+1);
    ret = max(ret, call(a, b+arr[indx], c, indx+1));
    ret = max(ret, call(a, b, c+arr[indx], indx+1));
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, i;
    cin >> test;
    while(test--)
    {
        cerr << test << endl;
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Case " << kase++ << ": ";
        if(call(0, 0, 0, 0))
            cout << "Eid Makes Happy Everyone\n";
        else
            cout << ":(\n";
    }
    return 0;
}
