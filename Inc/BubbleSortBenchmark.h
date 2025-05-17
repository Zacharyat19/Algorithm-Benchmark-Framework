#include <vector>

#include "AlgorithmBenchmark.h"

class BubbleSortBenchmark : public AlgorithmBenchmark
{
    public:
        BubbleSortBenchmark(size_t v_size);
        ~BubbleSortBenchmark();
        void run()                override;
        bool validate()           override;
        void results(double time) override;
    private:
        size_t size;
        std::vector<int> data;
        std::vector<int> reference;
};