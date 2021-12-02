#include <iostream>
#include<ctime>
using namespace std;

int BinarySearch(int data, int array_size, int* array) // Searches in an already SORTED ASCENDING array by repeatedly dividing the search interval in half. 
{                                                       // If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half,
    int index = 0;                                      // otherwise, narrow it to the upper half.
    int right_corner = array_size - 1;
    int left_corner = 0;
    while(left_corner<= right_corner)
    {
        index = (left_corner + right_corner) / 2;
        if (data < array[index])
        {
            right_corner = index - 1;
        }
        else
        {
            if (data > array[index])
            {
                left_corner = index + 1;
            }
            else
            {
                return index;
            }
        }
    }
    throw invalid_argument("Not found element with this data\n");
}

void QuickSort(int* array, int left_corner_of_array, int right_corner_of_array)  // Sorts by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays,
{                                                                                 // according to whether they are less than or greater than the pivot.
    int left = left_corner_of_array;
    int right = right_corner_of_array;
    int middle_element = array[(left + right) / 2];// All elements with values less than the pivot come before the division, while all elements with values greater than the pivot come after it.


    while (left <= right)
    {
        while (array[left] < middle_element)
            left++;
        while (array[right] > middle_element)
            right--;
        if (left <= right)
        {
            swap(array[left], array[right]);
            left++;
            right--;
        }
    }
    if (right > left_corner_of_array)
        QuickSort(array, left_corner_of_array, right);
    if (left < right_corner_of_array)
        QuickSort(array, left, right_corner_of_array);
}

void InsertionSort(int array_size, int* array) // Sorts by looking through the elements one by one and placing them in the right place among the previously ordered ones.
{
    int key; // the element whose place is being searched for
    for (int i1 = 1; i1 < array_size; i1++)
    {
        key = array[i1];
        for (int i2 = i1 - 1; (i2 >= 0) && (array[i2] > key); i2--)
        {
            array[i2 + 1] = array[i2];
            array[i2] = key;
        }
    }
}

bool Array_is_sorted(int array_size, int* array)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void random_help_us(int array_size, int* array)
{
    for (int i = 0; i < array_size; i++)
        swap(array[i], array[rand() % array_size]);
}

void BogoSort(int array_size, int *array) // Sorts the array by randomly rearranging the elements
{
    while (!Array_is_sorted(array_size, array))
        random_help_us(array_size, array);
}

void CountingSort(int array_size, char* array) // Creates an additional array in which it counts how many times which element has been encountered.
{                                               // The indexes of the new array are equivalent to the elements encountered.
    int max_enc=0; //max encountered value in ASCII table
    //int tmp;
    for (int i = 0; i < array_size; i++)
    {
        if (array[i] > max_enc)
        {
            max_enc = array[i];
        }
    }
    max_enc++;
    int* array_for_counting = new int[max_enc];
    for (int i = 0; i < max_enc; i++)
    {
        array_for_counting[i] = 0;
    }
    for (int i = 0; i < array_size; i++)
    {
        array_for_counting[array[i]]++;
    }
    int counter_for_orig_array = 0;
    for (int i = 0; i < max_enc; i++)
    {
        while (array_for_counting[i] != 0)
        {
            array[counter_for_orig_array] = i;
            array_for_counting[i]--;
            counter_for_orig_array++;
        }
    }
    delete[]array_for_counting;
}

void time_check_QuickSort(int array_size, int* array)
{
    clock_t begin = clock(); clock_t end = clock();
    double elapsed_secs = ((double)end - (double)begin) / CLOCKS_PER_SEC;
    for (int counter = 0; counter < 10; counter++)
    {
        for (int array_counter = 0; array_counter < array_size; array_counter++)
        {
            array[array_counter] = rand() % 100;
        }
        begin = clock();
        QuickSort(array,0,array_size-1);
        //QuickSort(0, array_size - 1, array);
        end = clock();
        elapsed_secs += ((double)end - (double)begin) / CLOCKS_PER_SEC;
        
    }
    elapsed_secs = elapsed_secs / 10;
    cout << "Sorting took =" << elapsed_secs << "second(s)" << endl;
}

void time_check_InsertionSort(int array_size, int* array)
{
    
    clock_t begin = clock(); clock_t end = clock();
    double elapsed_secs = ((double)end - (double)begin) / CLOCKS_PER_SEC;
    for (int counter = 0; counter < 10; counter++)
    {
        for (int array_counter = 0; array_counter < array_size; array_counter++)
        {
            array[array_counter] = rand() % 100;
        }
        begin = clock();
        InsertionSort(array_size, array);
        end = clock();
        elapsed_secs += ((double)end - (double)begin) / CLOCKS_PER_SEC;
    }
    elapsed_secs = elapsed_secs / 10;
    cout << "Sorting took =" << elapsed_secs << "second(s)" << endl;
}

int main()
{
    //int a[100000];
    int array10[10];
    int array100[100];
    int array1000[1000];
    int array10000[10000];
    int array100000[100000];

    cout << "\nTime for 10 elements:\n\n";
    cout << "QuickSortn:\n";
    time_check_QuickSort(10, array10);
    cout << "\n\n";
    cout << "InsertionSort\n";
    time_check_InsertionSort(10, array10);

    cout << "\n\n\nTime for 100 elements:\n\n";
    cout << "QuickSortn:\n";
    time_check_QuickSort(100, array100);
    cout << "\n\n";
    cout << "InsertionSort\n";
    time_check_InsertionSort(100, array100);

    cout << "\n\n\nTime for 1000 elements:\n\n";
    cout << "QuickSortn:\n";
    time_check_QuickSort(1000, array1000);
    cout << "\n\n";
    cout << "InsertionSort\n";
    time_check_InsertionSort(1000, array1000);

    cout << "\n\n\nTime for 10000 elements:\n\n";
    cout << "QuickSortn:\n";
    time_check_QuickSort(10000, array10000);
    cout << "\n\n";
    cout << "InsertionSort\n";
    time_check_InsertionSort(10000, array10000);

    cout << "\n\n\nTime for 100000 elements:\n\n";
    cout << "QuickSortn:\n";
    time_check_QuickSort(100000, array100000);
    cout << "\n\n";
    cout << "InsertionSort\n";
    time_check_InsertionSort(100000, array100000);
}