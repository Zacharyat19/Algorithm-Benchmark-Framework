#include <memory>
#include <chrono>

#include "../Inc/BubbleSortBenchmark.h"
#include "../Inc/SelectionSort.h"

int main()
{
    std::vector<std::unique_ptr<AlgorithmBenchmark>> benchmarks;

    benchmarks.push_back(std::make_unique<BubbleSortBenchmark>(1000));
    benchmarks.push_back(std::make_unique<SelectionSortBenchmark>(1000));

    for(const auto& benchmark : benchmarks)
    {
        auto start = std::chrono::high_resolution_clock::now();

        benchmark->run();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;

        benchmark->results(elapsed.count());
    }

    return 0;
}