#include "../Inc/InsertionSortBenchmark.h"

InsertionSortBenchmark::InsertionSortBenchmark(size_t v_size) : size(v_size) 
{
    data.resize(size);
    reference.resize(size);
    std::generate(data.begin(), data.end(), std::rand);
    reference = data;
    std::sort(reference.begin(), reference.end());
}

InsertionSortBenchmark::~InsertionSortBenchmark()
{
    data.clear();
    reference.clear();
}

void InsertionSortBenchmark::run()
{
    int key, j;

    for (size_t i = 1; i < data.size(); i++) 
    {
        key = data[i];
        j = i - 1;

        while (j >= 0 && data[j] > key) 
        {
            data[j + 1] = data[j];
            j = j - 1;
        }

        data[j + 1] = key;
    }
}

bool InsertionSortBenchmark::validate()
{
    return data == reference;
}

void InsertionSortBenchmark::results(double time)
{
    bool result = validate();
    double throughput = size / (time / 1000.0);
    double bandwidth = (3.0 * size * sizeof(int)) / (time * 1e6);

    std::cout << "==== Benchmark Results Insertion Sort ====\n";
    std::cout << "Runtime      : " << time << " ms\n";
    std::cout << "Throughput   : " << throughput << " ops/sec\n";
    std::cout << "Bandwidth    : " << bandwidth << " GB/s\n";
    std::cout << "Validation   : " << (result ? "Passed" : "Failed") << "\n\n";
}