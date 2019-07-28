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
 * @file bits/basic_vector.hpp
 * This is an internal header included by other header libraries. You
 * can use it by defining your datatype from it.
 * @example typedef basic_vector<int, 3> vec3i;
 * The above example will generate a datatype of 3 integer values.
 * When the size is within the range of 1-4 row direction swizzle will
 * be enabled. 
 */

#ifndef _CPPE_BASIC_VECTOR_HPP_
#define _CPPE_BASIC_VECTOR_HPP_

#if __cplusplus < 201103L
#error CPP-E Mat library requires at least C++11 std
#endif

#define ROW_VECTOR			0
#define COLUMN_VECTOR		1

#ifdef CPPE_DIRECTX
#define DEFAULT_DIRECTION	ROW_VECTOR
#else
#define DEFAULT_DIRECTION	COLUMN_VECTOR
#endif

#include <type_traits>
#include <cppe_type_traits.hpp>

/**
 * @class basic_vector
 * Basic template of a vector were T represent the typename, S the
 * size of the vector and D the direction, ROW_VECTOR for row and
 * COLUMN_VECTOR for column. The context of D is only valid in Matrices.
 */
namespace CPPE{
	template<typename T, size_t S, uint8_t D = DEFAULT_DIRECTION,
		bool = S && std::is_arithmetic<T>::value >
	class basic_vector;
}
#include <bits/swizzle.hpp>

namespace CPPE{
	template<typename T, size_t S, uint8_t D>
	class basic_vector<T, S, D, true> : public
		_detail::vector_base<T, S, D>{
	public:
		typedef T type;
		static const uint8_t direction = D;
		static const size_t length = S;
		
		basic_vector();
		
		basic_vector(const T v);
		
		template <typename... Ts>
		basic_vector(const Ts&... vs);
		
		template<typename T2, size_t S2>
		basic_vector& operator=(
		  const basic_vector<T2, S2, D> &v);
		
		T& operator[](size_t i);
		const T& operator[](size_t i) const;
		
		template<uint8_t D2 = !D>
		basic_vector<T, S, D2, true> transpose();
		
	private:
		class Terminator {};
		template <size_t offset, typename... Ts>
		void init(const T& v, const Ts&... vs);
		
		template <size_t offset, typename T1, size_t S1, typename... Ts>
		void init(const basic_vector<T1, S1, D>& v,
		  const Ts&... vs);
		
		template <size_t offset, typename T1, int8_t i1, int8_t i2,
		  int8_t i3, int8_t i4, typename... Ts>
		void init(const _detail::swizzle<T1, D, i1, i2, i3, i4>& v,
		  const Ts&... vs);
		
		template <size_t>
		void init(Terminator);
	};
}

#include <bits/basic_vector.tpp>
#include <bits/basic_vector_operators.tpp>

typedef CPPE::basic_vector<int, 4> vec4i;
typedef CPPE::basic_vector<int, 4, ROW_VECTOR> vec4ir;
typedef CPPE::basic_vector<int, 4, COLUMN_VECTOR> vec4ic;
typedef CPPE::basic_vector<float, 4> vec4;
typedef CPPE::basic_vector<float, 4, ROW_VECTOR> vec4r;
typedef CPPE::basic_vector<float, 4, COLUMN_VECTOR> vec4c;

#endif
