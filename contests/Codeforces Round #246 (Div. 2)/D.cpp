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

#define MAX 500010
/*************************************************HABIJABI ENDS HERE******************************************************/
struct info
{
    int tup[2], indx; //tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

int sorted[18][MAX], LCP[MAX], step;
string text;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array()
{
    int i, n = SZ(text), jump;
    for(i = 0; i < n; i++)
    {
        sorted[0][i] = text[i] - 'A'; //rank suffixes according to 1st char
//        clr(arr[i].tup, 0);
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(i = 0; i <=n; i++)
        {
            arr[i].indx = i;
            arr[i].tup[0] = sorted[step - 1][i]; // what i was in prev step
            arr[i].tup[1] = i + jump < n? sorted[step - 1][i + jump] : -1;
        }
        sort(arr, arr + n, comp);
        sorted[step][arr[0].indx] = 0;
        for(i = 1; i < n; i++)
            sorted[step][arr[i].indx] = arr[i].tup[0] == arr[i - 1].tup[0] &&
            arr[i].tup[1] == arr[i - 1].tup[1] ? sorted[step][arr[i - 1].indx] : i;
    }
}

void build_LCP_array()
{
    LCP[0] = 0;
    int n = SZ(text), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        for(j = step - 1; j >= 0; j--)
            if(sorted[j][id1] == sorted[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
    }
}

int left_limit, right_limit;

int get_low(int cur)
{
    char ch = text[cur];
    int low = left_limit, high = right_limit, mid, ret;
    while(low <= high)
    {
//        cout << low << ' ' << high << endl;
        mid = (low + high) / 2;
        if(arr[mid].indx + cur < SZ(text) && text[arr[mid].indx + cur] > ch)
            high = mid - 1;
        else if(arr[mid].indx + cur < SZ(text) && text[arr[mid].indx + cur] < ch)
            low = mid + 1;
        else if(arr[mid].indx + cur < SZ(text) && text[arr[mid].indx + cur] == ch)
            high = mid - 1, ret = mid;
        else
            low = mid + 1;
    }
    return ret;
}

int get_high(int cur)
{
    char ch = text[cur];
    int low = left_limit, high = right_limit, mid, ret;
    while(low <= high)
    {
//        cout << low << ' ' << high << endl;
        mid = (low + high) / 2;
        if(arr[mid].indx + cur < SZ(text) && text[arr[mid].indx + cur] > ch)
            high = mid - 1;
        else if(arr[mid].indx + cur < SZ(text) && text[arr[mid].indx + cur] < ch)
            low = mid + 1;
        else if(arr[mid].indx + cur < SZ(text) && text[arr[mid].indx + cur] == ch)
            low = mid + 1, ret = mid;
        else
            low = mid + 1;
    }
    return ret;
}

int get_match(int id1, int id2)
{
    int j, ret = 0;
    for(j = log2(SZ(text)) + 1; j >= 0; j--)
        if(sorted[j][id1] == sorted[j][id2] && id2 < SZ(text))
        {
            ret += (1 << j);
            id1 += (1 << j);
            id2 += (1 << j);
        }
    return ret;
}

vector <pair <int, int> > ans;

int main()
{
    CF
    while(cin >> text)
    {
        build_suffix_array();
        build_LCP_array();
//        printSA();
        int l = 0, r = SZ(text) - 1, len = 1;
        left_limit = 0, right_limit = SZ(text) - 1;
        while(l < SZ(text))
        {
//            cout << left_limit << ' ' << right_limit << endl;
            int low = get_low(l);
            int high = get_high(l);
            if(get_match(0, r) == len)
                ans.pb(make_pair(len, high - low + 1));
            left_limit = low;
            right_limit = high;
            l++, r--, len++;
        }
        cout << SZ(ans) + 1 << endl;
        for(int i = 0; i < SZ(ans); i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
        cout << SZ(text) <<  " 1" << endl;
    }
    return 0;
}


