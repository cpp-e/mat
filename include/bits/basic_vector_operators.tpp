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
 * @file bits/basic_vector_operators.tpp
 * This is an internal header implementation. Do not attempt to use it
 * directly.
 */

#ifndef _CPPE_BASIC_VECTOR_OPERATORS_TPP_
#define _CPPE_BASIC_VECTOR_OPERATORS_TPP_

// assignment operators
//operator +=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator+=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] += rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator+=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] += rhs;
	return lhs;
}

//operator -=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator-=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] -= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator-=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] -= rhs;
	return lhs;
}

//operator *=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator*=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] *= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator*=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] *= rhs;
	return lhs;
}

//operator /=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator/=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] /= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator/=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] /= rhs;
	return lhs;
}

//operator %=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator%=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] %= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator%=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] %= rhs;
	return lhs;
}

//operator &=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator&=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] &= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator&=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] &= rhs;
	return lhs;
}

//operator |=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator|=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] |= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator|=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] |= rhs;
	return lhs;
}

//operator ^=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator^=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] ^= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator^=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] ^= rhs;
	return lhs;
}

//operator <<=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator<<=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] <<= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator<<=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] <<= rhs;
	return lhs;
}

//operator >>=
template <typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
CPPE::basic_vector<T1, S1, D>& operator>>=(
  CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	size_t i = 0;
	for(; i < S1 && i < S2; ++i)
		lhs[i] >>= rhs[i];
	return lhs;
}

template <typename T1, typename T2, size_t S, uint8_t D>
  inline
CPPE::basic_vector<
  typename std::enable_if<std::is_arithmetic<T2>::value, T1>::type,
  S, D>& operator>>=(CPPE::basic_vector<T1, S, D> &lhs, const T2 &rhs){
	size_t i = 0;
	for(; i < S; ++i)
		lhs[i] >>= rhs;
	return lhs;
}

// unary operators
// (+) operator
template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D> operator+(
  const CPPE::basic_vector<T, S, D> &lhs){
	return lhs;
}

// (-) operator
template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D> operator-(
  const CPPE::basic_vector<T, S, D> &lhs){
	CPPE::basic_vector<T, S, D> tmp;
	for(size_t i = 0; i < S; ++i)
		tmp[i] = -lhs[i];
	return tmp;
}

// ~ operator
template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D> operator~(
  const CPPE::basic_vector<T, S, D> &lhs){
	CPPE::basic_vector<T, S, D> tmp;
	for(size_t i = 0; i < S; ++i)
		tmp[i] = ~lhs[i];
	return tmp;
}

// increment/decrement operators
// ++ operator
template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D>& operator++(
  CPPE::basic_vector<T, S, D> &lhs){
	for(size_t i = 0; i < S; ++i)
		++lhs[i];
	return lhs;
}

template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D> operator++(
  CPPE::basic_vector<T, S, D> &lhs, int){
	CPPE::basic_vector<T, S, D> tmp(lhs);
	++lhs;
	return tmp;
}

// -- operator
template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D>& operator--(
  CPPE::basic_vector<T, S, D> &lhs){
	for(size_t i = 0; i < S; ++i)
		--lhs[i];
	return lhs;
}

template<typename T, size_t S, uint8_t D> inline
CPPE::basic_vector<T, S, D> operator--(
  CPPE::basic_vector<T, S, D> &lhs, int){
	CPPE::basic_vector<T, S, D> tmp(lhs);
	--lhs;
	return tmp;
}

// equality operators
// operator ==
template<typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
bool operator==(const CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	if(S1 != S2)
		return false;
	for(size_t i = 0; i < S1; ++i)
		if(lhs[i] != rhs[i])
			return false;
	return true;
}

// operator !=
template<typename T1, typename T2, size_t S1, size_t S2,
  uint8_t D> inline
bool operator!=(const CPPE::basic_vector<T1, S1, D> &lhs,
  const CPPE::basic_vector<T2, S2, D> &rhs){
	return !(lhs == rhs);
}

// arithmetic operators
// + operator

// - operator

// * operator

// / operator

// % operator

// | operator

// & operator

// ^ operator

// >> operator

// << operator

#include <ostream>
template<typename T, typename U, size_t S, uint8_t D> inline
std::basic_ostream<T,std::char_traits<T> >& operator<<(
  std::basic_ostream<T,std::char_traits<T> > &os,
  const CPPE::basic_vector<U, S, D> &v){
	os << '(';
	size_t i = 0;
	for(; i < S - 1; ++i){
		os << (CPPE::is_char<U>::value ? (int)v[i] : v[i]) << ", ";
	}
	os << (CPPE::is_char<U>::value ? (int)v[i] : v[i]) << ')';
	return os;
}

template<typename T, typename U, uint8_t D, int8_t i1, int8_t i2,
  int8_t i3, int8_t i4> inline
std::basic_ostream<T,std::char_traits<T> >& operator<<(
  std::basic_ostream<T,std::char_traits<T> > &os,
  const CPPE::_detail::swizzle<U, D, i1, i2, i3, i4> &v){
	return os << CPPE::basic_vector<U, v.length, D>(v);
}

#endif
