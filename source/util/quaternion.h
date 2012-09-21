/******************************************************************************
 *
 * MantaFlow fluid solver framework
 * Copyright 2011 Tobias Pfaff, Nils Thuerey 
 *
 * This program is free software, distributed under the terms of the
 * GNU General Public License (GPL) 
 * http://www.gnu.org/licenses
 *
 * Basic quaternion class
 *
 ******************************************************************************/

#ifndef _QUATERNION_H
#define _QUATERNION_H

#include "vectorbase.h"

namespace Manta {

//! Very basic quaternion class
class Quaternion {
public:
    
    //! default constructor
    Quaternion() : x(0), y(0), z(0), w(0) {}
    
    //! copy constructor
    Quaternion(const Quaternion& q) : x(q.x), y(q.y), z(q.z), w(q.w) {}
    
    //! construct a quaternion from members
    Quaternion(Real _x, Real _y, Real _z, Real _w) : x(_x), y(_y), z(_z), w(_w) {}
        
    //! construct a quaternion from imag/real parts
    Quaternion(Vec3 _imag, Real _real) : imag(_imag), real(_real) {}
    
    //! Assign operator
    inline Quaternion& operator= (const Quaternion& q) {
        x = q.x;
        y = q.y;
        z = q.z;
        w = q.w;
        return *this;
    }
    
    //! Assign multiplication operator
    inline Quaternion& operator*= ( const Quaternion &q ) {
        *this = (*this) * q;
        return *this;
    }

    //! Assign multiplication operator
    inline Quaternion& operator*= ( const Real a ) {
        x *= a;
        y *= a;
        z *= a;
        w *= a;
        return *this;
    }
    
    //! return inverse quaternion
    inline Quaternion inverse() const {
        return Quaternion(-x,-y,-z,w);
    }

    // imaginary part
    union {
        struct {
            Real x;
            Real y;
            Real z;
        };
        Vec3 imag;
    };
    // real part
    union {
        Real w;
        Real real;
    };
};


//! Multiplication operator
inline Quaternion operator* ( const Quaternion &q1, const Quaternion &q2 ) {
    return Quaternion ( q2.w * q1.x + q2.x * q1.w + q2.y * q1.z - q2.z * q1.y,
                        q2.w * q1.y + q2.y * q1.w + q2.z * q1.x - q2.x * q1.z,
                        q2.w * q1.z + q2.z * q1.w + q2.x * q1.y - q2.y * q1.x,
                        q2.w * q1.w - q2.x * q1.x - q2.y * q1.y - q2.z * q1.z );
}

//! Multiplication operator
inline Quaternion operator* ( const Quaternion &q, const Real a ) {
    return Quaternion ( q.x*a, q.y*a, q.z*a, q.w*a);
}

} // namespace

#endif
