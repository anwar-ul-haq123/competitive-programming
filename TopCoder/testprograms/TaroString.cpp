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
#define infinity (1 << 28)
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

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

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

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

class TaroString {
public:
	string getAnswer(string S) {
	    int c = 0, a = 0, t = 0, i;
	    for(i = 0; i < SZ(S); i++)
        {
            if(S[i] == 'C')
                c++;
        }
	    for(i = 0; i < SZ(S); i++)
        {
            if(S[i] == 'A')
                a++;
        }
	    for(i = 0; i < SZ(S); i++)
        {
            if(S[i] == 'T')
                t++;
        }
        if(c != 1 || t != 1 || a != 1)
            return "Impossible";
        c = a = t = 0;
        for(i = 0; i < SZ(S); i++)
        {
            if(S[i] == 'C' && a == 0 && t == 0)
                c++;
            else if(S[i] == 'A' && c == 1 && t == 0)
                a++;
            else if(S[i] == 'T' && c == 1 && a == 1)
                t++;
        }
        if(c == 1 && t == 1 && a == 1)
            return "Possible";
        return "Impossible";
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	TaroString *obj;
	string answer;
	obj = new TaroString();
	clock_t startTime = clock();
	answer = obj->getAnswer(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	string p0;
	string p1;

	// ----- test 0 -----
	disabled = false;
	p0 = "XCYAZTX";
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = "CTA";
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = "ACBBAT";
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = "SGHDJHFIOPUFUHCHIOJBHAUINUIT";
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 4 -----
	disabled = false;
	p0 = "CCCATT";
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// Cat Taro has a string S.
// He wants to obtain the string "CAT" from the string S.
// In a single turn he can choose any character and erase all occurrences of this character in S.
// He can do as many turns as he wants (possibly zero).
//
//
//
//
// You are given the string S.
// Return "Possible" (quotes for clarity) if it is possible to obtain the string "CAT" and "Impossible" otherwise.
//
//
//
// DEFINITION
// Class:TaroString
// Method:getAnswer
// Parameters:string
// Returns:string
// Method signature:string getAnswer(string S)
//
//
// CONSTRAINTS
// -S will contain between 1 and 50 characters, inclusive.
// -S will contain only uppercase English letters ('A'-'Z').
//
//
// EXAMPLES
//
// 0)
// "XCYAZTX"
//
// Returns: "Possible"
//
// It is possible to obtain string "CAT" in three turns, as follows:
//
//
// Erase all characters 'X' (and obtain the string "CYAZT")
//
//
// Erase all characters 'Y' (and obtain the string "CAZT")
//
//
// Erase all characters 'Z' (and obtain the string "CAT")
//
//
//
// 1)
// "CTA"
//
// Returns: "Impossible"
//
//
//
// 2)
// "ACBBAT"
//
// Returns: "Impossible"
//
// Note that whenever you are erasing a character, you must erase all its occurrences. In this case, it is not possible to erase the first 'A' and keep the second one.
//
// 3)
// "SGHDJHFIOPUFUHCHIOJBHAUINUIT"
//
// Returns: "Possible"
//
//
//
// 4)
// "CCCATT"
//
// Returns: "Impossible"
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
