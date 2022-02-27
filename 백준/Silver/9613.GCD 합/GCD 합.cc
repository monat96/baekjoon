#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long ans = 0;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }
    

    return 0;
}