// Copyright 2021 alexgiving

#include "train.h"
#include <iostream>
#include <cstdlib>

/*
░█████╗░░█████╗░░██████╗░███████╗
██╔══██╗██╔══██╗██╔════╝░██╔════╝
██║░░╚═╝███████║██║░░██╗░█████╗░░
██║░░██╗██╔══██║██║░░╚██╗██╔══╝░░
╚█████╔╝██║░░██║╚██████╔╝███████╗
░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝
 */

Cage ::Cage() {
  light = std::rand() % 2;
  next = nullptr;
  prev = nullptr;
}

Cage* Cage::getPrev() const {
  return prev;
}

Cage* Cage:: getNext() const {
  return next;
}

bool Cage::getLight() const {
  return light;
}

void Cage::setPrev(Cage* _prev) {
  this->prev = _prev;
}

void Cage::setNext(Cage* _next) {
  this->next = _next;
}

void Cage::setLight(bool _light) {
  light = _light;
}

void Cage::changeLight() {
  light = !light;
}

void Cage::on() {
  this->light = true;
}

void Cage::off() {
  this->light = false;
}

/*
████████╗██████╗░░█████╗░██╗███╗░░██╗
╚══██╔══╝██╔══██╗██╔══██╗██║████╗░██║
░░░██║░░░██████╔╝███████║██║██╔██╗██║
░░░██║░░░██╔══██╗██╔══██║██║██║╚████║
░░░██║░░░██║░░██║██║░░██║██║██║░╚███║
░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚══╝
 */

Train ::Train() {
  first = nullptr;
  last = nullptr;
}

void Train::setFirst(Cage* _first) {
  first = _first;
}

void Train::setLast(Cage* _last) {
  last = _last;
}

Cage* Train::getFirst() const {
  return first;
}

Cage* Train::getLast() const {
  return last;
}

void Train::addCage(Cage* temp) {
  if (first == nullptr) {
    first = temp;
    last = temp;
    temp->setNext(temp);
    temp->setPrev(temp);
    return;
  }
  last->setNext(temp);
  first->setPrev(temp);
  temp->setPrev(last);
  temp->setNext(first);
  last = temp;
}

void Train::printTrain() {
  if (first != nullptr) {
    size_t counter = 0;
    Cage* _tempCage = first;
    std::cout << "Cage List:\n";
    while (_tempCage != last) {
      ++counter;
      std::cout << "Cage №" << counter << "\tLight is "
      << (_tempCage->getLight() ? "ON\n" : "OFF\n");
      _tempCage = _tempCage->getNext();
    }
    ++counter;
    std::cout << "Cage №" << counter << "\tLight is "
    << (_tempCage->getLight() ? "ON\n" : "OFF\n");
    }
}

size_t Train::checkLength() {
  if (first != nullptr) {
    size_t counter = 0;
    Cage* _tempCage = first;
    while (_tempCage != last) {
      _tempCage = _tempCage->getNext();
      ++counter;
    }
    return ++counter;
  }
  return 0;
}

size_t Train::getLength() {
  if (first != nullptr) {
    size_t length;
    size_t counter = 1;
    Cage* ptr = first;
    const bool startState = first->getLight();
    while (true) {
      ptr = ptr->getNext();
      if (ptr->getLight() != startState) {
        ++counter;
        continue;
      } else {
        length = counter;
        ptr->changeLight();
        for (size_t i = 0; i < counter; ++i)
          ptr = ptr->getPrev();
        counter = 1;
        if (ptr->getLight() != startState)
          return length;
      }
    }
  }
  return 0;
}



