#include <stdio.h>

void maxmin(int a[], int low, int high, int *max, int *min)
{
    int mid, max1, min1, max2, min2;

    if (low == high)
    {
        *max = *min = a[low];
        return;
    }

    if (high == low + 1)
    {
        if (a[low] > a[high])
        {
            *max = a[low];
            *min = a[high];
        }
        else
        {
            *max = a[high];
            *min = a[low];
        }
        return;
    }

    mid = (low + high) / 2;

    maxmin(a, low, mid, &max1, &min1);
    maxmin(a, mid + 1, high, &max2, &min2);

    *max = max1 > max2 ? max1 : max2;
    *min = min1 < min2 ? min1 : min2;
}

int main()
{
    int a[100], n, i, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    maxmin(a, 0, n - 1, &max, &min);

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}