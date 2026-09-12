#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float ratio;
};

int main()
{
    struct Item item[100], temp;
    int n, capacity, i, j;
    float total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and value of each item:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].weight, &item[i].value);
        item[i].ratio = (float)item[i].value / item[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            total += item[i].value;
        }
        else
        {
            total += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", total);

    return 0;
}