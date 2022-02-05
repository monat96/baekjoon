#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
#include <queue>
#include <list>
#include <stack>

using namespace std;


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, toPick;
    int arr[8];
    cin >> n >> toPick;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    do {
        for(int i = 0; i < toPick; i++) cout << arr[i] << ' ';
        cout << '\n';
        reverse(arr + toPick, arr + n);
    }while(next_permutation(arr, arr + n));
    return 0;
}