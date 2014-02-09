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
#include <math.h>
#include <stdbool.h>
#include "definitions.h"
#include "typedefs.h"
#include "calculations.h"

int calculateDistances(Data_t *dataset, Data_t data)
{
    int ret=SUCCEED;
    int i;

    for(i=0; (signed)dataset[i].classname!=FAIL; i++)
    {
        dataset[i].datadistance = distance(data, dataset[i]);
    }

    return ret;
}

double distance(Data_t a, Data_t b)
{
    return sqrt(pow(((double)a.lweight-(double)b.lweight),2) + pow(((double)a.ldistance-(double)b.ldistance),2)
                + pow(((double)a.rweight-(double)b.rweight),2) +pow(((double)a.rdistance-(double)b.rdistance),2));
}

int getNearest(KNearest_t *nearest, Data_t *dataset)
{
    int ret = SUCCEED;
    int i,e;
    bool first = true;

    for(i = 0; (signed)dataset[i].classname != FAIL; i++)
    {
        if(!first)
        {
//            for(e = 0; (signed)nearest[e].datastruct_id != FAIL; e++)
//            {
                if(dataset[i].datadistance < nearest->distance)// && e<=K) Neit!
                {
                    nearest->datastruct_id = i;
                    nearest->distance = dataset[i].datadistance;
                    //printf("%d, %f \n", nearest[e].datastruct_id, nearest[e].distance);
                }
//            }
        } else
        {
            nearest[0].datastruct_id=i;
            nearest[0].distance = dataset[i].datadistance;
            first = false;
            //printf("%d, %f \n", nearest[0].datastruct_id, nearest[0].distance);
        }
    }

    return ret;
}
