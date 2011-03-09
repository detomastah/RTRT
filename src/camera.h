#ifndef CAMERA
#define CAMERA

#include "scene.h"
#include <SDL/SDL.h>

typedef struct 
{
    int width;
    int height;
    double scale;
    RT_Vector origin, near_plane;
    SDL_Surface* screen;
    void (*render)(const void *self, RT_Scene *scene);
} RT_Camera;

void RT_Camera_Construct(RT_Camera *camera, SDL_Surface* screen, int w, int h);
void RT_Camera_SimpleRender(const void *self, RT_Scene *scene);
void setpixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);

#endif
