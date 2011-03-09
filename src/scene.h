#ifndef SCENE
#define SCENE

#include "basics.h"

typedef struct 
{
    int vertex_count;
    int vertex_normal_count;
    int face_count;
    int material_count;
    
    RT_Face *face_list;
    RT_Vector *vertex_list;
    RT_Vector *vertex_normal_list;
    RT_Material *material_list;
} RT_Scene;

void RT_Scene_Load(RT_Scene *scene, char *file_name);

#endif
