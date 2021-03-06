/* ================================================================
 *
 * PyCA Project
 *
 * Copyright (c) J. Samuel Preston, Linh K. Ha, Sarang C. Joshi. All
 * rights reserved.  See Copyright.txt or for details.
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the above copyright notice for more information.
 *
 * ================================================================ */

#ifndef __VFIELD3D_OPERS_H
#define __VFIELD3D_OPERS_H

#include <estream.h>
#include <pycaConst.h>
#include <Vec3D.h>
#include <Selector.h>

namespace PyCA {

class Image3D;
class Field3D;

class CVFieldOpers;
class GVFieldOpers;

/*
 * This is the operation on the VField or Displacement Field
 *
 */
template<int mode>
class VFieldOpers{
public:
    enum { exec_mode = mode };
    typedef typename BinSelector<mode, CVFieldOpers, GVFieldOpers>::Result Executer;
//////////////////////////////////////////////////////////////////////// 
// set vfield to zero
// i.e. v(x) = 0
////////////////////////////////////////////////////////////////////////
    static void SetToZero(Field3D& v, StreamT s);

//////////////////////////////////////////////////////////////////////// 
// convert velocity field to HField
// i.e. h(x) = x + v(x) * delta
////////////////////////////////////////////////////////////////////////
    static void toH(Field3D& h, const Field3D& v, const float& delta ,StreamT s, bool onDev=false);

//////////////////////////////////////////////////////////////////////// 
// convert velocity field to HField (inplace version)
// i.e. h(x) = x + v(x) * delta
////////////////////////////////////////////////////////////////////////
    static void toH_I(Field3D& h, const float& delta ,StreamT s, bool onDev=false);

    static void Splat(Field3D& a_o, const Field3D& a_h, const Field3D& a_i,
                             bool normalize, StreamT stream);
};

} // end namespace PyCA

#endif
