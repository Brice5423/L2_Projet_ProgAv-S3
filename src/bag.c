#include "../include/bag.h"

struct retained_t *new_bag() {
    struct retained_t *bagpack;

    bagpack = (struct retained_t *) calloc(1, sizeof(struct retained_t));

    bagpack->objects_list = (struct list_t *) calloc(1, sizeof(struct list_t));
    assert(bagpack->objects_list);

    return bagpack;
}

void bagcpy(struct retained_t *newBagpack, const struct retained_t *bagpack) {
    newBagpack->objects_list = listcpy(bagpack->objects_list);
    newBagpack->utilities_sum = bagpack->utilities_sum;
}

void free_bag(struct retained_t *bagpack) {
    assert(bagpack);
    del_list(bagpack->objects_list, &rmObject);
    free(bagpack);
    bagpack = NULL;
}

void clean_bag(struct retained_t *bagpack) {
    assert(bagpack);
    del_list(bagpack->objects_list, &rmInteger);

    bagpack->objects_list = new_list();
    assert(bagpack->objects_list);
    bagpack->utilities_sum = 0;
}

void push_object_in_bag(struct retained_t *bagpack, struct object_t *object) {
    cons(bagpack->objects_list, object);
    bagpack->utilities_sum += object->utility;
}

void view_bagpack(struct retained_t *bagpack, const char *title) {
    void (*ptr_view_fct)(const struct object_t *) = &view_object;

    printf("\n*****************\nVIEW BAGPACKAGING\t%s\t\tbagpack->objects_list->numElm : %i (view_bagpack)\n", title, bagpack->objects_list->numElm);
    view_list(bagpack->objects_list, ptr_view_fct);
    printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}