/*
 * converter.c
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#include "converter.h"
#include "stdlib.h"
#include "string.h"
#include "../Math/maths.h"
#include <math.h>

#include "Module/Inc/enumerators.h"

int IsValidNumber(char * string)
{
	int i;
	int len = strlen( string );
   for(i = 0; i < len; i++)
   {
      //ASCII value of 0 = 48, 9 = 57. So if value is outside of numeric range then fail
      //Checking for negative sign "-" could be added: ASCII value 45.
      if (string[i] < 48 || string[i] > 57)
         return 0;
   }

   return 1;
}

int split (char *str, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }

    *t = '\0';
    return count;
}

void FromCharToAddress(char const* addressStr, int* address, int* bit){
	*bit = -1;
	int i;
	char** token = NULL;
	int len = strlen(addressStr);
	char addr[len + 1];
	memcpy(addr, addressStr, sizeof(char) * len);
	addr[len] = '\0';
	int nSplit = split(addr, '.', &token);

	for(i = 0; i < nSplit; i++){

		if(IsValidNumber(token[i])){
			int intValue = atoi(token[i]);
			switch(i){
				case 0:
					*address = intValue;
					break;
				case 1:
					*bit = intValue;
					break;
			}
		}
		free(token[i]);
		token[i] = NULL;
	}

	free(token);
	token = NULL;
}

void ConvertData(BYTE dataType, double value, BYTE decimal, DWORD *intValue, BYTE* nWords){
	if(((DataType)dataType) == _FP_32BIT_){
		(*intValue) = FromDecimalToFloatingPointSinglePrecision(value);
		(*nWords) = 2;
	}
	else{
		(*intValue) = (DWORD)(value * pow(10, decimal));
		(*nWords) = 1;
	}
}



