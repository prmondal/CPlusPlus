#include<iostream>
#include<cstdlib>

using namespace std;

struct Pair {
    long first;
    long second;
    long sum;
};

bool isCommon(Pair p1, Pair p2) {
    return (p1.first == p2.first) || (p1.first == p2.second) || (p1.second == p2.first) || (p1.second == p2.second);
}

int compare(const void* p1, const void* p2) {
    return ((Pair*)p1)->sum - ((Pair*)p2)->sum;
}

void printElements(long A[], int n, long x) {
    long s = n * (n - 1) / 2;
    
    Pair aux[s];
    
    int k = 0;
    
    //store pair sum in the auxillary array
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
           aux[k].first = A[i];
           aux[k].second = A[j];
           aux[k].sum = A[i] + A[j];
           
           k++;
        }
    }
    
    //sort aux array
    qsort(aux, s, sizeof(aux[0]), compare);
    
    int i = 0, j = s - 1;
    
    while(i < j) {
        long sum = aux[i].sum + aux[j].sum;
        
        if(sum < x) {
            i++;
        } else if(sum > x) {
            j--;
        } else {
            if(!isCommon(aux[i], aux[j])) {
                cout << aux[i].first << " " << aux[i].second << " " << aux[j].first << " " << aux[j].second << endl;
                
                //i++;
                //j--;
                return;
            }
        }
    }
}

int main() {
    long A[] = {10, 20, 30, 40, 1, 2};
    printElements(A, sizeof(A) / sizeof(A[0]), 91);
    return 0;
}