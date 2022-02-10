#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        multimap<int, int> mm;

        cin >> n;

        while (n--)
        {
            char cmd;
            int val;
            cin >> cmd >> val;
            if (cmd == 'I')
                mm.insert({val, 0});
            else
            {
                if (mm.empty())
                    continue;
                multimap<int, int>::iterator iter;
                if (val > 0)
                    iter = mm.lower_bound(mm.rbegin()->first);
                else
                    iter = mm.lower_bound(mm.begin()->first);
                mm.erase(iter);
            }
        }
        if (mm.empty())
            cout << "EMPTY\n";
        else
            cout << mm.rbegin()->first << ' ' << mm.begin()->first << '\n';
    }
    return 0;
}