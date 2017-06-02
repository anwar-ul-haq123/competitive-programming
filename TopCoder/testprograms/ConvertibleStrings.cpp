#include <bits/stdc++.h>

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
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define F(i, n) for(i = 0; i < n; i++)

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
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define SZ 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/


class ConvertibleStrings {
public:
	int leastRemovals(string A, string B) {
	_
    char ataken[100], taken[100], bond[100][100];
    int i, j, mx, tem, k, l, a[100][100], b[100][100];
    clr(a, 0), clr(b, 0), clr(bond, 0), clr(taken, 0);
    for(i = 0; i < A.size(); i++)
    {
        a[A[i]][B[i]]++;
        b[B[i]][A[i]]++;
    }
    for(i = 'A'; i <= 'I'; i++)
    {
        mx = 0, l = 0;
        for(j = 'A'; j <= 'I'; j++)
        {
            int mxa = a[i][j], mxb = 0;
            for(k = 'A'; k <= 'I'; k++)
            {
                mxb = max(b[j][k], mxb);
            }
            if(b[j][i] == mxb)
            {
                if(mx < mxb)
                {
                    mx = mxb;
                    l = j;
                }
            }
        }
        taken[i] = l;
    }
    int cnt = 0;
    for(i = 0; i < A.size(); i++)
    {
        if(B[i] != taken[A[i]] && taken[A[i]] != 0)
            cnt++;
    }
    return cnt;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	ConvertibleStrings *obj;
	int answer;
	obj = new ConvertibleStrings();
	clock_t startTime = clock();
	answer = obj->leastRemovals(p0, p1);
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
	all_right = true;

	string p0;
	string p1;
	int p2;

	{
	// ----- test 0 -----
	p0 = "DD";
	p1 = "FF";
	p2 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "AAAA";
	p1 = "ABCD";
	p2 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "AAIAIA";
	p1 = "BCDBEE";
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "ABACDCECDCDAAABBFBEHBDFDDHHD";
	p1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE";
	p2 = 9;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Let X and Y be two strings of equal length, consisting of uppercase English letters only.
// The two strings are called convertible if there is a permutation P of the English alphabet with the following property:
// if each character c in the string X is replaced by the character P(c), we obtain the string Y.
// (In other words, X and Y are convertible iff the following holds: whenever two letters of X are equal, the corresponding two letters of Y must be equal, and vice versa.)
//
// For example, consider the string "ABCA".
// We can choose to replace each 'A' by a 'F', each 'B' by a 'B', and each 'C' by a 'G', obtaining the string "FBGF".
// Thus the strings "ABCA" and "FBGF" are convertible.
// The strings "ABCA" and "EFGH" are not convertible, because the two 'A's in the first string must correspond to the same letter in the second string.
// The strings "ABCA" and "EEEE" are not convertible, because different letters in the first string must correspond to different letters in the second string.
//
// You are given two strings A and B of the same length.
// These strings only contain English letters from 'A' to 'I', inclusive.
// (That is, only the first 9 letters of the alphabet are used.)
//
// You want to change A and B into two strings that are convertible.
// The only allowed change is to choose some indices (possibly none) and to remove the characters at those indices from each of the strings.
// (I.e., the removed characters must be at the same positions in both strings. For example, it is not allowed to only remove character 0 of A and character 3 of B.)
// For example, if A="ABAC", B="AHHA" and the chosen indices are 0 and 2, then the resulting strings will be "BC" and "HA".
// Our goal is to choose as few indices as possible, given that after the erasing we want to obtain two convertible strings.
// Compute and return the smallest possible number of chosen indices.
//
//
// DEFINITION
// Class:ConvertibleStrings
// Method:leastRemovals
// Parameters:string, string
// Returns:int
// Method signature:int leastRemovals(string A, string B)
//
//
// CONSTRAINTS
// -A will contain between 1 and 50 characters, inclusive.
// -A and B will be of the same length.
// -A will contain characters from 'A' to 'I' only.
// -B will contain characters from 'A' to 'I' only.
//
//
// EXAMPLES
//
// 0)
// "DD"
// "FF"
//
// Returns: 0
//
// The given strings are convertible without any removals. Any mapping with 'D' mapped to 'F' changes A to B.
//
// 1)
// "AAAA"
// "ABCD"
//
// Returns: 3
//
// We can choose any three indices.
//
// 2)
// "AAIAIA"
// "BCDBEE"
//
// Returns: 3
//
// One possible triple of indices is (1, 2, 5) (0-based indices).
//
//
// 3)
// "ABACDCECDCDAAABBFBEHBDFDDHHD"
// "GBGCDCECDCHAAIBBFHEBBDFHHHHE"
//
// Returns: 9
//
//
//
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
