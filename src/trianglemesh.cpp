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

#include "trianglemesh.h"
#include <cfloat>

TriangleMesh::TriangleMesh(Scene *s, int nv, int nt, Point *P, int *vi, int *mi) {
    scene = s;
    nverts = nv;
    ntris = nt;
    
    vertexIndex = new int[3 * ntris];
    memcpy(vertexIndex, vi, 3 * ntris * sizeof(int));
    
    p = new Point[nv];
    memcpy(p, P, nv * sizeof(Point));
    
    materialIndex = new int[ntris];
    memcpy(materialIndex, mi, ntris * sizeof(int));
    
    for (int i=0; i<ntris; i++) {
        tris.push_back(Triangle(this, i));
    }
}

bool TriangleMesh::Intersect(const Ray *r, Intersection *isect) {
    float mint = FLT_MAX;
    bool intersection = false;
    for (int i=0; i<ntris; i++) {
        float t;
        Triangle &tria = tris[i];
        if (tria.Intersect(r, &t, NULL) && t < mint) {
            intersection = true;
            isect->materialIndex = materialIndex[i];
            mint = t;
        }
    }
    return intersection;
}

Triangle::Triangle(TriangleMesh *m, int n) {
    mesh = m;
    v = &mesh->vertexIndex[3*n];
}

bool Triangle::Intersect(const Ray *ray, float *tHit, Intersection *isect) const {
	// Initialize triangle intersection statistics
	static
	StatsPercentage triangleHits("Geometry",
	                             "Triangle Ray Intersections");
	// Update triangle tests count
	triangleHits.Add(0, 1);
	// Compute $\VEC{s}_1$
	// Get triangle vertices in _p1_, _p2_, and _p3_
	const Point &p1 = mesh->p[v[0]];
	const Point &p2 = mesh->p[v[1]];
	const Point &p3 = mesh->p[v[2]];
	Vector e1 = p2 - p1;
	Vector e2 = p3 - p1;
	Vector s1 = Cross(ray->d, e2);
	float divisor = Dot(s1, e1);
	if (divisor == 0.)
		return false;
	float invDivisor = 1.f / divisor;
	// Compute first barycentric coordinate
	Vector d = ray->o - p1;
	float b1 = Dot(d, s1) * invDivisor;
	if (b1 < 0. || b1 > 1.)
		return false;
	// Compute second barycentric coordinate
	Vector s2 = Cross(d, e1);
	float b2 = Dot(ray->d, s2) * invDivisor;
	if (b2 < 0. || b1 + b2 > 1.)
		return false;
	// Compute _t_ to intersection point
	float t = Dot(e2, s2) * invDivisor;
	if (t < ray->mint || t > ray->maxt)
		return false;
	*tHit = t;
	return true;
}
