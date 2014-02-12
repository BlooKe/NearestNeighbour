/****************************************************************************
 * Copyright (c) 2014 Lauris Radzevics                                      *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining    *
 * a copy of this software and associated documentation files (the          *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, sublicense, and/or sell copies of the Software, and to       *
 * permit persons to whom the Software is furnished to do so, subject to    *
 * the following conditions:                                                *
 *                                                                          *
 * The above copyright notice and this permission notice shall be           *
 * included in all copies or substantial portions of the Software.          *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                    *
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE   *
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION   *
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION    *
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.          *
 ****************************************************************************/

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum { CLASSNAME, LWEIGHT, LDISTANCE, RWEIGHT, RDISTANCE, DATADISTANCE } data_type_t;

typedef enum {LEFT, BALANCE, RIGHT} class_t;
typedef enum {NONE, ONE, TWO, THREE, FOUR, FIVE} values_t;

typedef struct {
    int classname;
    int lweight;
    int ldistance;
    int rweight;
    int rdistance;
    double datadistance;
} Data_t;

typedef struct {
    int datastruct_id;
    double distance;
} KNearest_t;

typedef struct {
    int left;
    int balance;
    int right;
} Results_t;

#endif // TYPEDEFS_H
