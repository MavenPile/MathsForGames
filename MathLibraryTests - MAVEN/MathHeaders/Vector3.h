#pragma once
#include <string>
#include <cmath>

namespace MathClasses
{
    struct Vector3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

    public: //  VARIABLES

        union
        {
            struct { float x, y, z; };  //  12-bytes
            float data[3];              //  12-bytes
                //  the array data[3] shares memory with the anonymous struct
                //  data[0] uses the same memory as x, and so on for [1] and [2]
        };

    public: //  CONSTRUCTORS

        Vector3()   //  Default Constructor
        {
            x = 0.f;
            y = 0.f;
            z = 0.f;
        }

        Vector3(float xInput, float yInput, float zInput)   //  specialised constructor
        {
            x = xInput, y = yInput, z = zInput;
        }

    public: //  METHODS

        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

        float Magnitude() const
        {
            float temp = (x * x) + (y * y) + (z * z);

            if (0 >= temp)
            {
                return 0.f;
            }

            return sqrt(temp);
        }

        Vector3 Normalised() const
        {
            float mag = Magnitude();

            Vector3 temp;

            if (0 >= mag)
            {
                return temp;
            }

            temp.x = x / mag;

            temp.y = y / mag;

            temp.z = z / mag;

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
        }

        float Dot(const Vector3 rhs) const
        {
            return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
        }

        Vector3 Cross(const Vector3 rhs) const
        {
            float crossX = (y * rhs.z) - (z * rhs.y);
            
            float crossY = (z * rhs.x) - (x * rhs.z);

            float crossZ = (x * rhs.y) - (y * rhs.x);
            
            Vector3 temp(crossX, crossY, crossZ);

            return temp;
        }

    public: //  OPERATORS

        float& operator [] (int dim)
        {
            return data[dim];
        }

        const float& operator[] (int dim) const
        {
            return data[dim];
        }

        operator float* () { return data; } //  the Vector3 struct already acts like a float array
                                            //  this allows you to implicitly cast a Vector3 into a float array
                                            //  this may come up if a function needs a float array, not a Vector3
                                            //  you will be able to use a Vector3 in such a case, because this operator deals with it

        operator const float* () const { return data; } //  cast to float array - const-qualified

        Vector3 operator + (const Vector3& rhs) const
        {
            Vector3 sum(x + rhs.x, y + rhs.y, z + rhs.z);

            return sum;
        }

        Vector3 operator - (const Vector3& rhs) const
        {
            Vector3 sum(x - rhs.x, y - rhs.y, z - rhs.z);

            return sum;
        }

        Vector3 operator * (const float rhs) const
        {
            Vector3 product(x * rhs, y * rhs, z * rhs);

            return product;
        }

        friend Vector3 operator * (const float lhs, const Vector3 rhs)  //  'friend' keyword puts function outside scope of class
                                                                        //  a 'friend' function still has access to the class as a member
        {
            Vector3 product(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);

            return product;
        }

        Vector3 operator / (const float rhs) const
        {
            Vector3 divide(x / rhs, y / rhs, z / rhs);

            return divide;
        }

        void operator += (const Vector3& rhs) const
        {
            x + rhs.x, y + rhs.y, z + rhs.z;
        }

        void operator -= (const Vector3& rhs) const
        {
            x - rhs.x, y - rhs.y, z - rhs.z;
        }

        bool operator == (const Vector3& rhs) const
        {
            float xDist = fabsf(x - rhs.x);
            float yDist = fabsf(y - rhs.y);
            float zDist = fabsf(z - rhs.z);

            const float THRESHOLD = 0.00001f;   //  to account for floating point imprecision
                                                //  the calculated distances are checked against a predetermined
                                                //  threshold, giving a precision that is good enough

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;
        }

        bool operator != (const Vector3& rhs) const
        {
            return !(*this == rhs); //  because inequality is the opposite of the equality operator
        }
	};
}