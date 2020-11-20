#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
  long int A[5];
  long int B[5] = {0};
  double max = 0, min = 0;
  int i, j;

	for(i = 0; i < 5; i++) {
		scanf("%ld", &A[i]);
	}
  for(i = 0; i < 5; i++) {
  	for(j = 0; j < 5; j++) {
  		if(i == j) continue;
  		B[i] += A[j];
  	}
	}
	min = B[0];
	max = B[0];
  for(i = 0; i < 5; i++) {
		if(B[i] > max) max = B[i];
		if(B[i] < min) min = B[i];
	}
  
  printf("%.0f %.0f", min, max);
  return 0;
}
