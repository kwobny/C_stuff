#include <stdio.h>
#include <string.h>

#define INIT_CHARACTER_SET(set) {\
    .size = sizeof(set),\
    .elements = set,\
}

typedef struct {
    size_t size;
    char *elements;
} character_set_t;

const character_set_t characterSets[] = {
    INIT_CHARACTER_SET("abcdefghijklmnopqrstuvwxyz"),
    INIT_CHARACTER_SET("0123456789"),
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
        const character_set_t *character_set = characterSets;
        for ( ; character_set - characterSets < sizeof(characterSets)/sizeof(characterSets[0]); character_set++) {
            location = strchr(character_set->elements, i);
            if (location != NULL)
                break;
        }

        // If character is a letter or digit,
        // shift it the specified number of places
        // down the alphabet/digits.
        // Wrap around if it hits the end.
        if (location != NULL) {
            size_t offset = (location + shift_amount - character_set->elements) % character_set->size;
            location = character_set->elements + offset;
        }

        int return_code = putchar(location == NULL ? i : *location);
        if (return_code == EOF) {
            return 1;
        }
    }
    return 0;
}
