#include "../Inc/BubbleSortBenchmark.h"

BubbleSortBenchmark::BubbleSortBenchmark(size_t v_size) : size(v_size) 
{
    data.resize(size);
    reference.resize(size);
    std::generate(data.begin(), data.end(), std::rand);
    reference = data;
    std::sort(reference.begin(), reference.end());
}

BubbleSortBenchmark::~BubbleSortBenchmark()
{
    data.clear();
    reference.clear();
}

void BubbleSortBenchmark::run()
{
    for(size_t i = 0; i < data.size() - 1; i++)
    {
        bool swapped = false;
        for(size_t j = 0; j < data.size() - i - 1; j++)
        {
            if(data[j] > data[j + 1])
            {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

bool BubbleSortBenchmark::validate()
{
    return data == reference;
}

void BubbleSortBenchmark::results(double time)
{
    bool result = validate();
    double throughput = size / (time / 1000.0);
    double bandwidth = (3.0 * size * sizeof(int)) / (time * 1e6);

    std::cout << "==== Benchmark Results Bubble Sort ====\n";
    std::cout << "Runtime      : " << time << " ms\n";
    std::cout << "Throughput   : " << throughput << " ops/sec\n";
    std::cout << "Bandwidth    : " << bandwidth << " GB/s\n";
    std::cout << "Validation   : " << (result ? "Passed" : "Failed") << "\n\n";
}