#include <stdio.h>
#include "obj_loader/obj_parser.h"

//converted scene has very short load time, because of binary data format
//usage:
//obj_convert in.obj out.scene

int main(int argc, char* argv[])
{
    int i;
    RT_SceneData data;
    RT_Scene header;
    
    if(argc != 3 || !parse_obj_scene(&data, argv[1])) 
    {
        puts("Unable to load scene");
        return -1;
    }
    
    header.vertex_count = data.vertex_count;
    header.vertex_normal_count = data.vertex_normal_count;
    header.face_count = data.face_count;
    header.material_count = data.material_count;
    
    FILE *p_file;
    p_file = fopen(argv[2], "wb");
    
    if(!p_file) 
    {
        puts("Destination is not writable");
        return -1;
    }
    
    fwrite(&header, 1, sizeof(RT_Scene), p_file);    

	for(i=0; i<data.vertex_count; i++)
	{
	    obj_vector *o = data.vertex_list[i];
    	fwrite(o, 1, sizeof(RT_Vector), p_file);    
    }
    
    for(i=0; i<data.vertex_normal_count; i++)
	{
	    obj_vector *o = data.vertex_normal_list[i];
    	fwrite(o, 1, sizeof(RT_Vector), p_file);    
    }
    
	for(i=0; i<data.face_count; i++)
	{
	    obj_face *o = data.face_list[i];
	    fwrite(o, 1, sizeof(RT_Face), p_file); 
    }
    
	for(i=0; i<data.material_count; i++)
	{
	    obj_material *o = data.material_list[i];
	    fwrite(o, 1, sizeof(RT_Material), p_file); 
    }
    
    fclose (p_file);
    delete_obj_data(&data);
    puts("Data successfully written");
    return 0;
}


