#PBS -l nodes=16:ppn=1,mem=1gb,walltime=00:10:00
#PBS -m abe
#PBS -N ejercicio28

cd $PBS_O_WORKDIR
module load anaconda/python3
N=(100 1000 10000 100000 1000000 10000000 100000000)
i=2
n=10
mpicc -o integra.x integra.c -lm
for Ns in ${N[@]}
do
    echo $Ns
    mpiexec -np $n ./integra.x $Ns > "File_${i}.txt"
    # ./integra $n > "File_${i}.txt"
    i=$((i+1))
done

python plot.py