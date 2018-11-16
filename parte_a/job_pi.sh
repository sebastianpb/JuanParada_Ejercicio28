#PBS -l nodes=16:ppn=1,mem=1gb,walltime=00:10:00
#PBS -m abe
#PBS -N ejercicio28

cd $PBS_O_WORKDIR
make clean
make
mpirun -np 16 ./pi 100

