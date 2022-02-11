#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int arr[3];
int dpMin[3];
int dpMax[3];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dpMin, dpMin + 3, 0);
    fill(dpMax, dpMax + 3, 0);
    
    int n;
    cin >> n;

    for(int i = 0 ; i < n; i++) {

        for(int j = 0; j < 3; j++) {
            cin >> arr[j];
        }
        int tmpMin[3];
        int tmpMax[3];

        copy(dpMin, dpMin + 3, tmpMin);
        copy(dpMax, dpMax + 3, tmpMax);

        for(int j = 0; j < 3; j++) {
            int max = tmpMax[j];
            if(j + 1 < 3 && max < tmpMax[j+1]) max = tmpMax[j+1];
            if(j - 1 >= 0 && max < tmpMax[j-1]) max = tmpMax[j-1];
            dpMax[j] = max + arr[j];

            int min = tmpMin[j];
            if(j + 1 < 3 && min > tmpMin[j+1]) min = tmpMin[j+1];
            if(j - 1 >= 0 && min > tmpMin[j-1]) min = tmpMin[j-1];
            dpMin[j] = min + arr[j];
        }      
    }
    cout << *max_element(dpMax, dpMax + 3) << ' ' << *min_element(dpMin, dpMin + 3);
    
    return 0;
}