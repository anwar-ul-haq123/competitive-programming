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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
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

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 20010
/*************************************************HABIJABI ENDS HERE******************************************************/

class Intersect {
public:
	int area(vector <int> x, vector <int> y) {
	    int mxx = -infinity, i, mnx = infinity, mxy = -infinity, mny = infinity;

	    for(i = 0; i < SZ(x); i+=2)
        {
            mxx = max(mxx, min(x[i], x[i + 1]));
            mnx = min(mnx, max(x[i], x[i + 1]));
            mxy = max(mxy, min(y[i], y[i + 1]));
            mny = min(mny, max(y[i], y[i + 1]));
        }
        cout << mxx << ' ' << mnx << ' ' << mxy << ' ' << mny << endl;
	    if(mxx >= mnx || mxy >= mny) return 0;
	    return (mnx - mxx) * (mny - mxy);
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	Intersect *obj;
	int answer;
	obj = new Intersect();
	clock_t startTime = clock();
	answer = obj->area(p0, p1);
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
	vector <int> p1;
	int p2;

	// ----- test 0 -----
	disabled = false;
	p0 = {0,2,3,-4};
	p1 = {17,1000,18,6};
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {10000,-10000};
	p1 = {-10000,10000};
	p2 = 400000000;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {3,8,6,12,10,15};
	p1 = {7,17,7,17,7,17};
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {0,0,0,0,0,0,0,0};
	p1 = {5,5,5,5,5,5,5,5};
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {2,100,5,32,1000,-20,47,12};
	p1 = {29,-1000,-800,-200,-900,300,-600,-650};
	p2 = 1000;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = {1,7,12,3,16,8,3,12};
	p1 = {-90,-60,-70,3,-60,-90,-80,-100};
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
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
// You are searching for a new house. Location, location, location.  You have
// identified a number of desirable attributes, and for each have sketched a
// rectangular area that contains all the locations that have that attribute.
//
// You want it all. You need to find the area that is contained in every one of
// your rectangles. Create a class Intersection that contains a method area that
// takes as input the collection of rectangles and returns the area of
// their common intersection.
//
// The collection of rectangles is given by a vector <int> x and a vector <int> y. The first
// two values of x and y specify opposing corners of one rectangle, the next two specify opposing corners of the next
// rectangle, etc.  Thus, each rectangle is the region between its two x values and between
// its two y values.
//
//
//
// DEFINITION
// Class:Intersect
// Method:area
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int area(vector <int> x, vector <int> y)
//
//
// NOTES
// -the 2 values of x (and of y) for a given rectangle are not necessarily given in ascending order
//
//
// CONSTRAINTS
// -x contains an even number of elements between 2 and 50 inclusive
// -y contains the same number of elements as x
// -each element of x and y is between -10,000 and 10,000 inclusive
//
//
// EXAMPLES
//
// 0)
// {0,2,3,-4}
// {17,1000,18,6}
//
// Returns: 2
//
// There are 2 rectangles, one having diagonally opposed corners (0,17) and (2,1000) and the other having diagonally opposed corners (3,18) and (-4,6).
// The common intersection is the region bounded by x=0, x=2, y=17, y=18 which is
// a rectangle 2 units wide and 1 unit tall.
//
//
// 1)
// {10000,-10000}
// {-10000,10000}
//
// Returns: 400000000
//
// There is just one rectangle, so the answer is the area of that rectangle.
//
// 2)
// {3,8,6,12,10,15}
// {7,17,7,17,7,17}
//
// Returns: 0
//
// The first two rectangles intersect each other, and the second and third rectangles intersect each other, but no area is contained in all three rectangles.
//
// 3)
// {0,0,0,0,0,0,0,0}
// {5,5,5,5,5,5,5,5}
//
// Returns: 0
//
// Here we have 4 empty rectangles.
//
// 4)
// {2,100,5,32,1000,-20,47,12}
// {29,-1000,-800,-200,-900,300,-600,-650}
//
// Returns: 1000
//
// 5)
// {1,7,12,3,16,8,3,12}
// {-90,-60,-70,3,-60,-90,-80,-100}
//
// Returns: 0
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
