#include "../include/outils.h"

void rmInteger(int *i) {
    assert(i);
    free(i);
}
