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

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << '\n';
            n /= i;
        }
    }
    if (n != 1)
        cout << n;

    return 0;
}