
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE = 40;

int isTheSameName(const char *pOne, const char *pTwo)
{
    for (int s = 0; s < SIZE; s++)
    {
        if (*(pOne + s) != *(pTwo + s))
        {
            return 0; // returning false
        }
    }
    return 1; // the names are the same returning 1 as "True"
}

int main()
{
    long long number_of_names;
    char temp_name_store[SIZE / 2 + 1];
    char *pReal_name_list;
    long long sum = 0;
    int i, j, s;

    scanf("%lld", &number_of_names);
    pReal_name_list = (char *)malloc(sizeof(char) * number_of_names * SIZE);

    for (i = 0; i < number_of_names; i++) // just copying the first names.
    {
        scanf("%s", temp_name_store);
        /* for (s = 0; temp_name_store[s]; s++)
         {
             temp_name_store[s] = tolower(temp_name_store[s]);
         }*/
        for (s = 0; temp_name_store[s]; s++) // i could maybe have scan in this loop, but i like scanf("%s") handles whitespace for me.
        {
            *(pReal_name_list + (SIZE * i) + s) = temp_name_store[s];
        }
        for (s = s; s < SIZE / 2; s++)
        {
            *(pReal_name_list + (SIZE * i) + s) = '.';
        }
    }

    for (i = 0; i < number_of_names; i++) // surname time
    {
        scanf("%s", temp_name_store);
        /*for (s = 0; temp_name_store[s]; s++)
        {
            temp_name_store[s] = tolower(temp_name_store[s]);
        }*/
        for (s = 0; temp_name_store[s]; s++)
        {
            *(pReal_name_list + SIZE * i + (SIZE / 2) + s) = temp_name_store[s];
        }
        for (s = s; s < SIZE / 2; s++)
        {
            *(pReal_name_list + (SIZE * i) + (SIZE / 2) + s) = '.';
        }

        for (j = 0; j < i; j++) // checking the names we already did.
        {
            if (isTheSameName((pReal_name_list + (SIZE * i)), (pReal_name_list + (SIZE * j))))
            {
                sum--;
                break;
            }
        }
        sum++;
    }

    printf("%lld", sum);
    free(pReal_name_list);
    return 0;
}
