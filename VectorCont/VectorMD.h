#pragma once
#ifndef _VECTORMD_H_
#define _VECTORMD_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <random>
#include <iterator>
#include "Exception.h"

using namespace std;

template <typename T> class VectorMD;
template <typename T> ostream& operator<< (ostream& out, const VectorMD<T>& _vector);
template <typename T> istream& operator>> (istream& in, VectorMD<T>& _vector);

template <typename T>
class VectorMD
{
private:
    vector<T> Vector;
    int size;
public:
    VectorMD<T>();
    VectorMD<T>(int);
    ~VectorMD<T>();
    void get_Vector();
    T const get_Size();
    void init_Vector();
    VectorMD<T>(const VectorMD&);
    VectorMD<T> operator=(const VectorMD&);
    VectorMD<T> operator+(const VectorMD&);
    VectorMD<T> operator-(const VectorMD&);

    friend VectorMD operator*(const VectorMD&, T);

    VectorMD<T> operator/(T);
    VectorMD<T> operator*(T);
    T operator*(const VectorMD&);
    VectorMD<T> cross(const VectorMD&);
    VectorMD<T> operator+=(const VectorMD&);
    VectorMD<T> operator-=(const VectorMD&);
    VectorMD<T> operator*=(T);
    VectorMD<T> operator/=(T);
    friend ostream& operator<< <T>(ostream& out, const VectorMD<T>& _vector);
    friend istream& operator>> <T>(istream& in, VectorMD<T>& _vector);
    T distance(const VectorMD&);
    T module();
    void print_Vector();
};

template <typename T>
VectorMD<T>::VectorMD()
{
    this->size = rand() % 10;
    if (this->size == 0)
        this->size += 2;
    if (this->size == 1)
        this->size += 1;
    //this->init_Vector();
}

template <typename T>
VectorMD<T>::VectorMD(int _size)
{
    this->size = _size;
    this->Vector.reserve(this->size);
    this->Vector.resize(this->size);
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        *it = 0;
    //for (int i = 0; i < this->size; i++)
        //this->Vector.at(i) = 0;
}

template <typename T>
VectorMD<T>::~VectorMD()
{}

template <typename T>
void VectorMD<T>::get_Vector()
{
    return this->Vector;
}

template <typename T>
T const VectorMD<T>::get_Size()
{
    return this->size;
}

template <typename T>
void VectorMD<T>::init_Vector()
{
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        *it = rand() % 10;
    //for (int i = 0; i < int(this->Vector.size(); i++)
        //this->Vector.at(i) = rand() % 10;
}

template <typename T>
VectorMD<T>::VectorMD(const VectorMD& _vector)
{
    this->size = int(_vector.Vector.size());
    this->Vector.resize(int(_vector.Vector.size()));
    auto _it = _vector.Vector.begin();
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
    {
        *it = *_it;
        ++_it;
    }
    //for (int i = 0; i < int(this->Vector.size()); i++)
        //this->Vector.at(i) = _vector.Vector[i];
}

template <typename T>
VectorMD<T> VectorMD<T>::operator= (const VectorMD& _vector)
{
    try
    {
        if (this->Vector.size() != _vector.Vector.size())
            throw BadVectorDimensionException();
        auto _it = _vector.Vector.begin();
        for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        {
            *it = *_it;
            ++_it;
        }
        //for (int i = 0; i < int(this->Vector.size()); i++)
            //this->Vector.at(i) = _vector.Vector[i];
        return *this;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
}

template <typename T>
VectorMD<T> VectorMD<T>::operator+ (const VectorMD& _vector)
{
    try
    {
        if (this->Vector.size() != _vector.Vector.size())
            throw BadVectorDimensionException();
        VectorMD<T>* temp = new VectorMD<T>(int(this->Vector.size()));
        auto it = this->Vector.begin();
        auto _it = _vector.Vector.begin();
        for (auto it_temp = temp->Vector.begin(), end = temp->Vector.end(); it_temp != end; ++it_temp)
        {
            *it_temp = *it + *_it;
            ++it; ++_it;
        }
        //for (int i = 0; i < int(_vector.Vector.size()); i++)
            //temp->Vector.at(i) = this->Vector[i] + _vector.Vector[i];
        return *temp;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
}

template <typename T>
VectorMD<T> VectorMD<T>::operator- (const VectorMD& _vector)
{
    try
    {
        if (this->Vector.size() != _vector.Vector.size())
            throw BadVectorDimensionException();
        VectorMD<T>* temp = new VectorMD<T>(int(this->Vector.size()));
        auto it = this->Vector.begin();
        auto _it = _vector.Vector.begin();
        for (auto it_temp = temp->Vector.begin(), end = temp->Vector.end(); it_temp != end; ++it_temp)
        {
            *it_temp = *it - *_it;
            ++it; ++_it;
        }
        //for (int i = 0; i < int(this->Vector.size()); i++)
            //temp->Vector.at(i) = this->Vector[i] - _vector.Vector[i];
        return *temp;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
}

template <typename T>
VectorMD<T> VectorMD<T>::operator* (T multiply)
{
    VectorMD<T>* temp = new VectorMD<T>(int(this->Vector.size()));
    auto _it = this->Vector.begin();
    for (auto it = temp->Vector.begin(), end = temp->Vector.end(); it != end; ++it)
    {
        *it = *_it * multiply;
        ++_it;
    }
    //for (int i = 0; i < int(this->Vector.size()); i++)
        //temp->Vector.at(i) = this->Vector[i] * multiply;
    return *temp;
}

template <typename T>
VectorMD<T> VectorMD<T>::operator/ (T division)
{
    VectorMD<T>* temp = new VectorMD<T>(int(this->Vector.size()));
    auto _it = this->Vector.begin();
    for (auto it = temp->Vector.begin(), end = temp->Vector.end(); it != end; ++it)
    {
        *it = *_it / division;
        ++_it;
    }
    //for (int i = 0; i < int(this->Vector.size()); i++)
        //temp->Vector.at(i) = this->Vector[i] / division;
    return *temp;
}

template <typename T>
T VectorMD<T>::operator* (const VectorMD& _vector)
{
    try
    {
        if (this->Vector.size() != _vector.Vector.size())
            throw BadVectorDimensionException();
        T temp = 0;
        auto _it = _vector.Vector.begin();
        for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        {
            temp += *it * *_it;
            ++_it;
        }
        //for (int i = 0; i < int(this->Vector.size()); i++)
            //temp += this->Vector[i] * _vector.Vector[i];
        return temp;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
}

template <typename T>
VectorMD<T> VectorMD<T>::cross(const VectorMD& _vector)
{
    // рассмотреть отдельно
}

template <typename T>
VectorMD<T> VectorMD<T>::operator+= (const VectorMD& _vector)
{
    try
    {
        if (this->Vector.size() != _vector.Vector.size())
            throw BadVectorDimensionException();
        auto _it = _vector.Vector.begin();
        for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        {
            *it += *_it;
            ++_it;
        }
        //for (int i = 0; i < int(this->Vector.size()); i++)
            //this->Vector[i] += _vector.Vector[i];
        return *this;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
}

template <typename T>
VectorMD<T> VectorMD<T>::operator-= (const VectorMD& _vector)
{
    try
    {
        if (this->Vector.size() != _vector.Vector.size())
            throw BadVectorDimensionException();
        auto _it = _vector.Vector.begin();
        for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        {
            *it -= *_it;
            ++_it;
        }
        //for (int i = 0; i < int(this->Vector.size()); i++)
            //this->Vector[i] -= _vector.Vector[i];
        return *this;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
}

template <typename T>
VectorMD<T> VectorMD<T>::operator*= (T multiply)
{
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        *it *= multiply;
    //for (int i = 0; i < int(this->Vector.size()); i++)
        //this->Vector.at(i) *= multiply;
    return *this;
}

template <typename T>
VectorMD<T> VectorMD<T>::operator/= (T division)
{
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        *it /= division;
    //for (int i = 0; i < int(this->Vector.size()); i++)
        //this->Vector.at(i) /= division;
    return *this;
}

template <typename T>
ostream& operator<< <T>(ostream& out, const VectorMD<T>& _vector)
{
    out << "( " << _vector.Vector[0];
    //for (int i = 1; i < int(_vector.Vector.size()) - 1; i++)
    for (auto it = _vector.Vector.begin() + 1, end = _vector.Vector.end() - 1; it != end; ++it)
        out << "; " << *it; //_vector.Vector[int(it)];
    out << "; " << _vector.Vector[_vector.Vector.size() - 1] << " )\n";
    return out;
}

template <typename T>
istream& operator>> <T>(istream& in, VectorMD<T>& _vector)
{
    for (auto it = _vector.Vector.begin(), end = _vector.Vector.end(); it != end; ++it)
        in >> *it;
    //for (int i = 0; i < _vector.get_Size(); i++)
        //in >> _vector.Vector[i];
    return in;
}

template <typename T>
T VectorMD<T>::distance(const VectorMD& _vector)
{
    T temp = NULL;
    auto _it = _vector.Vector.begin();
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
    {
        temp += *it * *_it;
        ++_it;
    }
    //for (int i = 0; i < int(_vector.Vector.size()); i++)
        //temp += _vector.Vector[i] * _vector.Vector[i];
    temp = T(sqrt(temp));
    return temp;
}

template <typename T>
T VectorMD<T>::module()
{
    T temp = NULL;
    for (auto it = this->Vector.begin(), end = this->Vector.end(); it != end; ++it)
        temp += *it * *it;
    //for (int i = 0; i < int(this->Vector.size()); i++)
        //temp += this->Vector[i] * this->Vector[i];
    temp = T(sqrt(temp));
    return temp;
}

template <typename T>
void VectorMD<T>::print_Vector()
{
    cout << "( " << this->Vector[0];
    for (auto it = this->Vector.begin() + 1, end = this->Vector.end() - 1; it != end; ++it)
    //for (int i = 1; i < int(this->Vector.size()) - 1; i++)
        cout << "; " << *it; //cout << "; " << this->Vector[i];
    cout << "; " << this->Vector[int(this->Vector.size()) - 1] << " )\n";
}

template <typename T>
VectorMD<T> operator*(const VectorMD<T>& _vector, T multiply)
{
    VectorMD<T>* temp = new VectorMD<T>(_vector.Vector.size());
    auto _it = _vector.Vector.begin();
    for (auto it = temp->Vector.begin(), end = temp->Vector.end(); it != end; ++it)
    {
        *it = *_it * multiply;
        ++_it;
    }
    //for (int i = 0; i < int(temp->Vector.size()); i++)
        //temp->Vector.at(i) = _vector.Vector[i] * multiply;
    return *temp;
}
#endif // !_VECTORMD_H_