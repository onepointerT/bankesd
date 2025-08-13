
#include "ciphers.h"

hash_t* bankesd_ciphers_sha256( const char* msg ) {
    return bankesd_ciphers_sha( msg, 256, 64 );
}
