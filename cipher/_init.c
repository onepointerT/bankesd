
#include "ciphers.h"
#include "_blockbuf.h"

#include <stdlib.h>


hash_t* bankesd_ciphers_init_hash( const unsigned int lenght_of_hash_bits ) {
    hash_t* hash = (hash_t*) malloc(sizeof(hash_t));

    hash->hash = (char*) malloc(sizeof(char)*lenght_of_hash_bits);
    hash->parts = 0;

    return hash;
}


hash_t* bankesd_ciphers_init_hash_parts( const unsigned int lenght_of_hash_bits, void* parts_struct ) {
    hash_t* hash = bankesd_ciphers_init_hash( lenght_of_hash_bits );

    hash->parts = parts_struct;

    return hash;
}


_charbuf_t* _bankesd_charbuf_init( const unsigned short bufsize ) {

    struct _bankesd_charbuf* cbuf = (struct _bankesd_charbuf*) malloc(sizeof(struct _bankesd_charbuf));

    cbuf->buf = (char*) malloc(sizeof(char)*bufsize);
    cbuf->bufsize = bufsize;

    return cbuf;
}


_blockbuf_t* _bankesd_blockbuf_init( const unsigned int buffercount, const unsigned short buffersize_each ) {

    struct _bankesd_blockbuf* blkbuf = (struct _bankesd_blockbuf*) malloc(sizeof(struct _bankesd_blockbuf));

    blkbuf->buffercount = buffercount;
    blkbuf->bufferindex = 0;

    *blkbuf->buffers = (struct _bankesd_charbuf*) malloc(sizeof(struct _bankesd_charbuf)*buffercount);
    for ( unsigned int bci = 0; bci < buffercount; bci++ ) {
        blkbuf->buffers[bci] = _bankesd_charbuf_init( buffersize_each );
    }

    blkbuf->buf = blkbuf->buffers[0];

    return blkbuf;
}