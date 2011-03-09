#include "vector.h"

RT_Vector RT_Vector_Cross(RT_Vector *v1, RT_Vector *v2) {
    RT_Vector ret_val;
    ret_val.e[0] = v1->e[1]*v2->e[2] - v1->e[2]*v2->e[1];
    ret_val.e[1] = v1->e[2]*v2->e[0] - v1->e[0]*v2->e[2];
    ret_val.e[2] = v1->e[0]*v2->e[1] - v1->e[1]*v2->e[0];
    return ret_val;
}

RT_Vector RT_Vector_Sub(RT_Vector *v1, RT_Vector *v2) {
    RT_Vector ret_val;
    ret_val.e[0] = v1->e[0]-v2->e[0];
    ret_val.e[1] = v1->e[1]-v2->e[1];
    ret_val.e[2] = v1->e[2]-v2->e[2];
    return ret_val;
}

RT_Vector RT_Vector_Add(RT_Vector *v1, RT_Vector *v2) {
    RT_Vector ret_val;
    ret_val.e[0] = v1->e[0]+v2->e[0];
    ret_val.e[1] = v1->e[1]+v2->e[1];
    ret_val.e[2] = v1->e[2]+v2->e[2];
    return ret_val;
}

float RT_Vector_Dot(RT_Vector *v1, RT_Vector *v2) {
    return v1->e[0]*v2->e[0] + v1->e[1]*v2->e[1] + v1->e[2]*v2->e[2];
}
