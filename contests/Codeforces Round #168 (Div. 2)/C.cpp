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
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[SZ];

int main()
{
    map <int ,int> mp;
    int i, n, m = 0, k, num, cnt = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(i = 0; i < n; i++)
    {
        if(arr[i] % k == 0)
        {
            if(mp.find(arr[i] / k) == mp.end())
                mp[arr[i]]++;
        }
        else
            mp[arr[i]]++;
    }
    cout << mp.size();
    return 0;
}

