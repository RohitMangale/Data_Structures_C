
#include <stdio.h>
#include <stdlib.h>

int count = 0;

int insert(int arr[], int num, int val)
{
    count++;
    int loc;
    loc = val % num;
    if (arr[loc] == 0)
    {
        arr[loc] = val;
        return 0;
    }
    else
    {
        int i = 1;
        int h;
        int g = 5 - (val % 5);
        printf("\nloc = %d , g = %d",loc,g);
        while (count <= num)
        {
            h = (loc + i*g) % num;
            printf("\nh = %d",h);
            if (arr[h] == 0)
            {
                arr[h] = val;
                return 0;
            }
            i++;
        }
    }
}

void print(int arr[], int num)
{
    printf("\nArray: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t", arr[i]);
    }
    exit(0);
}

int main()
{
    int num, opt, val, flag = 0;
    printf("Enter the size of table: ");
    scanf("%d", &num);

    int tab[num];
    for (int i = 0; i < num; i++)
    {
        tab[i] = 0;
    }

    printf("Enter elements: ");
    scanf("%d", &val);
    insert(tab, num, val);

    while (opt)
    {
        if (count >= num)
        {
            printf("Table is full");
            break;
        }
        printf("Enter elements: ");
        scanf("%d", &val);
        insert(tab, num, val);
        // if(flag = 1){
        //     break;
        // }

        printf("Do you want to continue(0,1): ");
        scanf("%d", &opt);
    }
    print(tab, num);

    // while(1){
    //     printf("\n press 1-insert \t2-search \t3-delete \t0-exit \n Enter your choice: ");
    //     scanf("%d",&opt);
    //     switch(opt){
    //         case 1:
    //         insert();
    //         break;
    //         case 2:
    //         search();
    //         break;
    //         case 3:
    //         delete();
    //         break;
    //         case 0:
    //         exit(0);
    //         break;
    //         default:
    //         printf("You entered a wong nummber \n");
    //         break;
    //     }
    // }

    return 0;
}
