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

#include "scene.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

int line_num;
string current_file;

Scene::Scene() {
    mesh = NULL;
}

Scene::~Scene() {
    if (mesh)
        delete mesh;
}

bool Scene::Intersect(const Ray *r, Intersection *isect) {
    return mesh->Intersect(r, isect);
}

bool Scene::LoadFromFile(const char *fileName) {
    FILE *file;
    file = fopen(fileName, "rb");
    
    int nv, nt, nm;
    fread(&nv, 1, sizeof(int), file);
    fread(&nt, 1, sizeof(int), file);
    fread(&nm, 1, sizeof(int), file);
    
    Point *p = new Point[nv];
    fread(p, nv, sizeof(Point), file);
    
    int *vi = new int[3*nt];
    fread(vi, 3*nt, sizeof(int), file);
    
    int *mi = new int[nt];
    fread(mi, nt, sizeof(int), file);
    
    materials = new Material[nm];
    fread(materials, nm, sizeof(Material), file);
    
    mesh = new TriangleMesh(this, nv, nt, p, vi, mi);
    
    delete[] p;
    delete[] vi;
    delete[] mi;
    
    fclose(file);
}
