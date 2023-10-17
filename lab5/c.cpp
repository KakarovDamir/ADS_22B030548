#include <iostream>
#include <cmath>

using namespace std;

const int N = (int)1e5 + 5;

long long n;
long long a[N];

void heapify_up(long x){
    while(x != 1 && a[x/2] < a[x]){
        swap(a[x / 2],a[x]);
        x = x / 2;
    }
}

void push(long long x){
    n++;
    a[n] = x;
    heapify_up(n);
}

void heapify_down(int x){
    long long p = x;
    long long l = 2*x;
    long long r = 2*x + 1;
    if (l <= n && a[l] > a[p]) p = l;
    if (r <= n && a[r] > a[p]) p = r;
    if (p == x){
        return;
    }

    swap(a[p], a[x]);
    heapify_down(p);
}

void pop(){
    swap(a[1], a[n]);
    n--;
    heapify_down(1);
}

void print( long long m){
    long long sum = 0;
    while(m--){
        sum += a[1];
        long long max = a[1] - 1;
        pop();
        push(max); 
    }

    cout << sum;
}

int main (){
    long long d, m;
    cin >> d >> m;
    for (int i = 0;i < d;i++){
        long long x; cin >> x;
        push(x);
    }

    print(m);


    return 0;
}
//978