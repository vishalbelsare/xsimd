/***************************************************************************
* Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef XSIMD_NUMERICAL_CONSTANT_HPP
#define XSIMD_NUMERICAL_CONSTANT_HPP

#include <limits>
#include "../types/xsimd_types_include.hpp"

namespace xsimd
{

#define XSIMD_DEFINE_CONSTANT(NAME, SINGLE, DOUBLE)\
    template <class T>\
    constexpr T NAME() noexcept {\
        return T(NAME<typename T::value_type>());\
    }\
    template <>\
    constexpr float NAME<float>() noexcept {\
        return SINGLE;\
    }\
    template <>\
    constexpr double NAME<double>() noexcept {\
        return DOUBLE;\
    }

#define XSIMD_DEFINE_CONSTANT_HEX(NAME, SINGLE, DOUBLE)\
    template <class T>\
    constexpr T NAME() noexcept {\
        return T(NAME<typename T::value_type>());\
    }\
    template <>\
    constexpr float NAME<float>() noexcept {\
        return detail::caster32_t(SINGLE).f;\
    }\
    template <>\
    constexpr double NAME<double>() noexcept {\
        return detail::caster64_t(uint64_t(DOUBLE)).f;\
    }

XSIMD_DEFINE_CONSTANT(infinity, (std::numeric_limits<float>::infinity()), (std::numeric_limits<double>::infinity()))
XSIMD_DEFINE_CONSTANT(invlog_2, 1.442695040888963407359924681001892137426645954152986f, 1.442695040888963407359924681001892137426645954152986)
XSIMD_DEFINE_CONSTANT_HEX(invlog_2hi, 0x3fb8b000, 0x3ff7154765200000)
XSIMD_DEFINE_CONSTANT_HEX(invlog_2lo, 0xb9389ad4, 0x3de705fc2eefa200)
XSIMD_DEFINE_CONSTANT(invlog10_2, 3.32192809488736234787031942949f, 3.32192809488736234787031942949)
XSIMD_DEFINE_CONSTANT(log_2, 0.6931471805599453094172321214581765680755001343602553f, 0.6931471805599453094172321214581765680755001343602553)
XSIMD_DEFINE_CONSTANT_HEX(log_2hi, 0x3f318000, 0x3fe62e42fee00000)
XSIMD_DEFINE_CONSTANT_HEX(log_2lo, 0xb95e8083, 0x3dea39ef35793c76)
XSIMD_DEFINE_CONSTANT_HEX(log10_2hi, 0x3e9a0000, 0x3fd3440000000000)
XSIMD_DEFINE_CONSTANT_HEX(log10_2lo, 0x39826a14, 0x3ed3509f79fef312)
XSIMD_DEFINE_CONSTANT_HEX(logeps, 0xc17f1402, 0xc04205966f2b4f12)
XSIMD_DEFINE_CONSTANT(maxflint, 16777216.0f, 9007199254740992.0)
XSIMD_DEFINE_CONSTANT(maxlog, 88.3762626647949f, 709.78271289338400)
XSIMD_DEFINE_CONSTANT(maxlog2, 127.0f, 1023.)
XSIMD_DEFINE_CONSTANT(maxlog10, 38.23080825805664f, 308.2547155599167)
XSIMD_DEFINE_CONSTANT_HEX(mediumpi, 0x43490fdb, 0x412921fb54442d18)
XSIMD_DEFINE_CONSTANT(minlog, -88.3762626647949f, -708.3964185322641)
XSIMD_DEFINE_CONSTANT(minlog2, -127.0f, -1023.)
XSIMD_DEFINE_CONSTANT(minlog10, -37.89999771118164f, -308.2547155599167)
XSIMD_DEFINE_CONSTANT(minusinfinity, (-infinity<float>()), (-infinity<double>()))
XSIMD_DEFINE_CONSTANT(minuszero, -0.0f, -0.0)
XSIMD_DEFINE_CONSTANT_HEX(nan, 0xFFFFFFFF, 0xFFFFFFFFFFFFFFFF)
XSIMD_DEFINE_CONSTANT_HEX(pio_2lo, 0xb33bbd2e, 0x3c91a62633145c07)
XSIMD_DEFINE_CONSTANT_HEX(pio2, 0x3fc90fdb, 0x3ff921fb54442d18)
XSIMD_DEFINE_CONSTANT_HEX(pio2_1, 0x3fc90f80, 0x3ff921fb54400000)
XSIMD_DEFINE_CONSTANT_HEX(pio2_1t, 0x37354443, 0x3dd0b4611a626331)
XSIMD_DEFINE_CONSTANT_HEX(pio2_2, 0x37354400, 0x3dd0b4611a600000)
XSIMD_DEFINE_CONSTANT_HEX(pio2_2t, 0x2e85a308, 0x3ba3198a2e037073)
XSIMD_DEFINE_CONSTANT_HEX(pio2_3, 0x2e85a300, 0x3ba3198a2e000000)
XSIMD_DEFINE_CONSTANT_HEX(pio2_3t, 0x248d3132, 0x397b839a252049c1)
XSIMD_DEFINE_CONSTANT_HEX(pio4, 0x3f490fdb, 0x3fe921fb54442d18)
XSIMD_DEFINE_CONSTANT_HEX(signmask, 0x80000000, 0x8000000000000000)
XSIMD_DEFINE_CONSTANT(smallestposval, 1.1754944e-38f, 2.225073858507201e-308)
XSIMD_DEFINE_CONSTANT_HEX(sqrteps, 0x39b504f3, 0x3e50000000000000)
XSIMD_DEFINE_CONSTANT_HEX(twentypi, 0x427b53d1, 0x404f6a7a2955385e)
XSIMD_DEFINE_CONSTANT_HEX(twoopi, 0x3f22f983, 0x3fe45f306dc9c883)
XSIMD_DEFINE_CONSTANT_HEX(twotonmb, 8388608.0f, 4503599627370496.0)

#undef XSIMD_DEFINE_CONSTANT
#undef XSIMD_DEFINE_CONSTANT_HEX

    template <class T>
    constexpr T allbits() noexcept;

    template <class T>
    constexpr as_integer_t<T> maxexponent() noexcept;

    template <class T>
    constexpr int32_t nmb() noexcept;

    /**************************
     * allbits implementation *
     **************************/

    namespace detail
    {
        template <class T, bool = std::is_integral<T>::value>
        struct allbits_impl
        {
            static constexpr T get_value() noexcept
            {
                return T(~0);
            }
        };

        template <class T>
        struct allbits_impl<T, false>
        {
            static constexpr T get_value() noexcept
            {
                return nan<T>();
            }
        };
        
    }

    template <class T>
    constexpr T allbits() noexcept
    {
        return T(detail::allbits_impl<typename T::value_type>::get_value());
    }

    /******************************
     * maxexponent implementation *
     ******************************/

    template <class T>
    constexpr as_integer_t<T> maxexponent() noexcept
    {
        return as_integer_t<T>(maxexponent<typename T::value_type>());
    }

    template<>
    constexpr int32_t maxexponent<float>() noexcept
    {
        return 127;
    }

    template <>
    constexpr int64_t maxexponent<double>() noexcept
    {
        return 1023;
    }

    /**********************
     * nmb implementation *
     **********************/

    template <class T>
    constexpr int32_t nmb() noexcept
    {
        return nmb<typename T::value_type>();
    }

    template <>
    constexpr int32_t nmb<float>() noexcept
    {
        return 23;
    }

    template <>
    constexpr int32_t nmb<double>() noexcept
    {
        return 52;
    }

}

#endif
