void push_object_in_array(struct states_array_t * states,
													const struct objects_t * set,
													const int i) {
  for(int bag = 0; bag < (states->Vmax +1 ); bag += 1) {
 		// Pour l'objet courant (i-1), parcourir chaque état du sac-à-dos
 		// Identifier cet état pour l'étape précédente (i-1)
 		// Identifier cet état pour l'étape courante (i)
    int pred = ...;
    int curr = ...;
    int OPT1 = states->OPT[pred];
    states->CHM[curr] = INFTY; //hyp.: l'object i n'est pas dans le sac
    if(...) { // Il faut s'assurer qu'il y a de la place dans le sac
      int pred_without_i = ;
			int OPT2 = ;
			if() { // Sélectionne la meilleur configuration 
				states->OPT[curr] = ...;
				states->CHM[curr] = ...; // Noter que l'object i est dans le sac
			} else {
				states->OPT[curr] = ...;
			}
    } else {
        states->OPT[curr] = ...;
    }
  }
}