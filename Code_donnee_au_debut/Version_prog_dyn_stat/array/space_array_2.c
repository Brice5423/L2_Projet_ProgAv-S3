/**
 * Private Function
 **/
void init_opt_chm(struct states_array_t * states) {
    states->OPT = ...;
    states->CHM = ...;
    for( int obj = 1; obj <= states->num_obj; obj += 1) {
        for(int bag = 0; bag <= states->Vmax; bag += 1) {
            int idx = ...;
            states->OPT[idx] = UNDTR;
            states->CHM[idx] = UNDTR;
        }
    }
    for(int bag = 0; bag <= states->Vmax; bag += 1) {
        states->CHM[bag] = UNDTR;
    }
}