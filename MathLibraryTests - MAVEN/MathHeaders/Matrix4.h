#pragma once
namespace MathClasses
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

            Vector4 axis[3];
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
	};
}