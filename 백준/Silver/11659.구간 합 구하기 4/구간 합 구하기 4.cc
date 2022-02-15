#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100'001];
int psum[100'001];

int get_psum(int start, int end)
{
    int ret = psum[end];
    if(start > 0) ret -= psum[start-1];
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    psum[1] = arr[1];
    for(int i = 2; i <= n; i++) psum[i] = psum[i-1] + arr[i];

    while(m--)
    {
        int i, j;
        cin >> i >> j;
        cout << get_psum(i, j) << '\n';
    }
    return 0;
}