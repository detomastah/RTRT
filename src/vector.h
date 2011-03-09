#ifndef VECTOR
#define VECTOR

#include "basics.h"

RT_Vector RT_Vector_Cross(RT_Vector *v1, RT_Vector *v2);
RT_Vector RT_Vector_Sub(RT_Vector *v1, RT_Vector *v2);
RT_Vector RT_Vector_Add(RT_Vector *v1, RT_Vector *v2);
float RT_Vector_Dot(RT_Vector *v1, RT_Vector *v2);

#endif
