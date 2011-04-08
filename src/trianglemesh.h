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

#ifndef RTRT_TRIANGLEMESH_H
#define RTRT_TRIANGLEMESH_H

#include "rtrt.h"
#include "geometry.h"
#include <vector>

class Scene;
class Triangle;

class Intersection {
public:
    int materialIndex;
};

class TriangleMesh {
public:
    TriangleMesh(Scene *s, int nv, int nt, Point *p, int *vi, int *mi);
    bool Intersect(const Ray *r, Intersection *isect);
public:    
    int ntris;
    int nverts;
    int *vertexIndex;
    int *materialIndex;
    vector<Triangle> tris;
    Point *p;
    Scene *scene;
};

class Triangle {
public:
    Triangle(TriangleMesh *m, int n);
    bool Intersect(const Ray *ray, float *tHit, Intersection *isect) const;
public:
    TriangleMesh *mesh;
    int *v;
};

#endif
