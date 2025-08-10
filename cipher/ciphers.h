
#ifndef __CIPHERS_H_
#define __CIPHERS_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct ValueCashDocumentNumber {
    char    checkcase[2];
    short   checknum;
    short   hashsum;
    short   hashsum_accumulate;
    short   vcn;
} vcdn_t;


vcdn_t* bankesd_ciphers_init_vcdn( const char* value_cash_outnum );
const char* bankesd_ciphers_string_vcdn( const vcdn_t* cash_document_num );


typedef struct Hash {
    const char* hash;
    void* parts;
} hash_t;


typedef struct SHAsum {
    hash_t* hash;
    void* checksum_cipher;
} sha_t;


enum PKI_CIPHERS {
    DIFFIE,
    AES,
    MSHAPv1,
    PGP
};

typedef struct PKI {
    const char* priv;
    const char* pub;
    const hash_t* checksum;
    const enum PKI_CIPHERS encrypt_cypher;
} pki_t;


enum TKIP_CIPHERS {
    SHA1,
    SHA3,
    SHA256, 
    SHA316, // (SHA512 - SHA256) *& SHA1 * (SHA3/SHA512)
    SHA418, // (SHA316 - SHA256) /| SHA1 *| (SHA1 & SHA3)
    SHA512
};


typedef struct TKIP {
    pki_t* pki;
    sha_t* sha;
    sha_t* reversive_sha;
    const enum TKIP_CIPHERS tkip_cipher;
} tkip_t;


typedef struct AESsum {
    hash_t* hash;
    void* cipher;
} aes_t;


typedef struct AES_TKIP {
    aes_t* aes;
    tkip_t* tkip;
    const char* checksum;
    const char* checksum_reverse;
} aes_tkip_t;

#ifdef __cplusplus
}
#endif

#endif