#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_category(char c) {
    if (isupper(c)) return 0;
    if (islower(c)) return 1;
    if (isdigit(c)) return 2;
    return 3;
}

double calculate_similarity(char *pattern, char *password) {
    int pattern_len = strlen(pattern);
    int password_len = strlen(password);
    int min_len = pattern_len < password_len ? pattern_len : password_len;
    
    int match_count = 0;
    for (int i = 0; i < min_len; i++) {
        if (get_category(pattern[i]) == get_category(password[i])) {
            match_count++;
        }
    }
    
    return ((double)match_count / pattern_len) * 100;
}

int main() {
    int num_participants;
    
    printf("Enter number of participants: ");
    scanf("%d", &num_participants);
    
    char *pattern = (char*)malloc(100 * sizeof(char));
    printf("Enter password pattern: ");
    scanf("%s", pattern);
    
    char **passwords = (char**)malloc(num_participants * sizeof(char*));
    double *scores = (double*)malloc(num_participants * sizeof(double));
    
    for (int i = 0; i < num_participants; i++) {
        passwords[i] = (char*)malloc(100 * sizeof(char));
        printf("Enter password for participant %d: ", i + 1);
        scanf("%s", passwords[i]);
        scores[i] = calculate_similarity(pattern, passwords[i]);
    }
    
    printf("\nSimilarity scores:\n");
    for (int i = 0; i < num_participants; i++) {
        printf("Password: %s - Similarity: %.2f%%\n", passwords[i], scores[i]);
    }
    
    int max_index = 0;
    for (int i = 1; i < num_participants; i++) {
        if (scores[i] > scores[max_index]) {
            max_index = i;
        }
    }
    
    printf("\nPassword with highest similarity: %s (%.2f%%)\n", passwords[max_index], scores[max_index]);
    
    for (int i = 0; i < num_participants; i++) {
        free(passwords[i]);
    }
    free(passwords);
    free(scores);
    free(pattern);
    
    return 0;
}
