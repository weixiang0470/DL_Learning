#define TEST(x) x*=2; x+=1 
#include <iostream>

using namespace std;

int main(void){

    // int a[3] = {1,2,3};
    // int *p = a;

    // *(p++) += 123;
    // *(++p) += 123;
    // for(int x : a){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    for(int i=0,j=1; i<5 ;i++){
        TEST(j);
        cout<<j<<endl;
    }
    
    return 0;
}