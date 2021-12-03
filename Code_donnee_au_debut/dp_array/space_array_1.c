void push_object_in_array(struct states_array_t *S, struct objects_t *LO, int i) {
    /* Faites attention que les objets dans LO sont rangés à partir de 0
     * tandis qu'ils sont rangés à partue de 1 dans OPT (et CHM) */
    for (int bag = 0; bag < (S->Vmax + 1); bag += 1) {
        // Parcourir chaque état du sac-à-dos
        int pred = ...; // Calculer l'index de l'état pour l'objet (i-1)
        int curr = ...; // Calculer l'index de l'état pour l'objet (i)
        int OPT1 = S->OPT[pred];
        S->CHM[curr] = INFTY; //hyp.: l'objet i n'est pas dans le sac
        if (...) { // S'il y a de la place dans le sac
            int pred_without_i = ...; // L'index du bag SANS l'objet (i)
            int OPT2 = ...;
            if (...) { // Sélectionne la meilleur configuration
                S->OPT[curr] = ...;
                S->CHM[curr] = ...; // Noter que l'objet i est dans le sac
            } else states->OPT[curr] = ...;
        } else states->OPT[curr] = ...; // S'il n'y a pas de place
    }
}