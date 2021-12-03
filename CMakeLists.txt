cmake_minimum_required(VERSION 3.20)
project(Projet_ProgAv_S3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_ProgAv_S3 src/main.c src/dp_rec.c include/prec.h src/objects.c include/objects.h src/dp_array.c src/space_array.c include/space_array.h include/global.h)
