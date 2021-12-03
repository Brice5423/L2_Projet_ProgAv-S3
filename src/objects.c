#include <stdio.h>
#include <stdbool.h>

#include "../include/objects.h"


struct objects_t *new_objects(int argc, char **argv, bool utility) {
    struct objects_t *set = ...;
    int i, offset = 4;
    set->nb_objects = (utility) ? (argc - offset) / 2 : (argc - offset);
    set->objects = ...;
    if (utility) {
        int j;
        for (i = offset, j = 0; i < argc; i += 2, j += 1) {
            /** TODO **/
        }
    } else
        for (i = offset; i < argc; i += 1) {
            /** TODO **/
        }
    return set;
}

void view_object(struct object_t *object) {
    printf("(%d , %d) ", object->volume, object->utility);
}

void view_objet_set(struct objects_t *set) {
    printf("\n*** View objet set ***\n");
    for (int o = 0; o < set->nb_objects; o += 1) view_object(set->objects + o);
    printf("\n**********************\n");
}