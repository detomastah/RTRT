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

#ifndef MATERIAL_H
#define MATERIAL_H

#define OBJ_FILENAME_LENGTH 500
#define MATERIAL_NAME_SIZE 255

class Material {
public:
    char name[MATERIAL_NAME_SIZE];
    char texture_filename[OBJ_FILENAME_LENGTH];
    float amb[3];
    float diff[3];
    float spec[3];
    float reflect;
    float refract;
    float trans;
    float shiny;
    float glossy;
    float refract_index;
};

#endif
