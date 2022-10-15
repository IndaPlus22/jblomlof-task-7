/***
 * Template to a Kattis solution.
 * See: https://open.kattis.com/help/c
 * Author: Viola Söderlund <violaso@kth.se>
 */

//this solution is a bit iffy in terminal since it wont really stop.
//however kattis enjoys inputting as files and thus we can use EOF.

#include <stdio.h> // standard input/output library

/// Kattis calls main function to run your solution
int main()
{
    long long variable_1; // ints/longs are 4 bytes (in my system atleast) thus i we need long long :)
    long long variable_2;

    fprintf(stderr, "Size of variable must be greather than or equal to 8. Your variable is: %d bytes\n", sizeof(variable_1));
    if (sizeof(variable_1) < 8)
    {
        return 1; // uh oh i dont think memory wants to die. We exit here otherwise we might overflow.
    }

    // I treid to do this with the function abs. (aka i did abs(variable_1 - variable_2)) but i guess it shits it self
    //  since input can be greater than an int.
    while (EOF != scanf("%lld %lld", &variable_1, &variable_2))
    {
        if (variable_1 > variable_2)
        {
            printf("%lld\n", variable_1 - variable_2);
        }
        else
        {
            printf("%lld\n", variable_2 - variable_1);
        }
    }
    return 0;
}