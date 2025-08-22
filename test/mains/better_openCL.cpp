#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 200

#include <CL/opencl.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "FileParse/FileIO.hpp"

const int numElements = 32;

int main(void)
{
	// Filter for a 2.0 or newer platform and set it as the default
	std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);
	cl::Platform platformFound;
	for (cl::Platform &p : platforms)
	{
		std::string platver = p.getInfo<CL_PLATFORM_VERSION>();
		if (platver.find("OpenCL 2.") != std::string::npos ||
			platver.find("OpenCL 3.") != std::string::npos)
		{
			// Note: an OpenCL 3.x platform may not support all required features!
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
	}

	std::vector<std::string> programStrings;
	programStrings.push_back(FileIO::Read("../media/better_1.cl"));
	programStrings.push_back(FileIO::Read("../media/better_2.cl"));

	cl::Program program(programStrings);
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

	typedef struct { int *bar; } Foo;

	// Get and run kernel that initializes the program-scope global
	// A test for kernels that take no arguments
	auto kernal_updateGlobal = cl::KernelFunctor<>(program, "updateGlobal");	//	<> is the Parameters. empty in this case
	kernal_updateGlobal(cl::EnqueueArgs(cl::NDRange(1)));						//	runs (queues) ?



	/*	SMV : Shared Virtual Memory
			pointer to shaded memory ?
			Video Memory / GPU Memory ?
	*/
	auto anSVMInt = cl::allocate_svm<int, cl::SVMTraitCoarse<>>();
	*anSVMInt = 5;

	cl::SVMAllocator<Foo, cl::SVMTraitCoarse<cl::SVMTraitReadOnly<>>> svmAllocReadOnly;
	auto fooPointer = cl::allocate_pointer<Foo>(svmAllocReadOnly);
	fooPointer -> bar = anSVMInt.get();

	cl::SVMAllocator<int, cl::SVMTraitCoarse<>> svmAlloc;
	std::vector<int, cl::SVMAllocator<int, cl::SVMTraitCoarse<>>> inputA(numElements, 1, svmAlloc);
	cl::coarse_svm_vector<int> inputB(numElements, 2, svmAlloc);

	/*	Buffer :
			Video Memory / GPU Memory ?
	*/
	//cl::Buffer outputBuffer(CL_MEM_READ_ONLY, numElements * sizeof(int));
	std::vector<int> output(numElements, 0xdeadbeef);
	cl::Buffer outputBuffer(begin(output), end(output), false);



	//	what do pipes do ?
	cl::Pipe aPipe = cl::Pipe(sizeof(cl_int), numElements / 2);



	auto kernal_vectorAdd = cl::KernelFunctor<
		decltype(fooPointer)&,
		int*,
		cl::coarse_svm_vector<int>&,
		cl::Buffer,
		int,
		cl::Pipe&,
		cl::DeviceCommandQueue
	>(program, "vectorAdd");

	// Default command queue, also passed in as a parameter
	cl::DeviceCommandQueue defaultDeviceQueue = cl::DeviceCommandQueue::makeDefault(
		cl::Context::getDefault(),
		cl::Device::getDefault()
	);

	// Ensure that the additional SVM pointer is available to the kernel
	// This one was not passed as a parameter
	kernal_vectorAdd.setSVMPointers(anSVMInt);

    cl_int error;
    kernal_vectorAdd(
        cl::EnqueueArgs(
            cl::NDRange(numElements/2),
            cl::NDRange(numElements/2)),
        fooPointer,
        inputA.data(),
        inputB,
        outputBuffer,
        3,
        aPipe,
        defaultDeviceQueue,
        error
        );

	const int * oB = (const int *)outputBuffer.get();
	cl::copy(outputBuffer, begin(output), end(output));

	std::cout << "Output:\n";
	for (int i = 0; i < numElements; ++i)
	{
		std::cout << "[" << i << "]" << "\t" << oB[i] << "\n";
		std::cout << "[" << i << "]" << "\t" << output[i] << "\n";
	}
	std::cout << "\n\n";

	return 0;
}
