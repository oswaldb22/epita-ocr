/* Put all general includes here, we will optimize them later */

#include <stdio.h>		//Input/Output
#include <curses.h>		//Console input
#include <stdlib.h>		//Malloc
#include <math.h>		//Maths
#include <time.h>		//Time (Mainly for RNG)
#include <assert.h> 	//Asserts
#include <string.h>		//Strings
//Typedef
#ifndef TYPEDEF_CUSTOM
#define TYPEDEF_CUSTOM

#define UNUSED(x) (void)x
typedef unsigned long ulong;
typedef unsigned int uint;
typedef const ulong ULONG;
typedef const uint UINT;

#endif
