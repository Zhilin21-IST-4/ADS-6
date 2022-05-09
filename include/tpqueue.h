// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int firstt, smt;
 public:
    TPQueue() : firstt(0), smt(0) {}
    void push(T value) {
        int i = smt++;
        while ((--i >= firstt) && (arr[i % size].prior < value.prior)) {
            arr[(i + 1) % size] = arr[i % size];
        }
        arr[(i + 1) % size] = value;
    }
    T pop() {
        return arr[(firstt++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
