#include <iostream>

using namespace std;

const int N = (int)1e5 + 5;

int n, sum = 0; 
int a[N]; 


void heapify_up(int v) {
	while (v != 1 && a[v/2] < a[v]) {
		swap(a[v/2], a[v]);
		v = v / 2;
	}
}

void push(int x) {
	n++;
	a[n] = x;
	heapify_up(n);
}

int top() {
	if (n == 0) {
		cout << "[Error] Heap is empty\n";
		exit(0);
	}
	return a[1];
}


void heapify_down(int v) {
	// find max among v, 2v, 2v+1
	int p = v;
	int l = 2*v;
	int r = 2*v+1;
	if (l <= n && a[l] > a[p]) p = l;
	if (r <= n && a[r] > a[p]) p = r;
	if (p == v) // if v is greater than l&r
		return;
	// p = l or r (left or right son)
	swap(a[p], a[v]);
	heapify_down(p);
}

void pop() {
	swap(a[1],a[n]);
	n--;
	heapify_down(1);
}

void print(){
	while (n > 1){
		int x = a[1];
		pop();
		int y = a[1];
		pop();
		if (x != y){
			y = abs(y - x);
			push(y);
		}else if (x == y){
			continue;
		}
	}
}

int main() {
	int m;
	cin >> m;
	for (int i = 0;i < m;i++){
		int x;cin >> x;
		push(x);
	}
	print();
    if (n > 0){
        cout << a[1];
    }
    else{
        cout << 0;
    }


	return 0;
}
//899