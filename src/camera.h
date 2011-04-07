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

#ifndef CAMERA
#define CAMERA

#include "scene.h"
#include <SDL/SDL.h>

typedef struct 
{
    int width;
    int height;
    double scale;
    SDL_Surface* screen;
    void (*render)(const void *self, Scene *scene);
} RT_Camera;

void RT_Camera_Construct(RT_Camera *camera, SDL_Surface* screen, int w, int h);
void RT_Camera_SimpleRender(const void *self, Scene *scene);
void setpixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);

#endif
