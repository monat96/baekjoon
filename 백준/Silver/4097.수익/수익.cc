#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 1; i < n; i++)
            arr[i] = max(arr[i - 1] + arr[i], arr[i]);
        cout << *max_element(arr.begin(), arr.end()) << '\n';
    }
    
    return 0;
}
