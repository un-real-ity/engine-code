#include <math.h>
#include "Matrix.h"

Matrix::Matrix(float _11_, float _12_, float _21_, float _22_, float _31_, float _32_)
    : _11(_11_), _12(_12_), _21(_21_), _22(_22_), _31(_31_), _32(_32_)
{
}

Matrix::Matrix()
    : _11(1.0f), _12(0.0f), _21(0.0f), _22(1.0f), _31(0.0f), _32(0.0f)
{
}

float Matrix::Determinant()
{
    return (_11 * _22) - (_12 * _21);
}

Matrix Matrix::Identity()
{
    return Matrix();
}

Matrix Matrix::Scale(float x, float y)
{
    Matrix res;
    res._11 = x,    res._12 = 0.0f;
    res._21 = 0.0f; res._22 = y;
    res._31 = 0.0f; res._32 = 0.0f;

    return Matrix(
        x, 0.0f,
        0.0f, y,
        0.0f, 0.0f);
}

Matrix Matrix::Translate(float x, float y)
{
    return Matrix(
        1.0f, 0.0f,
        0.0f, 1.0f,
        x, y);
}

Matrix Matrix::Rotation(float angleInRadian)
{
    float c = cos(angleInRadian);
    float s = sin(angleInRadian);

    return Matrix(
        c, s,
        -s, c,
        0.0f, 0.0f);
}

Matrix Matrix::operator+(const Matrix & rhs) const
{
    return Matrix(
        _11 + rhs._11, _12 + rhs._12,
        _21 + rhs._21, _22 + rhs._22,
        _31 + rhs._31, _32 + rhs._32);
}

Matrix Matrix::operator-(const Matrix & rhs) const
{
    return Matrix(
        _11 - rhs._11, _12 - rhs._12,
        _21 - rhs._21, _22 - rhs._22,
        _31 - rhs._31, _32 - rhs._32);
}

Matrix Matrix::operator-() const
{
    return Matrix(
        -_11, -_12,
        -_21, -_22,
        -_31, -_32);
}

Matrix Matrix::operator*(float n) const
{
    return Matrix(
        _11 * n, _12 * n,
        _21 * n, _22 * n,
        _31 * n, _32 * n);
}

Matrix Matrix::operator/(float n) const
{
    return Matrix(
        _11 / n, _12 / n,
        _21 / n, _22 / n,
        _31 / n, _32 / n);
}

Matrix Matrix::operator*(const Matrix& rhs) const
{
    return Matrix(
        _11 * rhs._11 + _12 * rhs._21, _11 * rhs._12 + _12 * rhs._22,
        _21 * rhs._11 + _22 * rhs._21, _21 * rhs._12 + _22 * rhs._22,
        _31 * rhs._11 + _32 * rhs._21 + rhs._31, _31 * rhs._12 + _32 * rhs._22 + rhs._32);
}
