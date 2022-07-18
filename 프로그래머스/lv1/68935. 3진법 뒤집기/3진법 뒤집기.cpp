#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solution(int n) {
    ll trinary = 0;
    ll answer = 0;
    while (n > 0) {
        trinary = 10 * trinary + (n % 3);
        n /= 3;
    }
    int digit = 1;
    while (trinary > 0) {
        answer += (trinary % 10) % 3 * digit;
        digit *= 3;
        trinary /= 10;
    }
    return answer;
}