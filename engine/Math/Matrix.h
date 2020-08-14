#pragma once

struct Matrix
{
    Matrix(float _11_, float _12_,
        float _21_, float _22_,
        float _31_, float _32_);

    Matrix();

    float Determinant();

    static Matrix Identity();
    static Matrix Scale(float x, float y);
    static Matrix Translate(float x, float y);
    static Matrix Rotation(float angleInRadian);

    Matrix& operator=(const Matrix& rhs) = default;
    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator-() const;
    Matrix operator*(float n) const;
    Matrix operator/(float n) const;
    Matrix operator*(const Matrix& rhs) const;

    float _11, _12;
    float _21, _22;
    float _31, _32;
};
