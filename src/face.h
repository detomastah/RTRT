#ifndef FACE
#define FACE

#include "scene.h"

int RT_Face_Intersect(RT_Face *face, RT_Scene *scene, RT_Ray *ray, float *t_hit);

#endif
