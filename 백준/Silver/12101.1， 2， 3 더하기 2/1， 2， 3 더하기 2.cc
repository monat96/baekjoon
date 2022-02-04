#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int arr[] = {1, 2, 3};
int cnt = 0;
vector<int> picked;

void func(int n, int k, int tot)
{
    if(n == tot)
    {
        cnt++;
        if(k == cnt)
        {
            
            for(int i = 0; i < picked.size(); i++)
            {
                cout << picked[i];
                if(i < picked.size()-1) cout <<'+';
            }
        }
        return ;
    }
    for(auto val : arr)
    {
        if(tot + val > n) continue;
        picked.push_back(val);
        func(n, k, tot + val);
        picked.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    func(n, k, 0);
    if(cnt < k) cout << -1;
    return 0;
}