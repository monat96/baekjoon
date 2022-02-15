#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int arr[301];
    int dp[301];

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = max(arr[0] + arr[1], arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for (size_t i = 3; i < n; i++)
    {
        		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
    }
    cout << dp[n - 1] << endl;
    
    return 0;
}
