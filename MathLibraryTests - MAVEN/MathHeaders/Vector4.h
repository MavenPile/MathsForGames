#pragma once
#include <string>
#include <cmath>

namespace MathClasses
{
    struct Vector4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

    public: //  VARIABLES

        union
        {
            struct { float x, y, z, w; };
            float data[4];
        };

    public: //  CONSTRUCTORS

        Vector4()
        {
            x = 0.f;
            y = 0.f;
            z = 0.f;
            w = 0.f;
        }

        Vector4(float xInput, float yInput, float zInput, float wInput)
        {
            x = xInput, y = yInput, z = zInput, w = wInput;
        }

    public: //  METHODS

        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
        }

        float Magnitude() const
        {
            float temp = (x * x) + (y * y) + (z * z) + (w * w);

            return sqrt(temp);
        }

        Vector4 Normalised() const
        {
            float mag = Magnitude();

            Vector4 temp(0, 0, 0, 0);

            if (0 >= mag)
            {
                return temp;
            }

            temp.x = x / mag;
            temp.y = y / mag;
            temp.z = z / mag;
            temp.w = w / mag;

            return temp;
        }

        void Normalise()
        {
            float mag = Magnitude();

            if (0 >= mag)
            {
                return;
            }

            x = x / mag;
            y = y / mag;
            z = z / mag;
            w = w / mag;
        }

        float Dot(const Vector4 rhs) const
        {
            return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
        }

        Vector4 Cross(const Vector4 rhs) const
        {
            float crossX = (y * rhs.z) - (z * rhs.y);
            float crossY = (z * rhs.x) - (x * rhs.z);
            float crossZ = (x * rhs.y) - (y * rhs.x);
            float crossW = 0;

            Vector4 temp(crossX, crossY, crossZ, crossW);

            return temp;
        }

    public: //  OPERATORS

        float& operator [] (int dim)
        {
            return data[dim];
        }

        const float& operator [] (int dim) const
        {
            return data[dim];
        }

        operator float* ()
        {
            return data;
        }

        operator const float* () const
        {
            return data;
        }

        Vector4 operator + (const Vector4& rhs) const
        {
            Vector4 sum((x + rhs.x), (y + rhs.y), (z + rhs.z), (w + rhs.w));

            return sum;
        }

        Vector4 operator - (const Vector4& rhs) const
        {
            Vector4 sum((x - rhs.x), (y - rhs.y), (z - rhs.z), (w - rhs.w));

            return sum;
        }

        Vector4 operator * (const float rhs) const
        {
            Vector4 product((x * rhs), (y * rhs), (z * rhs), (w * rhs));

            return product;
        }

        friend Vector4 operator * (const float lhs, const Vector4 rhs)
        {
            Vector4 product((rhs.x * lhs), (rhs.y * lhs), (rhs.z * lhs), (rhs.w * lhs));

            return product;
        }

        Vector4 operator / (const float rhs) const
        {
            Vector4 product(x / rhs, y / rhs, z / rhs, w / rhs);

            return product;
        }

        //void operator += (const Vector4& rhs) const
        //{
        //    x = x + rhs.x;
        //    y = y + rhs.y;
        //    z = z + rhs.z;
        //    w = w + rhs.w;
        //}

        //void operator -= (const Vector4& rhs) const
        //{
        //    x = x - rhs.x;
        //    y = y - rhs.y;
        //    z = z - rhs.z;
        //    w = w - rhs.w;
        //}

        bool operator == (const Vector4& rhs) const
        {
            float xDist = fabsf(x - rhs.x);
            float yDist = fabsf(y - rhs.y);
            float zDist = fabsf(z - rhs.z);
            float wDist = fabsf(w - rhs.w);

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD && wDist < THRESHOLD;
        }

        bool operator != (const Vector4 rhs) const
        {
            return !(*this == rhs);
        }
	};
}