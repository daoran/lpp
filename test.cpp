//
// Created by 4c3y on 19.08.22.
//




#include <iostream>

#define CAT( A, B ) A ## B
#define SELECT( NAME, NUM ) CAT( NAME ## _, NUM )

#define GET_COUNT( _1, _2, _3, _4, _5, _6, COUNT, ... ) COUNT
#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1 )
#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)
#define LOG(...) VA_SELECT( LOG, __VA_ARGS__ )
#define LOG_1(X) "foo< X >"
#define LOG_2(X, Y) "bar< " << X <<  ">( Y )"

int main() {
  int x = 1;
  std::cout << LOG(x) << std::endl;
}