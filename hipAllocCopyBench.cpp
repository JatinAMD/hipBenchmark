#include <benchmark/benchmark.h>
#include <iostream>
#include <hip/hip_runtime.h>


static void BM_hipalloc(benchmark::State& state) {
    for (auto _ : state) {
        int *a; 
        hipMalloc((void**)&a, 10 * sizeof(int));
        hipFree(a);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_hipalloc);

static void BM_hipcopy(benchmark::State& state) {
    for (auto _ : state) {
        int *a;
        int b[] = {1,2,3,4,5,6,7,8,9,10};
        hipMalloc((void**)&a, 10 * sizeof(int));
        hipMemcpy(a, b, 10 * sizeof(float), hipMemcpyHostToDevice);
        hipFree(a);
    }
}
BENCHMARK(BM_hipcopy);

static void BM_hipcopyback(benchmark::State& state) {                            
    for (auto _ : state) {                                               
        int *a;                                                      
        int b[] = {1,2,3,4,5,6,7,8,9,10};                            
        hipMalloc((void**)&a, 10 * sizeof(int));                     
        hipMemcpy(a, b, 10 * sizeof(float), hipMemcpyHostToDevice);  
        hipMemcpy(b, a, 10 * sizeof(float), hipMemcpyDeviceToHost);
        hipFree(a);                                                  
    }                                                                    
}                                                                            
BENCHMARK(BM_hipcopyback);                                                       

BENCHMARK_MAIN();
