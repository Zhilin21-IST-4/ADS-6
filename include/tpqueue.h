// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T a[100];
    int f, l;
 public:
    TPQueue() : f(0), l(0) {}
    void push(T value) {
        int i = l++;
        while ((--i >= f) && (a[i % size].prior < value.prior)) {
            a[(i + 1) % size] = a[i % size];
        }
        a[(i + 1) % size] = value;
    }
    T pop() {
        return a[(f++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
