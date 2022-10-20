
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE = 21;
int main()
{
    long long number_of_names;
    scanf("%lld", &number_of_names);
    char name_list[number_of_names][SIZE];
    char temp_name_store[SIZE * 2];
    char real_name_list[number_of_names][SIZE * 2];
    long long sum = 0;
    int i, j, s;
    int boolflag;
    for (i = 0; i < number_of_names; i++) // just copying the first names.
    {
        scanf("%s", &temp_name_store);
       /* for (s = 0; temp_name_store[s]; s++) 
        {
            temp_name_store[s] = tolower(temp_name_store[s]);
        }*/
        strcpy(name_list[i], temp_name_store);
    }
    for (i = 0; i < number_of_names; i++) // surname time
    {
        scanf("%s", &temp_name_store);
        /*for (s = 0; temp_name_store[s]; s++) 
        {
            temp_name_store[s] = tolower(temp_name_store[s]);
        }*/
        strcat(temp_name_store, "_");
        strcat(temp_name_store, name_list[i]); // adding first name to surname. Will have format surname_firstname
        boolflag = 1;
        for (j = 0; j < sum; j++) // checking the names we already did.
        {
            if (!strcmp(temp_name_store, real_name_list[j]))
            {
                boolflag = 0;
                break;
            }
        }
        if (boolflag)
        {
            strcpy(real_name_list[sum++], temp_name_store);
            real_name_list[sum][0] = '\0';
        }
    }
    printf("%lld", sum);
    return 0;
}
