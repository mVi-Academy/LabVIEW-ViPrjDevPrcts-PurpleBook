#ifndef _fundtypes_H
#define _fundtypes_H
/*
	(c) Copyright 1990-2020 by National Instruments Corp.
	All rights reserved.


	fundtypes.h - Fundamental data types.

	Header intended for use by C and C++. No C++ style (//) comments.
*/

#include "platdefines.h"

/*The MSVC compiler does not define all the C99 types, so define a subset here*/
#if MSWin
#  if (defined(_CVI_) && (_CVI_ >= 910)) || (_MSC_VER >= 1900 && (!defined(USE_C99_TYPES) || USE_C99_TYPES == 1))
    /* If we're compiling using CVI, just use their C99 types. */
#   include <stdint.h>
#  else
     /* If the C99 types have been defined already by stdint.h, don't define them again. */
#    if !defined(_STDINT_H_) && !defined(_STDINT_H) && !defined(_STDINT)
       typedef signed char     int8_t;
       typedef unsigned char   uint8_t;
       typedef short           int16_t;
       typedef unsigned short  uint16_t;
       typedef int             int32_t;
       typedef unsigned int    uint32_t;

#      if defined(_MSC_VER) && (_MSC_VER < 1300)
         typedef long            intptr_t;
         typedef unsigned long   uintptr_t;
#      endif /* defined(_MSC_VER) && (_MSC_VER < 1300) */
#    endif /* !defined(_STDINT_H_) && !defined(_STDINT_H) && !defined(_STDINT) */
#  endif /* defined(_CVI_) && (_CVI_ >= 910) */
#else

#   ifndef __STDC_LIMIT_MACROS
#       define __STDC_LIMIT_MACROS /*for enabling the INT8_MIN, etc. macros declared in stdint.h */
#   endif /* __STDC_LIMIT_MACROS */

#   include <stdint.h>

#endif /*MSWin*/

#ifdef USE_C99_TYPES

#  ifndef _NI_int8_DEFINED_
    #define _NI_int8_DEFINED_
    typedef int8_t              int8;
#  endif
#  ifndef _NI_uInt8_DEFINED_
    #define _NI_uInt8_DEFINED_
    typedef uint8_t             uInt8;
#  endif
#  ifndef _NI_uChar_DEFINED_
    #define _NI_uChar_DEFINED_
    typedef uInt8               uChar;
#  endif
#  ifndef _NI_int16_DEFINED_
    #define _NI_int16_DEFINED_
    typedef int16_t             int16;
#  endif
#  ifndef _NI_uInt16_DEFINED_
    #define _NI_uInt16_DEFINED_
    typedef uint16_t            uInt16;
#  endif
#  ifndef _NI_int32_DEFINED_
    #define _NI_int32_DEFINED_
    typedef int32_t             int32;
#  endif
#  ifndef _NI_uInt32_DEFINED_
    #define _NI_uInt32_DEFINED_
    typedef uint32_t            uInt32;
#  endif
#  ifndef _NI_float32_DEFINED_
    #define _NI_float32_DEFINED_
    typedef float               float32;
#  endif
#  ifndef _NI_float64_DEFINED_
    #define _NI_float64_DEFINED_
    typedef double              float64;
#  endif

#endif /* USE_C99_TYPES */

#include "lv_prolog.h"

#if Mac || Palm/*##############################################################*/

#   ifndef USE_C99_TYPES
#     ifndef _NI_int8_DEFINED_
        #define _NI_int8_DEFINED_
        typedef char                int8;
#     endif
#     ifndef _NI_uInt8_DEFINED_
        #define _NI_uInt8_DEFINED_
        typedef unsigned char       uInt8;
#     endif
#     ifndef _NI_uChar_DEFINED_
        #define _NI_uChar_DEFINED_
        typedef uInt8               uChar;
#     endif
#     ifndef _NI_int16_DEFINED_
        #define _NI_int16_DEFINED_
        typedef short               int16;
#     endif
#     ifndef _NI_uInt16_DEFINED_
        #define _NI_uInt16_DEFINED_
        typedef unsigned short      uInt16;
#     endif
#     if (ProcessorType == kX64)
#       ifndef _NI_int32_DEFINED_
            #define _NI_int32_DEFINED_
            typedef int                 int32;
#       endif
#       ifndef _NI_uInt32_DEFINED_
            #define _NI_uInt32_DEFINED_
            typedef unsigned int        uInt32;
#       endif
#     else
#       ifndef _NI_int32_DEFINED_
            #define _NI_int32_DEFINED_
            typedef long                 int32;
#       endif
#        ifndef _NI_uInt32_DEFINED_
            #define _NI_uInt32_DEFINED_
            typedef unsigned long        uInt32;
#        endif
#     endif
#     ifndef _NI_float32_DEFINED_
        #define _NI_float32_DEFINED_
        typedef float               float32;
#     endif
#     ifndef _NI_float64_DEFINED_
        #define _NI_float64_DEFINED_
        typedef double              float64;
#     endif
#   endif /* USE_C99_TYPES */

#   if (ProcessorType == kM68000) || ((ProcessorType == kPPC) && (Compiler == kMPW))
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef long double floatExt;
#     endif
#       define ExtHiLo 0
#       define CompilerSupportsExt 1
#   elif MacOSX && (ProcessorType == kPPC)
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef double floatExt;
#     endif
#     define CompilerSupportsExt 1
#   elif MacX86 || MacX64
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef struct { /* force GCC to make this struct 10 bytes */
            int32   mlo __attribute__((packed,aligned(2)));
            int32   mhi __attribute__((packed,aligned(2)));
            int16   e __attribute__((packed,aligned(2)));
        } floatExt;
#     endif
#     define CompilerSupportsExt 0
#   else
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef struct {
            double hi;
            double lo;
        } floatExt;
#     endif
#     define ExtHiLo 1
#     define CompilerSupportsExt 1
#   endif

#    define CompilerSupportsInt64 1
#    ifndef USE_C99_TYPES
#     ifndef _NI_int64_DEFINED_
        #define _NI_int64_DEFINED_
        typedef long long           int64;
#     endif
#     ifndef _NI_uInt64_DEFINED_
        #define _NI_uInt64_DEFINED_
        typedef unsigned long long  uInt64;
#     endif
#    endif /* USE_C99_TYPES */

#elif Unix /*###########################################################*/

#   ifndef USE_C99_TYPES
#     ifndef _NI_int8_DEFINED_
        #define _NI_int8_DEFINED_
        typedef signed char         int8;
#     endif
#     ifndef _NI_uInt8_DEFINED_
        #define _NI_uInt8_DEFINED_
        typedef unsigned char       uInt8;
#     endif
#     ifndef _NI_uChar_DEFINED_
        #define _NI_uChar_DEFINED_
        typedef uInt8               uChar;
#     endif
#     ifndef _NI_int16_DEFINED_
        #define _NI_int16_DEFINED_
        typedef short int           int16;
#     endif
#     ifndef _NI_uInt16_DEFINED_
        #define _NI_uInt16_DEFINED_
        typedef unsigned short int  uInt16;
#     endif
#     ifndef _NI_int32_DEFINED_
        #define _NI_int32_DEFINED_
        typedef int                 int32;
#     endif
#     ifndef _NI_uInt32_DEFINED_
        #define _NI_uInt32_DEFINED_
        typedef unsigned int        uInt32;
#     endif
#     ifndef _NI_float32_DEFINED_
        #define _NI_float32_DEFINED_
        typedef float               float32;
#     endif
#     ifndef _NI_float64_DEFINED_
        #define _NI_float64_DEFINED_
        typedef double              float64;
#     endif
#   endif /* USE_C99_TYPES */

#   define ExtHiLo 0
#   if ProcessorType==kPARISC || ProcessorType==kMIPS || (Linux && PowerPC)
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef double          floatExt;
#     endif
#     define CompilerSupportsExt 1
#   elif ProcessorType==kX86 || ProcessorType==kX64
#       if (Compiler==kGCC)
#         ifndef _NI_floatExt_DEFINED_
            #define _NI_floatExt_DEFINED_
            typedef struct { /* force GCC to make this struct 10 bytes */
                int32   mlo __attribute__((packed,aligned(2)));
                int32   mhi __attribute__((packed,aligned(2)));
                int16   e __attribute__((packed,aligned(2)));
            } floatExt;
#         endif
#       else
#         ifndef _NI_floatExt_DEFINED_
            #define _NI_floatExt_DEFINED_
            typedef struct {
                int32   mlo;
                int32   mhi;
                int16   e;
            } floatExt;
#         endif
#       endif
#       define CompilerSupportsExt 0
#   elif ProcessorType == kARM
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef double          floatExt;
#     endif
#     define CompilerSupportsExt 1
#   else
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef long double     floatExt;
#     endif
#     define CompilerSupportsExt 1
#   endif

#   if OpSystem==kPowerUnix || (OpSystem == kHPUX && defined(__cplusplus))
#       define CompilerSupportsInt64 0
#         ifndef _NI_int64_DEFINED_
            #define _NI_int64_DEFINED_
            typedef struct {
                int32   hi, lo;
            } int64;
#         endif
#         ifndef _NI_uInt64_DEFINED_
            #define _NI_uInt64_DEFINED_
            typedef struct {
                int32   hi, lo;
            } uInt64;
#         endif
#   else
#       define CompilerSupportsInt64 1
#       ifndef USE_C99_TYPES
#         ifndef _NI_int64_DEFINED_
            #define _NI_int64_DEFINED_
            typedef long long       int64;
#         endif
#         ifndef _NI_uInt64_DEFINED_
            #define _NI_uInt64_DEFINED_
            typedef unsigned long long  uInt64;
#         endif
#       endif /* USE_C99_TYPES */
#   endif /*OpSystem==kPowerUnix || (OpSystem == kHPUX && defined(__cplusplus))*/

#elif MSWin /*##########################################################*/

#   ifndef USE_C99_TYPES
#     ifndef _NI_int8_DEFINED_
        #define _NI_int8_DEFINED_
        typedef char                int8;
#     endif
#     ifndef _NI_uInt8_DEFINED_
        #define _NI_uInt8_DEFINED_
        typedef unsigned char       uInt8;
#     endif
#     ifndef _NI_uChar_DEFINED_
        #define _NI_uChar_DEFINED_
        typedef uInt8               uChar;
#     endif
#     ifndef _NI_int16_DEFINED_
        #define _NI_int16_DEFINED_
        typedef short int           int16;
#     endif
#     ifndef _NI_uInt16_DEFINED_
        #define _NI_uInt16_DEFINED_
        typedef unsigned short int  uInt16;
#     endif
#     ifndef _NI_int32_DEFINED_
        #define _NI_int32_DEFINED_
        typedef long                int32;
#     endif
#     ifndef _NI_uInt32_DEFINED_
        #define _NI_uInt32_DEFINED_
        typedef unsigned long       uInt32;
#     endif
#     ifndef _NI_float32_DEFINED_
        #define _NI_float32_DEFINED_
        typedef float               float32;
#     endif
#     ifndef _NI_float64_DEFINED_
        #define _NI_float64_DEFINED_
        typedef double              float64;
#     endif

#   endif /* USE_C99_TYPES */

#   if (defined(_NI_VC_) || defined(_NI_SC_) || defined(_NI_BC_)) && !(defined(_CVI_) && (_CVI_ >= 910))
#       define CompilerSupportsInt64 0
#       ifndef _NI_int64_DEFINED_
          #define _NI_int64_DEFINED_
          typedef struct {
              int32   hi, lo;
          } int64;
#       endif
#       ifndef _NI_uInt64_DEFINED_
          #define _NI_uInt64_DEFINED_
          typedef struct {
              int32   hi, lo;
          } uInt64;
#       endif
#   else
#       define CompilerSupportsInt64 1
#       ifndef USE_C99_TYPES
#           if Compiler==kMetroWerks
#             ifndef _NI_int64_DEFINED_
                #define _NI_int64_DEFINED_
                typedef long long               int64;
#             endif
#             ifndef _NI_uInt64_DEFINED_
                #define _NI_uInt64_DEFINED_
                typedef unsigned long long      uInt64;
#             endif
#           else
#             ifndef _NI_int64_DEFINED_
                #define _NI_int64_DEFINED_
                typedef __int64                 int64;
#             endif
#             ifndef _NI_uInt64_DEFINED_
                #define _NI_uInt64_DEFINED_
                typedef unsigned __int64        uInt64;
#             endif
#           endif
#       endif /* USE_C99_TYPES */
#   endif

#   define ExtHiLo 0
#   if ProcessorType == kX64
#       pragma pack(push)
#       pragma pack(2)
#   endif
#     ifndef _NI_floatExt_DEFINED_
        #define _NI_floatExt_DEFINED_
        typedef struct {
            int32   mlo;
            int32   mhi;
            int16   e;
        } floatExt;
#     endif
#       define CompilerSupportsExt 0
#   if ProcessorType == kX64
#       pragma pack(pop)
#   endif

#elif Vdk /*##########################################################*/

#   ifndef USE_C99_TYPES
#     ifndef _NI_int8_DEFINED_
        #define _NI_int8_DEFINED_
        typedef signed char         int8;
#     endif
#     ifndef _NI_uInt8_DEFINED_
        #define _NI_uInt8_DEFINED_
        typedef unsigned char       uInt8;
#     endif
#     ifndef _NI_uChar_DEFINED_
        #define _NI_uChar_DEFINED_
        typedef uInt8               uChar;
#     endif
#     ifndef _NI_int16_DEFINED_
        #define _NI_int16_DEFINED_
        typedef short int           int16;
#     endif
#     ifndef _NI_uInt16_DEFINED_
        #define _NI_uInt16_DEFINED_
        typedef unsigned short int  uInt16;
#     endif
#     ifndef _NI_int32_DEFINED_
        #define _NI_int32_DEFINED_
        typedef int                 int32;
#     endif
#     ifndef _NI_uInt32_DEFINED_
        #define _NI_uInt32_DEFINED_
        typedef unsigned int        uInt32;
#     endif
#     ifndef _NI_float32_DEFINED_
        #define _NI_float32_DEFINED_
        typedef float               float32;
#     endif
#     ifndef _NI_float64_DEFINED_
        #define _NI_float64_DEFINED_
        typedef double              float64;
#     endif
#   endif /* USE_C99_TYPES */

#  ifndef _NI_floatExt_DEFINED_
    #define _NI_floatExt_DEFINED_
    typedef double              floatExt;
#  endif

#   define CompilerSupportsInt64 1
#   ifndef USE_C99_TYPES
#     ifndef _NI_int64_DEFINED_
        #define _NI_int64_DEFINED_
        typedef long long     int64;
#     endif
#     ifndef _NI_uInt64_DEFINED_
        #define _NI_uInt64_DEFINED_
        typedef unsigned long long uInt64;
#     endif
#   endif /* USE_C99_TYPES */

#elif Rtx /*##########################################################*/

#  ifndef _NI_int8_DEFINED_
	#define _NI_int8_DEFINED_
	typedef signed char			int8;
#  endif
#  ifndef _NI_uInt8_DEFINED_
	#define _NI_uInt8_DEFINED_
	typedef unsigned char		uInt8;
#  endif
#  ifndef _NI_uChar_DEFINED_
	#define _NI_uChar_DEFINED_
	typedef uInt8				uChar;
#  endif
#  ifndef _NI_int16_DEFINED_
	#define _NI_int16_DEFINED_
	typedef short int			int16;
#  endif
#  ifndef _NI_uInt16_DEFINED_
	#define _NI_uInt16_DEFINED_
	typedef unsigned short int	uInt16;
#  endif
#  ifndef _NI_int32_DEFINED_
	#define _NI_int32_DEFINED_
	typedef int					int32;
#  endif
#  ifndef _NI_uInt32_DEFINED_
	#define _NI_uInt32_DEFINED_
	typedef unsigned int		uInt32;
#  endif
#  ifndef _NI_float32_DEFINED_
	#define _NI_float32_DEFINED_
	typedef float				float32;
#  endif
#  ifndef _NI_float64_DEFINED_
	#define _NI_float64_DEFINED_
	typedef double				float64;
#  endif

#  ifndef _NI_floatExt_DEFINED_
	#define _NI_floatExt_DEFINED_
	typedef double              floatExt;
#  endif
	#define CompilerSupportsInt64 1
#  ifndef _NI_int64_DEFINED_
	#define _NI_int64_DEFINED_
	typedef long long int64;
#  endif
#  ifndef _NI_uInt64_DEFINED_
	#define _NI_uInt64_DEFINED_
	typedef unsigned long long uInt64;
#  endif

#endif

#ifndef EXTCODE_CMPLX_TYPES
#define EXTCODE_CMPLX_TYPES

#ifndef _NI_cmplx64_DEFINED_
#define _NI_cmplx64_DEFINED_
/** @brief Complex single-precision floating point number. */
typedef struct {
	float32 re;
	float32 im;
} cmplx64;
#endif

#ifndef _NI_cmplx128_DEFINED_
#define _NI_cmplx128_DEFINED_
/** @brief Complex double-precision floating point number. */
typedef struct {
	float64 re;
	float64 im;
} cmplx128;
#endif

#ifndef _NI_cmplxExt_DEFINED_
#define _NI_cmplxExt_DEFINED_
/** @brief Complex extended-precision floating point number. */
typedef struct {
	floatExt re;
	floatExt im;
} cmplxExt;
#endif

#endif /* EXTCODE_CMPLX_TYPES */

#include "lv_epilog.h"

#ifndef _NI_Bool32_DEFINED_
#define _NI_Bool32_DEFINED_
/* Bool32 is based on our own int32 type. */
typedef int32       Bool32;
#endif
#undef  TRUE
#undef  FALSE
#define TRUE        1
#define FALSE       0

/* For making void* pts that are distinguishable. */
#define NIPrivatePtr(x) typedef struct x ## _t { void *p; } *x

/* Minimum of signed integral types.  */
#ifndef INT8_MIN
#  define INT8_MIN     (-128)
#endif /* INT8_MIN */
#ifndef INT16_MIN
#  define INT16_MIN    (-32767-1)
#endif /* INT16_MIN */
#ifndef INT32_MIN
#  define INT32_MIN    (-2147483647-1)
#endif /* INT32_MIN */
/* Maximum of signed integral types.  */
#ifndef INT8_MAX
#  define INT8_MAX     (127)
#endif /* INT8_MAX */
#ifndef INT16_MAX
#  define INT16_MAX    (32767)
#endif /* INT16_MAX */
#ifndef INT32_MAX
#  define INT32_MAX    (2147483647)
#endif /* INT32_MAX */

/* Maximum of unsigned integral types.  */
#ifndef UINT8_MAX
#  define UINT8_MAX    (255)
#endif /* UINT8_MAX */
#ifndef UINT16_MAX
#  define UINT16_MAX   (65535)
#endif /* UINT16_MAX */
#ifndef UINT32_MAX
#  define UINT32_MAX   (4294967295U)
#endif /* UINT32_MAX */

/* Limits for fundamental types. */
#ifndef uInt8_MAX
#define uInt8_MAX       UINT8_MAX
#endif
#ifndef uInt16_MAX
#define uInt16_MAX      UINT16_MAX
#endif
#ifndef uInt32_MAX
#define uInt32_MAX      UINT32_MAX
#endif

#ifndef int8_MIN
#define int8_MIN        INT8_MIN
#endif
#ifndef int8_MAX
#define int8_MAX        INT8_MAX
#endif
#ifndef int16_MIN
#define int16_MIN       INT16_MIN
#endif
#ifndef int16_MAX
#define int16_MAX       INT16_MAX
#endif
#ifndef int32_MIN
#define int32_MIN       INT32_MIN
#endif
#ifndef int32_MAX
#define int32_MAX       INT32_MAX
#endif

#ifndef float32_MAX
#define float32_MAX     3.402823466e+38F
#endif
#ifndef float64_MAX
#define float64_MAX     1.7976931348623158e+308
#endif

#if CompilerSupportsInt64
#  if MSWin
/*   If the C99 types have been defined already by stdint.h, don't define them again. */
#    if !defined(_STDINT_H_) && !defined(_STDINT_H)
#       ifdef _MSC_VER
            typedef __int64                 int64_t;
            typedef unsigned __int64        uint64_t;
#       else
            typedef long long int           int64_t;
            typedef unsigned long long int  uint64_t;
#       endif /* _MSC_VER */
#    endif /* !defined(_STDINT_H_) && !defined(_STDINT_H) */
#  endif /* MSWin */
#  ifdef USE_C99_TYPES
#     ifndef _NI_int64_DEFINED_
        #define _NI_int64_DEFINED_
        typedef int64_t     int64;
#     endif
#     ifndef _NI_uInt64_DEFINED_
        #define _NI_uInt64_DEFINED_
        typedef uint64_t    uInt64;
#     endif
#  endif /* USE_C99_TYPES */

/* 64-bit integer constants */
#   if MSWin && defined(_MSC_VER) && (_MSC_VER < 1300)
/* Before VC 7.1, we need to use this special way of adorning constants */
#       define I64Const(n) n##i64
#       define U64Const(n) n##ui64
#   else
#       define I64Const(n) n##LL
#       define U64Const(n) n##ULL
#   endif

#   ifndef INT64_MIN
#       define INT64_MIN    ( I64Const(-9223372036854775807) - 1)
#   endif /* INT64_MIN */
#   ifndef INT64_MAX
#       define INT64_MAX    I64Const(9223372036854775807)
#   endif /* INT64_MAX */
#   ifndef UINT64_MAX
#       define UINT64_MAX   U64Const(0xffffffffffffffff)
#   endif /* UINT64_MAX */

#ifndef int64_ZERO
#   define int64_ZERO   I64Const(0)
#endif
#ifndef uInt64_ZERO
#   define uInt64_ZERO  U64Const(0)
#endif
#ifndef int64_MIN
#   define int64_MIN    INT64_MIN
#endif
#ifndef int64_MAX
#   define int64_MAX    INT64_MAX
#endif
#ifndef uInt64_MAX
#   define uInt64_MAX   UINT64_MAX
#endif

#else /* CompilerSupportsInt64=0 */
#   if MSWin
/* Go ahead and give these symbols definition. */
       typedef int64         int64_t;
       typedef uInt64        uint64_t;
#   endif
#endif

#ifndef _NI_HRESULT_DEFINED_
#   define _NI_HRESULT_DEFINED_
#   if MSWin
        typedef long    HRESULT;
        typedef long    SCODE;
#   else
        typedef int32   HRESULT;
        typedef int32   SCODE;
#   endif /* MSWin */
#endif /*_NI_HRESULT_DEFINED_*/

#ifndef Unused
/* The macro Unused can be used to avoid compiler warnings for
unused parameters or locals. */
#   ifdef __cplusplus
/* This implementation of Unused is safe for const parameters. */
#       define Unused(var_or_param)    _Unused(reinterpret_cast<const void*>(&var_or_param))
        inline void _Unused(const void *) {}
#   elif MSWin
/* This implementation of Unused is not safe for const parameters. */
#       define Unused(var_or_param)    var_or_param=var_or_param
#   else
#       define Unused(var_or_param)
#   endif
#endif /* Unused */

#ifndef ConstNotEq
/* The ConstNotEq macro can be used to avoid
"expression is constant" warnings in "if"
statements -- only avoids the warning if you
compile with a C++ compiler. */
#   ifdef __cplusplus
        inline bool _ConstNotEq(const int32 a, const int32 b) { return a != b; }
#       define ConstNotEq(a, b) _ConstNotEq(a, b)
#   else
#       define ConstNotEq(a, b) (a != b)
#   endif /* __cplusplus */
#endif /* ConstNotEq */

#ifndef ConstEvalBool
/* The ConstEvalBool macro can be used to avoid
"expression is constant" warnings in "if"
statements -- only avoids the warning if you
compile with a C++ compiler. */
#   ifdef __cplusplus
        inline bool _ConstEvalBool(const bool a) { return a; }
#       define ConstEvalBool(a) _ConstEvalBool(a)
#   else
#       define ConstEvalBool(a) (a)
#   endif /* __cplusplus */
#endif /* ConstEvalBool */

/* Get the system definitions for
size_t, NULL, ptrdiff_t, offsetof, wchar_t */

#ifdef _CVI_
#include <cvidef.h>
#endif /* _CVI_ */

#include <stddef.h>

/* Macros to convert from pointers to non-pointer types.
On 64-bit systems, these will truncate the values to 32 bits. */
#define PtrToUInt32(p)  ((uInt32)(uintptr_t)p)

/* Localize the warnings for float comparison to one place
see http://www.codeguru.com/forum/showthread.php?t=323835 */
#ifdef __cplusplus
	#include <math.h> /* fabs */
	#include <float.h> /* DBL_EPSILON */
	enum FloatComparisonMethod {
		FloatComparisonExact,
		FloatComparisonWithinEpsilon
	};
	namespace LVFloats {
		inline bool Equal64(const float64 &f1, const float64 &f2, FloatComparisonMethod method= FloatComparisonExact) {
			if(FloatComparisonWithinEpsilon == method) {
				return fabs(f1 - f2) < DBL_EPSILON;
			}
			return (f1 <= f2) && (f1 >= f2); /* f1 == f2; */
		}
		inline bool Equal32(const float32 &f1, const float32 &f2, FloatComparisonMethod method= FloatComparisonExact) {
#if !VxWorks
			if(FloatComparisonWithinEpsilon == method) {
				return fabsf(f1 - f2) < FLT_EPSILON;
			}
#endif /* !VxWorks */
			return (f1 <= f2) && (f1 >= f2); /* f1 == f2; */
		}
		template <typename T>
		inline bool Equal(const T &v1, const T &v2, FloatComparisonMethod /* method */ = FloatComparisonExact) {
			return (v1 <= v2) && (v1 >= v2); /* v1 == v2; */
		}
		template <>
		inline bool Equal<float64>(const float64 &v1, const float64 &v2, FloatComparisonMethod method) {
			return Equal64(v1, v2, method);
		}
		template <>
		inline bool Equal<float32>(const float32 &v1, const float32 &v2, FloatComparisonMethod method) {
			return Equal32(v1, v2, method);
		}
	} /* namespace LVFloats */
#endif /* __cplusplus */

#endif /* _fundtypes_H */
