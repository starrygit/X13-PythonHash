#include "x13.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"
#include "sha3/sph_sm3.h"


void sm3_hash(const char* input, char* output)
{
    sph_blake512_context     ctx_blake;
    sm3_ctx_t               ctx_sm3;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16], hashB[16];

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 80);
    sph_blake512_close (&ctx_blake, hashA);

    memset(hashB, 0, 64);
    sm3_init(&ctx_sm3);
    sph_sm3(&ctx_sm3, hashA, 64);
    sph_sm3_close(&ctx_sm3, hashB);

    memcpy(output, hashB, 32);
	
}

