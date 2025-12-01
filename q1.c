#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, index_lowest, update_index;
    int *stock;
    int total = 0;
    float avg;

    printf("Enter the number of book categories: ");
    scanf(" %d", &n);

    stock = (int*) malloc(n * sizeof(int));
    
    if (stock == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    
    printf("\nEnter the stock quantity for each category:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("Category %d: ", i);
        scanf(" %d", &stock[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        total += stock[i];
    }
    
    avg = (float)total / n;
    int min = 999;
    for (int i = 0; i < n; i++)
    {
        if (stock[i] < min)
        {
            min = stock[i];
            index_lowest = i;
        }
    }
    
    printf("\n-----Results-----\n");
    printf("Total Stocks: %d\n", total);
    printf("Average stock per category: %.2f\n", avg);
    printf("Category with the lowest stock: %d\n", index_lowest+1);

    printf("Enter the category number to update stock: ");
    scanf(" %d", &update_index);

    if ((update_index - 1) >= 0 && (update_index - 1) < n)
    {
        printf("Enter new stock value: ");
        scanf(" %d", &stock[update_index - 1]);
        printf("Updated! Category %d now has %d items.\n", update_index, stock[update_index - 1]);
    }
    else
    {
        printf("Invalid category number!\n");
    }

    free(stock);
    return 0;
}
