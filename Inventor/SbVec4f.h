/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2002 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

#ifndef COIN_SBVEC4F_H
#define COIN_SBVEC4F_H

#include <stdio.h>

#include <Inventor/SbBasic.h>

#ifdef __PIVY__
%apply float *OUTPUT { float& x, float& y, float& z, float& w };
#endif

class SbVec3f;

class COIN_DLL_API SbVec4f {
public:
#ifndef __PIVY__
  SbVec4f(void);
  SbVec4f(const float v[4]);
#endif

  SbVec4f(const float x, const float y, const float z, const float w);
  float dot(const SbVec4f& v) const;
  SbBool equals(const SbVec4f& v, const float tolerance) const;
  void getReal(SbVec3f& v) const;

#ifndef __PIVY__
  const float* getValue(void) const;
#endif

  void getValue(float& x, float& y, float& z, float& w) const;
  float length(void) const;
  void negate(void);
  float normalize(void);

#ifndef __PIVY__
  SbVec4f& setValue(const float v[4]);
#endif

  SbVec4f& setValue(const float x, const float y, const float z,
                    const float w);

#ifdef __PIVY__
  // swig - add a method for wrapping c++ operator[] access
  %addmethods {
	float __getitem__(int i) {
	  return (self->getValue())[i];
	}
  }
#endif

#ifndef __PIVY__
  float& operator [](const int i);
  const float& operator [](const int i) const;
#endif

  SbVec4f& operator *=(const float d);
  SbVec4f& operator /=(const float d);
  SbVec4f& operator +=(const SbVec4f& u);
  SbVec4f& operator -=(const SbVec4f& u);
  SbVec4f operator -(void) const;
  friend COIN_DLL_API SbVec4f operator *(const SbVec4f& v, const float d);
  friend COIN_DLL_API SbVec4f operator *(const float d, const SbVec4f& v);
  friend COIN_DLL_API SbVec4f operator /(const SbVec4f& v, const float d);
  friend COIN_DLL_API SbVec4f operator +(const SbVec4f& v1, const SbVec4f& v2);
  friend COIN_DLL_API SbVec4f operator -(const SbVec4f& v1, const SbVec4f& v2);
  friend COIN_DLL_API int operator ==(const SbVec4f& v1, const SbVec4f& v2);
  friend COIN_DLL_API int operator !=(const SbVec4f& v1, const SbVec4f& v2);

  void print(FILE * fp) const;

private:
  float vec[4];
};

#ifdef __PIVY__
%clear float& x, float& y, float& z, float& w;
#endif

#ifndef __PIVY__
COIN_DLL_API SbVec4f operator *(const SbVec4f& v, const float d);
COIN_DLL_API SbVec4f operator *(const float d, const SbVec4f& v);
COIN_DLL_API SbVec4f operator /(const SbVec4f& v, const float d);
COIN_DLL_API SbVec4f operator +(const SbVec4f& v1, const SbVec4f& v2);
COIN_DLL_API SbVec4f operator -(const SbVec4f& v1, const SbVec4f& v2);
COIN_DLL_API int operator ==(const SbVec4f& v1, const SbVec4f& v2);
COIN_DLL_API int operator !=(const SbVec4f& v1, const SbVec4f& v2);
#endif

#endif // !COIN_SBVEC4F_H
