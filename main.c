#include <stdio.h>
#include <string.h>
#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 30

int main(void) {
    char sentence[MAX_SENTENCE_LENGTH];
    int word[MAX_WORD_LENGTH + 1] = {0};
    int count = 0;
    printf("Nhap vao cau: \n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        size_t length = strlen(token);
        if (length <= MAX_WORD_LENGTH) {
            word[length]++;
            count++;
        }
        token = strtok(NULL, " ");
    }
    int tu = 0, mau = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word[i] > 0) {
            tu += i * word[i];
            mau += i;
        }
    }
    printf("Trung binh trong so: %.2f", count > 0 ? 1.0 * tu / mau : 0.0);
    return 0;
}
