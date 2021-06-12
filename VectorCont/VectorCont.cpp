#include "VectorMD.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int inputVectorDimension = 0;

    try
    {
        cout << "Введите размерность пространства:\n";
        cin >> inputVectorDimension;

        if (inputVectorDimension < 2)
            throw BadSpaceDimensionException();

        VectorMD<double>* vector1 = new VectorMD<double>(inputVectorDimension);
        VectorMD<double>* vector2 = new VectorMD<double>(inputVectorDimension);
        
        VectorMD<double> vectorAddtiton(inputVectorDimension);          // operator+
        VectorMD<double> vectorDifference(inputVectorDimension);        // operator-
        VectorMD<double> vectorNumberMultiply(inputVectorDimension);    // operator* T
        VectorMD<double> vectorNumberDivision(inputVectorDimension);    // operator/ T
        VectorMD<double> vectorMultiply(inputVectorDimension);          // operator*
        VectorMD<double> vectorAddEqual(inputVectorDimension);          // operator+=
        VectorMD<double> vectorDiffEqual(inputVectorDimension);         // operator-=
        VectorMD<double> vectorMulEqualNumber(inputVectorDimension);    // operator*=
        VectorMD<double> vectorDiffEqualNumber(inputVectorDimension);   // operator/=

        double number = 2.;

        cout << "Введите вектор 1:\n";
        cin >> *vector1;
        cout << "Вектор 1 = " << *vector1;

        cout << "\nВведите вектор 2:\n";
        cin >> *vector2;
        cout << "Вектор 2 = " << *vector2;

        vectorAddtiton = *vector1 + *vector2;
        cout << "\nСумма двух векторов = " << vectorAddtiton << endl;

        vectorDifference = *vector1 - *vector2;
        cout << "Разность двух векторов = " << vectorDifference << endl;

        vectorNumberMultiply = *vector1 * number;
        cout << "Произведение вектора 1 на число " << number << " = " << vectorNumberMultiply << endl;

        vectorNumberDivision = *vector1 / number;
        cout << "Деление вектора 1 на число " << number << " = " << vectorNumberDivision << endl;

        vectorAddEqual += *vector1;
        cout << "Сумма двух векторов = " << vectorAddEqual << endl;

        vectorDiffEqual -= *vector1;
        cout << "Разность двух векторов = " << vectorDiffEqual << endl;

        vectorMulEqualNumber = *vector1;
        vectorMulEqualNumber *= number;
        cout << "Произведение вектора на число " << number << " = " << vectorMulEqualNumber << endl;

        vectorDiffEqualNumber = *vector1;
        vectorDiffEqualNumber /= number;
        cout << "Деление вектора на число " << number << " = " << vectorDiffEqualNumber << endl;

        double t = *vector1 * *vector2;
        cout << "Скалярное произведение двух векторов = " << t << endl;
    }
    catch (Exception& e)
    {
        e.ShowMessage();
        return 0;
    }
    return 0;
}