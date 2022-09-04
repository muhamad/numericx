// ==++==
//
//    Copyright (C) Muhammad Aladdin
//
//    The use and distribution terms for this software are contained in the file 
//    named LICENSE, which can be found in the root of this distribution.
//
// ==--==
/*============================================================
**
** File:  mathx.hpp
**
** Purpose: library main header
**
===========================================================*/

#ifndef MATHX_HPP
#define MATHX_HPP

///////////////////////////
//   ESSENTIAL HEADERS   //
///////////////////////////

#ifndef CHAR_BIT
#   include <climits>
#endif

#ifndef FLT_RADIX
#   include <cfloat>
#endif

#include <limits>
#include <iomanip>
#include <string>
#include <iostream>
#include <cmath> // for frexp, pow

////////////////////////////
//  COMPILER PRE-OPTIONS  //
////////////////////////////

#include "src/common/helper/compiler_pre.hpp"

/////////////////////////////
//   COMFIG FILE INCLUDE   //
/////////////////////////////

#include "mathx_config.hpp"
#include "src/common/helper/check.hpp"

#if MATHX_BIG_ENDIAN == MATHX_TRUE
#   error big-endian implementation is a work in progress and not yet completed.
#endif

/////////////////////////////
//   COMMON HEADER FILES   //
/////////////////////////////

#include "src/common/helper/typedefs.hpp"
#include "src/common/helper/startup_pre.hpp"
#include "src/common/info/info_t.hpp"
#include "src/common/helper/cth.hpp"
#include "src/common/info/int_info.hpp"
#include "src/common/info/float_info.hpp"
#include "src/common/info/sys_info.hpp"
#include "src/common/helper/value_t.hpp"
#include "src/common/helper/string_id.hpp"
#include "src/common/helper/string_helper.hpp"
#include "src/common/helper/startup_post.hpp"

////////////////////////
//     MAIN TYPES     //
////////////////////////

#include "src/base/cast.hpp"
#include "src/cast/predefined.hpp"
#include "src/base/alphnum_base.hpp"
#include "src/base/int_contract.hpp"
#include "src/base/int_t.hpp"
#include "src/base/uint_t.hpp"


//////////////////////////////
//  INTEGER IMPLEMENTATION  //
//////////////////////////////

#include "src/int/imp/meta.hpp"
#include "src/int/imp/helper.hpp"
#include "src/int/cc/prototype.hpp"
#include "src/int/nc/prototype.hpp"
#include "src/int/sc/prototype.hpp"
#
#if MATHX_BIG_ENDIAN == MATHX_TRUE
#   include "src/int/imp/be/default_range.hpp"
#   include "src/int/imp/be/default_logic.hpp"
#   include "src/int/imp/be/default_arithmetic.hpp"
#   include "src/int/cc/imp_be.hpp"
#   include "src/int/nc/imp_be.hpp"
#   include "src/int/sc/imp_be.hpp"
#else
#   include "src/int/imp/le/default_range.hpp"
#   include "src/int/imp/le/default_logic.hpp"
#   include "src/int/imp/le/default_arithmetic.hpp"
#   include "src/int/cc/imp_le.hpp"
#   include "src/int/nc/imp_le.hpp"
#   include "src/int/sc/imp_le.hpp"
#endif
#
#include "src/int/imp/cmn/default_bitwise.hpp"
#include "src/int/imp/cmn/default_meta.hpp"
#include "src/int/cc/imp_cmn.hpp"
#include "src/int/nc/imp_cmn.hpp"
#include "src/int/sc/imp_cmn.hpp"
#include "src/int/imp/predefined.hpp"

//////////////////////////
//  STL IMPLEMENTATION  //
//////////////////////////

#if MATHX_ALLOW_STL == MATHX_TRUE
#   include "src/stl/prototype.hpp"
#   include "src/stl/imp_cmn.hpp"
#   include "src/stl/imp_int.hpp"
#   include "src/stl/limits/int_t.hpp"
#   include "src/stl/limits/uint_t.hpp"
#   include "src/stl/iomanip.hpp"
#   include "src/stl/iostream.hpp"
#endif

///////////////////////////
//  MATH IMPLEMENTATION  //
///////////////////////////

#include "src/math/macro.hpp"
#include "src/math/imp_int.hpp"
#include "src/math/math.hpp"
#include "src/math/imp_cmn.hpp"

////////////////////////
//   CAST INTERFACE   //
////////////////////////

#include "src/cast/int_nc.hpp"
#include "src/cast/int_sc.hpp"

//////////////////////////////////
//  CONSTRUCTOR IMPLEMENTATION  //
//////////////////////////////////

#include "src/base/constructors.inl"

//////////////////////////////
// PREDEFINED NUMERIC TYPES //
//////////////////////////////

#include "src/types.hpp"

////////////////////////
//    VERSION INFO    //
////////////////////////

#include "src/version.hpp"

/////////////////////////////
//  COMPILER POST-OPTIONS  //
/////////////////////////////

#include "src/common/helper/compiler_post.hpp"


#endif // MATHX_HPP
