#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8];
vector<int> picked;

void func(int size, int toPick, int pick)
{
    if(toPick == pick)
    {
        for(auto val : picked) cout << arr[val] << ' ';
        cout << '\n';
        return ;
    }
    int start = picked.empty() ? 0 : picked.back();
    for(int next = start; next < size; next++)
    {
        picked.push_back(next);
        func(size, toPick, pick+1);
        picked.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    func(n, m, 0);
    return 0;
}
