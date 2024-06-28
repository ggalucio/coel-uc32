/*
 * maths.c
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#include "math.h"
#include "maths.h"

#define MANTISSA_FIELD_LEN_SINGLE_PRECISION		23
#define EXP_SINGLE_PRECISION_START_BIT			23
#define SIGN_SINGLE_PRECISION_START_BIT			31
#define MANTISSA_SINGLE_PRECISION_START_BIT		0
#define EXP_BIAS_SINGLE_PRECISION				127

typedef union {

    float Real;
    struct
    {

        // Order is important.
        // Here the members of the union data structure
        // use the same memory (32 bits).
        // The ordering is taken
        // from the LSB to the MSB.
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    }FP;
}Num;

#define ToDecimal(length)																\
				int i;																	\
				for(i = 0; i < length; i++){											\
					decimal += (((mantissa >> i) & 0x01) * pow(2,(-1) * (length - i)));	\
				}																		\

int GetExponent(const DWORD intValue){

	if(intValue == 1)
		return 0;

	int exp = 0;
	int i = 0;
	while(i < 32){
		DWORD shValue = (intValue >> i) & 0x01;

		if(shValue > 0)
			exp = i;

		i++;
	}

	return exp;
}

DWORD FromDecimalToFloatingPointSinglePrecision(const double value){
	/* Instantiate the union */
	Num var;

	/* Get the real value */
	var.Real = value;

	/* Return number in FP format */
	return (var.FP.sign << SIGN_SINGLE_PRECISION_START_BIT) | (var.FP.exponent << EXP_SINGLE_PRECISION_START_BIT) | var.FP.mantissa;
}

double  FromFloatingPointToDecimalSinglePrecision(const double value){
	DWORD val 		= (DWORD)value;
	BYTE sign 		= (val >> SIGN_SINGLE_PRECISION_START_BIT);
	BYTE exp 		= (val >> EXP_SINGLE_PRECISION_START_BIT) 		& 0xff;
	DWORD mantissa 	= (val >> MANTISSA_SINGLE_PRECISION_START_BIT)  & 0x7fffff;

	double leading 	= exp != 0 ? 1.0 : 0.0;
	int bias 		= exp != 0 ? EXP_BIAS_SINGLE_PRECISION : (EXP_BIAS_SINGLE_PRECISION - 1);

	int 	realExp = exp - bias;
	double 	mult = pow(2, realExp) * (sign ? -1 : 1);


	double decimal = leading;
	ToDecimal(MANTISSA_FIELD_LEN_SINGLE_PRECISION);
	return decimal * mult;
}

const char* GetDecimalFormat(BYTE decimal){
	switch(decimal)
	{
		case 1:		return "%.1f";
		case 2:		return "%.2f";
		case 3:		return "%.3f";
		default:	return "%.0f";
	}
}
