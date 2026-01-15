// 1) Recurrence relation => 
//                      3T(n/2)+n*log(n)
//                      f(n) = nlog(n)+n+n+1
// 2) TC = O(n^log2(3))
//      we used masters theorm case 1 in which a>b^k
//      due to which TC= O(n^logb(a))



#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int flag = 0;
void complexRec(int n , int *cntop , int *depth) {

    if(flag == 0){
        (*depth)++;
    }
    
    if (n <= 2) {
        if(flag == 0){
            flag = 1;
        }
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
            (*cntop)++;
            temp[i] = i ^ p;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       (*cntop)++;
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2 , cntop , depth);
   complexRec(n / 2 , cntop , depth);
   complexRec(n / 2 , cntop , depth);
}

int main(){
    auto start = high_resolution_clock::now();
    int cntop =0;
    int depth = 0;
    int n;
    cin >> n;
    complexRec(n , &cntop , &depth);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Num of operations : " << cntop << endl << "Depth of recurssion tree : " << depth << endl << "Time : " << duration.count() << "ms" << endl;
    return 0;
}