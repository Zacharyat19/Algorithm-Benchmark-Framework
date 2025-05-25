#include "AlgorithmBenchmark.h"

class MergeSortBenchmark : public AlgorithmBenchmark
{
    public:
        MergeSortBenchmark(size_t v_size);
        ~MergeSortBenchmark();
        void run()                override;
        bool validate()           override;
        void results(double time) override;
    private:
        size_t size;
        std::vector<int> data;
        std::vector<int> reference;

        void merge(int low, int mid, int high);
        void mergesort(int low, int high);
};