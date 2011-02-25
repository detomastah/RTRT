typedef struct
{
	float e[3];
} obj_vector, RT_Vector;

typedef struct {
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

typedef struct {
	int vertex_count;
	int vertex_normal_count;
	int face_count;
	int material_count;
	
    RT_Face *face_list;
    RT_Vector *vertex_list;
	RT_Vector *vertex_normal_list;
	RT_Material *material_list;
} RT_Scene;
