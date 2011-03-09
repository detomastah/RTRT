#ifndef BASICS
#define BASICS

#define OBJ_FILENAME_LENGTH 500
#define MATERIAL_NAME_SIZE 255
#define OBJ_LINE_SIZE 500
#define MAX_VERTEX_COUNT 4 //can only handle quads or triangles

typedef struct
{
    float e[3];
} obj_vector, RT_Vector;

typedef struct 
{
    RT_Vector o; //origin
    RT_Vector d; //direction
} RT_Ray;

typedef struct
{
    int vertex_index[MAX_VERTEX_COUNT];
    int normal_index[MAX_VERTEX_COUNT];
    int texture_index[MAX_VERTEX_COUNT];
    int vertex_count;
    int material_index;
} obj_face, RT_Face;

typedef struct
{
    char name[MATERIAL_NAME_SIZE];
    char texture_filename[OBJ_FILENAME_LENGTH];
    float amb[3];
    float diff[3];
    float spec[3];
    float reflect;
    float refract;
    float trans;
    float shiny;
    float glossy;
    float refract_index;
} obj_material, RT_Material;

#endif
