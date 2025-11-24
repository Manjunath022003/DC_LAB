#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
long long i,n=1000000;
long long count;
double x,y,pi;
#pragma omp parallel for private(i) reduction(+:count)
for(int i=0;i<n;i++){
x=(double)rand()/RAND_MAX;
y=(double)rand()/RAND_MAX;
if((x*x+y*y)<=1){
count++;
}
}
pi=4.0*(double)count/(double)(n);
printf("pi value is:%f",pi);
return 0;
}

Output
Pi value is : 3.140440

