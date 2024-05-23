#pragma once

namespace Math
{
    struct Matrix4
    {
    public: //  VARIABLES

        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
            };

            float v[16];

            float mm[4][4];

            Vector4 axis[4];
        };

    public: //  CONSTRUCTORS

        Matrix4()
        {
            for (int i = 0; i < 16; i++)
            {
                v[i] = 0.f;
            }
        }

        Matrix4(float n1, float n2, float n3, float n4, 
                float n5, float n6, float n7, float n8, 
                float n9, float n10, float n11, float n12, 
                float n13, float n14, float n15, float n16)
        {
            m1 = n1, m2 = n2, m3 = n3, m4 = n4,
            m5 = n5, m6 = n6, m7 = n7, m8 = n8,
            m9 = n9, m10 = n10, m11 = n11, m12 = n12,
            m13 = n13, m14 = n14, m15 = n15, m16 = n16;
        }

        Matrix4(float* array)
        {
            for (int i = 0; i < 16; i++)
            {
                v[i] = array[i];
            }
        }

    public: //  METHODS

        static Matrix4 MakeIdentity()
        {
            return Matrix4( 1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1);
        }

        Matrix4 Transposed()
        {
            return Matrix4( m1, m5 , m9 , m13,
                            m2, m6 , m10, m14,
                            m3, m7 , m11, m15,
                            m4, m8 , m12, m16);
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);

            for (int i = 1; i < 16; i++)
            {
                str += ", " + std::to_string(v[i]);
            }

            return str;
        }

        static Matrix4 MakeTranslation(float x, float y, float z)
        {
            Matrix4 temp = MakeIdentity();

            temp.axis[3].x = x;
            temp.axis[3].y = y;
            temp.axis[3].z = z;
            //temp.axis[3].w = 1;

            return temp;
        }

        static Matrix4 MakeTranslation(Vector3 vec)
        {
            return MakeTranslation(vec.x, vec.y, vec.z);
        }

        static Matrix4 MakeRotateX(float a)
        {
            return Matrix4(1, 0, 0, 0, 0, cosf(a), -sinf(a), 0, 0, sinf(a), cosf(a), 0, 0, 0, 0, 1);
        }

        static Matrix4 MakeRotateY(float a)
        {
            return Matrix4(cosf(a), 0, sinf(a), 0, 0, 1, 0, 0, -sinf(a), 0, cosf(a), 0, 0, 0, 0, 1);
        }

        static Matrix4 MakeRotateZ(float a)
        {
            return Matrix4(cosf(a), sinf(a), 0, 0, -sinf(a), cosf(a), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
        }

        //static Matrix4 MakeRotateW(float a)
        //{

        //}

        static Matrix4 MakeEuler(float pitch, float yaw, float roll)
        {
            Matrix4 x = MakeRotateX(pitch);
            Matrix4 y = MakeRotateY(yaw);
            Matrix4 z = MakeRotateZ(roll);

            return (z * y * x);
        }

        static Matrix4 MakeEuler(Vector3 rot)
        {
            Matrix4 x = MakeRotateX(rot.x);
            Matrix4 y = MakeRotateY(rot.y);
            Matrix4 z = MakeRotateZ(rot.z);

            return (z * y * x);
        }

        static Matrix4 MakeScale(float xScale, float yScale, float zScale)
        {
            return Matrix4(xScale, 0.f, 0.f, 0.f, 0.f, yScale, 0.f, 0.f, 0.f, 0.f, zScale, 0.f, 0.f, 0.f, 0.f, 1.0f);

        }

        static Matrix4 MakeScale(Vector3 scale)
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

        Matrix4 operator * (const Matrix4 rhs) const
        {
            Matrix4 result;

            for (int i = 0; i < 4; i++)
            {
                Vector4 col(mm[0][i], mm[1][i], mm[2][i], mm[3][i]);

                for (int j = 0; j < 4; j++)
                {
                    result.mm[j][i] = col.Dot(rhs.axis[j]);
                }
            }

            return result;
        }

        Vector4 operator * (const Vector4 rhs) const
        {
            Vector4 result;

            result.x = Vector4(m1,m5,m9,m13).Dot(rhs);
            result.y = Vector4(m2,m6,m10,m14).Dot(rhs);
            result.z = Vector4(m3,m7,m11,m15).Dot(rhs);
            result.w = Vector4(m4,m8,m12,m16).Dot(rhs);

            return result;
        }

        bool operator == (const Matrix4 rhs) const
        {
            float THRESHOLD = 0.00001f;

            for (int row = 0; row < 4; row++)
            {
                for (int col = 0; col < 4; col++)
                {
                    if (axis[row][col] - rhs.axis[row][col] > THRESHOLD)
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        bool operator != (const Matrix4 rhs) const
        {
            return !(*this == rhs);
        }
	};
}