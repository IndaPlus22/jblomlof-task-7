/*
Ok ok ok, I now know why my code has been so shitty
BTW this is the fourth version using the inbuilt qsort(),
since that seems to be the only viable option to get quick runtime
I've now realized in my attempt at being cool i made the array simple
strings WITHOUT the end_of_string_character, the null character,.
And thus the strcmp function believes i want to compare THE WHOLE array....
CLASSIC

Should be all good now :I
I implemented a lazy fix :) simply extending the array and adding that character.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int SIZE = 42; // 20 for firstname + 1 for seperation + 20 for surname + 1 for nul
                     // make sure to include a space for the Nul string character
const int HALF = 21; // 20 for the name and + 1 for seperation.

int my_comp(const void *pOne, const void *pTwo)
{
    //return (*(long long*)pOne - *(long long*)pTwo);
    return strcmp(pOne, pTwo);
    //wow im actually mentally unstable rn
    //How come strcmp works GOOD,
    //but not (*(int*)pOne - *(int*)pTwo) ?!?!?!
    //not even  with (long long*) !?!? so it cant be faulty because of overflow/underflow
}

int main()
{
    long long number_of_names;
    char temp_name_store[SIZE];
    long long dupes = 0;
    long long i;
    int s;

    scanf("%lld", &number_of_names);
    //printf("%lld", number_of_names);
    char name_list[number_of_names][SIZE];

    for (i = 0; i < number_of_names; i++) // just copying the first names.
    {
        scanf("%s", temp_name_store);
        for (s = 0; temp_name_store[s]; s++) // i could maybe have scan in this loop, but i like scanf("%s") handles whitespace for me.
        {
            name_list[i][s] = temp_name_store[s];
        }
        for (s = s; s < HALF; s++)
        {
           name_list[i][s] = '.';
        }
    }

    for (i = 0; i < number_of_names; i++) // surname time
    {
        scanf("%s", temp_name_store);
        for (s = 0; temp_name_store[s]; s++)
        {
            name_list[i][s + HALF] = temp_name_store[s];
        }
        for (s = s; s < HALF; s++)
        {
            name_list[i][s + HALF] = '.';
        }
        name_list[i][SIZE - 1] = 0;
        // this is the GREAT FIX ^^
    }

    qsort(name_list, number_of_names, sizeof(char[SIZE]), my_comp);

    for (i = 0; i < number_of_names - 1; i++)
    {
        if (strcmp(name_list[i], name_list[i + 1]) == 0) 
            dupes++;
    }

    printf("%lld", (number_of_names - dupes));
    return 0;
}