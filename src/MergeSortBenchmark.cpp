#include "../Inc/MergeSortBenchmark.h"

MergeSortBenchmark::MergeSortBenchmark(size_t v_size) : size(v_size) 
{
    data.resize(size);
    reference.resize(size);
    std::generate(data.begin(), data.end(), std::rand);
    reference = data;
    std::sort(reference.begin(), reference.end());
}

MergeSortBenchmark::~MergeSortBenchmark()
{
    data.clear();
    reference.clear();
}

void MergeSortBenchmark::merge(int low, int mid, int high)
{
    int i, j, k;
    int v1 = mid - low + 1;
    int v2 = high - mid;

    std::vector<int> vLeft(v1), vRight(v2);

    for (i = 0; i < v1; i++)
    {
        vLeft[i] = data[low + i];
    }
    
    for (j = 0; j < v2; j++)
    {
        vRight[j] = data[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;
    while (i < v1 && j < v2) 
    {
        if (vLeft[i] <= vRight[j]) 
        {
            data[k] = vLeft[i];
            i++;
        } 
        else 
        {
            data[k] = vRight[j];
            j++;
        }

        k++;
    }

    while (i < v1) 
    {
        data[k] = vLeft[i];
        i++;
        k++;
    }

    while (j < v2) 
    {
        data[k] = vRight[j];
        j++;
        k++;
    }
}

void MergeSortBenchmark::mergesort(int low, int high)
{
    if (low < high) 
    {
      
        int mid = low + (high - low) / 2;

        mergesort(low, mid);
        mergesort(mid + 1, high);

        merge(low, mid, high);
    }
}

void MergeSortBenchmark::run()
{
    mergesort(0, data.size() - 1);
}

bool MergeSortBenchmark::validate()
{
    return data == reference;
}

void MergeSortBenchmark::results(double time)
{
    bool result = validate();
    double throughput = size / (time / 1000.0);
    double bandwidth = (3.0 * size * sizeof(int)) / (time * 1e6);

    std::cout << "==== Benchmark Results Merge Sort ====\n";
    std::cout << "Runtime      : " << time << " ms\n";
    std::cout << "Throughput   : " << throughput << " ops/sec\n";
    std::cout << "Bandwidth    : " << bandwidth << " GB/s\n";
    std::cout << "Validation   : " << (result ? "Passed" : "Failed") << "\n\n";
}