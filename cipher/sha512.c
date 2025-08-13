
#include "ciphers.h"

hash_t* bankesd_ciphers_sha512( const char* msg ) {
    return bankesd_ciphers_sha( msg, 512, 128 );
}
