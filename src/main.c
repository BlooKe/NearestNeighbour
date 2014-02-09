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

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "definitions.h"
#include "typedefs.h"
#include "calculations.h"
#include "fileread.h"

int main(void)
{
    int ret=SUCCEED;
    clock_t toc;
    Data_t *dataset;
    int datacount = 0;
    Data_t chdata = { FAIL, THREE, ONE, THREE, ONE, 0.0 };
    KNearest_t *nearest;

    clock_t tic = clock();

    dataset = (Data_t *)malloc(sizeof(*dataset) * 700);
    memset(dataset, FAIL, sizeof(*dataset)*700);

    nearest = (KNearest_t *)malloc(sizeof(*nearest));
    memset(nearest, FAIL, sizeof(*nearest));

    ret = readfile(DATAFILE, dataset, &datacount);

    ret = calculateDistances(dataset, chdata);

    ret = getNearest(nearest, dataset);

    printf("%d\n", dataset[nearest->datastruct_id].classname);

    toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    return 0;
}
