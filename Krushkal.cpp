#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u;
    int v;
    int w;
}arr[10];

bool cmp(struct edge a, struct edge b){
    int r1 = a.w;
    int r2 = b.w;
    return r1 < r2;
}

int main(){
    
    for(int i=0; i<10; i++){
        cin >> arr[i].u;
        cin >> arr[i].v;
        cin >> arr[i].w;
    }
    sort(arr, arr + 10, cmp);
    int x[] = {1,2,3,4,5};
    int cnt = 0, a, b, i = 0, sum = 0;
    while(cnt < 4){
        if(x[arr[i].u] != x[arr[i].v]){
            a = min(x[arr[i].u], x[arr[i].v]);
            b = max(x[arr[i].u], x[arr[i].v]);
            for(int j = 0; j < 5; j++){
                if(x[j] == a)
                    x[j] = b;
            }
            cnt++;
            sum += arr[i].w;
            cout << arr[i].u << " " << arr[i].v << " " << arr[i].w << endl;
        }
    }
    cout << sum << endl;
    return 0;
}