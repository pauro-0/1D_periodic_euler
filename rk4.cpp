// rk4.cpp
#include "rk4.h"
#include <cassert>

template<class T>
RungeKutta4<T>::RungeKutta4(DataStruct<T> &_Un)
  : Un(_Un)
{
    nSteps      = 4;
    currentStep = 0;

    // coeficientes RK4
    coeffsA = new T[4]{ 0., 0.5, 0.5, 1.0 };
    coeffsB = new T[4]{ 1., 2.0, 2.0, 1.0 };

    // dimensionamos los DataStruct
    Ui.setSize(Un.getSize());
    fi_cur.setSize(Un.getSize());
    f_accum.setSize(Un.getSize());
}

template<class T>
RungeKutta4<T>::~RungeKutta4()
{
    delete[] coeffsA;
    delete[] coeffsB;
}

template<class T>
int RungeKutta4<T>::getNumSteps()
{
    return nSteps;
}

template<class T>
void RungeKutta4<T>::initRK()
{
    currentStep = 0;
    // zero‐out de f_accum
    T* ptr = f_accum.getData();
    for(int i = 0; i < f_accum.getSize(); ++i)
        ptr[i] = 0.;
}

template<class T>
void RungeKutta4<T>::stepUi(T dt)
{
    assert(currentStep < nSteps);

    T* dataUi  = Ui.getData();
    const T* dataU = Un.getData();

    if (currentStep == 0) {
        for (int i = 0; i < Ui.getSize(); ++i)
            dataUi[i] = dataU[i];
    } else {
        const T* dataFi = fi_cur.getData();
        T a = coeffsA[currentStep];
        for (int i = 0; i < Ui.getSize(); ++i)
            dataUi[i] = dataU[i] + a * dt * dataFi[i];
    }
}

template<class T>
void RungeKutta4<T>::setFi(DataStruct<T> &F)
{
    // …pendiente de implementar…
}

template<class T>
void RungeKutta4<T>::finalizeRK(const T dt)
{
    // …pendiente de implementar…
}

template<class T>
DataStruct<T>* RungeKutta4<T>::currentU()
{
    return &Ui;
}

// instanciaciones
template class RungeKutta4<float>;
template class RungeKutta4<double>;
