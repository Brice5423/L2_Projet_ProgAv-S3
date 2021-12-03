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
