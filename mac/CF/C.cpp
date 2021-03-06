#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("control.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 5010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int adj[MAX][MAX];
int n, arr[MAX], cnt[MAX], xor_value[MAX], end_point[MAX], start_point[MAX], dp[MAX];
int color[MAX], can_start[MAX];
pair<int,int> limits[MAX];

pair<int,int> dfs(int u)
{
	pair<int,int> &ret = limits[u], tem;
	if(ret.first != -1) return ret;
	ret = mp(start_point[u], end_point[u]);
	for(int v = 0; v < MAX; v++)
	{
		if(adj[u][v] == 0) continue;
		// cout << u << '-' << v << endl;
		tem = dfs(v);
		ret.first = min(ret.first, tem.first);
		ret.second = max(ret.second, tem.second);
	}
	return ret;
}

int call(int indx)
{
	if(indx > n)
		return 0;
	int &ret = dp[indx];
	if(~ret) return ret;
	ret = call(indx+1);
	if(can_start[indx])
		ret = max(ret, call(end_point[arr[indx]]+1) + xor_value[arr[indx]]);
	return ret;
}

int main()
{
	// in;
	int i, j;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	clr(end_point, -1);
	clr(start_point, -1);
	for(i = 1; i <= n; i++)
	{
		if(start_point[arr[i]] != -1)
			continue;
		int rem = cnt[arr[i]];
		start_point[arr[i]] = i;
		for(j = i; j <= n && rem; j++)
		{
			if(arr[j] == arr[i])
			{
				rem--;
				end_point[arr[i]] = j;
			}
			else
			{
				adj[arr[i]][arr[j]] = 1;
				// cout << arr[i] << '-' << arr[j] << endl;
			}
		}
	}
	clr(limits, -1);
	for(i = 0; i < MAX; i++)
	{
		if(cnt[i] == 0) continue;
		dfs(i);
		clr(color, 0);
		// cout << i << ' ' << limits[i].first << ' ' << limits[i].second << endl;
		for(j = limits[i].first; j <= limits[i].second; j++)
			color[arr[j]] = 1;
		for(j = 1; j < MAX; j++)
			if(color[j])
				xor_value[i] ^= j;
		can_start[limits[i].first] = 1;
	}
	clr(dp, -1);
	cout << call(0);
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 










//4460230




