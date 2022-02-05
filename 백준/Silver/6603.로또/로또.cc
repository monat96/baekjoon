#include <stdio.h>
#include <stdlib.h>

void combination(int arr[], int n, int r, int index, int data[], int i)
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
    {
        return;
    }

    data[index] = arr[i];
    combination(arr, n, r, index + 1, data, i + 1);
    combination(arr, n, r, index, data, i + 1);
}

int main(int argc, char const *argv[])
{

    int *arr, *data;
    int n, r = 6;

    while (true)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        arr = (int *)malloc(sizeof(int) * n);
        data = (int *)malloc(sizeof(int) * r);

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        combination(arr, n, r, 0, data, 0);

        printf("\n");

        free(arr);
        free(data);
    }

    return 0;
}
