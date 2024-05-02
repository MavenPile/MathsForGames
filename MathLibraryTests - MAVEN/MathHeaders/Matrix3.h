#pragma once
namespace MathClasses
{
    struct Matrix3
    {
    public: //  VARIABLES

        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };

            float v[9]; //  a 1D array of all m#

            float mm[3][3]; //  a 2D array, 3x3, of m# in rows and columns

            Vector3 axis[3];    //  an array of three Vector3's containing m#'s

        };  //  all values within union share the same memory
            //  gives different ways to access data within the matrix

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
            return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
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

        static Matrix3 MakeTranslation(float x, float y, float z)
        {
            Matrix3 temp = MakeIdentity();

            temp.axis[2].x = x;
            temp.axis[2].y = y;
            temp.axis[2].z = z;

            return temp;
        }

        static Matrix3 MakeTranslation(Vector3 vec)
        {
            return MakeTranslation(vec.x, vec.y, vec.z);
        }

        static Matrix3 MakeRotateX(float a)
        {
            return Matrix3(1, 0, 0, 0, cosf(a), -sinf(a), 0, sinf(a), cosf(a));
        }

        static Matrix3 MakeRotateY(float a)
        {
            return Matrix3(cosf(a), 0, sinf(a), 0, 1, 0, -sinf(a), 0, cosf(a));
        }

        static Matrix3 MakeRotateZ(float a)
        {
            return Matrix3(cosf(a), sinf(a), 0, -sinf(a), cosf(a), 0, 0, 0, 1); //  this is a mix-match, but it works
        }

        static Matrix3 MakeEuler(float pitch, float yaw, float roll)
        {
            Matrix3 x = MakeRotateX(pitch);
            Matrix3 y = MakeRotateY(yaw);
            Matrix3 z = MakeRotateZ(roll);

            return (z * y * x);
        }

        static Matrix3 MakeEuler(Vector3 rot)
        {
            Matrix3 x = MakeRotateX(rot.x);
            Matrix3 y = MakeRotateY(rot.y);
            Matrix3 z = MakeRotateZ(rot.z);

            return (z * y * x);
        }

        static Matrix3 MakeScale(float xScale, float yScale)
        {
            return Matrix3(xScale, 0.f, 0.f, 0.f, yScale, 0.f, 0.f, 0.f, 1.f);
        }

        static Matrix3 MakeScale(float xScale, float yScale, float zScale)
        {
            return Matrix3(xScale, 0.f, 0.f, 0.f, yScale, 0.f, 0.f, 0.f, zScale);
        }

        static Matrix3 MakeScale(Vector3 scale)
        {
            return MakeScale(scale.x, scale.y, scale.z);
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
            //Matrix3 result;
            
            //for (int i = 0; i < 3; i++)
            //{
            //    Vector3 col(mm[i][0], mm[i][1], mm[i][2]);

            //    for (int j = 0; j < 3; j++)
            //    {
            //        result.mm[i][j] = col.Dot(rhs.axis[j]);
            //    }
            //}

            //for (int i = 0; i < 3; ++i)
            //{
            //    Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

            //    for (int j = 0; j < 3; ++i)
            //    {
            //        result.mm[j][i] = row.Dot(rhs.axis[j]);
            //    }
            //}


            //result.m1 = m1 * rhs.m1 + m4 * rhs.m2 + m7 * rhs.m3;
            //result.m4 = m1 * rhs.m4 + m4 * rhs.m5 + m7 * rhs.m6;
            //result.m7 = m1 * rhs.m7 + m4 * rhs.m8 + m7 * rhs.m9;

            //result.m1 = Vector3(m1, m4, m7).Dot(rhs.axis[0]);
            //result.m2 = Vector3(m1, m4, m7).Dot(rhs.axis[1]);
            //result.m3 = Vector3(m1, m4, m7).Dot(rhs.axis[2]);

            //result.m2 = m2 * rhs.m1 + m5 * rhs.m2 + m8 * rhs.m3;
            //result.m5 = m2 * rhs.m4 + m5 * rhs.m5 + m8 * rhs.m6;
            //result.m8 = m2 * rhs.m7 + m5 * rhs.m8 + m8 * rhs.m9;

            //result.m2 = Vector3(m2, m5, m8).Dot(rhs.axis[0]);
            //result.m5 = Vector3(m2, m5, m8).Dot(rhs.axis[1]);
            //result.m8 = Vector3(m2, m5, m8).Dot(rhs.axis[2]);

            //result.m3 = m3 * rhs.m1 + m6 * rhs.m2 + m9 * rhs.m3;
            //result.m6 = m3 * rhs.m4 + m6 * rhs.m5 + m9 * rhs.m6;
            //result.m9 = m3 * rhs.m7 + m6 * rhs.m8 + m9 * rhs.m9;

            //result.m3 = Vector3(m3, m6, m9).Dot(rhs.axis[0]);
            //result.m6 = Vector3(m3, m6, m9).Dot(rhs.axis[1]);
            //result.m9 = Vector3(m3, m6, m9).Dot(rhs.axis[2]);

            Matrix3 result;

            for (int i = 0; i < 3; i++)
            {
                Vector3 col(mm[0][i], mm[1][i], mm[2][i]);  //  creates a vector representing a column in the lhs matrix
                                                            //  [m1]    [m4]    [m7]
                                                            //  [m2]then[m5]then[m8]
                                                            //  [m3]    [m6]    [m9]

                for (int j = 0; j < 3; j++)
                {
                    result.mm[j][i] = col.Dot(rhs.axis[j]); //  changes the lhs array using the dot product of lhs col, and rhs axis/row
                                                            //  
                                                            //  
                                                            //  
                }
            }

            return result;
        }

        Vector3 operator * (const Vector3 rhs) const
        {
            Vector3 temp;

            temp.x = Vector3(m1, m4, m7).Dot(rhs);
            temp.y = Vector3(m2, m5, m8).Dot(rhs);
            temp.z = Vector3(m3, m6, m9).Dot(rhs);

            return temp;
        }

        bool operator == (const Matrix3 rhs) const
        {
            float THRESHOLD = 0.00001f;
            
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if (axis[col][row] - rhs.axis[col][row] > THRESHOLD)
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        bool operator != (const Matrix3 rhs) const
        {
            return !(*this == rhs);
        }
	};
}