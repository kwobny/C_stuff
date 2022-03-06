#include <stdio.h>
#include <string.h>

const char *const characterSets[] = {
    "abcdefghijklmnopqrstuvwxyz",
    "0123456789",
};

int main(int argc, char *argv[]) {
    int shift_amount = 1;
    for (int i = getchar(); i != EOF; i = getchar()) {
        // Skip current character if it is a null byte
        // to prevent strchr from matching it as part of
        // a character set.
        if (i == 0)
            continue;

        // Check if character is in one of the character sets,
        // i.e. if it is alphanumeric. If it is, then record its location
        // in the character set array.
        char *location = NULL;
        for (size_t j = 0; j < sizeof(characterSets) && location == NULL; j++) {
            location = strchr(characterSets[i], i);
        }

        // If character is a letter or digit,
        // shift it the specified number of places
        // down the alphabet/digits.
        if (location != NULL) {
            location += shift_amount;
        }
    }
    return 0;
}
