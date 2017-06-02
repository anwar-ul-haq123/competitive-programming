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

class CandyAddict {
public:
	vector<long long> solve(vector <int> x, vector <int> y, vector <int> z) {
	    vector <LL> X, Y, Z, ret;
	    X = x;
	    Y = y;
	    Z = z;
        for(int i = 0; i < SZ(X); i++)
        {
            LL low = 0, high = Z[i], din = 0, mid, baki = 0, lagbe = Y[i] * Z[i];
            while(low <= high)
            {
                mid = (low + high) / 2;
                if(mid * X[i] >= lagbe)
                {
                    high = mid - 1;
                    din = mid;
                }
                else
                    low = mid + 1;
            }
            baki = X[i] * Z[i]
        }
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, vector<long long> p3) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	CandyAddict *obj;
	vector<long long> answer;
	obj = new CandyAddict();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p3[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p2;
	vector<long long> p3;

	// ----- test 0 -----
	disabled = false;
	p0 = {5};
	p1 = {3};
	p2 = {3};
	p3 = {6ll};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {5,5,5,5,5};
	p1 = {3,3,3,3,3};
	p2 = {1,2,3,4,5};
	p3 = {2ll,1ll,6ll,2ll,7ll};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {1000000000,1000000000,1000000000,1000000000,1000000000};
	p1 = {1,2,3,999999998,999999999};
	p2 = {342568368,560496730,586947396,386937583,609483745};
	p3 = {342568367000000000ll,60496729000000000ll,253614062000000001ll,773875166ll,609483745ll};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
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
// Alice is a candy addict!
// She doesn't eat any food except for candy.
// More precisely, the only thing she eats on any day is one piece of candy in the evening.
//
//
//
// Alice receives an allowance of x dollars every morning.
// One piece of candy costs y dollars.
// We will follow Alice for z days.
// The days will be numbered 1 through z.
// At the beginning of day 1, Alice has no money and no candies.
//
//
//
// Each day looks as follows:
//
// In the morning, Alice receives her allowance.
// At noon, Alice checks whether she has some candies. If she still has some candies, she does nothing. If she has no candies, she uses her money to buy as many candies as she currently can.
// In the evening, Alice eats one candy.
//
//
//
//
// For the given x, y, and z, we want to calculate the amount of money Alice has left at the end of day z.
// (Alice may also have some candies at the end of day z. We are not interested in those.)
//
//
//
// You are given multiple queries (x,y,z) and you have to process all of them.
// More precisely, you are given vector <int>s X, Y, and Z, each with Q elements.
// For each valid i, you must answer the query with x=X[i], y=Y[i], and z=Z[i].
// Return a vector<long long> with Q elements: the answers to the queries, in the same order.
//
//
// DEFINITION
// Class:CandyAddict
// Method:solve
// Parameters:vector <int>, vector <int>, vector <int>
// Returns:vector<long long>
// Method signature:vector<long long> solve(vector <int> X, vector <int> Y, vector <int> Z)
//
//
// CONSTRAINTS
// -The number of queries will be between 1 and 100, inclusive.
// -X, Y, Z will contain same number of elements.
// -Each element of X, Y and Z will be between 1 and 1,000,000,000, inclusive.
// -For each valid i, Y[i] <= X[i].
//
//
// EXAMPLES
//
// 0)
// {5}
// {3}
// {3}
//
// Returns: {6 }
//
// There is only one query.
// In this query, Alice receives 5 dollars each day, a candy costs 3 dollars, and there are 3 days.
// The entire process will look as follows:
//
// Day 1 morning: Alice receives 5 dollars. She now has 5 dollars and 0 candies.
// Day 1 noon: Alice has no candies, so she buys one. She now has 2 dollars and 1 candy.
// Day 1 evening: Alice eats a candy. She now has 2 dollars and 0 candies.
// Day 2 morning: Alice receives 5 dollars. She now has 7 dollars and 0 candies.
// Day 2 noon: Alice has no candies, so she buys two. She now has 1 dollar and 2 candies.
// Day 2 evening: Alice eats a candy. She now has 1 dollar and 1 candy.
// Day 3 morning: Alice receives 5 dollars. She now has 6 dollars and 1 candy.
// Day 3 noon: Alice still has some candies, so she does nothing. She still has 6 dollars and 1 candy.
// Day 3 evening: Alice eats a candy. She now has 6 dollars and 0 candies.
//
// Hence, at the end of day 3 Alice will have 6 dollars.
//
// 1)
// {5,5,5,5,5}
// {3,3,3,3,3}
// {1,2,3,4,5}
//
// Returns: {2, 1, 6, 2, 7 }
//
//
//
// 2)
// {1000000000,1000000000,1000000000,1000000000,1000000000}
// {1,2,3,999999998,999999999}
// {342568368,560496730,586947396,386937583,609483745}
//
// Returns: {342568367000000000, 60496729000000000, 253614062000000001, 773875166, 609483745 }
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
