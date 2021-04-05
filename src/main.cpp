// Copyright 2021 alexgiving

#include <iostream>
#include "train.h"

int main() {

  Train train;

  for (size_t i = 0; i < 1; ++i) {
    Cage* cage = new Cage();
    train.addCage(cage);
  }
  train.printTrain();
  std::cout << train.checkLength() << std::endl;
  std::cout << train.getLength();
  return 0;
}
