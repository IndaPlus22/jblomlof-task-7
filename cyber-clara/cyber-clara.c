
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 21;
int main()
{
    int number_of_names;
    scanf("%d", &number_of_names);
    char name_list[number_of_names][SIZE];
    char temp_name_store[SIZE * 2];
    char real_name_list[number_of_names][SIZE * 2];
    int sum = 0;
    int i, j;
    int boolflag;
    for (i = 0; i < number_of_names; i++) //just copying the first names.
    {   
        scanf("%s", &temp_name_store);
        strcpy(name_list[i], temp_name_store);
    }
    for (i = 0; i < number_of_names; i++) //surname time
    {
        scanf("%s", &temp_name_store);
        strcat(temp_name_store, "_");
        strcat(temp_name_store, name_list[i]); // adding first name to surname. Will have format surname_firstname
        boolflag = 1;
        for (j = 0; j < i ; j++) //checking the names we already did.
        {
            if (!(strcmp(temp_name_store, real_name_list[j])))
            {
                boolflag = 0;
                break;
            } 
            else if (real_name_list[j][0] == '\0') //blank name, thus all names after must also be blank right?
            {
                break;
            }
        }
        if (boolflag)
        {
            strcpy(real_name_list[i], temp_name_store);
            sum++;
        } 
        else 
        {
            real_name_list[i][0] = '\0';
        }
    }
    printf("%d", sum);
    return 0;
}
