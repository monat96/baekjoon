#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void bt(vector<int> arr, vector<int> &picked, int toPick, int size)
{
    if(toPick == 0)
    {
        for(auto idx : picked) cout << arr[idx] << ' ';
        cout << '\n';
        return ;
    }

    for(int point = 0; point < size; point++)
    {
        picked.push_back(point);
        bt(arr, picked, toPick - 1, size);
        picked.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> picked;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    bt(arr, picked, m, n);
	return 0;
}
