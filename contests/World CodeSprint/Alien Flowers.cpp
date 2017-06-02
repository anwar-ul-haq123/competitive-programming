#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 101
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int A, B, C, D, dp[MAX][MAX][MAX][MAX][3], mod = 1e9+7;

int call(int a, int b, int c, int d, int last)
{
    if(a > A || b > B || c > C || d > D)
        return 0;
    if(a == A && b == B && c == C && d == D)
        return 1;
    int &ret = dp[a][b][c][d][last];
    if(ret != -1) return ret;
    ret = 0;
    if(last == 0)
    {
        ret += call(a+1, b, c, d, 0);
        ret %= mod;
        ret += call(a, b+1, c, d, 1);
        ret %= mod;
    }
    else if(last == 1)
    {
        ret += call(a, b, c, d+1, 0);
        ret %= mod;
        ret += call(a, b, c+1, d, 1);
        ret %= mod;
    }
    else
    {
        ret += call(a, b, c, d, 0);
        ret %= mod;
        ret += call(a, b, c, d, 1);
        ret %= mod;
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    cin >> A >> B >> C >> D;
    clr(dp, -1);
    cout << call(0, 0, 0, 0, 2);
    return 0;
}
