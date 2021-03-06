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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 15
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int n;
bool canvisit[1 << MAX], color[MAX][1 << MAX];
int dp[5 + (1 << 15)];
vector <int> adj[15];

void dfs(int cur, int mask)
{
    canvisit[mask] = true;
    color[cur][mask] = 1;
    for(int i = 0; i < SZ(adj[cur]); i++)
    {
        int v = adj[cur][i];
        if(!color[v][mask | (1 << v)])
            dfs(v, mask | (1 << v));
    }
}

int call(int mask)
{
    if(mask == 0)
        return 0;
    int &ret = dp[mask];
    if(ret != -1) return ret;
    ret = infinity;
    int subset = mask;
    do
    {
        if(canvisit[subset])
            ret = min(ret, call(mask ^ subset) + 1);
        subset = subset - 1;
        subset = subset & mask;
    }while(subset);
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, test, kase, m, a, b;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        clr(canvisit, 0);
        clr(dp, -1);
        clr(color, 0);
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++) adj[i].clear();
        while(m--)
        {
            scanf("%d %d", &a, &b);
            a--, b--;
            adj[a].pb(b);
        }
        for(i = 0; i < n; i++)
            dfs(i, (1 << i));
        printf("Case %d: %d\n", kase, call((1 << n) - 1));
    }
    return 0;
}

