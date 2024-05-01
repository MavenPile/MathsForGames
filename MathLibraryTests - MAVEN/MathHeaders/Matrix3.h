#pragma once
namespace MathClasses
{
    struct Matrix3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            float v[9];

            float mm[3][3];

            Vector3 axis[3];
        };

    public: //  CONSTRUCTORS

        Matrix3()
        {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.f;
        }

        Matrix3(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9)
        {
            m1 = n1, m2 = n2, m3 = n3, m4 = n4, m5 = n5, m6 = n6, m7 = n7, m8 = n8, m9 = n9;
        }

        Matrix3(float* array)
        {
            m1 = array[0], m2 = array[1], m3 = array[2], m4 = array[3], m5 = array[4], m6 = array[5], m7 = array[6], m8 = array[7], m9 = array[8];
        }

    public: //  METHODS

        static Matrix3 MakeIdentity()
        {
            Matrix3 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;

            identity.m4 = 0;
            identity.m5 = 1;
            identity.m6 = 0;

            identity.m7 = 0;
            identity.m8 = 0;
            identity.m9 = 1;

            return identity;
        }

        Matrix3 Transposed()
        {
            Matrix3 temp;

            return temp;
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);

            for (size_t i = 1; i < 9; i++)
            {
                str += ", " + std::to_string(v[i]);
            }

            return str;
        }

    public: //  OPERATORS

        float& operator [] (int dim)
        {
            return v[dim];
        }

        const float& operator [] (int dim) const
        {
            return v[dim];
        }

        operator float* ()
        {
            return v;
        }

        operator const float* () const
        {
            return v;
        }

        Matrix3 operator * (const Matrix3 rhs) const
        {
            Matrix3 result;
            
            for (size_t i = 0; i < 3; i++)
            {
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                for (size_t j = 0; j < 3; j++)
                {
                    result.mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }

            return result;
        }

        Matrix3 operator * (const Vector3 rhs) const
        {
            Matrix3 temp;

            return temp;
        }

        bool operator == (const Matrix3 rhs) const
        {
            return false;
        }

        bool operator != (const Matrix3 rhs) const
        {
            return false;
        }
	};
}