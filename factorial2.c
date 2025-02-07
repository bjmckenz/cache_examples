#include <stdio.h>

/*
* Moving towards cache, ONE WEIRD TRICK.
*
* Instead of referring to the function directly, we'll use a pointer
* to it.
*
* No other changes.
*/


// a type for this flavor of provider
typedef long (*long_func_ptr)(int param);


// a factorial "provider"
long factorial(int of_num) {
    printf(__FILE__ ":%2d   factorial(%d) called\n",__LINE__,
        of_num);

    if (of_num < 2)
        return of_num;

    return of_num * factorial(of_num-1);
}

int main(int argc, char *argv[]) {
    int test_val;

    if (argc < 2
            || 1 != sscanf(argv[1],"%d",&test_val)
            || test_val < 0)
        return 1;

    // PROGRAM INITIALIZATION
    long_func_ptr factorial_provider = factorial;


    // PROGRAM FUNCTIONALITY

    // how to use it
    for (int ix=test_val; ix > 0; ix--) {
        printf(__FILE__ ":%2d   factorial of %d is %ld\n",__LINE__,
            ix,
            (*factorial_provider)(ix)
        );
    }
    for (int ix=0; ix < test_val; ix++) {
        printf(__FILE__ ":%2d   factorial of %d is %ld\n",__LINE__,
            ix,
            (*factorial_provider)(ix)
        );
    }

    return 0;
}
