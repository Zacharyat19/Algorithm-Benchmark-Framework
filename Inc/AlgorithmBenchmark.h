#pragma once

class AlgorithmBenchmark
{
    public:
        virtual void run()                = 0;
        virtual bool validate()           = 0;
        virtual void results(double time) = 0;
        virtual ~AlgorithmBenchmark() = default;
};