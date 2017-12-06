#include "x13.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_sm3.h"


void sm3_hash(const char* input, char* output)
{
    sm3_ctx_t               ctx_sm3;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16];

    sm3_init(&ctx_sm3);
    sph_sm3(&ctx_sm3, input, 80);
    sph_sm3_close(&ctx_sm3, hashA);

    memcpy(output, hashA, 32);
	
}

