#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

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
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;
//
//template <class T> T sqr(T a){return a * a;}    // square
//template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
//template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
//template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
//template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
//template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
//template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
//template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
//template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/*************************************************HABIJABI ENDS HERE******************************************************/



class Egalitarianism3Easy {
public:
    int dist[15][15];

    void apsp(int n)
    {
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		int i, j, k, ret = 1;
		clr(dist, 63);
		for(i = 0; i < SZ(a); i++)
            dist[a[i]-1][b[i]-1] = dist[b[i]-1][a[i]-1] = len[i];
        apsp(n);
		for(i = 0; i < (1 << n); i++)
        {
//            cout << i << "ic\n";
            set <int> ss;
            for(j = 0; j < n; j++)
            {
                for(k = 0; k < n; k++)
                {
                    if(j == k) continue;
//                    cout << j << ' ' << k << endl;
                    if((i & (1 << j)) && (i & (1 << k)))
                        ss.insert(dist[j][k]);
                }
            }
            if(SZ(ss) == 1)
                ret = max(ret, no_of_ones(i));
        }
        return ret;
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	Egalitarianism3Easy *obj;
	int answer;
	obj = new Egalitarianism3Easy();
	clock_t startTime = clock();
	answer = obj->maxCities(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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

	int p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;

	// ----- test 0 -----
	disabled = false;
	p0 = 4;
	p1 = {1,1,1};
	p2 = {2,3,4};
	p3 = {1,1,1};
	p4 = 3;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 6;
	p1 = {1,2,3,2,3};
	p2 = {2,3,4,5,6};
	p3 = {2,1,3,2,3};
	p4 = 3;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 10;
	p1 = {1,1,1,1,1,1,1,1,1};
	p2 = {2,3,4,5,6,7,8,9,10};
	p3 = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
	p4 = 9;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = {1};
	p2 = {2};
	p3 = {3};
	p4 = 2;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = 1;
	p1 = {};
	p2 = {};
	p3 = {};
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
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
// PROBLEM STATEMENT
// In Treeland there are n cities, numbered 1 through n.
// The cities are linked by n-1 bidirectional roads.
// Each road connects a pair of cities.
// The roads are built in such a way that each city is reachable from each other city by roads.
// (In other words, the topology of the road network is a tree.)
//
//
// You are given the int n and three vector <int>s that describe the road network: a, b, and len.
// For each i between 0 and n-2, inclusive, there is a road of length len[i] that connects the cities a[i] and b[i].
//
//
// The distance between two cities is the sum of lengths of roads on the sequence of roads that connects them. (Note that this sequence of roads is always unique.)
//
//
// You want to select k cities in such a way that all pairwise distances between the selected cities are the same.
// In other words, there must be a distance d such that the distance between every two selected cities is d.
// Return the largest possible value of k for which this is possible.
//
// DEFINITION
// Class:Egalitarianism3Easy
// Method:maxCities
// Parameters:int, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
//
//
// CONSTRAINTS
// -n will be between 1 and 10, inclusive.
// -a will contain exactly n-1 elements.
// -b will contain exactly n-1 elements.
// -len will contain exactly n-1 elements.
// -Each element in a will be between 1 and n, inclusive.
// -Each element in b will be between 1 and n, inclusive.
// -Each element in len will be between 1 and 1,000, inclusive.
// -The graph described by a and b will be a tree.
//
//
// EXAMPLES
//
// 0)
// 4
// {1,1,1}
// {2,3,4}
// {1,1,1}
//
// Returns: 3
//
// There are 4 cities and 3 roads, each of length 1.
// The roads connect the following pairs of cities: (1,2), (1,3), and (1,4).
// The optimal answer is k=3.
// We can select three cities in the required way: we select the cities {2, 3, 4}.
// The distance between any two of these cities is 2.
//
// 1)
// 6
// {1,2,3,2,3}
// {2,3,4,5,6}
// {2,1,3,2,3}
//
// Returns: 3
//
// Again, the largest possible k is 3.
// There are two ways to select three equidistant cities: {1, 4, 6} and {4, 5, 6}.
// (In both cases the common distance is 3.)
//
// 2)
// 10
// {1,1,1,1,1,1,1,1,1}
// {2,3,4,5,6,7,8,9,10}
// {1000,1000,1000,1000,1000,1000,1000,1000,1000}
//
// Returns: 9
//
//
//
// 3)
// 2
// {1}
// {2}
// {3}
//
// Returns: 2
//
//
//
// 4)
// 1
// {}
// {}
// {}
//
// Returns: 1
//
// Note that n can be 1.
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
