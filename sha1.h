/*
 *  sha1.h
 */

#ifndef _SHA1_H_
#define _SHA1_H_

#include <stdio.h>
#include <stdint.h> 
/*
 * If you do not have the ISO standard stdint.h header file, then you
 * must typdef the following:
 *    name              meaning
 *  uint32_t         unsigned 32 bit integer
 *  uint8_t          unsigned 8 bit integer (i.e., unsigned char)
 *  int_least16_t    integer of >= 16 bits
 *
 */

#ifndef _SHA_enum_
#define _SHA_enum_
enum
{
    shaSuccess = 0,
    shaNull,            /* Null pointer parameter */
    shaInputTooLong,    /* input data too long */
    shaStateError       /* called Input after Result */
};
#endif
#define SHA1HashSize 20

/*
 *  This structure will hold context information for the SHA-1
 *  hashing operation
 */
typedef struct SHA1Context
{
    uint32_t Intermediate_Hash[SHA1HashSize/4]; /* Message Digest  */

    uint32_t Length_Low;            /* Message length in bits      */
    uint32_t Length_High;           /* Message length in bits      */

                               /* Index into message block array   */
    int_least16_t Message_Block_Index;
    uint8_t Message_Block[64];      /* 512-bit message blocks      */

    int Computed;               /* Is the digest computed?         */
    int Corrupted;             /* Is the message digest corrupted? */
} SHA1Context;

/*
 *  Function Prototypes
 */

int RXCTXGZIAWAGCQWPGPFTCLFGKUHJJKR(SHA1Context *);
int AIUVHCWPFURNWHLMPATIEGQMQKWBVGT(SHA1Context *,
                const uint8_t *,
                unsigned int);
int XQPVXTROYMFLKPWWEZRPFYFSQROSMWN(SHA1Context *,
                uint8_t Message_Digest[SHA1HashSize]);

int LNCGMVYBUMIHWXGVCFMTKMYEDPSVDPI(char* testcase, uint8_t Message_Digest[SHA1HashSize]);

#endif
