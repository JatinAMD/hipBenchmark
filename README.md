# hipBenchmark

READ ME FIRST - Guide to Micro-Benchmark your HIP Code.

Checkout the google benchmark lib.
```bash                                                                                   
# Check out the library.                                                                  
$ git clone https://github.com/google/benchmark.git                                       
# Benchmark requires Google Test as a dependency. Add the source tree as a subdirectory.  
$ git clone https://github.com/google/googletest.git benchmark/googletest                 
# Make a build directory to place the build output.                                       
$ mkdir build && cd build                                                                 
# Generate a Makefile with cmake.                                                         
# Use cmake -G <generator> to generate a different file type.                             
$ cmake ../benchmark                                                                      
# Build the library.                                                                      
$ make                                                                                    
```                                                                                       

### Debug vs Release                                                           
                                                                               
By default, benchmark builds as a debug library. You will see a warning in the 
output when this is the case. To build it as a release library instead, use:   
                                                                               
```                                                                            
cmake -DCMAKE_BUILD_TYPE=Release                                               
```                                                                            
                                                                               
To enable link-time optimisation, use                                          
                                                                               
```                                                                            
cmake -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_LTO=true                   
```                                                                            

This builds the `benchmark` and `benchmark_main` libraries and tests.                     
On a unix system, the build directory should now look something like this:                
                                                                                          
```                                                                                       
/benchmark                                                                                
/build                                                                                    
  /src                                                                                    
    /libbenchmark.a                                                                       
    /libbenchmark_main.a                                                                  
  /test                                                                                   
    ...                                                                                   
```                                                                                       
                                                                                          
Next, you can run the tests to check the build - totally optional. 
                                                                                          
```bash                                                                                   
$ make test                                                                               
```                                                                                       

Now open 'postflags' file and set the include and link library, make sure it represents your directory structure.
Basically  ```-I``` and ```-L``` flags to point to right directory.

For AMD Platforms
```bash
$ hipcc $(<preflags) <sourcefile> -o <destination> $(<postflags)
```
For NVIDIA Platforms - Basically skip preflags
```bash
$ hipcc <sourcefile> -o <destination> $(<postflags)
```
