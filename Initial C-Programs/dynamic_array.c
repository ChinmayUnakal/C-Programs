#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int new_n;
    int choice;

    printf("Enter your choice:\n"
           "1 - Grow the array\n"
           "2 - Shrink the array\n");
    scanf("%d", &choice);

    printf("Enter the number of elements you want in the array:\n");
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));

    if (p == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("The %d elements you entered are:\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", p[i]);
    }

    if (choice == 1)
    {
        printf("Enter the number of elements you want to add:\n");
        scanf("%d", &new_n);

        int *new_p = realloc(p, (n + new_n) * sizeof(int));

        if (new_p == NULL)
        {
            printf("Allocation failed\n");
            free(p);
            return 1;
        }

        p = new_p;

        printf("Enter the new elements:\n");

        for (int i = n; i < n + new_n; i++)
        {
            scanf("%d", &p[i]);
        }

        n += new_n;

        printf("Modified array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d\n", p[i]);
        }
    }
    else if (choice == 2)
    {
        int ele_rem;

        printf("Enter the number of elements you want to remove:\n");
        scanf("%d", &ele_rem);

        for (int r = 0; r < ele_rem; r++)
        {
            int value;
            int found = 0;

            printf("Enter element to remove:\n");
            scanf("%d", &value);

            for (int i = 0; i < n; i++)
            {
                if (p[i] == value)
                {
                    found = 1;

                    for (int j = i; j < n - 1; j++)
                    {
                        p[j] = p[j + 1];
                    }

                    n--;
                    break;
                }
            }

            if (!found)
            {
                printf("Element %d not found\n", value);
            }
        }

        int *new_p = realloc(p, n * sizeof(int));

        if (new_p != NULL)
        {
            p = new_p;
        }
        else if (n != 0)
        {
            printf("Reallocation failed\n");
            free(p);
            return 1;
        }

        printf("Modified array:\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d\n", p[i]);
        }
    }
    else
    {
        printf("Invalid choice\n");
    }

    free(p);

    return 0;
}