#include "camera.h"
#include "face.h"

void RT_Camera_Construct(RT_Camera *camera, SDL_Surface* screen, int w, int h) 
{
    camera->width = w;
    camera->height = h;
    camera->scale = 2.0;
    camera->render = &RT_Camera_SimpleRender;
    camera->screen = screen;
}

void RT_Camera_SimpleRender(const void *self, RT_Scene *scene) 
{
    RT_Camera *camera = (RT_Camera*)self;
    int i, j, k;
    for(i=0; i<camera->width; i++) 
        for(j=0; j<camera->height; j++) 
        {
            RT_Ray current_ray;
            current_ray.o.e[0] = 250;
            current_ray.o.e[1] = 250;
            current_ray.o.e[2] = -500;
            current_ray.d.e[0] = -320*(i-camera->width/2)/camera->width;
            current_ray.d.e[1] = -240*(j-camera->height/2)/camera->height;
            current_ray.d.e[2] = 280;
            
            float t, best_t = 99999999;
            
            int hit = 0, best_index;
            
            for(k=0; k<scene->face_count; k++)
            {
                RT_Face *f = &scene->face_list[k];
                
                if (RT_Face_Intersect(f, scene, &current_ray, &t))
                {
                    hit = 1; 
                    if (t<best_t) 
                    {
                        best_t = t;
                        best_index = k;
                    }
                }
            }
            if (hit) 
            {
                int material_index = scene->face_list[best_index].material_index;
                obj_material *mat = &scene->material_list[material_index];
                
                setpixel(camera->screen, i, j, mat->diff[0]*255, mat->diff[1]*255, mat->diff[2]*255 );
            }
        }    
}


void setpixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B)
{
    Uint32 color = SDL_MapRGB(screen->format, R, G, B);
    
    switch (screen->format->BytesPerPixel) {
        case 1: { /* Assuming 8-bpp */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *bufp = color;
        }
        break;

        case 2: { /* Probably 15-bpp or 16-bpp */
            Uint16 *bufp;

            bufp = (Uint16 *)screen->pixels + y*screen->pitch/2 + x;
            *bufp = color;
        }
        break;

        case 3: { /* Slow 24-bpp mode, usually not used */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *(bufp+screen->format->Rshift/8) = R;
            *(bufp+screen->format->Gshift/8) = G;
            *(bufp+screen->format->Bshift/8) = B;
        }
        break;

        case 4: { /* Probably 32-bpp */
            Uint32 *bufp;

            bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x;
            *bufp = color;
        }
        break;
    }
}



