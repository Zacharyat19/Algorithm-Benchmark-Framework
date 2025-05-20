#include <vector>

#include "AlgorithmBenchmark.h"

class SelectionSortBenchmark : public AlgorithmBenchmark
{
    public:
        SelectionSortBenchmark(size_t v_size);
        ~SelectionSortBenchmark();
        void run()                override;
        bool validate()           override;
        void results(double time) override;
    private:
        size_t size;
        std::vector<int> data;
        std::vector<int> reference;
};