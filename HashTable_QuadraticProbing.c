

#include <stdio.h>
int num = 0;
float loadfactor = 0;

int insert(int arr[], int val)
{
    int loc = val % num, i;
    int count = 0;
    if (arr[loc] == 0)
    {
        arr[loc] = val;
        printf("\nHashvalue of %d is %d", val, loc);
        return 0;
    }
    printf("\nHashvalue of %d is %d", val, loc);

    printf("\nCollision:");
    for (i = 1; i <= 20; i++)
    {

        int new;
        new = (loc + (i * i)) % num;
        printf("\nProbing %d, hashvalue: %d", i, new);
        if (arr[new] == 0)
        {
            arr[new] = val;
            printf("\nHashvalue of %d is %d", val, new);

            return 0;
        }
    }
    if (i >= 20)
    {
        loadfactor = loadfactor - 1;
        printf("\nElement Can't be placed");
    }
}

int search(int arr[], int val)
{
    int loc = val % num;
    int count = 0, found = 0,i;

    if (arr[loc] == val)
    {

        printf("\nValue found at index: %d", loc);
        found = 1;
        return 0;
    }
    else
    {
        for (i = 1; i <= 20; i++)
        {

            int new;
            new = (loc + (i * i)) % num;
            printf("\nProbing %d, hashvalue: %d", i, new);
            if (arr[new] == val)
            {
                printf("\nValue found at index: %d", loc);
                found = 1;

                return 0;
            }
        }
    }
    if (found == 0)
    {
        printf("\nValue not in hash table");
        return 0;
    }
}

void print(int arr[])
{
    printf("\nHash Table: ");

    for (int i = 0; i < num; i++)
    {
        printf("\n %d  - %d ", i, arr[i]);
    }
    printf("\n");
}

int main()
{
    int val, opt = 1;

    printf("\n Hashing with Quadratic probing -------- ");
    printf("\nEnter Size of hash table: ");
    scanf("%d", &num);
    int arr[num];

    for (int i = 0; i < num; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter Element: ");
        scanf("%d", &val);
        insert(arr, val);

        printf("\n\nDo you want to continue:(0,1)");
        scanf("%d", &opt);
        loadfactor++;
        if (opt != 1)
        {
            break;
        }
    }
    if (loadfactor == num)
    {
        printf("\nTable is full ");
    }

    opt = 1;

    while (opt)
    {
        printf("\nEnter Element to search : ");
        scanf("%d", &val);
        search(arr, val);

        printf("\n\nDo you want to continue:(0,1)");
        scanf("%d", &opt);
    }

    print(arr);

    loadfactor = loadfactor / num;
    printf("\nLoad Factor: %f", loadfactor);
    return 0;
}
