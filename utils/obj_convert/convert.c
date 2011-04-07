#include <stdio.h>
#include "obj_loader/obj_parser.h"

//converted scene has very short load time, because of binary data format
//usage:
//obj_convert in.obj out.scene

int main(int argc, char* argv[])
{
    int i;
    RT_SceneData data;
    
    if(argc != 3 || !parse_obj_scene(&data, argv[1])) 
    {
        puts("Unable to load scene");
        return -1;
    }
    
    FILE *p_file;
    p_file = fopen(argv[2], "wb");
    
    if(!p_file) 
    {
        puts("Destination is not writable");
        return -1;
    }
    
    fwrite(&data.vertex_count, 1, sizeof(int), p_file);
    fwrite(&data.face_count, 1, sizeof(int), p_file);
    fwrite(&data.material_count, 1, sizeof(int), p_file);        

    for(i=0; i<data.vertex_count; i++)
	{
	    obj_vector *v = data.vertex_list[i];	    
	    fwrite(v, 1, sizeof(obj_vector), p_file);
    }

    
	for(i=0; i<data.face_count; i++)
	{
	    obj_face *f = data.face_list[i];
	    int *vi = f->vertex_index;
    	fwrite(vi, 3, sizeof(int), p_file);
    }
    
	for(i=0; i<data.face_count; i++)
	{
	    obj_face *f = data.face_list[i];
	    fwrite(&f->material_index, 1, sizeof(int), p_file);
    }
    
	for(i=0; i<data.material_count; i++)
	{
	    obj_material *m = data.material_list[i];
	    fwrite(m, 1, sizeof(obj_material), p_file); 
    }
    
    fclose (p_file);
    delete_obj_data(&data);
    puts("Data successfully written");
    return 0;
}


