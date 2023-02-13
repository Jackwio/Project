#include <string>
#include <iostream>
using namespace std ;

bool testIdCardIfExist(string idCard) ;

bool testIdCardIfExist(string idCard){
    
    int total = 0 ;

    if( idCard.size() != 10 ){
        return false ;
    }

    if( idCard[0] < 'A' || idCard[0] > 'Z' ){
        return false ;
    }

    if( idCard[1] != '1' && idCard[1] != '2' ){
        return false ;
    }

    for( int i = 2 ; i < idCard.size() ; i++ ){
        if( idCard[i] < '0' || idCard[i] > '9' ){
            return false ;
        } 
    }

    string calculate = "ABCDEFGHJKLMNPQRSTUVXYWZIO" ;
    size_t English = calculate.find(idCard[0]) + 10 ;
    idCard = to_string(English) + idCard.substr(1) ;
    
    total += idCard[0]-48 ;

    for( int i = 1 ; i < idCard.size() - 1 ; i++ ){
        total += ( idCard[i] - 48 ) * ( 10 - i ) ;
    }

    total += idCard[idCard.size() - 1]- 48 ;

    if( total % 10 != 0){
        return false ;
    }
    return true ;

}