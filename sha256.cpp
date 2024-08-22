#include "sha256.h"
#include <openssl/sha.h>

void SHA256Hash(const unsigned char* input, size_t len, unsigned char* output) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, len);
    SHA256_Final(output, &sha256);
}
