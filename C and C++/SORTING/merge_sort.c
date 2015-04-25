#include <stdio.h>
#include <malloc.h>
#include <limits.h>
void merge(int A[], int p, int q, int r){
	int *L, *R;
	int i, j, k;
	int lsize = q-p+1, rsize = r-q;
	L=(int*)malloc(lsize*sizeof(int));
	R=(int*)malloc(rsize*sizeof(int));
	for(i=0; i<lsize; i++){
		L[i] = A[i+p];
	}
	L[i] = INT_MAX;
	for(j=0; j<rsize; j++){
		R[j] = A[j+q+1];
	}
	R[j] = INT_MAX;
	i=0;
	j=0;
	for(k=p;k<=r;){
		if(L[i] <= R[j]){
			A[k] = L[i];
			k++;
			i++;
		}
		else {
			A[k] = R[j];
			k++;
			j++;
		}
	}
}

void mergeSort(int A[], int p, int r){
	int q;
	if(p<r){
		q = (p+r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main(){
	int i;
	int A[] = {13, 2, 69, 6, 1000, 32, 75, 15, 6, 29, 531};
	for(i=0; i<11; i++)
		printf("%d ", A[i]);
	mergeSort(A, 0, 10);
	printf("\n");
	for(i=0; i<11; i++)
		printf("%d ", A[i]);
}
