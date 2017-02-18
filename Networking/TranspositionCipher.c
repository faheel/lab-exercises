#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAX_KEY_SIZE 8

void find_column_order(char key[], int column_order[]) {
    int i, j, pos, min_index;
    int marked[MAX_KEY_SIZE] = {0};
    char min;

    for (i = 0, pos = 0; i < strlen(key); i++) {
        min = CHAR_MAX;
        min_index = -1;
        for (j = 0; j < strlen(key); j++) {
            if (!marked[j] && key[j] < min) {
                min = key[j];
                min_index = j;
            }
        }
        if (min_index == -1)
            break;
        column_order[pos++] = min_index;
        marked[min_index] = 1;
        printf("%d, ", column_order[pos-1]);
    }
}

void str_to_matrix(char plain_text[], char plain_text_matrix[][MAX_KEY_SIZE], int key_length) {
    int row, col, i;

    for (row = 0, i = 0; i < strlen(plain_text); row++) {
        for (col = 0; col < key_length && i < strlen(plain_text); col++) {
            plain_text_matrix[row][col] = plain_text[i++];
            printf("%c", plain_text_matrix[row][col]);
        }
        printf("\n");
    }
}

void transposition_cipher(char plain_text[], char key[], char cipher_text[]) {
    char plain_text_matrix[MAX_LENGTH / MAX_KEY_SIZE + 1][MAX_KEY_SIZE];

    str_to_matrix(plain_text, plain_text_matrix, strlen(key));

    int column_order[MAX_KEY_SIZE];
    find_column_order(key, column_order);

    printf("\nCipher text : ");
    int row, col, i;
    for (i = 0; i < strlen(key); i++) {
        col = column_order[i];
        for (row = 0; row < strlen(key); row++) {
            printf("%c", plain_text_matrix[row][col]);
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    char plain_text[MAX_LENGTH];
    char key[MAX_KEY_SIZE];
    char cipher_text[MAX_LENGTH];

    printf("Enter plain-text : ");
    scanf("%s", plain_text);

    printf("Enter key : ");
    scanf("%s", key);

    transposition_cipher(plain_text, key, cipher_text);

    return 0;
}
