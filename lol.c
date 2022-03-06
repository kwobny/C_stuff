#include <stdio.h>
#include <search.h>

const char letters[] = "abcdefghijklmnopqrstuvwxyz";
const char digits[] = "0123456789";
size_t numberOfLetters = sizeof(letters)-1;
size_t numberOfDigits = sizeof(digits)-1;

int compareChar(const char *key, const char *other) {
    return *key - *other;
}

int main(void) {
    for (char i = getchar(); i != EOF; i = getchar()) {
        char *location = lfind(&i, letters, &numberOfLetters, sizeof(char), compareChar);
        if (location == NULL) {
            location = lfind(&i, digits, &numberOfDigits, sizeof(char), compareChar);
        }

hello:
        // If character is a letter or digit
        if (location != NULL)
            location += 1;
    }
    return 0;
}
