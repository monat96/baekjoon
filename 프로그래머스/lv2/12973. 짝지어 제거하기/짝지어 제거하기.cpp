#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stck;
    for(auto ch : s) {
        bool isSame = false;
        while(!stck.empty() && ch == stck.top()) {
            isSame=true;
            stck.pop();
        }
        if(!isSame) stck.push(ch);
    }
    return stck.empty();
}