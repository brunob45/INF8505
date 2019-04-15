// RSA Private-Key: (1024 bit, 2 primes)
unsigned char modulus[] = {
    0x00, 0xc8, 0x46, 0x7f, 0xda, 0x54, 0x17, 0xa4, 0x45, 0x6c, 0xdd, 0x47, 0x70, 0x1c, 0x7d,
    0x9e, 0x26, 0xae, 0x23, 0xf3, 0xea, 0x7a, 0xc9, 0x1f, 0x94, 0x98, 0x6a, 0x9c, 0x9b, 0x88,
    0x4b, 0xca, 0xf5, 0x12, 0x62, 0x4c, 0x21, 0xb3, 0x90, 0xb6, 0x1c, 0xec, 0x95, 0x83, 0xef,
    0x6d, 0x83, 0xba, 0xd9, 0xd1, 0x33, 0xb2, 0x51, 0x45, 0x81, 0xaa, 0x7b, 0x2b, 0x93, 0xb8,
    0x1e, 0x32, 0xd2, 0xaa, 0x3e, 0xb1, 0x27, 0x98, 0x1d, 0x09, 0xf7, 0xc9, 0x22, 0xc8, 0xa7,
    0x3b, 0x49, 0xb9, 0x8c, 0xfa, 0xea, 0xcb, 0xae, 0xef, 0xea, 0xe5, 0x1f, 0x19, 0xd6, 0xc4,
    0x5f, 0x66, 0xed, 0x99, 0xaf, 0x46, 0xba, 0x0e, 0x0c, 0xbf, 0xfa, 0xb4, 0x1f, 0x35, 0x53,
    0xe8, 0x3b, 0xc0, 0xce, 0xbe, 0xed, 0xff, 0xcd, 0x63, 0x1b, 0x10, 0xc2, 0x98, 0x6a, 0x78,
    0x74, 0x45, 0xd6, 0xf1, 0x01, 0x46, 0x6b, 0x0d, 0xab
};
unsigned char publicExponent[] = { // 65537
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01
};
unsigned char privateExponent[] = {
    0x00, 0x99, 0x59, 0x49, 0xea, 0x5d, 0xbb, 0x60, 0x7f, 0xfc, 0x34, 0x8e, 0xcf, 0xac, 0x31,
    0x0f, 0x58, 0xa4, 0xbc, 0x48, 0xb7, 0x00, 0xdf, 0x61, 0x3c, 0x01, 0x5c, 0x98, 0x9f, 0x8a,
    0xc4, 0x26, 0x1a, 0x72, 0xc2, 0x2b, 0x73, 0x1e, 0xb0, 0x2e, 0x91, 0x85, 0x21, 0x92, 0xcd,
    0x50, 0xb8, 0xad, 0xe8, 0xbc, 0x83, 0xee, 0x04, 0xc6, 0xc8, 0xdb, 0x45, 0xc6, 0x7f, 0x2c,
    0x5a, 0x8b, 0x25, 0xbd, 0x4e, 0x38, 0xdf, 0x89, 0x05, 0x43, 0xab, 0xc3, 0xaf, 0xfa, 0xf6,
    0xe1, 0x4d, 0x23, 0xbc, 0x04, 0x63, 0x2b, 0x83, 0xcc, 0x99, 0xd3, 0x14, 0x05, 0x49, 0x7b,
    0xef, 0x19, 0xb4, 0xda, 0x11, 0xd8, 0xc1, 0x3a, 0x4c, 0x65, 0xef, 0xf6, 0x18, 0xcf, 0x5d,
    0xd2, 0xce, 0x8b, 0x29, 0x82, 0x6a, 0x96, 0xe7, 0x9c, 0xb8, 0x41, 0xad, 0xea, 0x9f, 0xe9,
    0xbf, 0x40, 0xad, 0xa8, 0x04, 0xe6, 0x48, 0xa4, 0x19
};
unsigned char ONE[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
};
