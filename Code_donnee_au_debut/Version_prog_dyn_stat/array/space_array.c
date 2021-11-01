void free_states_array(struct states_array_t * states) {
  assert(states);
  /** TODO **/
}

struct states_array_t * new_states_array(const int num_objects, const int Vmax) {
  struct states_array_t * NS = ...;
  assert(NS != NULL);

	/** TODO **/
  init_opt_chm(NS);
  return NS;
}
