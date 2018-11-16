#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char **argv){
    long n_points;
    double x,y, suma1, suma2, integ, frac;
    long long i;
    long long j;

    int rank, number;
    int n_points_proc;

    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &number);

    n_points = atol(argv[1]);

    n_points_proc = n_points / number;
   

    srand48(rank);
    suma1=0;
    suma2=0;
    for(i=0;i<n_points_proc;i++){  
        suma1=0;
        for(j=0;j<10;j++){
            x=drand48();
            suma1+=drand48();
        }
        y=pow(suma1,2);
        
        //y=exp(x);
        suma2 += y;
    }
    frac=suma2/n_points_proc;
    frac=frac/n_points;
    
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&frac, &integ, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (rank == 0){
        printf("%.16f", integ);
        //end_time = MPI_Wtime();
        //computation_time = end_time - start_time;       
        //printf("Time of calculating pi is: %f\n", computation_time);  
    }
 
    //MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize(); 
    return 0;
}