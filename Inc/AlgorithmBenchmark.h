#pragma once

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <chrono>

class AlgorithmBenchmark
{
    public:
        virtual void run()                = 0;
        virtual bool validate()           = 0;
        virtual void results(double time) = 0;
        virtual ~AlgorithmBenchmark() = default;
};