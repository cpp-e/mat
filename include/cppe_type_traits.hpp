//======================================================================
// CPP-E Mat 1.0 - https://github.com/cpp-e/mat
//----------------------------------------------------------------------
// Components for manipulating matrices
//
// Copyright (C) 2019 CPP-E
//
// This file is part of CPP-E Martix library. It is free to use,
// distribute, and/or modify it under the terms of GNU General Public
// License version 3.
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.

/**
 * @file cppe_type_traits.hpp
 * This is a type trait library to handel any special traits required by
 * Matrix library.
 */

#ifndef _CPPE_TYPE_TRAITS_HPP_
#define _CPPE_TYPE_TRAITS_HPP_

#include <stdint.h>
#include <stddef.h>

namespace CPPE{
	template <typename T>
	struct is_char : std::integral_constant<bool,
	  std::is_same<char, typename std::remove_cv<
	    typename std::make_signed<T>::type>::type>::value ||
	  std::is_same<char16_t, typename std::remove_cv<
	    typename std::make_signed<T>::type>::type>::value ||
	  std::is_same<char32_t, typename std::remove_cv<
	    typename std::make_signed<T>::type>::type>::value ||
	  std::is_same<wchar_t, typename std::remove_cv<
	    typename std::make_signed<T>::type>::type>::value >
	{};
	
	template <typename T, typename U>
	struct eval_type : std::enable_if<
	  (std::is_arithmetic<T>::value && std::is_arithmetic<T>::value),
	  typename std::conditional<(std::is_floating_point<T>::value &&
	    std::is_floating_point<U>::value),
	    typename std::conditional<(sizeof(T) > sizeof(U)), T, U>::type,
	    typename std::conditional<std::is_floating_point<T>::value, T,
	      typename std::conditional<std::is_floating_point<U>::value, U,
	        typename std::conditional<(sizeof(T) < sizeof(int) &&
	          sizeof(U) < sizeof(int)), int, typename std::conditional<
	            (sizeof(T) > sizeof(U)), T, typename std::conditional<
	              (sizeof(T) == sizeof(U) &&
	              std::is_unsigned<T>::value), T, U>::type>::type
	        >::type>::type>::type>::type>
	{};
}

#endif
