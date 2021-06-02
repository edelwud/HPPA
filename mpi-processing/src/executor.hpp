#include <image/image-rgb.hpp>
#include <image/image-rgb-cpu.hpp>

#include <loader/loader.hpp>

#include <filters/laplace-filter.cuh>
#include <filters/embossing-filter.cuh>

#include <string>

double executeGPU(std::string from, std::string to) {
	auto image = Loader::loadImage(from, 3);
	ImageRGB imageHandler(image);

	imageHandler.setFilter(embossingFilter);
	double gpuTime = imageHandler.applyFilter();	

	Loader::saveImage(imageHandler.getImage(), to, 3);

	return gpuTime;
}


double executeCPU(std::string from, std::string to) {
        auto image = Loader::loadImage(from, 3);
        ImageRGBCpu imageHandler(image);

        imageHandler.setFilter(embossingFilter);
        double gpuTime = imageHandler.applyFilter();

        Loader::saveImage(imageHandler.getImage(), to, 3);

        return gpuTime;
}
