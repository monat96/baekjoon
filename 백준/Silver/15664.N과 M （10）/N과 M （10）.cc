#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8];
vector<int> picked;
bool isUsed[8];


void func(int size, int toPick, int pick)
{
    if(toPick == pick)
    {
        for(int i = 0; i < toPick; i++)
            cout << arr[picked[i]] << ' ';
        cout << '\n';
        return ;
    }
    int tmp = 0;
    int start = picked.empty() ? 0 : picked.back() + 1;
    for(int i = start; i < size; i++)
    {
        if(isUsed[i] || tmp == arr[i]) continue;
        isUsed[i] = true;
        picked.push_back(i);
        
        tmp = arr[i];
        func(size, toPick, pick + 1);

        isUsed[i] = false;
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
