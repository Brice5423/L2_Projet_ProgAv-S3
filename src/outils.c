//
// Created by brice on 28/12/2021.
//

#include "../include/outils.h"

void rmInteger(int *i) {
    assert(i);
    free(i);
}
