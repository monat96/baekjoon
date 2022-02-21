#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1'000'000;

int dp[5'001];
int arr[5'001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    for(int i = 1; i <= str.length(); i++) arr[i] = str[i-1] - '0';
    dp[0] = 1;
    for(int i = 1; i <= str.length(); i++) {
        if(arr[i] > 0) dp[i] = (dp[i] + dp[i-1]) % mod;
        int digit = arr[i-1] * 10 + arr[i];
        if(digit >= 10 && digit <= 26) dp[i] = (dp[i] + dp[i-2]) % mod;
    }
    cout << dp[str.length()];
    return 0;
}
