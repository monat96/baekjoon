#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
#include <queue>
#include <list>
#include <stack>
#include <stdio.h>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    vector<string> pckmn;
    map<string, int> pckmn_map;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        pckmn.push_back(s);
        pckmn_map.insert({s, i});

    }
    while(m--) {
        string s;
        cin >> s;
        if(s[0] >= '0' && s[0] <= '9')
            cout << pckmn[stoi(s) - 1]  << '\n';
        else
            cout << pckmn_map[s] << '\n';
    }
    return 0;
}

