#!/bin/bash
#PBS -N run-mpi-cuda
#PBS -l nodes=3:ppn=2
#PBS -l mem=10gb
#PBS -j oe
#PBS -q batch

# set working rirectory to current
cd $PBS_O_WORKDIR

# run job for a.out, redirect all output to file *.run.out
echo `pwd`

free 1>free-`hostname`-run.out&&

#echo $PATH
#echo $LD_LIBRARY_PATH
#cat $PBS_NODEFILE

/usr/lib64/openmpi/bin/mpirun -hostfile $PBS_NODEFILE ./build/src/mpi-processing

