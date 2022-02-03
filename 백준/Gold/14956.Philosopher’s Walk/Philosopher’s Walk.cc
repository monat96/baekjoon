#include <iostream>
#include <vector>

using namespace std;

pair<int, int> func(int side, int walk)
{
    if(side == 1) {
        if(walk == 1) return {1, 1};
        else if(walk == 2) return {1, 2};
        else if(walk == 3) return {2, 2};
        else return {2, 1};
    }

    int half = side / 2;
    int section = half * half;

    // Bottom left
    if(walk <= section) {
        pair<int, int> ret = func(half, walk);
        return {ret.second, ret.first};
    }
    // Upper left
    if(walk <= 2*section) {
        pair<int, int> ret = func(half, walk-section);
        return {ret.first, ret.second + half};
    }
    // Upper right
    if (walk <= 3*section) {
        pair<int, int> ret = func(half, walk-2*section);
        return {ret.first+half, ret.second+half};
    }
    // Bottom right
    pair<int, int> ret = func(half, walk-3*section);
    return {2*half - ret.second + 1, half - ret.first + 1};
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    pair<int, int> ret = func(n, m);
    cout << ret.first << ' ' << ret.second;

    return 0;
}
// Bottom left
// (1, 1) -> (1, 1)
// (1, 2) -> (2, 1)
// (2, 2) -> (2, 2)
// (2, 1) -> (1, 2)
// second, first

// Bottom right
// (1, 1) -> (4, 2)
// (1, 2) -> (3, 2)
// (2, 2) -> (3, 1)
// (2, 1) -> (4, 1)
// 2*half-second+1, half-first+1