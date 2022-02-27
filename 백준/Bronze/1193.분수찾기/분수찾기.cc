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

    int n;
    cin >> n;
    int idx = 1;
    for (; idx * (idx + 1) / 2 < n; idx++);
    int sub = idx*(idx+1)/2 - n;
    if (idx%2==0)
        cout << idx-sub<<'/'<<1+sub;
    else
        cout << 1+sub<<'/'<<idx-sub;

    return 0;
}