#include "../Inc/SelectionSortBenchmark.h"

SelectionSortBenchmark::SelectionSortBenchmark(size_t v_size) : size(v_size) 
{
    data.resize(size);
    reference.resize(size);
    std::generate(data.begin(), data.end(), std::rand);
    reference = data;
    std::sort(reference.begin(), reference.end());
}

SelectionSortBenchmark::~SelectionSortBenchmark()
{
    data.clear();
    reference.clear();
}

void SelectionSortBenchmark::run()
{
    int idx;
    for(size_t i = 0; i < data.size() - 1; i++)
    {
        idx = i;
        for(size_t j = i + 1; j < data.size(); j++)
        {
            if(data[j] < data[idx])
            {
                idx = j;
            }
        }

        std::swap(data[i], data[idx]);
    }
}

bool SelectionSortBenchmark::validate()
{
    return data == reference;
}

void SelectionSortBenchmark::results(double time)
{
    bool result = validate();
    double throughput = size / (time / 1000.0);
    double bandwidth = (3.0 * size * sizeof(int)) / (time * 1e6);

    std::cout << "==== Benchmark Results Selection Sort ====\n";
    std::cout << "Runtime      : " << time << " ms\n";
    std::cout << "Throughput   : " << throughput << " ops/sec\n";
    std::cout << "Bandwidth    : " << bandwidth << " GB/s\n";
    std::cout << "Validation   : " << (result ? "Passed" : "Failed") << "\n\n";
}