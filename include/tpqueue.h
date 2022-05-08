// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T a[100];
    int firstt, smt;
 public:
    TPQueue() : firstt(0), smt(0) {}
    void push(T value) {
        int i = smt++;
        while ((--i >= firstt) && (a[i % size].prior < value.prior)) {
            a[(i + 1) % size] = a[i % size];
        }
        a[(i + 1) % size] = value;
    }
    T pop() {
        return a[(firstt++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
