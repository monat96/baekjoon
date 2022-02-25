#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int sign = 1, num = 0, ans = 0;

    for(auto ch : str)
    {
        if(ch == '+' || ch == '-') {
            ans += num * sign;
            if(ch == '-') sign = -1;
            num = 0;
        }
        else {
            num *= 10;
            num += (ch-'0');
        }
    }  
    ans += num * sign;
    cout << ans;

    return 0;
}