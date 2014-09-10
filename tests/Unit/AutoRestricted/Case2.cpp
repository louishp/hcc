// RUN: %amp_device -D__GPU__ %s -m32 -emit-llvm -c -S -O2 -o %t.ll && mkdir -p %t
// RUN: %clamp-device %t.ll %t/kernel.cl
// RUN: pushd %t && %embed_kernel kernel.cl %t/kernel.o && popd
// RUN: %cxxamp %link %t/kernel.o %s -o %t.out && %t.out
#include <amp.h>

using std::vector;
using namespace Concurrency;

int f(int) restrict(cpu)
{
    return 0;
}

int f(float) restrict(cpu)
{
    return 0;
}

int test()
{
    accelerator device;
    accelerator_view rv = device.get_default_view();

    vector<int> vA(1, 0);
    array<int, 1> aA(extent<1>(1), vA.begin(), rv);

    parallel_for_each(aA.get_extent(), [&](index<1> idx) restrict(auto) { // Inferred as CPU
        int i = 0;

        aA[idx] = f(i);
    });

    vA = aA;

    return ((vA[0] == 1) ? 0 : 1);
}

int main(int argc, char **argv)
{
    int ret = test();
    return 0;
}

