#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> picked;

void func(int size, int toPick, int pick)
{
    if(toPick == pick)
    {
        for(auto val : picked) cout << val << ' ';
        cout << '\n';
        return ;
    }
    int start = picked.empty() ? 1 : picked.back();
    for(int next = start; next <= size; next++)
    {
        picked.push_back(next);
        func(size, toPick, pick + 1);
        picked.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    func(n, m, 0);
    
    return 0;
}
