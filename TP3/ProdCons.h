/*
  Class Producteur et Consommateur
*/

#ifndef PROD_CONS
#define PROD_CONS

#include <queue>

struct rect
{
  int slice_number;
  int y_start;
  rect(int slice_number, int y_start) : slice_number(slice_number), y_start(y_start) {}
};

class ProdCons
{

public:
  int number_of_slices;
  int number_of_threads;
  std::queue<rect> buffer;
  ProdCons(int number_of_slices, int number_of_threads) : number_of_slices(number_of_slices),
                                                          number_of_threads(number_of_threads){};

  void put(rect element) {}

  rect get(){};
};

#endif