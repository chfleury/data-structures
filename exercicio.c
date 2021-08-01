#include <stdio.h>
#include <stdlib.h>

void merge(int A[],int l,int mid,int h) {
  int i=l,j=mid+1,k=l;
  int B[140000];
  while(i<=mid && j<=h){
    if(A[i]<A[j])
      B[k++]=A[i++];
    else
     B[k++]=A[j++];
  }
  for(;i<=mid;i++)
    B[k++]=A[i];
  for(;j<=h;j++)
    B[k++]=A[j];
  for(i=l;i<=h;i++)
    A[i]=B[i];
}
void iterativoMergeSort(int A[],int n) {
  int p,l,h,mid,i;
  for(p=2;p<=n;p=p*2) {
    for(i=0;i+p-1<n;i=i+p){
      l=i;
      h=i+p-1;
      mid=(l+h)/2; 
      merge(A,l,mid,h);
    }
    if(n-i>p/2){
      l = i;
      h = i+p-1;
      mid = (l+h)/2;
      merge(A, l, mid, n-1);
    }
  }
  if(p/2<n){
    merge(A,0,p/2-1,n-1);
  }
} 

 
int binarySearch (int A[], int n, int x) {
  int start = 0, end = n - 1;

  while (start <= end) {
    int mid = start + (end - start)/2; // (start + end)/2 might overflow 
    
    if (x == A[mid]) {
      return mid;
    }

    if (x < A[mid]) { 
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return -1; // Not found
}


int main () {
  int N;
  scanf("%d", &N);
  int A[N];

  for(int i = 0; i<N;i++){
    scanf("%d", &A[i]);
  }

  iterativoMergeSort(A,N);


  int tmp;
  while(scanf("%d", &tmp) == 1){
    binarySearch(A, N, tmp ) != -1 ? printf("sim\n"):printf("nao\n");
  }

  return 0;
}