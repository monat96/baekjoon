#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int dp[100001];

    for (size_t i = 0; i < N + 1; i++)
        dp[i] = i;

    for (size_t i = 2; i < N + 1; i++)
        for (size_t j = 0; j * j < i + 1; j++)
            if (dp[i] > dp[i - j * j] + 1) dp[i] = dp[i - j * j] + 1;

    cout << dp[N] << "\n";
    return 0;
}
