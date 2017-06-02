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

class CandyMaking {
public:

    vector <int> vol, weight;

    double get(double den)
    {
        double ret = 0;
        for(int i = 0; i < SZ(vol); i++)
        {
            ret += abs((den * vol[i]) - (double) weight[i]);
        }
        return ret;
    }

    double call(void)
    {
        double lef, rig, a, b;
        int i;
        double lowdist, highdist;
        double mn = *max_element(all(weight)) * 2;
        a = 0, b = mn;
        for(i = 0; i < 1000; i++)
        {
            lef = (a * 2.0 + b) / 3.0;

            rig = (a + b * 2.0) / 3.0;

            lowdist = get(lef);
            highdist = get(rig);
            if(lowdist > highdist)
            {
                mn = highdist;
                a = lef;
            }
            else
            {
                mn = lowdist;
                b = rig;
            }
        }
        return mn;
    }

	double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
		vol = containerVolume;
		weight = desiredWeight;
		return call();
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2) {
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
	CandyMaking *obj;
	double answer;
	obj = new CandyMaking();
	clock_t startTime = clock();
	answer = obj->findSuitableDensity(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	double p2;

	// ----- test 0 -----
	disabled = false;
	p0 = {5};
	p1 = {1000};
	p2 = 0.0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {10,10};
	p1 = {1000,2000};
	p2 = 1000.0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {10,20,40};
	p1 = {4000,2000,1000};
	p2 = 5250.0;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121};
	p1 = {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223};
	p2 = 983673.2727272725;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = {30621,30620,2};
	p1 = {1,1,1000000};
	p2 = 999999.9999673415;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 5 -----
	disabled = false;
	p0 = {1};
	p1 = {1000000};
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
//
// Alice likes making candy.
// Recently, she promised to make candy for all her classmates.
// Alice has N classmates.
// We will number them 0 through N-1, inclusive.
//
//
//
// Each of the classmates brought Alice one container for the candy.
// Each of the classmates also has a desired total weight of their candy.
// You are given this information as two vector <int>s with N elements each: containerVolume and desiredWeight.
// For each i, the volume of the container brought by classmate i is containerVolume[i] liters, and he or she expects the candy in the container to weigh desiredWeight[i] grams.
//
//
//
// Alice has promised to fill all containers with candy completely.
// However, she only has the time to make one type of candy, with constant density.
// This means that she might be unable to meet the exact desired weights of candy.
//
//
//
// Alice now needs to choose the density of the candy she is going to make.
// In order to make everyone as happy as possible, Alice decided that she wants to minimize the sum of differences between desired and actual weights.
// In other words:
// For each classmate, we compute the positive difference between the desired and actual weight of candy they received.
// Then, we sum all those differences.
// Alice needs to choose the density of her candy so that this sum becomes as small as possible.
//
//
//
// Compute and return the minimum sum  of differences between desired and actual weights.
//
//
// DEFINITION
// Class:CandyMaking
// Method:findSuitableDensity
// Parameters:vector <int>, vector <int>
// Returns:double
// Method signature:double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight)
//
//
// NOTES
// -Your return value must have an absolute or a relative error at most 1e-9.
//
//
// CONSTRAINTS
// -N will be between 1 and 50.
// -containerVolume and desiredWeight will each contain exactly N elements.
// -Each element of containerVolume and desiredWeight will between 1 and 1,000,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {5}
// {1000}
//
// Returns: 0.0
//
// There is one classmate. Her container has 5 liters and she expects 1000 grams of candy. Alice should choose the density of 200 grams per liter. The sum of differences between desired and actual weights is 0.
//
// 1)
// {10,10}
// {1000,2000}
//
// Returns: 1000.0
//
// There are two classmates. They have a 10-liter container each. However, one of them wants 1000 grams of candy and the other wants 2000 grams. There is no way for Alice to satisfy both of them exactly. (Note that she must always fill all containers completely.)
//
// There are multiple optimal choices for the density. For these choices, the sum of differences between desired and actual weights is 1000.
//
// 2)
// {10,20,40}
// {4000,2000,1000}
//
// Returns: 5250.0
//
//
//
// 3)
// {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121}
// {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223}
//
// Returns: 983673.2727272725
//
//
//
// 4)
// {30621,30620,2}
// {1,1,1000000}
//
// Returns: 999999.9999673415
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
