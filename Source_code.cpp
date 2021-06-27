#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <time.h> 
using namespace std;

int digitcount(int n){ 
    return (log10(n) + 1);
}

int decimalToBinary(int n) 
{ 
    int b = 0; 
    int cnt = 0; 
    while (n != 0) { 
        int rem = n % 2; 
        int c = pow(10, cnt); 
        b += rem * c; 
        n /= 2; 
        cnt++; 
    } 
    return b; 
} 

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
    return dec_value;
}

// Positions starting from 1
int insert(int n, int pos, int b){
    string strn = to_string(n);
    string strb = to_string(b);
    strn[pos] = strb[0];
    n = stoi(strn);
    return n;
}

// Integer input
int set_bit_count(int n){ // Brian and Kerningham
    int count = 0;
    while(n != 0){
        count += (n&1);
        n = n/2;
    }
    return count;
}


int main()
{
    int x, b, p, f, r;
    cout<<"Enter Number to be sent : ";
    cin>>x;
    b = decimalToBinary(x);
    cout<<"\nBinary Coded message : "<<b;
    if(set_bit_count(x)%2 == 0){
        p = 0;
    }
    else{
        p = 1;
    }
    f = b*10 + p;
    cout<<"\nMessage to be sent(including parity) : "<<f;
    cout<<".\n.\n.\n.\n.\n.\n.\n";
    srand (time(0));
    int pos = rand()%digitcount(f);
    
    srand (time(NULL));
    int bit = rand()%2;
    r = insert(f, pos, bit);
    cout<<"Received Message : "<<r;
    if(set_bit_count(binaryToDecimal(r))%2 == 0){
        p = 0;
    }
    else{
        p = 1;
    }
    r = r*10 + p;
    cout<<"\nAfter Parity Encoding : "<<r<<endl;
    if(r%10 == 1){
        cout<<"As Parity Bit is 1, error detected.";
    }
    else{
        cout<<"Original Bits : "<<r/100<<endl;
        cout<<"Message : "<<binaryToDecimal(r/100);
    }
    return 0;
}
