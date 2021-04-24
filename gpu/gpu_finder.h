#pragma once

#include "Matrix/Matrix.h"

#ifdef __APPLE__
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif

#include <sstream>
#include <fstream>

class Gpu_Finder final {

private:

    cl::Platform platform_;
    cl::Context context_;
    cl::Device device_;
    cl::CommandQueue queue_;
    cl::Program program_;
    mutable cl::Kernel kernel_;

    const std::string kernel_name_;

private:

    const std::vector<std::string> patterns_;

    linal::Matrix<std::vector<size_t>> Pattern_table = linal::Matrix<std::vector<size_t>>(256,256);
    size_t maxdepth = 0;

    std::vector<linal::Matrix<cl_float4>> Signature_tables;


private:

    void ChoosePlatformAndDevice(); //choose by user in console
    void ChooseDefaultPlatformAndDevice(); //choose first suited platform and device

    void BuildPatternTable();
    void BuildSignatureTables();

    std::vector<size_t> FindSmallPatterns(const std::string& text) const;

public:

    explicit Gpu_Finder(const std::vector<std::string>& patterns, const std::string& kernel_name = "match.cl");

    std::vector<size_t> GetCounts(const std::string& text, size_t& time) const;

};