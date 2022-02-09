#include <stdio.h>
#include <stdlib.h>

void printCombination(int *, int n, int r, int *sum, int k);
void combination(int arr[], int n, int r, int *sum, int k, int index, int data[], int i);
int arrSum(int arr[], int n);

int main(int argc, char const *argv[])
{
    int n, k, r = 3, sum = 0;
    int *arr;

    scanf("%d %d", &n, &k);

    arr = (int *)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printCombination(arr, n, r, &sum, k);
    
    return 0;
}
void printCombination(int arr[], int n, int r, int *sum, int k)
{
    int data[r];

    combination(arr, n, r, sum, k, 0, data, 0);

    printf("%d\n", *sum);
}
void combination(int arr[], int n, int r, int *sum, int k, int index, int data[], int i)
{
    if (index == r)
    {
        int x = arrSum(data, r);

        if (x <= k && abs(x - k) < abs(*sum - k))
            *sum = x;
        return;
    }
    if (i >= n)
    {
        return;
    }
    data[index] = arr[i];
    combination(arr, n, r, sum, k, index + 1, data, i + 1);
    combination(arr, n, r, sum, k, index, data, i + 1);
}
int arrSum(int arr[], int n)
{
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}