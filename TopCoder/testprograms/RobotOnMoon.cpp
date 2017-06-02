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
//template <class T> void show(T a){cout << a << endl;}
//template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

class RobotOnMoon {
public:
	int longestSafeCommand(vector <string> board) {
	    int i, j, si, sj;
	    for(i = 0; i < SZ(board); i++)
            for(j = 0; j < SZ(board[0]); j++)
                if(board[i][j] == 'S')
                {
                    si = i, sj = j;
                    break;
                }
        for(i = 0; i < SZ(board[si]); i++)
            if(board[si][i] == '#')
                return -1;
        for(i = 0; i < SZ(board); i++)
            if(board[i][sj] == '#')
                return -1;
        return SZ(board) + SZ(board[0]) - 2;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	RobotOnMoon *obj;
	int answer;
	obj = new RobotOnMoon();
	clock_t startTime = clock();
	answer = obj->longestSafeCommand(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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

	vector <string> p0;
	int p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {"#####","#...#","#.S.#","#...#","#####"};
	p1 = -1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {"S......"};
	p1 = 6;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {"#.######","#.#..S.#","#.#.##.#","#......#","########"};
	p1 = -1;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {"S"};
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
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
// There is a robot on the moon.
// You are given a vector <string> board containing the map of a rectangular area.
// The robot is currently located somewhere in that area.
// In the map, the character '.' (period) represents an empty square, 'S' represents an empty square that currently contains the robot, and '#' represents an obstacle.
//
//
// We are going to send a sequence of commands to the robot.
// Each command must be one of 'U', 'D', 'L', and 'R', representing a step up, down, left, and right, respectively.
//
//
// Whenever the robot receives a command, one of three things will happen:
//
// If the requested move leads to an empty square, the robot performs the move.
// If the requested move leads to a square with an obstacle, the robot ignores the command and remains in place.
// If the requested move leads out of the mapped area, the robot leaves the mapped area and dies immediately.
//
//
//
// A sequence of commands is called safe if the robot is still alive after executing the entire sequence.
//
//
// When sending commands to the moon, some of them may get lost along the way.
// This may sometimes change a safe sequence of commands into an unsafe one.
// We want to avoid that.
//
//
// A sequence of commands is called perfectly safe if it is safe, and each of its subsequences is safe as well.
// (Note that this includes subsequences that are not contiguous.)
//
//
// Find and return the largest X such that there is a perfectly safe sequence of X commands.
// If there are arbitrarily long perfectly safe sequences, return -1 instead.
//
// DEFINITION
// Class:RobotOnMoon
// Method:longestSafeCommand
// Parameters:vector <string>
// Returns:int
// Method signature:int longestSafeCommand(vector <string> board)
//
//
// NOTES
// -The direction 'U' corresponds to moving from board[i][j] to board[i-1][j]. The direction 'L' corresponds to moving from board[i][j] to board[i][j-1].
//
//
// CONSTRAINTS
// -board will contain between 1 and 50 elements, inclusive.
// -Each element of board will contain between 1 and 50 characters.
// -Each element of board will contain same number of characters.
// -The characters in board will be '.', '#' or 'S'.
// -There will be exactly one 'S' in board.
//
//
// EXAMPLES
//
// 0)
// {"#####",
//  "#...#",
//  "#.S.#",
//  "#...#",
//  "#####"}
//
// Returns: -1
//
// There are obstacles all around the map. This means that all possible sequences of commands are perfectly safe.
//
// 1)
// {"S......"}
//
// Returns: 6
//
// The longest perfectly safe string is "RRRRRR"
//
// 2)
// {"#.######",
//  "#.#..S.#",
//  "#.#.##.#",
//  "#......#",
//  "########"}
//
// Returns: -1
//
// Even though it is possible to leave this map, there are still arbitrarily long perfectly safe sequences of commands. For example, any sequence that does not contain any 'U' is perfectly safe.
//
// 3)
// {"S"}
//
// Returns: 0
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
