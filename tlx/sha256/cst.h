unsigned int n=1026;
unsigned short modulus[] = {
  0x0dab, 
  0x466b, 0xf101, 0x45d6, 0x7874, 0x986a, 0x10c2, 0x631b, 0xffcd, 
  0xbeed, 0xc0ce, 0xe83b, 0x3553, 0xb41f, 0xbffa, 0x0e0c, 0x46ba, 
  0x99af, 0x66ed, 0xc45f, 0x19d6, 0xe51f, 0xefea, 0xcbae, 0xfaea, 
  0xb98c, 0x3b49, 0xc8a7, 0xc922, 0x09f7, 0x981d, 0xb127, 0xaa3e, 
  0x32d2, 0xb81e, 0x2b93, 0xaa7b, 0x4581, 0xb251, 0xd133, 0xbad9, 
  0x6d83, 0x83ef, 0xec95, 0xb61c, 0xb390, 0x4c21, 0x1262, 0xcaf5, 
  0x884b, 0x9c9b, 0x986a, 0x1f94, 0x7ac9, 0xf3ea, 0xae23, 0x9e26, 
  0x1c7d, 0x4770, 0x6cdd, 0xa445, 0x5417, 0x7fda, 0xc846, 0x0000, 
  
};
unsigned short C [] = {
  0x379c, 
  0xebf3, 0xd4a1, 0xe66b, 0xae1d, 0xa2a9, 0xfca7, 0xa21f, 0xa237, 
  0x9c45, 0xf739, 0xae81, 0x3d36, 0xea00, 0xe596, 0x9493, 0x8a62, 
  0xb457, 0x0a5f, 0xa547, 0x6143, 0x3379, 0x338b, 0xc639, 0x6cc5, 
  0xbdcf, 0x6d5f, 0x82d6, 0x52f6, 0x8b2e, 0x4449, 0xe0d1, 0xd1fd, 
  0x7e9e, 0xe08f, 0xf8af, 0xb7c6, 0xdb21, 0x5dcd, 0xe04f, 0x4083, 
  0x866d, 0xc85a, 0x9d1a, 0x9ddc, 0x4bc7, 0xe69b, 0xf952, 0x1d0c, 
  0xd86c, 0xbea3, 0x6ef1, 0x875a, 0x68a5, 0x103f, 0x144b, 0x9885, 
  0x7764, 0x3011, 0x6ca4, 0x7985, 0xf403, 0xd74a, 0xa8fd, 0x0000, 
  
};
unsigned short ONE [] = {
  0x0001, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  
};
unsigned short publicExponent[] = {
  0x0001, 
  0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  
};
unsigned short privateExponent[] = {
  0xa419, 
  0xe648, 0xa804, 0x40ad, 0xe9bf, 0xea9f, 0x41ad, 0x9cb8, 0x96e7, 
  0x826a, 0x8b29, 0xd2ce, 0xcf5d, 0xf618, 0x65ef, 0x3a4c, 0xd8c1, 
  0xda11, 0x19b4, 0x7bef, 0x0549, 0xd314, 0xcc99, 0x2b83, 0x0463, 
  0x23bc, 0xe14d, 0xfaf6, 0xc3af, 0x43ab, 0x8905, 0x38df, 0xbd4e, 
  0x8b25, 0x2c5a, 0xc67f, 0xdb45, 0xc6c8, 0xee04, 0xbc83, 0xade8, 
  0x50b8, 0x92cd, 0x8521, 0x2e91, 0x1eb0, 0x2b73, 0x72c2, 0x261a, 
  0x8ac4, 0x989f, 0x015c, 0x613c, 0x00df, 0x48b7, 0xa4bc, 0x0f58, 
  0xac31, 0x8ecf, 0xfc34, 0x607f, 0x5dbb, 0x49ea, 0x9959, 0x0000, 
  
};
unsigned short INPUT[] = {
  0x3456, 
  0x0012, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  
};