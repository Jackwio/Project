#include <iostream>
#include "Identify.h"
using namespace std ;

int main(){

    string idCard ;
    bool Exist ;

    cin >> idCard ;
    Exist = testIdCardIfExist(idCard) ;

    if(Exist){
        cout << "Exist" ;
    }
    else{
        cout << "Not Exist" ;
    }
    return 0 ;

}