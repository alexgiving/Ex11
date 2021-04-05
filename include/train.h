// Copyright 2021 alexgiving

#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <iostream>

class Cage {
 private:
  bool light;
  Cage* next;
  Cage* prev;
 public:
  Cage();
  void on();
  void off();
  void changeLight();
  void setLight(bool);
  void setPrev(Cage*);
  void setNext(Cage*);
  [[nodiscard]] bool getLight() const;
  [[nodiscard]] Cage* getPrev() const;
  [[nodiscard]] Cage* getNext() const;
};

class Train {
 private:
  Cage* first;
  Cage* last;
 public:
  Train();
  void addCage(Cage*);
  void setFirst(Cage*);
  void setLast(Cage*);
  [[nodiscard]] Cage* getFirst() const;
  [[nodiscard]] Cage* getLast() const;
  size_t checkLength();
  size_t getLength();
  void printTrain();
};

#endif  // INCLUDE_TRAIN_H_
