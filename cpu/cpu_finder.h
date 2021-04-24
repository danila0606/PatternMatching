#pragma once

#include <string>
#include <vector>
#include <chrono>

class Cpu_Finder final {
public:
    Cpu_Finder(const std::vector<std::string>& patterns) : patterns_(patterns) {}

    std::vector<size_t> GetCounts(const std::string& text, size_t& time) const;
private:

    size_t find(const std::string& text, const std::string& pattern) const;

    std::vector<std::string> patterns_;
};