#include "../Inc/QuickSortBenchmark.h"

QuickSortBenchmark::QuickSortBenchmark(size_t v_size) : size(v_size) 
{
    data.resize(size);
    reference.resize(size);
    std::generate(data.begin(), data.end(), std::rand);
    reference = data;
    std::sort(reference.begin(), reference.end());
}

QuickSortBenchmark::~QuickSortBenchmark()
{
    data.clear();
    reference.clear();
}

int QuickSortBenchmark::partition(int low, int high)
{
    int pi = data[high];

    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if(data[j] <= pi)
        {
            i++;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[high]);

    return (i + 1);
}

void QuickSortBenchmark::quicksort(int low, int high)
{
    if(low < high)
    {
        int pi = partition(low, high);

        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

void QuickSortBenchmark::run()
{
    quicksort(0, data.size() - 1);
}

bool QuickSortBenchmark::validate()
{
    return data == reference;
}

void QuickSortBenchmark::results(double time)
{
    bool result = validate();
    double throughput = size / (time / 1000.0);
    double bandwidth = (3.0 * size * sizeof(int)) / (time * 1e6);

    std::cout << "==== Benchmark Results Quick Sort ====\n";
    std::cout << "Runtime      : " << time << " ms\n";
    std::cout << "Throughput   : " << throughput << " ops/sec\n";
    std::cout << "Bandwidth    : " << bandwidth << " GB/s\n";
    std::cout << "Validation   : " << (result ? "Passed" : "Failed") << "\n\n";
}