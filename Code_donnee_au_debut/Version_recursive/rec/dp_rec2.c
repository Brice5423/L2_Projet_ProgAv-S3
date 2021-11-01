void p_rec(const int Vmax, struct objects_t * object_set, struct retained_t * bagpack) {
  const int nb_objects = object_set->nb_objects;
  struct retained_t * duplicata = ...;
  bagcpy(...);
  // Prediction : the bag utility before any new object put into it
  int first = object_set->first_idx;
  struct retained_t * best_bagpack = ...;
  bagcpy(...);
  // Verification by trying the other objects
  for(int obj_idx ...) {
    struct object_t * ptr_object = ...;
    int curr_volume = ...;
    if(...) {
      bagcpy(...);
      push_object_in_bag(...);
      object_set->first_idx = ...;
      p_rec(...);
      if(...) {
        clean_bag(...);
        bagcpy(...);
      }
    }
  }
  clean_bag(bagpack);
  bagcpy(bagpack, best_bagpack);
  free_bag(best_bagpack);
  free_bag(duplicata);
}