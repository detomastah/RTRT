#include "scene.h"
#include <stdio.h>
#include <stdlib.h>

void RT_Scene_Load(RT_Scene *scene, char *file_name) 
{
    FILE *p_file;
    p_file = fopen(file_name, "rb");
    
    fread(scene, 1, sizeof(RT_Scene), p_file);
    
    scene->vertex_count = scene->vertex_count;
    scene->vertex_list = (RT_Vector*)malloc(sizeof(RT_Vector)*scene->vertex_count);
    fread(scene->vertex_list, scene->vertex_count, sizeof(RT_Vector), p_file);
    
    scene->vertex_normal_count = scene->vertex_normal_count;
    scene->vertex_normal_list = (RT_Vector*)malloc(sizeof(RT_Vector)*scene->vertex_normal_count);
    fread(scene->vertex_normal_list, scene->vertex_normal_count, sizeof(RT_Vector), p_file);
    
    scene->face_count = scene->face_count;
    scene->face_list = (RT_Face*)malloc(sizeof(RT_Face)*scene->face_count);
    fread(scene->face_list, scene->face_count, sizeof(RT_Face), p_file);
    
    scene->material_count = scene->material_count;
    scene->material_list = (RT_Material*)malloc(sizeof(RT_Material)*scene->material_count);
    fread(scene->material_list, scene->material_count, sizeof(RT_Material), p_file);
    
    fclose(p_file);
}
