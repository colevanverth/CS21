#include <iostream>
#include <vector>

void merge(std::vector<int> & A, int lo, int mid, int hi);
void merge(std::vector<int> & A, int lo, int mid, int hi) {
   std::vector<int> lows;
   std::vector<int> highs; 
   for (int i = lo; i <= mid; i++) {
      lows.push_back(A[i]);
   }
   for (int i = mid + 1; i <= hi; i++) {
      highs.push_back(A[i]); 
   }
   int loIndex = 0; 
   int hiIndex = 0;
   for (int i = lo; i <= hi; ++i) {
      if (loIndex >= lows.size()) {
         A[i] = highs[hiIndex];
         hiIndex++;
      }
      else if (hiIndex >= highs.size()) {
         A[i] = lows[loIndex];
         loIndex++;
      }
      else if  (lows[loIndex] < highs[hiIndex]) {
         A[i] = lows[loIndex];
         loIndex++;
      }
      else {
         A[i] = highs[hiIndex];
         hiIndex++;
      }
   }
}
void mergeSort(std::vector<int> & A, int lo, int hi);
void mergeSort(std::vector<int> & A, int lo, int hi) {
   if (lo < hi) {
      int mid = lo + (hi - lo) / 2; 
      mergeSort(A, lo, mid);
      mergeSort(A, mid + 1, hi);
      merge(A, lo, mid, hi);
   }
}

int main() {
    std::vector<int> data; 
    int intBuffer;
    while (std::cin >> intBuffer) {
       data.push_back(intBuffer);
    }
    mergeSort(data, 0, data.size() - 1);
    for (auto number : data) {
       std::cout << number << std::endl; 
    }
}
