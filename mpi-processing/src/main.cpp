#include <mpi.h>
#include <iostream>
#include <map>

#include "executor.hpp"

#define PICTURES_NUMBER 6

static std::map<int, std::pair<std::string, std::string>> tasks = {
	{ 0, { "/home/shared/evm/stud/s8500/Image/ppm/avp_logo.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/avp_logo.ppm" } },
	{ 1, { "/home/shared/evm/stud/s8500/Image/ppm/belka.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/belka.ppm" } },
	{ 2, { "/home/shared/evm/stud/s8500/Image/ppm/cat.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/cat.ppm" } },
	{ 3, { "/home/shared/evm/stud/s8500/Image/ppm/fire.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/fire.ppm" } },
	{ 4, { "/home/shared/evm/stud/s8500/Image/ppm/graffiti.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/graffiti.ppm" } },
	{ 5, { "/home/shared/evm/stud/s8500/Image/ppm/nature.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/nature.ppm" } },
	{ 6, { "/home/shared/evm/stud/s8500/Image/ppm/nvidia.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/nvidia.ppm" } },
	{ 7, { "/home/shared/evm/stud/s8500/Image/ppm/nvidia.ppm", "/home/shared/evm/stud/s8500/u850502/Azarko_Yersh_Buglakov_Zalevskaya/HPPA/mpi-processing/result/nvidia.ppm" } },
}; 

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);
	
	int procRank, procSize;
	MPI_Comm_rank(MPI_COMM_WORLD, &procRank);
	MPI_Comm_size(MPI_COMM_WORLD, &procSize);

	char processorName[MPI_MAX_PROCESSOR_NAME];
	int nameLength;
	MPI_Get_processor_name(processorName, &nameLength);

	std::cout << "Processor " << processorName << " with rank " << procRank << " of " << procSize << " started" << std::endl;	

	int cpuTime = 0;
	int gpuTime = 0;

	if (tasks.find(procRank) != tasks.end()) {
		std::cout << "Task for " << procRank << " found" << std::endl;

		auto from = tasks[procRank].first;		
		auto to = tasks[procRank].second;

		cpuTime += executeCPU(from, to + "_embossing_cpu");
		gpuTime += executeGPU(from, to + "_embossing_gpu");

		std::cout << "Task " << procRank << " handeled successfully" << std::endl;
	} else 
		std::cout << "Task " << procRank << " not found" << std::endl;


	if (procRank == 0) {
		double time;
		for (int i = 1; i < procSize; ++i) {
                        MPI_Recv(&time, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        cpuTime += time;

                        MPI_Recv(&time, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        gpuTime += time;
                }
		std::cout << "Average CPU time: " << (double)(cpuTime/PICTURES_NUMBER) << std::endl; 
		std::cout << "Average GPU time: " << (double)(gpuTime*10/PICTURES_NUMBER) << std::endl;
	} else {
                MPI_Send(&cpuTime, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
                MPI_Send(&gpuTime, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);		
	}
	
	MPI_Finalize();
	return 0;
}
