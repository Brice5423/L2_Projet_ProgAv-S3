void view_chm(const struct states_array_t * states) {
  printf("CHM |\t");
	for(int bag = 0; bag < (states->Vmax + 1); bag += 1) printf("%2d\t", bag);
	printf("\n----|");
	for(int bag = 0; bag < (states->Vmax + 1); bag += 1) printf("--------");
	printf("\n");
	for(int obj = 0; obj < (states->num_obj + 1); obj += 1) {
		printf("%3d |\t", obj);
		for(int bag = 0; bag < (states->Vmax + 1); bag += 1) {
			int idx = obj * (states->Vmax + 1) + bag;
			if(states->CHM[idx] == INFTY) {
				printf("PRE\t");
			} else if(states->CHM[idx] == UNDTR) {
				printf("UND\t");
			} else {
				printf("%2d\t", states->CHM[idx]);
			}
		}
		printf("\n");
	}
	printf("\n");
}