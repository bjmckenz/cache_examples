#include <stdio.h>

/*
* This is a basic, no cache program. NOTHING weird.
*
* We call the function a "provider" because it provides data when
* requested. Look at that 4-bubble picture to remind yourself.
*
* What's wrong with this?
*
* It keeps calculating factorial even though the value never changes!
* Why should we do it multiple times? fact(5) is ALWAYS 120
*/


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

    // how to use it
    for (int ix=test_val; ix > 0; ix--) {
        printf(__FILE__ ":%2d   factorial of %d is %ld\n",__LINE__,
            ix,
            factorial(ix)
        );
    }
    for (int ix=0; ix < test_val; ix++) {
        printf(__FILE__ ":%2d   factorial of %d is %ld\n",__LINE__,
            ix,
            factorial(ix)
        );
    }

    return 0;
}
