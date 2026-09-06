#include <stdio.h>
void bucketSort(int a[], int n)
{
    int bucket[100] = {0};
    int i, j = 0;
    for (i = 0; i < n; i++)
        bucket[a[i]]++;
    for (i = 0; i < 100; i++)
    {
        while (bucket[i] > 0)
        {
            a[j++] = i;
            bucket[i]--;
        }
    }
}
int main()
{
    int a[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements (0-99):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bucketSort(a, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}