#include<iostream>
using namespace std;
void hanoi(char from, char to, char another, int amount, int num){
    if(amount==1){  
        cout<<"Move ring "<<num<<" from "<<from<<" to "<<to<<"\n";
        return;
    }
    hanoi(from, another, to, amount-1, 1);
    hanoi(from, to, another, 1, amount);
    hanoi(another, to, from, amount-1, 1);
}
int main(){
    int n;
    while(cin>>n){ 
        hanoi('A','C','B',n,1);  
    }
    return 0;
}