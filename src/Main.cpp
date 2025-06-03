#include <unordered_map>

#include "../Inc/CLI11.hpp"
#include "../Inc/BubbleSortBenchmark.h"
#include "../Inc/SelectionSortBenchmark.h"
#include "../Inc/QuickSortBenchmark.h"
#include "../Inc/InsertionSortBenchmark.h"
#include "../Inc/MergeSortBenchmark.h"

int main(int argc, char** argv)
{
    CLI::App app{"Algorithm Benchmark"};

    std::vector<std::string> algorithms;
    std::vector<int> sizes;

    app.add_option("-a,--algorithm", algorithms, "Algorithms to benchmark")->required()
        ->check(CLI::IsMember({"BubbleSort", "SelectionSort", "QuickSort", "InsertionSort", "MergeSort"}))
        ->expected(1, -1);

    app.add_option("-s,--size", sizes, "Input sizes")->required()->expected(1, -1);

    CLI11_PARSE(app, argc, argv);

    std::unordered_map<std::string, std::function<std::unique_ptr<AlgorithmBenchmark>(int)>> factory = 
    {
        {"BubbleSort",    [](int size) { return std::make_unique<BubbleSortBenchmark>(size);    }},
        {"SelectionSort", [](int size) { return std::make_unique<SelectionSortBenchmark>(size); }},
        {"QuickSort",     [](int size) { return std::make_unique<QuickSortBenchmark>(size);     }},
        {"InsertionSort", [](int size) { return std::make_unique<InsertionSortBenchmark>(size); }},
        {"MergeSort",     [](int size) { return std::make_unique<MergeSortBenchmark>(size);     }}
    };

    std::vector<std::unique_ptr<AlgorithmBenchmark>> benchmarks;

    for (size_t i = 0; i < algorithms.size(); i++) 
    {
        if (factory.count(algorithms[i])) 
        {
            benchmarks.emplace_back(factory[algorithms[i]](sizes[i]));
        }
    }

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