// rk4.h
#ifndef RK4_H
#define RK4_H

#include "DataStructs.h"

template<typename T>
class RungeKutta4 {
public:
    RungeKutta4(DataStruct<T> &Un);    // constructor
    ~RungeKutta4();                    // destructor

    void initRK();                     // reinicia currentStep y f_accum
    void stepUi(T dt);                 // calcula Ui para la etapa currentStep

    // stubs por implementar:
    void setFi(DataStruct<T> &F);      // copia RHS y acumula
    void finalizeRK(const T dt);       // aplica el acumulado y actualiza Un

    DataStruct<T>* currentU();         // puntero a Ui
    int getNumSteps();                 // devuelve 4

private:
    DataStruct<T> &Un;                 // estado actual Uₙ
    DataStruct<T>  Ui;                 // U intermedio en cada etapa

    // — buffers optimizados —
    DataStruct<T>  fi_cur;             // buffer para fₖ
    DataStruct<T>  f_accum;            // f₁ + 2·f₂ + 2·f₃ + f₄

    int    nSteps;                     // siempre 4
    int    currentStep;                // índice de etapa [0..3]

    T*     coeffsA;                    // coeficientes aₖ
    T*     coeffsB;                    // coeficientes bₖ
};

#endif // RK4_H


