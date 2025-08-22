#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 200
#include <CL/opencl.hpp>

#include <iostream>
#include <vector>
#include <array>

#include "FileParse/FileIO.hpp"

int main(void)
{
	/*std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	cl::Platform platformFound;
	for (cl::Platform &p : platforms)
	{
		std::string platver = p.getInfo<CL_PLATFORM_VERSION>();
		if (platver.find("OpenCL 2.") != std::string::npos ||
			platver.find("OpenCL 3.") != std::string::npos)
		{
			platformFound = p;
		}
	}
	if (platformFound() == 0)
	{
		std::cout << "No OpenCL 2.0 or newer platform found.\n";
		return -1;
	}

	cl::Platform platform = cl::Platform::setDefault(platformFound);
	if (platform != platformFound)
	{
		std::cout << "Error setting default platform.\n";
		return -1;
	}*/

	std::string file_text = FileIO::Read("../media/my.cl");

	cl::Program program(file_text);
	try
	{
		program.build("-cl-std=CL2.0");
	}
	catch (...)
	{
		cl_int buildErr = CL_SUCCESS;
		cl::BuildLogType buildInfo = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(&buildErr);
		for (std::pair<cl::Device, std::string> &pair : buildInfo)
		{
			std::cerr << pair.second << std::endl << std::endl;
		}
		return 1;
	}

	cl_int err;

	int BufferLen = 4;
	int defaultVal = 0;


	std::vector<int> data(BufferLen, defaultVal + 10000);
	cl::SVMAllocator<int, cl::SVMTraitFine<>> svm_alloc;



	cl::Buffer bufferI(std::begin(data), std::end(data), false, false, &err);
	if (err != CL_SUCCESS) { std::cout << "Error: " << err << "\n"; } else { std::cout << "Succ\n"; }
	cl::Buffer bufferO(CL_MEM_WRITE_ONLY, BufferLen * sizeof(int), nullptr, &err);
	if (err != CL_SUCCESS) { std::cout << "Error: " << err << "\n"; } else { std::cout << "Succ\n"; }



	cl::fine_svm_vector<int> svmI(BufferLen, defaultVal + 20000, svm_alloc);
	cl::fine_svm_vector<int> svmO(BufferLen, svm_alloc);



	int * valI = (int *)svm_alloc.allocate(BufferLen * sizeof(int));
	int * valO = (int *)svm_alloc.allocate(BufferLen * sizeof(int));
	for (int i = 0; i < BufferLen; i++) {valI[i] = defaultVal + 30000; }



	std::cout << "bufI:"; for (int i = 0; i < BufferLen; i++) { std::cout << " " << data[i]; } std::cout << "\n";
	std::cout << "svmI:"; for (int i = 0; i < BufferLen; i++) { std::cout << " " << svmI[i]; } std::cout << "\n";
	std::cout << "valI:"; for (int i = 0; i < BufferLen; i++) { std::cout << " " << valI[i]; } std::cout << "\n";



	auto kernel_test = cl::KernelFunctor<
		cl::Buffer,
		cl::Buffer,
		cl::fine_svm_vector<int>&,
		cl::fine_svm_vector<int>&,
		int *,
		int *
	>(program, "testFunc", &err);
	if (err != CL_SUCCESS) { std::cout << "Error: " << err << "\n"; } else { std::cout << "Succ\n"; }


	std::cout << "valI: " << ((void *)valI) << "\n";
	std::cout << "valO: " << ((void *)valO) << "\n";


	for (int j = 0; j < 10; j++)
	{
		kernel_test(
			cl::EnqueueArgs(
				cl::NDRange(BufferLen)
			),
			bufferI,
			bufferO,
			svmI,
			svmO,
			valI,
			valO,
			err
		);
		std::cout << "Kernel Run [" << j << "]: ";
		if (err != CL_SUCCESS) { std::cout << "Error: " << err << "\n"; } else { std::cout << "Succ\n"; }



		//	kernel runs in "Background". if you dont wait what the SVM and Pointers still have old values
		cl::finish();
		cl::copy(bufferO, std::begin(data), std::end(data));

		std::cout << "bufO:"; for (int i = 0; i < BufferLen; i++) { std::cout << " " << data[i]; } std::cout << "\n";
		std::cout << "svmO:"; for (int i = 0; i < BufferLen; i++) { std::cout << " " << svmO[i]; } std::cout << "\n";
		std::cout << "valO:"; for (int i = 0; i < BufferLen; i++) { std::cout << " " << valO[i]; } std::cout << "\n";

		cl::copy(std::begin(data), std::end(data), bufferI);
		for (int i = 0; i < BufferLen; i++)
		{
			svmI[i] = svmO[i];
			valI[i] = valO[i];
		}
	}



	svm_alloc.deallocate(valI, BufferLen * sizeof(int));
	svm_alloc.deallocate(valO, BufferLen * sizeof(int));

	return 0;
}
