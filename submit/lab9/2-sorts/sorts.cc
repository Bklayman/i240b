#include "sorts.hh"

static void
swap(int a[], int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void
insertionSort(int a[], int n)
{
  for (int i = 1; i < n; ++i) {
    //insert i'th record into sorted portion
    for (int j = i; (j > 0) && (a[j] < a[j - 1]); --j) {
      swap(a, j, j - 1);
    }
  }
}

void
bubbleSort(int a[], int n)
{
  for (int i = 0; i < n - 1; ++i) {
    for (int j = n - 1; j > i; --j) {
      if (a[j] < a[j - 1]) swap(a, j, j - 1);
    }
  }
}

void
selectionSort(int a[], int n)
{
  for (int i = 0; i < n - 1; ++i) {
    int minIndex = i;
    for (int j = n - 1; j > i; --j) {
      //find for min value in rest of array
      if (a[j] < a[minIndex]) minIndex = j;
    }
    swap(a, i, minIndex);
  }
}

//sort a[lo, hi) using temp[] as temporary storage
static void
msort(int a[], int temp[], int lo, int hi) {
  if (hi - lo < 2) return; //empty or single element
  int mid = (lo + hi)/2;   //select midpoint
  msort(a, temp, lo, mid); //mergesort lo half
  msort(a, temp, mid, hi); //mergesort hi half
  
  for (int i = lo; i < hi; ++i) {
    //copy subarray to temp
    temp[i] = a[i];
  }
  
  //merge temp[] subarrays back to a[]
  int i1 = lo;
  int i2 = mid;
  for (int dest = lo; dest < hi; ++dest) {
    if (i1 == mid) {
      //left sublist exhausted
      a[dest] = temp[i2++];
    }
    else if (i2 == hi) {
      //right sublist exhausted 
      a[dest] = temp[i1++];
    }
    else if (temp[i1] <= temp[i2]) {
      //smaller value in i1
      a[dest] = temp[i1++];
    }
    else {
      //get smaller value from i2
      a[dest] = temp[i2++];
    }
  }   
}

void
mergeSort(int a[], int n) 
{
  int* temp = new int[n];
  msort(a, temp, 0, n);
  delete temp;
}

static int
findPivot(int a[], int i, int j)
{
  return (i+j)/2;
}

/** partition a [lo, hi] into < pivot left sub-array and >= pivot
 *  right sub-array, returning index of first position in right
 *  sub-array 
 */
static int
partition(int a[], int lo, int hi, int pivot)
{
  while (lo <= hi) { //while interval is non-empty
    while (a[lo] < pivot) {
      //this loop will not run off the end of the array
      //because pivot is at a[hi]
      ++lo;
    }
    while ((hi >= lo) && (a[hi] >= pivot)) --hi;
    if (hi > lo) swap(a, lo, hi); //swap out-of-place values
  }
  return lo;            // Return first position in right partition
}

/** sort a [lo, hi] */
static void
qsort(int a[], int lo, int hi)
{
  if (hi - lo < 1) return;
  int pivotindex = findPivot(a, lo, hi);  // Pick a pivot
  swap(a, pivotindex, hi);           // Stick pivot at end
  // k will be the first position in the right subarray
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);                        // Put pivot in place
  qsort(a, lo, k - 1);  // Sort left partition
  qsort(a, k + 1, hi);  // Sort right partition
}

/** sort a [0, n) */
void
quickSort(int a[], int n)
{
  qsort(a, 0, n - 1);
}
