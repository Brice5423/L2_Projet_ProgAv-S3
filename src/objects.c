#include "../include/objects.h"

struct objects_t *new_objects(const int argc, char **argv, bool utility) {
    struct objects_t *set;
    int offset;
    int i;

    set = (struct objects_t *) calloc(1, sizeof(struct objects_t));
    offset = 4;

    set->nb_objects = (utility) ? (argc - offset) / 2 : (argc - offset);
    set->objects = ...;

    if (utility) {
        int j;

        for (i = offset, j = 0; i < argc; i += 2, j++) {
            /** TODO **/
        }

    } else {
        for (i = offset; i < argc; i += 1) {
            /** TODO **/
        }
    }

    return set;
}

void view_object(const struct object_t *object) {
    printf("(%d , %d) ", object->volume, object->utility);
}

void view_objet_set(const struct objects_t *set) {
    printf("\n*** View objet set ***\n");
    for (int o = 0; o < set->nb_objects; o += 1) view_object(set->objects + o);
    printf("\n**********************\n");
}