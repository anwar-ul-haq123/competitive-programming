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


class RectangleCoveringEasy {
public:
	int solve(int holeH, int holeW, int boardH, int boardW) {
	 	if(max(holeH, holeW) <= max(boardH, boardW) && min(holeH, holeW) <= min(boardH, boardW) &&
            !(max(holeH, holeW) == max(boardH, boardW) && min(holeH, holeW) == min(boardH, boardW)))
            return 1;
        return -1;
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	RectangleCoveringEasy *obj;
	int answer;
	obj = new RectangleCoveringEasy();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1, p2, p3);
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
	int p1;
	int p2;
	int p3;
	int p4;

	// ----- test 0 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = 1;
	p3 = 1;
	p4 = -1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = 3;
	p1 = 5;
	p2 = 4;
	p3 = 6;
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = 10;
	p1 = 20;
	p2 = 25;
	p3 = 15;
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = 3;
	p1 = 10;
	p2 = 3;
	p3 = 12;
	p4 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
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
//
// There is a rectangular hole in the ground.
// You are given the dimensions of this rectangle: ints holeH and holeW.
//
//
//
// You have a rectangular board.
// You are given its dimensions: ints boardH and boardW.
// You would like to use the board to cover the hole.
//
//
//
// There are some rules you must follow when covering the hole:
//
// You may rotate the board, but you must place it so that the sides of the board are parallel to the sides of the hole.
// The board must cover the entire hole.
// All corners of the board must be strictly outside the hole. (That is, they are not allowed to lie on the boundary of the hole.)
//
//
//
//
// If you can cover the hole using the board you have, return 1. Otherwise, return -1.
//
//
// DEFINITION
// Class:RectangleCoveringEasy
// Method:solve
// Parameters:int, int, int, int
// Returns:int
// Method signature:int solve(int holeH, int holeW, int boardH, int boardW)
//
//
// CONSTRAINTS
// -holeW, holeH, boardW, and boardH will be between 1 and 1,000,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// 1
// 1
// 1
// 1
//
// Returns: -1
//
// The vertices of the board must not be on the boundary of the hole.
//
// 1)
// 3
// 5
// 4
// 6
//
// Returns: 1
//
// One possibility is to place the board so that it extends over the hole by 0.5 on each side.
//
// 2)
// 10
// 20
// 25
// 15
//
// Returns: 1
//
// Here we have to rotate the board by 90 degrees.
//
// 3)
// 3
// 10
// 3
// 12
//
// Returns: 1
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
