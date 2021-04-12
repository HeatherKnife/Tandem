    #include <stdio.h>

    void print_array(int a[]);

    int main(void)
    {
        int first[11] = {7,7,7,7,7,7,7,7,7,7,7};

        int second[14] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2};

        int third[16] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

        int fourth[23] = {-3, 4, 33, 22, 9, -100, 2, 56, 57, 55, 2, 90, 2234, 32, 8, 123, 2, 33, 22, 22, 33, -1, -3}; 


        int array_length = sizeof(second);
        print_array(second, array_length);



        return(0);
    }

    void print_array(int *a, int array_length)
    {
        //size_t size = sizeof(a);

        //printf("%zu\n", size);

        int i;
        for(i=0;i<=array_length;i++)
        {
            printf("%d ", *a);
            a++;
        }
    }