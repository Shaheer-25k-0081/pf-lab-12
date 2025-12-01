#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    char choice;

    printf("Enter the number of movie categories: ");
    scanf(" %d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory Allocation Failed!");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter your rating for category # %d: ", i+1);
        scanf(" %d", &arr[i]);
    }

    printf("Do you want to change rating of any of the category?\nY: Yes\nN: No\nYour Choice: ");
    scanf(" %c", &choice);

    tolower(choice);
    if (choice == 'y')
    {
        int num;
        printf("Which category do you want to change rating of: ");
        scanf(" %d", &num);

        printf("Enter your new rating for this category: ");
        scanf(" %d", &arr[num - 1]);
    }
    
    
    int sum = 0;
    float avg;
    int highest_rating = 0;
    for (int i = 0; i < n; i++)
    {   
        if (arr[i] > highest_rating)
        {
            highest_rating = i;
        }
        
        sum += arr[i];
    }
    avg = (float)sum / n;

    printf("Total ratings across all categories = %d\n", sum);
    printf("Average ratings per category = %.2f\n", avg);
    printf("Category with the highest rating count is %d", highest_rating);

    free(arr);

    return 0;
}
