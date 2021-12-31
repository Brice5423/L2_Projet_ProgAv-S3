#include "../include/objects.h"

struct objects_t *new_objects(const int argc, char **argv, bool utility) {
    struct objects_t *set;
    int offset;
    int i;

    set = (struct objects_t *) calloc(1, sizeof(struct objects_t));

    offset = 4; // 4 Parce que ce sera à partir du 4ème argument que les objets sont declarer (./exe_projet mode(R|A|L) utilité(1|0) VMax volume1 utilité1 volume2 utilité2 par exemple)
    set->nb_objects = (utility) ? (argc - offset) / 2 : (argc - offset);

    // Voir si c'est bien "set->nb_objects" et non "1" pour le nombre d'objets
    set->objects = (struct object_t *) calloc(set->nb_objects, sizeof(struct object_t));

    if (utility) {
        int j;

        for (i = offset, j = 0; i < argc; i += 2, j++) {
            set->objects[j].volume = atoi(argv[i]);
            set->objects[j].utility = atoi(argv[i + 1]);
        }

    } else {
        for (i = offset; i < argc; i++) {
            set->objects[i - offset].volume = atoi(argv[i]);
            set->objects[i - offset].utility = atoi(argv[i]);
        }
    }

    return set;
}

void view_object(const struct object_t *object) {
    printf("(%d , %d) ", object->volume, object->utility);
}

void view_objet_set(const struct objects_t *set) {
    int o;

    printf("\n*** View objet set ***\tset->nb_objects : %i (view_objet_set)\n", set->nb_objects);
    for (o = 0; o < set->nb_objects; o++) {
        view_object(set->objects + o);
    }
    printf("\n**********************\n");
}

void rmObject(struct object_t *object) {
    assert(object);
    free(object);
}