#ifndef PROJET_PROGAV_S3_OBJECTS_H
#define PROJET_PROGAV_S3_OBJECTS_H

struct object_t {
    int volume;
    int utility;
};

struct objects_t {
    struct object_t *objects;
    int nb_objects;
    int first_idx;
};

struct objects_t *new_objects(int argc, char **argv, bool utility);

void view_object(struct object_t *object);

void view_objet_set(struct objects_t *set);

#endif //PROJET_PROGAV_S3_OBJECTS_H
