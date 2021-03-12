#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 44 ms 17.1 MB
int findContentChildren_v1(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    auto gi = g.begin();
    auto si = s.begin();
    int sum = 0;
    while (gi != g.end() && si != s.end())
    {
        cout << *gi << " " << *si << endl;
        if (*gi > *si)
        {
            // 如果不能满足孩子的胃口，饼干移动到下一个
            si++;
        }
        else
        {
            // 能够满足孩子的胃口，孩子、饼干后移，匹配数加1
            gi++;
            si++;
            sum++;
        }
    }
    return sum;
}
// 32 ms 17.1 MB
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    auto gi = g.begin();
    auto si = s.begin();
    auto ge = g.end();
    auto se = s.end();
    int sum = 0;
    while (gi != ge && si != se)
    {
        if (*gi <= *si)
        {
            gi++;
            sum++;
        }
        si++;
    }
    return sum;
}

int main()
{
    vector<int> g{1, 2, 3}, s{1, 1};
    cout << findContentChildren(g, s) << endl;
}