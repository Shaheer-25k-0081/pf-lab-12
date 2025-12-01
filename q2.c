#include <stdio.h>
#include <stdlib.h>

int main() {
    char **feedbacks;
    int n;

    printf("Enter the number of feedback entries: ");
    scanf("%d", &n);
    getchar();

    feedbacks = (char **) malloc(n * sizeof(char*));
    if (feedbacks == NULL)
        return 0;

    for (int i = 0; i < n; i++) {
        feedbacks[i] = (char *) malloc(1000 * sizeof(char));
        if (feedbacks[i] == NULL)
            return 0;

        printf("Enter feedback #%d: ", i + 1);
        fgets(feedbacks[i], 1000, stdin);
        char *newline = feedbacks[i];
        while (*newline != '\0') {
            if (*newline == '\n') {
                *newline = '\0';
                break;
            }
            newline++;
        }
    }

    int max_length = 0;
    char *longest_entry = NULL;

    for (int i = 0; i < n; i++) {
        int current_length = 0;
        char *current_char = feedbacks[i];
        while (*current_char != '\0') {
            current_length++;
            current_char++;
        }

        if (current_length > max_length) {
            max_length = current_length;
            longest_entry = feedbacks[i];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("-----Entry #%d-----\n", i + 1);
        printf("%s\n", feedbacks[i]);
    }

    printf("Longest Entry: %s\n", longest_entry);

    for (int i = 0; i < n; i++)
        free(feedbacks[i]);
    free(feedbacks);

    return 0;
}
