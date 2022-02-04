#include <stdio.h>
#include <stdlib.h>

void recursion(int arr[], int n, int r, int index, int data[], int i)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }
    if (i >= n)
        return;
    
    data[index] = arr[i];
    recursion(arr, n, r, index + 1, data, i + 1);
    recursion(arr, n, r, index, data, i + 1);
}
int main(int argc, char const *argv[])
{
    int n, r;
    int *arr, *data;

    scanf("%d %d", &n, &r);
    
    arr = (int *)malloc(sizeof(int) * n);
    data = (int *)malloc(sizeof(int) * r);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    recursion(arr, n, r, 0, data, 0);
    return 0;
}
