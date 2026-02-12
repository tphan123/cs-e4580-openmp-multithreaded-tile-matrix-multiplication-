#include "mm.h"
#include <algorithm>
#include <cstdint> 
void gemm(int m, int n, int k,
          const std::int8_t* A,
          const std::int8_t* B,
          std::int32_t* C)
{
    const int tilesize = 64;
    #pragma omp parallel
    for (int kk = 0; kk < k ; kk += tilesize) {
        
            int kk_tileend = std::min(k, kk + tilesize);       
            #pragma omp for collapse(2) schedule(static) 
            for (int i = 0; i < m ; ++i) {
                for (int j =0; j < n; ++j){
                    int32_t acc = 0; 
                    for (int k_inner = kk; k_inner < kk_tileend ; ++k_inner){
                        acc += A[i*k+ k_inner]*B[k_inner*n+j]; 
                    }

                    if (kk == 0) {
                        C[i*n + j] = acc;
                    }
                    else         {
                        C[i*n + j] += acc;
                    }

                

            
            
               
            }
        }
    }
}

 

