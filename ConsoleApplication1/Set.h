#pragma once /* インクルードガードと同じ働き */

#ifndef SET_H
#define SET_H

typedef int int32_t;
typedef unsigned int uint32_t;
typedef char byte_t;
typedef unsigned char ubyte_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef long int64_t;
typedef unsigned long uint64_t;
typedef long long int128_t;
typedef unsigned long long uint128_t;

#define SIZE_OF_MAX ((uint32_t) 2*2*2*2*2 - 1)

#endif /* SET_H */