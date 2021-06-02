#!/bin/sh

cd /home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/build
../../../cmake/bin/cmake ..


../../../cmake/bin/cmake --build ./ --target mpi-processing
