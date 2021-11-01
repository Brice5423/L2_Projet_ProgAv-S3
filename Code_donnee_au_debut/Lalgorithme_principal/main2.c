//int main(int argc, char **argv) {
    const char mode = argv[1][0];
    const bool utility = (atoi(argv[2]) == 0) ? false : true;
    const int Vmax = atoi(argv[3]);
    struct retained_t *retained_objects = new_bag();
    struct objects_t *object_set = new_objects(argc, argv, utility);

    #ifdef _TRACE_
    fprintf(stderr, "mode=%c usefullness=%c Vmax=%d\n", mode, (utility)?'U':'N', Vmax);
    fprintf(stderr, "Object set full with %d objects\n", object_set->nb_objects);
    view_objet_set(object_set);
    #endif

    if (mode == 'R') {
        struct retained_t *my_bag = new_bag();
        prec(Vmax, object_set, my_bag);
        view_bagpack(my_bag, "Final selection");
    } else if (mode == 'A') {
        dp_array(Vmax, object_set);
    } else {
        dp_list(Vmax, object_set);
    }
    return EXIT_SUCCESS;
}