#include <iostream>
#include <time.h>

using namespace std;

void Quicksort (int [], int, int);
void Quicksort_midpoint(int [], int , int );
void Quicksort_medianOfThree(int , int , int );
void InsertionSort(int , int );
int Partition(int arr[], int, int); //helper function for quicksort

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

int main(){
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1,arr2,arr3);
    Quicksort(arr1, 0, NUMBERS_SIZE-1);
    //call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << elapsedTime << endl;
    return 0;
}


int Partition(int numbers[], int i, int k){
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
       bool done = false;

    // midpoint = i + (k-i)/2;
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
    j = Partition(numbers, i, k);
    Quicksort(numbers, i, j);
    Quicksort(numbers, j+1, k);
}

void Quicksort_midpoint(int numbers[], int i, int k){
    if (i>=k) //cannot sort if it is i is == or above k
        return;
   Quicksort(numbers, i ,k);
}



void Quicksort_medianOfThree(int numbers[], int i, int k){

}

void InsertionSort(int numbers[], int numbersSize){

}