#include <bits/stdc++.h>

using namespace std;

#define MAX 100'001


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = 0;
    int minLen = MAX;
    long long tot_sum = arr[right];
    
    while(left <= right && right < n)
    {
        if(tot_sum < s)  {
            right++;
            tot_sum += arr[right];
        }
        else {
            int len = right - left + 1;
            if(minLen > len) minLen = len;

            tot_sum -= arr[left];
            left++;
        }
    }
    if(minLen == MAX) cout << 0;
    else cout << minLen;
    return 0;
}
