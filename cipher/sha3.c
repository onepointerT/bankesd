
#include "ciphers.h"

hash_t* bankesd_ciphers_sha3( const char* msg ) {
    return bankesd_ciphers_sha( msg, 180, 3 );
}
