/**
 * Demonstrate structure padding, packing and memory alignment.
 *
 * References:
 * - http://www.catb.org/esr/structure-packing/
 *
 * Build:
 *  gcc struct_pad.c -o struct_pad
 */
#include <stdio.h>

int main() {
  struct {
    int i0;
    char c0;
    char c1;
    int *p0;
    int i1;
    float f0;
  } s0;

  struct {
    int i0;
    char c0;
    int *p0;
    int i1;
    char c1;
    float f0;
  } s1;

#pragma pack(1)
  struct {
    int i0;
    char c0;
    int *p0;
    int i1;
    char c1;
    float f0;
  } s2;
#pragma pop

  struct {
    int i0;
    char c0 : 4;
    char c1 : 3;
    int i1 : 3;
    int f0 : 5;
    int *p0;
  } s3;

  printf("sizeof(s0) = %lu:\n", sizeof(s0));
  printf("\ti0: %lu bytes at %p\n", sizeof(s0.i0), &s0.i0);
  printf("\tc0: %lu bytes at %p\n", sizeof(s0.c0), &s0.c0);
  printf("\tc1: %lu bytes at %p\n", sizeof(s0.c1), &s0.c1);
  printf("\tp0: %lu bytes at %p\n", sizeof(s0.p0), &s0.p0);
  printf("\ti1: %lu bytes at %p\n", sizeof(s0.i1), &s0.i1);
  printf("\tf0: %lu bytes at %p\n", sizeof(s0.f0), &s0.f0);
  printf("\n");
  printf("sizeof(s1) = %lu:\n", sizeof(s1));
  printf("\ti0: %lu bytes at %p\n", sizeof(s1.i0), &s1.i0);
  printf("\tc0: %lu bytes at %p\n", sizeof(s1.c0), &s1.c0);
  printf("\tp0: %lu bytes at %p\n", sizeof(s1.p0), &s1.p0);
  printf("\ti1: %lu bytes at %p\n", sizeof(s1.i1), &s1.i1);
  printf("\tc1: %lu bytes at %p\n", sizeof(s1.c1), &s1.c1);
  printf("\tf0: %lu bytes at %p\n", sizeof(s1.f0), &s1.f0);
  printf("\n");
  printf("sizeof(s2) = %lu (packed s1):\n", sizeof(s2));
  printf("\ti0: %lu bytes at %p\n", sizeof(s2.i0), &s2.i0);
  printf("\tc0: %lu bytes at %p\n", sizeof(s2.c0), &s2.c0);
  printf("\tp0: %lu bytes at %p\n", sizeof(s2.p0), &s2.p0);
  printf("\ti1: %lu bytes at %p\n", sizeof(s2.i1), &s2.i1);
  printf("\tc1: %lu bytes at %p\n", sizeof(s2.c1), &s2.c1);
  printf("\tf0: %lu bytes at %p\n", sizeof(s2.f0), &s2.f0);
  printf("\n");
  printf("sizeof(s3) = %lu:\n", sizeof(s3));
  printf("\ti0: %lu bytes at %p\n", sizeof(s3.i0), &s3.i0);
  // sizeof and getting an address of a bit field is illegal
  printf("\tp0: %lu bytes at %p\n", sizeof(s3.p0), &s3.p0);

  return 0;
}