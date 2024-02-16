#include <iostream>
#include <ProdCons.h>

void ProdCons::put(rect element)
{
  buffer.push(element);
}

rect ProdCons::get()
{
  rect element = buffer.front();
  buffer.pop();
  return element;
}