#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cassert>
#include <map>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string cmd;
    cin >> cmd;
    
    int idx[] = {1, 0, 0};

    for(auto ch : cmd)
    {
        if(ch == 'A') swap(*idx, *(idx+1));
        else if(ch == 'B') swap(*(idx + 1) , *(idx + 2));
        else swap(*(idx + 2), *idx);
    }
    int i = find(idx, idx + 3, 1) - idx;
    cout << i + 1;
    return 0;
}
