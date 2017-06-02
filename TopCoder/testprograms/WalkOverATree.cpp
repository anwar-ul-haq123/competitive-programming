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
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 55
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

vector <int> adj[MAX];

int dp[MAX][110][2], l;

void dfs(int u, int par)
{
    int j, k;
    for(auto v: adj[u])
    {
        if(v == par) continue;
        dfs(v, u);
        for(j = l; j >= 1; j--)
            for(k = 1; k <= j; k++)
            {
                dp[u][j][0] = max(dp[u][j][0], dp[u][j-k][1]+dp[v][k-1][0]);
                if(k-2>=0)
                    dp[u][j][0] = max(dp[u][j][0], dp[u][j-k][0]+dp[v][k-2][1]);
                if(k-2>=0)
                    dp[u][j][1] = max(dp[u][j][1], dp[u][j-k][1]+dp[v][k-2][1]);
            }
    }
}

class WalkOverATree {
public:
	int maxNodesVisited(vector <int> parent, int L) {
	    for(int i = 0; i <= SZ(parent); i++)
            adj[i].clear();
        clr(dp, 0);
        l = L;
		for(int i = 0; i < SZ(parent); i++)
            adj[i+1].pb(parent[i]), adj[parent[i]].pb(i+1);
        for(int i = 0; i <= SZ(parent); i++)
            for(int j = 0; j <= L; j++)
                dp[i][j][0] = dp[i][j][1] = 1;
        dfs(0, -1);
        return max(dp[0][L][1],dp[0][L][0]);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	WalkOverATree *obj;
	int answer;
	obj = new WalkOverATree();
	clock_t startTime = clock();
	answer = obj->maxNodesVisited(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;

	vector <int> p0;
	int p1;
	int p2;

	// ----- test 0 -----
	disabled = false;
	p0 = {0,0};
	p1 = 2;
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {0,0};
	p1 = 3;
	p2 = 3;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {0,1,2,3};
	p1 = 2;
	p2 = 3;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {0,0,0,0,2,4,2,3,1};
	p1 = 1;
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
	p1 = 4;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
	p1 = 26;
	p2 = 17;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 6 -----
	disabled = false;
	p0 = {0,0,2,0};
	p1 = 100;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 7 -----
	disabled = false;
	p0 = {0,0,2};
	p1 = 4;
	p2 = 4;
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
