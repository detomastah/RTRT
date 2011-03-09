#include "face.h"
#include "vector.h"

int RT_Face_Intersect(RT_Face *face, RT_Scene *scene, RT_Ray *ray, float *t_hit) 
{
    RT_Vector *p1 = &scene->vertex_list[ face->vertex_index[0] ];
    RT_Vector *p2 = &scene->vertex_list[ face->vertex_index[1] ];
    RT_Vector *p3 = &scene->vertex_list[ face->vertex_index[2] ];
    RT_Vector e1 = RT_Vector_Sub(p2, p1);
    RT_Vector e2 = RT_Vector_Sub(p3, p1);
    RT_Vector s1 = RT_Vector_Cross(&ray->d, &e2);    
    float divisor = RT_Vector_Dot(&s1, &e1);
    if (divisor == 0.0)
        return 0;
    float invDivisor = 1.0/divisor;
    //first barycentric
    RT_Vector d = RT_Vector_Sub(&ray->o, p1);
    float b1 = RT_Vector_Dot(&d, &s1)*invDivisor;
    if (b1<0.0 || b1>1.0)
        return 0;
    //second barycentric
    RT_Vector s2 = RT_Vector_Cross(&d, &e1);
    float b2 = RT_Vector_Dot(&ray->d, &s2)*invDivisor;
    if (b2<0.0 || b1+b2>1.0)
        return 0;       
    float t = RT_Vector_Dot(&e2, &s2)*invDivisor;
    //if (t<min
    *t_hit = t;
    return 1;
}
