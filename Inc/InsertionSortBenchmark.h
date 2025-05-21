#include "AlgorithmBenchmark.h"

class InsertionSortBenchmark : public AlgorithmBenchmark
{
    public:
        InsertionSortBenchmark(size_t v_size);
        ~InsertionSortBenchmark();
        void run()                override;
        bool validate()           override;
        void results(double time) override;
    private:
        size_t size;
        std::vector<int> data;
        std::vector<int> reference;
};