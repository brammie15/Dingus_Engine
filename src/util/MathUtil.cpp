//
// Created by Bram on 22/04/2022.
//

#include "MathUtil.h"

float random(float min, float max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

float map(float n,float start1, float stop1, float start2,float stop2) {
    return (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
};