#include<mpi.h>
#include<stdio.h>
int main(int argc,char **argv){
MPI_Init(&argc,&argv);
int  rank,size;
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
int sum,max,min,prod;
int asum,amax,amin,aprod;
int value=rank+1;
MPI_Reduce(&value,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
MPI_Reduce(&value,&max,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
MPI_Reduce(&value,&min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
MPI_Reduce(&value,&prod,1,MPI_INT,MPI_PROD,0,MPI_COMM_WORLD);
if(rank==0){
printf("sum:%d",sum);
printf("prod:%d",prod);
printf("min:%d",min);
printf("max:%d",max);
}
printf("\n");
MPI_Allreduce(&value,&asum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
MPI_Allreduce(&value,&amax,1,MPI_INT,MPI_MAX,MPI_COMM_WORLD);
MPI_Allreduce(&value,&amin,1,MPI_INT,MPI_MIN,MPI_COMM_WORLD);
MPI_Allreduce(&value,&aprod,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);

printf("rank=%d allsum=%d allmax=%d allmin=%d allprod=%d\n",rank,asum,amax,amin,aprod);
MPI_Finalize();
return 0;
}
Output
sum: 36  prod: 40320  min: 1  max: 8
rank=0 allsum=36 allmax=8 allmin=1 allprod=40320
rank=1 allsum=36 allmax=8 allmin=1 allprod=40320
rank=2 allsum=36 allmax=8 allmin=1 allprod=40320
rank=3 allsum=36 allmax=8 allmin=1 allprod=40320
