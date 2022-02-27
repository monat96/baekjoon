#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, p, v;
    for(int i = 1;;i++)
    {
        cin >> l >> p >> v;
        int ans = 0;
        if(l == 0 && p == 0 && v == 0) break;
        ans += (v / p * l);
        ans += min(v % p, l);
        cout << "Case "<<i<<": "<<ans <<'\n';
    }

    return 0;
}