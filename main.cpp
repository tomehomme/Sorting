#include <iostream>
#include <time.h>

using namespace std;

void Quicksort (int [], int, int);
void Quicksort_midpoint(int [], int , int );
void Quicksort_medianOfThree(int [], int , int );
void InsertionSort(int [], int);
int Partition_M(int arr[], int, int); //helper function for quicksort

const int NUMBERS_SIZE = 50000;
int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

void testQuicksort_Midpoint(int arr1[]){
    cout << "Testing Quicksort_Midpoint" << endl;
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    //call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << elapsedTime << endl;
    cout << endl;

}

void testQuicksort_medianOfThree(int arr2[]){
    cout << "Testing Quicksort_medianOfThree" << endl;
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    //call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << elapsedTime << endl;
    cout << endl;

}

void testInsertionSort(int arr3[]){
    cout << "Testing InsertionSort" << endl;
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE-1);
    //call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << elapsedTime << endl;
    cout << endl;

}

int main(){
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1,arr2,arr3);


    testQuicksort_Midpoint(arr1);
    testQuicksort_medianOfThree(arr2);
    testInsertionSort(arr3);
    

    return 0;
}


int Partition_M(int numbers[], int i, int k){
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    bool done = false;

    midpoint = (i+k)/2;
    pivot = numbers[midpoint];

    l=i;
    h=k;

    while(!done){
        while(numbers[l]<pivot){
            l++;
        }
        while (pivot < numbers[h]){
            h--;
        }
        if (l>=h){
            done = true;
        }
        else{
            swap(numbers[l],numbers[h]);
            l++;
            h--;
        }
    }
    return h;
}

void Quicksort(int numbers[],int i, int k){
    int j = 0;
    if (i>=k)
        return;
    j = Partition_M(numbers, i, k);
    Quicksort(numbers, i, j);
    Quicksort(numbers, j+1, k);
}

void Quicksort_midpoint(int numbers[], int i, int k){
    int j = 0;
    if (i>=k) //cannot sort if invalid indexes
        return;
    j = Partition_M(numbers, i, k);
    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j+1, k);
}

int Partition_Three(int numbers[], int i, int k){
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    bool done = false;

    int leftmost = numbers[i];
  
    midpoint = numbers[(i+k)/2]; 
    int rightmost  = numbers[k];
    int temp[] = {leftmost, midpoint, rightmost};

    for (int i =0; i < 3; i++){
        for (int j = i; j<3;j++){
            if (temp[i]<temp[j]){
                swap(temp[i],temp[j]);
            }
        }
    }
    if (leftmost == temp[1]){
        pivot = leftmost;
    }
    else if (midpoint == temp[1]){
        pivot = midpoint;
    }
    else{
        pivot = rightmost;
    }
    
    
    l=i;
    h=k;

    while(!done){
        while(numbers[l]<pivot){
            l++;
        }
        while (pivot < numbers[h]){
            h--;
        }
        if (l>=h){
            done = true;
        }
        else{
            swap(numbers[l],numbers[h]);
            l++;
            h--;
        }
    }
    return h;
}

void Quicksort_medianOfThree(int numbers[], int i, int k){
    int j = 0;
    if (i>=k) //cannot sort if invalid indexes
        return;
    j = Partition_Three(numbers, i, k);
    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j+1, k);
}

void InsertionSort(int numbers[], int numbersSize){
    int i = 0;
    int j = 0;
    for (i = 1; i < numbersSize; i++){
        j = i;
        while (j>0 && numbers[j] < numbers[j-1]){
            swap(numbers[j],numbers[j-1]);
            j--;
        }
    }
}