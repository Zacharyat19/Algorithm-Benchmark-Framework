#include <vector>

#include "AlgorithmBenchmark.h"

class QuickSortBenchmark : public AlgorithmBenchmark
{
    public:
        QuickSortBenchmark(size_t v_size);
        ~QuickSortBenchmark();
        void run()                override;
        bool validate()           override;
        void results(double time) override;
    private:
        size_t size;
        std::vector<int> data;
        std::vector<int> reference;

        int  partion(int low, int high);
        void quicksort(int low, int high);
};