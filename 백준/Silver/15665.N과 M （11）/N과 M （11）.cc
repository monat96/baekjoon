#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> picked;

void func(int size, int toPick, int pick)
{
    if(toPick == pick)
    {
        for(int i = 0; i < toPick; i++)
            cout << arr[picked[i]] << ' ';
        cout << '\n';
        return ;
    }
    for(int i = 0; i < size; i++)
    {
        picked.push_back(i);
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
    bool check[10'001];

    while(n--)
    {
        int x;
        cin >> x;
        if(check[x]) continue;
        arr.push_back(x);
        check[x] = true;
    }
    sort(arr.begin(), arr.end());
    func(arr.size(), m, 0);
    return 0;
}
