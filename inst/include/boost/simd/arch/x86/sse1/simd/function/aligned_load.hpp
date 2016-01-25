//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from an aligned pointer
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bd::sse_
                          , bd::pointer<bd::scalar_<bd::single_<Pointer>>>
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::sse_>>
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm_load_ps(p);
    }
  };

} } }

#endif
