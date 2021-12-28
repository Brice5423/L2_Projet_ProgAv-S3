cmake_minimum_required(VERSION 3.20)
project(Projet_ProgAv_S3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_ProgAv_S3 src/main.c src/dp_rec.c include/dp_rec.h src/objects.c include/objects.h src/space_array.c include/space_array.h include/global.h src/elmlist.c include/elmlist.h src/list.c include/list.h src/bag.c include/bag.h src/dp_array.c include/dp_array.h src/dp_list.c include/dp_list.h src/states.c include/states.h src/outils.c include/outils.h)
