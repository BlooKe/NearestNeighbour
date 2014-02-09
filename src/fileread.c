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
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "typedefs.h"
#include "fileread.h"

int readfile(char *file_name, Data_t *datastruct, int *datacount)
{
    int ret = SUCCEED;
    char line[12];
    char *token;
    FILE *fp;
    int i;

    fp = fopen(file_name,"r");

    if( fp == NULL )
    {
      perror("Error while opening the file.\n");
      ret = FAIL;
    }

    while( fgets(line, 11, fp) != NULL )
    {
        token = strtok( line, "," );
            for(i=0; token != NULL; i++ )
            {
                ret = setValue(datastruct, i, token);
                token = strtok( NULL, "," );
            }
        (*datacount)++;
            datastruct++;
    }

    fclose(fp);
    return ret;
}


int setValue(Data_t *datastruct, int place, char *value)
{
    int ret = SUCCEED;
    switch (place) {
        case CLASSNAME:
        {
            if (strcmp("L", value)==0)
                datastruct->classname=LEFT;
            else if (strcmp("B", value)==0)
                datastruct->classname=BALANCE;
            else if (strcmp("R", value)==0)
                datastruct->classname=RIGHT;
        } break;
        case LWEIGHT:
        {
            datastruct->lweight=atoi(value);
        } break;
        case LDISTANCE:
        {
            datastruct->ldistance=atoi(value);
        } break;
        case RWEIGHT:
        {
            datastruct->rweight=atoi(value);
        } break;
        case RDISTANCE:
        {
            datastruct->rdistance=atoi(value);
        } break;
        default:
        {
            printf("Wrong data type - return FAIL!");
            ret=FAIL;
        } break;
    }
    return ret;
}

