#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[16];
vector<int> picked;
bool check()
{
    int cnt = 0;
    for(auto ch : picked)
    {
        char chk = arr[ch];
        if(chk == 'a' || chk == 'o' || chk == 'e' || chk == 'i' || chk == 'u') cnt++;
    }
    return cnt >= 1 && (picked.size() - cnt) >= 2;
}
void func(int size, int toPick, int pick)
{
    if(toPick == pick)
    {   
        if(check()) {
            for(auto val : picked)
                cout << arr[val];
            cout << '\n';
        }
        return ;
    }
    int start = picked.empty() ? 0 : picked.back() + 1;
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

    int m, n;
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    func(n, m, 0);
    return 0;
}
