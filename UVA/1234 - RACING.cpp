#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return p.w < w;
    }
};

int par[10005], res;

int find_set(int node);
void mst(int n);

vector <edge> e;

int main()
{
    int n, m, i, test;
    edge t;
    while(scanf("%d", &test) && test)
        {
            while(test--)
                {
                    scanf("%d %d", &n, &m);
                    for(i = 1; i <= n; i++)
                        par[i] = i;
                    for(i = 1; i <= m; i++)
                        {
                            scanf("%d %d %d", &t.u, &t.v, &t.w);
                            e.pub(t);
                        }
                    res = 0;
                    mst(n);
                    printf("%d\n", res);
                    e.clear();
                }
        }
    return 0;
}

int find_set(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_set(par[node]);
}

void mst(int n)
{
    sort(e.begin(), e.end());
    for(int i = 0; i < e.size(); i++)
        {
            int u = find_set(e[i].u);
            int v = find_set(e[i].v);
            if(u == v)
                res += e[i].w;
            else
                par[u] = v;
        }
}
