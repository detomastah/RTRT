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

#include <stdio.h>
#include <SDL/SDL.h>

#define WIDTH 320
#define HEIGHT 240
#define BPP 4
#define DEPTH 32

#include "camera.h"

int main(int argc, char* argv[])
{
    SDL_Surface *screen;
    SDL_Event event;
  
    int keypress = 0;
    int h=0; 
  
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return 1;
   
    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_HWSURFACE)))
    {
        SDL_Quit();
        return 1;
    }
    
    int i, j;
    Scene s;
    s.LoadFromFile(argv[1]);
    
    /*
    if(parse_obj_scene(&data, "cornell_box.obj")) {
        printf("Face count: %d\n", data.face_count);
    	for(i=0; i<data.face_count; i++)
    	{
		    obj_face *o = data.face_list[i];
		    printf(" face ");
		    for(j=0; j<3; j++)
		    {
			    printVector(data.vertex_list[ o->vertex_index[j] ]);
		    }
		    printf("\n");
	    }
    }
    
    */

  
    while(!keypress) 
    {
        RT_Camera cam;
        RT_Camera_Construct(&cam, screen, WIDTH, HEIGHT);
        if(SDL_MUSTLOCK(screen)) 
        {
            if(SDL_LockSurface(screen) < 0) return 1;
        }
        cam.render(&cam, &s);
        if(SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
        SDL_Flip(screen); 
         //DrawScreen(screen,h++);
         while(SDL_PollEvent(&event)) 
         {      
              switch (event.type) 
              {
                  case SDL_QUIT:
	              keypress = 1;
	              break;
                  case SDL_KEYDOWN:
                       keypress = 1;
                       break;
              }
         }
    }
    
    SDL_Quit();

    return 0;
}


