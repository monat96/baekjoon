#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cctype>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<pair<int, int>> stck;
    stck.push({100000001, 0});
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++)
    {
        int x;
        cin >> x;
        while(stck.top().first < x) stck.pop();
        cout << stck.top().second << ' ';
        stck.push({x, i});
    }
    return 0;
}