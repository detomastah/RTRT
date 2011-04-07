/* 
    RTRT source code
    Copyright (C) 2011  Łukasz Pełszyński

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "camera.h"

void RT_Camera_Construct(RT_Camera *camera, SDL_Surface* screen, int w, int h) 
{
    camera->width = w;
    camera->height = h;
    camera->scale = 2.0;
    camera->render = &RT_Camera_SimpleRender;
    camera->screen = screen;
}

void RT_Camera_SimpleRender(const void *self, Scene *scene) 
{
    RT_Camera *camera = (RT_Camera*)self;
    int i, j, k;
    for(i=0; i<camera->width; i++) 
        for(j=0; j<camera->height; j++) 
        {
            Ray r;
            r.o = Point(250,250,-500);
            float rdx = -320*(i-camera->width/2)/camera->width;
            float rdy = -240*(j-camera->height/2)/camera->height;
            r.d = Vector(rdx, rdy ,280);
            
            Intersection i;
            
            if (scene->Intersect(&r, &i)) 
            {
                //int material_index = scene->face_list[best_index].material_index;
                //Material *mat = scene->materials[material_index];
                
                //setpixel(camera->screen, i, j, mat->diff[0]*255, mat->diff[1]*255, mat->diff[2]*255 );
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



