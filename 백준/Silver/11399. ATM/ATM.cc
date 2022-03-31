#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else 
        return 0;
}
int main()
{
    int n;
    int *ary;
    int cnt = 0;

    scanf("%d", &n);

    ary = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &ary[i]);

    qsort(ary, n, sizeof(int), compare);

    for(int i = 1; i < n; i++)
        ary[i] += ary[i - 1];

    for(int i = 0; i < n; i++)
        cnt += ary[i];

    printf("%d", cnt);
    return 0;
}