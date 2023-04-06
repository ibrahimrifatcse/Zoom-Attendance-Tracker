#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDS 1000

int main()
{
    FILE *all_ids_file, *garbage_ids_file;
    char all_ids[MAX_IDS][11], garbage_ids[MAX_IDS][11], id[11], *ptr;
    int i, j, all_ids_count = 0, garbage_ids_count = 0, missing_ids_count = 0;
    int missing_ids[MAX_IDS];
    
    // Open files for reading
    all_ids_file = fopen("EcoAll.txt", "r");
    garbage_ids_file = fopen("Echogarbage.txt", "r");
    
    // Check if files opened successfully
    if (all_ids_file == NULL)
    {
        printf("Error: Unable to open EcoAll.txt file.\n");
        return 1;
    }
    if (garbage_ids_file == NULL)
    {
        printf("Error: Unable to open Echogarbage.txt file.\n");
        return 1;
    }
    
    // Read all IDs from all_ids.txt into an array
    while (fgets(id, 11, all_ids_file) != NULL)
    {
        ptr = strchr(id, '\n');
        if (ptr != NULL)
        {
            *ptr = '\0';
        }
        strncpy(all_ids[all_ids_count], id, 10);
        all_ids_count++;
    }
    fclose(all_ids_file);
    
    // Read all IDs from garbage_ids.txt into an array
    while (fscanf(garbage_ids_file, "%10s", id) != EOF)
    {
        // Check if the ID is 9 digits long
        if (strlen(id) == 9)
        {
            for (j = 0; j < 9; j++)
            {
                if (!isdigit(id[j]))
                {
                    break;
                }
            }
            if (j == 9)
            {
                strncpy(garbage_ids[garbage_ids_count], id, 10);
                garbage_ids_count++;
            }
        }
    }
    fclose(garbage_ids_file);
    
    // Find the missing IDs
    for (i = 0; i < all_ids_count; i++)
    {
        for (j = 0; j < garbage_ids_count; j++)
        {
            if (strcmp(all_ids[i], garbage_ids[j]) == 0)
            {
                break;
            }
        }
        if (j == garbage_ids_count)
        {
            missing_ids[missing_ids_count] = i;
            missing_ids_count++;
        }
    }
    
    // Print the missing IDs
    printf("Absent students:\n");
    for (i = 0; i < missing_ids_count; i++)
    {
        printf("%d %s\n", i+1, all_ids[missing_ids[i]]);
    }

    return 0;
}
