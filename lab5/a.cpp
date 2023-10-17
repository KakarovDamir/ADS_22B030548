#include <iostream>
#include <vector>

using namespace std;
const int N = (int)1e5 + 5; 

long long n = 0;
long long v[N];
long long sum = 0, total = 0;

void heapify_up(int val){
    while(val != 1 && v[val / 2] > v[val]){
        swap(v[val / 2], v[val]);
        val = val / 2;
    }
}

void push(long long x){
    n++;
    v[n] = x;
    heapify_up(n);
}

void heapify_down(long long x){
    long long p = x;
    long long l = 2 * x;
    long long r = 2 * x + 1;

    if (l <= n && v[l] < v[p]) p = l;
    if (r <= n && v[r] < v[p]) p = r;
    if (p == x){
        return;
    }

    swap(v[p], v[x]);
    heapify_down(p);
}

void pop(){
    sum += v[1];
    swap(v[1], v[n]);
    n--;
    heapify_down(1);
}

void print(){
    if (n >= 2){
        pop();
        pop();
        push(sum);

        total += sum;
        sum = 0; 

        print();
    }
    else{
        cout << total;
    }
}


int main (){

    long long m;
    cin >> m;
    for (int i = 0;i < m;i++){
        int x;cin >> x;
        push(x);
    }
    
    print();
    return 0;
}

//751