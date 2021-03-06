#include HEADER
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#if defined(BRANCH)
#define N 10000
#define P1 10079
#define P2 10631
#define Pr 11
#define P3 31

void gen(int src1[], int src2[])
{
    src1[0] = src2[0] = 0;
    int seed1 = Pr, seed2 = Pr*Pr*Pr;
    for(int i=1; i<N; ++i) {
        src1[i] = src1[i-1] + (seed1 % P1) % P3;
        src2[i] = src2[i-1] + (seed2 % P2) % P3;
        //printf("%d, %d, %d\n",src1[i],src2[i],i);
        seed1 = (seed1 * Pr * Pr * Pr * Pr) % P1;
        seed2 = (seed2 * Pr * Pr * Pr) % P2;
    }
    return;
}
#endif

int main(void)
{
#if defined(PI)
    printf("pid: %d\n", getpid());
    sleep(10);
    compute_pi_baseline(50000000);
#elif defined(MATRIX)
    static int array[10000][10000] = {0};
    matrix(10000,10000,array);
#elif defined(BRANCH)
    static int src1[N], src2[N], dst[N*2];
    gen(src1, src2);
    merge(src1, src2, dst, N);
#endif
    return 0;

}


