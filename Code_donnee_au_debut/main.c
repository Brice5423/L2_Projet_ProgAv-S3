int main(int argc, char **argv) {
    /** @brief main parameters are :
      * - argc : # of parameters
    * - argv : a vector of string ; each one is a parameter (as a string) */
    if (argc < 4) {
        fprintf(stderr, "USAGE\n\tdp Mode(R|A|L) Utilié(0|1) Vmax vol_1, use_1 ..., vol_n, use_n\n");
        fprintf(stderr, "\t* Mode is\n");
        fprintf(stderr, "\t\t- R for recursive approach,\n");
        fprintf(stderr, "\t\t- A for array approach,\n");
        fprintf(stderr, "\t\t- L for list approach\n");
        fprintf(stderr, "\t* Utilité prend 1 pour des objets avec utilités, 0 sinon\n");
        fprintf(stderr, "\t* Vmax is for bag max volume\n");
        fprintf(stderr, "\t* vol_i is for #i object's volume, i in {1, ... , n}");
        fprintf(stderr, "\t* use_i is for #i object's utility, i in {1, ... , n}");
        exit(-1);
    }