#include <stdio.h>
#include <string.h>

const char *const characterSets[] = {
    "abcdefghijklmnopqrstuvwxyz",
    "0123456789",
};

int main(void) {
    for (int i = getchar(); i != EOF; i = getchar()) {
        char *location = NULL;
        for (size_t j = 0; j < sizeof(characterSets) && location == NULL; j++) {
            location = strchr(characterSets[i], i);
        }

hello:
        // If character is a letter or digit
        if (location != NULL)
            location += 1;
    }
    return 0;
}
