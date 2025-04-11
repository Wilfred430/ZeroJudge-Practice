#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>v , int n, int remain){
    if (n == 0){
        return v[0] == remain;
    }
    else{
        return check(v, n-1 , remain - v[n]) ||  check(v , n-1 , remain + v[n]);
    }
}

int main(){
    int M , N;
    while (cin >>M >>N)
    {
        for (int i=0 ; i< M ; i++){
            vector<int> v(N);
            for (int j=0; j<N ; j++){
                cin >>v[j];
            }
            cout << (check(v,N-1 , 0) ? "Yes" : "No" )<<endl;
        }
        
    }
    
    return 0;
}