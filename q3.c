#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int containDigit(char *str) {
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;

    printf("Enter the number of usernames: ");
    scanf(" %d", &n);
    getchar();

    char **usernames = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++)
    {
        usernames[i] = malloc(100 * sizeof(char));
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter string: ");
        fgets(usernames[i], 100, stdin);
    }
    
    int newSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (!containDigit(usernames[i]))
        {
            usernames[newSize] = usernames[i];
            newSize ++;
        }
        else
        {
            free(usernames[i]);
        }
    }
    n = newSize;

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", usernames[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        free(usernames[i]);
    }
    free(usernames);
    return 0;
}
