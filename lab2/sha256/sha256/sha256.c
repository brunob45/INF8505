#include <stdio.h> 
#include <string.h> 

/* de-comment the following line to activate the custom_instruction */
#define custom_instruction

#define uchar unsigned char // 8-bit byte
#define uint unsigned int // 32-bit word

// DBL_INT_ADD treats two unsigned ints a and b as one 64-bit integer and adds c to it
#define DBL_INT_ADD(a,b,c) if (a > 0xffffffff - (c)) ++b; a += c;
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

uint k[64] = {
   0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
   0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
   0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
   0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
   0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
   0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
   0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
   0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};


void sha256_transform(uchar data[], 
                      uint& h0, uint& h1, uint& h2, uint& h3, 
                      uint& h4, uint& h5, uint& h6, uint& h7)
{  
   uint a,b,c,d,e,f,g,h, i,j,t1,t2,m[64];
     
   for (i=0,j=0; i < 16; ++i, j += 4) {
      m[i] = (data[j] << 24) | (data[j+1] << 16) | (data[j+2] << 8) | (data[j+3]);
   }   
     
   for ( ; i < 64; ++i) {
        m[i] = SIG1(m[i-2]) + m[i-7] + SIG0(m[i-15]) + m[i-16];
   }
   
   a = h0;
   b = h1;
   c = h2;
   d = h3;
   e = h4;
   f = h5;
   g = h6;
   h = h7;
  
   for (i = 0; i < 64; ++i) {
   
      #ifdef custom_instruction        
        sha256_ci(a, b, c, d, e, f, g, h, k[i], m[i]);
      #else
        t1 = h + EP1(e) + CH(e,f,g) + k[i] + m[i];
        t2 = EP0(a) + MAJ(a,b,c);
            
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
      #endif
   
   }
   
   h0 += a;
   h1 += b;
   h2 += c;
   h3 += d;
   h4 += e;
   h5 += f;
   h6 += g;
   h7 += h;
}  

void sha256(uchar data[], uint len, uchar hash[])
{  
   uint t,i;
   uchar buf[64];

 // Initialize state 
 
   uint a = 0x6a09e667;
   uint b = 0xbb67ae85;
   uint c = 0x3c6ef372;
   uint d = 0xa54ff53a;
   uint e = 0x510e527f;
   uint f = 0x9b05688c;
   uint g = 0x1f83d9ab;
   uint h = 0x5be0cd19;
  
 // Process message
   uint datalen = len; 
   uchar* pdata = data;
   while ( datalen >= 64) {
       sha256_transform(pdata,a,b,c,d,e,f,g,h);
       datalen -= 64;
       pdata += 64;
   } 

 // Final padding  
   if (datalen < 56) { 
      uint i = 0;
      while (i < datalen)
          buf[i++] = *pdata++;
      buf[i++] = 0x80; 
      while (i < 56) 
          buf[i++] = 0;
   }
   else { 
      uint i = 0;
      while (i < datalen)
          buf[i++] = *pdata++;
      buf[i++] = 0x80; 
      while (i < 64) 
         buf[i++] = 0x00; 
      sha256_transform(buf,a,b,c,d,e,f,g,h);
      memset(buf,0,56); 
   }  
   
   // Append to the padding the total message's length in bits and transform. 
   unsigned long long bitlen = len << 3; 

   buf[63] = bitlen; 
   buf[62] = bitlen >> 8; 
   buf[61] = bitlen >> 16; 
   buf[60] = bitlen >> 24; 
   buf[59] = bitlen >> 32; 
   buf[58] = bitlen >> 40; 
   buf[57] = bitlen >> 48;  
   buf[56] = bitlen >> 56; 
   sha256_transform(buf,a,b,c,d,e,f,g,h);
   
   // Since this implementation uses little endian byte ordering and SHA uses big endian,
   // reverse all the bytes when copying the final state to the output hash. 
   for (i=0; i < 4; ++i) { 
      hash[i]    = (a >> (24-i*8)) & 0x000000ff; 
      hash[i+4]  = (b >> (24-i*8)) & 0x000000ff; 
      hash[i+8]  = (c >> (24-i*8)) & 0x000000ff;
      hash[i+12] = (d >> (24-i*8)) & 0x000000ff;
      hash[i+16] = (e >> (24-i*8)) & 0x000000ff;
      hash[i+20] = (f >> (24-i*8)) & 0x000000ff;
      hash[i+24] = (g >> (24-i*8)) & 0x000000ff;
      hash[i+28] = (h >> (24-i*8)) & 0x000000ff;
   }  
}  

#include "text.c"

// Expected outout
const char expected_result[] = "29192b7d91dd827105283dbb264d7c6908f7ac605c2f2c96a71ad50897f8a64f";

void print_hash(unsigned char hash[])
{
   int idx;
   for (idx=0; idx < 32; idx++)
      printf("%02x",hash[idx]);
   printf("\n");
}

void convert_hash(unsigned char hash[], char* p)
{
   int idx;
   for (idx=0; idx < 32; idx++)
      p += sprintf(p,"%02x",hash[idx]);
   *p = '\0';
}


int main()
{
   unsigned char hash[32];
   int len;
   char buf[66];

   len = strlen((const char*)input_text);
   sha256(input_text,len,hash);
   
   printf("SHA256 calculated result:\n");
   print_hash(hash);

   convert_hash(hash,buf);
   
   printf("\n");
   if (strcmp(buf, expected_result) == NULL) 
      printf("SHA256 result is correct\n");
   else 
      printf("SHA256 result is incorrect\n");
        
   return 0;
}

