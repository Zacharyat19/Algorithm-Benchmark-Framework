# Algorithm Benchmark Framework

This project benchmarks C++ algorithms with high-resolution timing, aiming to evaluate performance for various data sizes and algorithm types.

## Features

- Modular design with abstract base class (`AlgorithmBenchmark`)
- High-resolution timing using `std::chrono`
- CLI-configurable data size
- Clean output of runtime results
- Easily extendable with additional algorithm implementations

## CLI Arguments

The program accepts multiple algorithms and corresponding input sizes via command-line options:

```bash
./benchmark -a BubbleSort -a QuickSort -s 1000 -s 10000
```
This runs:
- `BubbleSort` with input size `1000`
- `QuickSort` with input size `10000`

Options:
- `-a, --algorithm`

  List of algorithms to benchmark.

  Required. Available options: BubbleSort, SelectionSort, QuickSort, InsertionSort
- `-s, --size`

  List of input sizes, in the same order as the algorithms provided.

  Required. Must match the number of algorithms.
