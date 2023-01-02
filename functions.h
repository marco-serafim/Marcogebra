#include <stdio.h>
#include <math.h>

double modulum(double number){  // basic modulum function
  if(number < 0){
    number *= -1;
  }
  return number;
}

double function_make(double x){
  result = x * 2;           // here is where the function law will be decrared
  return result;
}
