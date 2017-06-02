#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

using namespace std;


class FoxAndClassroom {
public:
	string ableTo(int n, int m) {
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	FoxAndClassroom *obj;
	string answer;
	obj = new FoxAndClassroom();
	clock_t startTime = clock();
	answer = obj->ableTo(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	int p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 3;
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 6;
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 6;
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 5;
	p1 = 7;
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 10;
	p1 = 10;
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// Fox Ciel is now in high school.
// The seats in her classroom are arranged into an n by m matrix.
// The rows are numbered from 0 to n-1 (front to back) and the columns from 0 to m-1 (left to right).
// 
// 
// 
// At the beginning, Ciel can choose any of the seats.
// Then, at the end of each week Ciel will shift one row to the back and one column to the right, wrapping around whenever necessary.
// Formally, if her current seat is in row r and column c, then her seat next week will be the one in row ((r+1) modulo n) and column ((c+1) modulo m).
// 
// 
// 
// Fox Ciel now wonders whether she can sit in all the seats in the classroom if she follows the above procedure.
// As we already mentioned, she can start in any of the seats.
// Also, she can attend the school for as many weeks as she wants to.
// Return "Possible" if she can sit in all the seats and "Impossible" otherwise.
// 
// DEFINITION
// Class:FoxAndClassroom
// Method:ableTo
// Parameters:int, int
// Returns:string
// Method signature:string ableTo(int n, int m)
// 
// 
// CONSTRAINTS
// -n will be between 2 and 10, inclusive.
// -m will be between 2 and 10, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 3
// 
// Returns: "Possible"
// 
// We will use (r,c) to denote the chair at row r, column c.
// Suppose Ciel starts at (1,0).
// In the following weeks she will then sit at (0,1), (1,2), (0,0), (1,1), (0,2), (1,0) again, (0,1) again, and so on.
// We can see that already after 6 weeks Ciel sat in all the seats.
// 
// 1)
// 2
// 2
// 
// Returns: "Impossible"
// 
// Suppose that she starts at (0,0).
// Then the next week she will sit at (1,1) and the week after that she will be back at (0,0).
// She would never sit at (0,1) and (1,0).
// Similarly we can show that none of the other starting positions work.
// 
// 2)
// 4
// 6
// 
// Returns: "Impossible"
// 
// 
// 
// 3)
// 3
// 6
// 
// Returns: "Impossible"
// 
// 
// 
// 4)
// 5
// 7
// 
// Returns: "Possible"
// 
// 
// 
// 5)
// 10
// 10
// 
// Returns: "Impossible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
