#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    do {
        for (auto ret : arr) cout << ret << ' ' ;
        cout << '\n';
    }while(next_permutation(arr.begin(), arr.end()));
    
	return 0;
}