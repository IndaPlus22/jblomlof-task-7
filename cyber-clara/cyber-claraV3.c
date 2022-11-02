
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE = 21;

int isTheSameName(const char *pOne, const char *pTwo)
{
    int s;
    for (s = 0; *(pOne + s) != '.'; s++)
    {
        if (*(pOne + s) != *(pTwo + s))
        {
            return 0; // returning false
        }
    }
    if (*(pTwo + s) != '.') 
    {
        return 0;
    }
    return 1; // the names are the same returning 1 as "True"
}

int main()
{
    long long number_of_names;
    char temp_name_store[SIZE + 1];
    char *pFirstname_list;
    char *pSurname_list;
    long long sum = 0;
    int i, j, s;

    scanf("%lld", &number_of_names);
    pFirstname_list = (char *)malloc(sizeof(char) * number_of_names * SIZE);
    pSurname_list = (char *)malloc(sizeof(char) * number_of_names * SIZE);

    for (i = 0; i < number_of_names; i++) // just copying the first names.
    {
        scanf("%s", temp_name_store);
        /* for (s = 0; temp_name_store[s]; s++)
         {
             temp_name_store[s] = tolower(temp_name_store[s]);
         }*/
        for (s = 0; temp_name_store[s]; s++) // i could maybe have scan in this loop, but i like scanf("%s") handles whitespace for me.
        {
            *(pFirstname_list + (SIZE * i) + s) = temp_name_store[s];
        }
        for (s = s; s < SIZE; s++)
        {
            *(pFirstname_list + (SIZE * i) + s) = '.';
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
            *(pSurname_list + (SIZE * i) + s) = temp_name_store[s];
        }
        for (s = s; s < SIZE; s++)
        {
            *(pSurname_list + (SIZE * i) + s) = '.';
        }
    }

    // look for clashes
    for (i = 0; i < number_of_names; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (isTheSameName(pFirstname_list + (i * SIZE), pFirstname_list + (j * SIZE)))
            {
                if (isTheSameName(pSurname_list + (i * SIZE), pSurname_list + (j * SIZE)))
                {
                    // its a copy
                    sum--;
                    break;
                }
            }
        }
        sum++;
    }

    printf("%lld", sum);
    free(pFirstname_list);
    free(pSurname_list);
    return 0;
}
