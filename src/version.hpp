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
** File:  version.hpp
**
** Purpose: mathx version info
**
===========================================================*/

#ifndef MATHX_VERSION_HPP
#define MATHX_VERSION_HPP

//  7-bits (version major number)
#define MATHX_MAJOR   0
// 13-bits (version minor number)
#define MATHX_MINOR   1
//  2-bits (release-type): 0: update-id, 1: alpha, 2: beta, 3: release-candidate
#define MATHX_RT      1
// 10-bits (sub-id): release-type value
#define MATHX_RID     1
// version as 32-bits unsigned integer
#define MATHX_VERSION ((MATHX_MAJOR << 25) | (MATHX_MINOR << 12) | (MATHX_RT << 10) | MATHX_RID)

// helper macros to convert version to string

#define MATHX_CONCAT(X, Y)       MATHX_CONCAT_STAGE(X, Y)
#define MATHX_CONCAT_STAGE(X, Y) X ## Y
#define MATHX_TO_STR(X)          MATHX_TO_STR_STAGE(X)
#define MATHX_TO_STR_STAGE(X)    # X

#if MATHX_RID == 0
#   define MATHX_RT_ALL
#else
#   if MATHX_RT == 0
#      define MATHX_RT_ALL MATHX_CONCAT(u, MATHX_RID)
#   elif MATHX_RT == 1
#      define MATHX_RT_ALL MATHX_CONCAT(a, MATHX_RID)
#   elif MATHX_RT == 2
#      define MATHX_RT_ALL MATHX_CONCAT(b, MATHX_RID)
#   else
#      define MATHX_RT_ALL MATHX_CONCAT(rc, MATHX_RID)
#   endif
#endif

#if MATHX_MINOR == 0
#   define MATHX_MINOR_ALL
#else
#   define MATHX_MINOR_ALL MATHX_CONCAT(., MATHX_MINOR)
#endif

#define MATHX_MINOR_RT_ALL MATHX_CONCAT(MATHX_MINOR_ALL, MATHX_RT_ALL)
#define MATHX_MAJOR_ALL    MATHX_CONCAT(MATHX_MAJOR, MATHX_MINOR_RT_ALL)


// version as ordinary null-terminated string
#define MATHX_VERSION_STR  MATHX_TO_STR(MATHX_MAJOR_ALL)

namespace mathx
{

// version info
struct version
{
	enum ReleaseType
	{ Update = 0, Alpha = 1, Beta = 2, RC = 3 };


	static const    unsigned full  = MATHX_VERSION;
	static const         int major = MATHX_MAJOR;
	static const         int minor = MATHX_MINOR;
	static const ReleaseType rtype = (ReleaseType)MATHX_RT;
	static const         int rid   = MATHX_RID;

	static const char* name() { return MATHX_VERSION_STR; }
};

}

#undef MATHX_CONCAT
#undef MATHX_CONCAT_STAGE
#undef MATHX_TO_STR
#undef MATHX_TO_STR_STAGE
#undef MATHX_RT_ALL
#undef MATHX_MINOR_ALL
#undef MATHX_MINOR_RT_ALL
#undef MATHX_MAJOR_ALL
#undef MATHX_VERSION_STR


#endif // MATHX_VERSION_HPP
