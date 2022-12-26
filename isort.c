#include <stdio.h>

#define SIZE 50

void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);
void enterNumbers(int * arr , int size);
void printNumbers(int * arr , int size);


int main()
{
    // we define the array , then simply enter input from the user into the array
    // we then implement on the array insertion sort , then finally print to check for success
    int arr[SIZE] = {0}; 
    enterNumbers(arr , SIZE);
    insertion_sort(arr , SIZE);
    printNumbers(arr , SIZE);

    return 1;
}


// side-function shifts from arr pointer , i amount of indexes to the right
void shift_element(int* arr, int i)
{
    for (int j = i; j > 0; j--)
    {
        *(arr + j) = *(arr + (j - 1));
    }
}

// implementation of insertion sort using the shift method
void insertion_sort(int* arr , int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int key = 0;
        if( *(arr + i) > *(arr + i + 1))
        {
            key = *(arr + i + 1);
            for (int j = 0; j <= i; j++)
            {
                if(key < *(arr + j))
                {
                    shift_element(arr + j, i - j + 1);
                    *(arr + j) = key;
                    break;
                }
            }   
        }
    }
    
}

// we simply print the numbers to check for success
void enterNumbers(int * arr , int len)
{
    for (int i = 0; i < len; i++)
    {
        int c = 0;
        scanf(" %d"  , &c);
        *(arr + i) = c;
    }  
}

void printNumbers(int * arr , int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d,", *(arr + i));
    }
    
}