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

#define gcd(a, b) __gcd(a, b)
#define SZ(a) (int) a.size()

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    

class HappyLetterDiv2 {
public:
	
	char getHappyLetter(string letters) {
		string s;
		int i, j, happy = 0, k;
		char ret = '.';
		for(i = 'a'; i <= 'z'; i++)
		{
			s = letters;
			for(j = 0; j < SZ(s); j++)
			{
				if(s[j] == i || s[j] == -1) continue;
				for(k = 0; k < SZ(s); k++)
				{
					if(s[j] == s[k] || s[k] == i || s[k] == -1) continue;
					s[j] = s[k] = -1;
					break;
				}
			}
			int cnt = 0, have = 0, gone = 0;
			for(j = 0; j < SZ(s); j++)
			if(s[j] != i && s[j] != -1)
				cnt++;
			for(j = 0; j < SZ(s); j++)
			if(s[j] == i)
				have++;
			for(j = 0; j < SZ(s); j++)
			if(s[j] == -1)
				gone++;
			if(cnt < have && have != gone)
			{
				happy++;
				ret = i;
			}
		}
		if(happy == 1)
			return ret;
		return '.';
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	ManySquares *obj;
	int answer;
	obj = new ManySquares();
	clock_t startTime = clock();
	answer = obj->howManySquares(p0);
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
	
	vector <int> p0;
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {1,1,2,2,1,1,2};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {3,1,4,4,4,10,10,10,10};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3};
	p1 = 3;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,1,1,2,2,2,3,3,3,4,4,4};
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,1,1,2,1,1,1,3,1,1,1};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {2,2,4,4,8,8};
	p1 = 0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
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
// You found a box from an old game.
// The box contains a lot of sticks and a manual.
// Frustrated by the fact the manual was unreadable, you decided to invent your own game with the sticks.
// In your game, the goal is to use the sticks to build as many squares as possible.
// There are only two rules:
// 
// Each stick can only be used in one square.
// Each square must consist of exactly 4 sticks. That is, you cannot combine two or more sticks to create one side of the square.
// 
// 
// You are given a vector <int> sticks.
// The elements of sticks are the lengths of the sticks you have.
// Return the maximum number of squares you can make.
// 
// 
// DEFINITION
// Class:ManySquares
// Method:howManySquares
// Parameters:vector <int>
// Returns:int
// Method signature:int howManySquares(vector <int> sticks)
// 
// 
// NOTES
// -If you can't make any square, return 0.
// 
// 
// CONSTRAINTS
// -sticks will contain between 1 and 50 elements.
// -Each element of sticks will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1,2,2,1,1,2}
// 
// Returns: 1
// 
// You can build a square with side 1.
// 
// 
// 1)
// {3, 1, 4, 4, 4, 10, 10, 10, 10}
// 
// 
// Returns: 1
// 
// You can build a square with side 10. You cannot build a square with side 4. (Note that you are not allowed to use 3+1 instead of a 4.)
// 
// 
// 2)
// {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3}
// 
// Returns: 3
// 
// 
// 
// 3)
// {1,1,1,2,2,2,3,3,3,4,4,4}
// 
// Returns: 0
// 
// Sometimes you can't make any square.
// 
// 
// 4)
// {1,1,1,2,1,1,1,3,1,1,1}
// 
// Returns: 2
// 
// 
// 
// 5)
// {2,2,4,4,8,8}
// 
// Returns: 0
// 
// You are also not allowed to break the sticks.
// 
// 
// END KAWIGIEDIT TESTING//Powered by KawigiEdit-pf 2.3.0
//With unused code cleaner (beta) by ahmed_aly
