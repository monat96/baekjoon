#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

const int S = 50;

int a[S];
int b[S];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    int ans = 0;
    sort(a, a + n);
    sort(b, b + n, [](const int a, const int b) {return a > b;});

    for(int i = 0; i < n; i++) ans += a[i] * b[i];
    cout << ans;

    return 0;
}
