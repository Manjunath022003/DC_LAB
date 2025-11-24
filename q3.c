#include<stdio.h>
#include<mpi.h>
int main(int argc,char ** argv){
MPI_Init(&argc,&argv);
int rank,data;
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
if(rank==0){
data=100;
printf("root data is:%d\n",data);
}
MPI_Bcast(&data,1,MPI_INT,0,MPI_COMM_WORLD);
printf("processor %d received data:%d\n",rank,data);
MPI_Finalize();
return 0;
}

Output
root data is:100
processor 0 received data:100
processor 1 received data:100
processor 2 received data:100
processor 3 received data:100
processor 4 received data:100
processor 5 received data:100
processor 6 received data:100
processor 7 received data:100
