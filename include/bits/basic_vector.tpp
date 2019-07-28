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
 * @file bits/basic_vector.tpp
 * This is an internal header implementation. Do not attempt to use it
 * directly.
 */

#ifndef _CPPE_BASIC_VECTOR_TPP_
#define _CPPE_BASIC_VECTOR_TPP_

namespace CPPE{
	template <typename T, size_t S, uint8_t D>
	basic_vector<T, S, D, true>::basic_vector(){
		for(size_t i = 0; i < S; ++i)
			this->data[i] = 0;
	}
	
	template <typename T, size_t S, uint8_t D>
	basic_vector<T, S, D, true>::basic_vector(const T v){
		for(size_t i = 0; i < S; ++i)
			this->data[i] = v;
	}

	template <typename T, size_t S, uint8_t D>
	template <typename... Ts>
	basic_vector<T, S, D, true>::basic_vector(const Ts&... vs){
		init<0>(vs..., Terminator{});
	}
	
	template <typename T, size_t S, uint8_t D>
	template <typename T2, size_t S2>
	basic_vector<T, S, D, true>& basic_vector<T, S, D, true>
	  ::operator= (const basic_vector<T2, S2, D> &v){
		size_t ln = S > S2 ? S2 : S;
		size_t i = 0;
		for(; i < ln; ++i)
			this->data[i] = v[i];
		for(; i < S; ++i)
			this->data[i] = 0;
		return *this;
	}
	
	template <typename T, size_t S, uint8_t D>
	T& basic_vector<T, S, D, true>::operator[](size_t i){
		return this->data[i];
	}

	template <typename T, size_t S, uint8_t D>
	const T& basic_vector<T, S, D, true>::operator[](size_t i) const{
		return this->data[i];
	}
	
	template <typename T, size_t S, uint8_t D>
	template<uint8_t D2>
	basic_vector<T, S, D2, true> basic_vector<T, S, D, true>
	  ::transpose(){
		basic_vector<T, S, D2, true> tmpV;
		for(size_t i = 0; i < S; ++i)
			tmpV.data[i] = this->data[i];
		return tmpV;
	}
	
	template <typename T, size_t S, uint8_t D>
	template <size_t offset, typename... Ts>
	void basic_vector<T, S, D, true>::init(const T& v, const Ts&... vs){
		if(offset >= S)
			return;
		this->data[offset] = v;
		init<offset + 1>(vs...);
	}

	template <typename T, size_t S, uint8_t D>
	template <size_t offset, typename T1, size_t S1,
	  typename... Ts>
	void basic_vector<T, S, D, true>::init(
	  const basic_vector<T1, S1, D>& v, const Ts&... vs){
		if(offset >= S)
			return;
		size_t ln = (S - offset) > S1 ? S1 : (S - offset);
		size_t i = 0;
		for(; i < ln; ++i)
			this->data[i + offset] = v[i];
		init<offset + S1>(vs...);
	}
	
	template <typename T, size_t S, uint8_t D>
	template <size_t offset, typename T1, int8_t i1, int8_t i2,
	  int8_t i3, int8_t i4, typename... Ts>
	void basic_vector<T, S, D, true>::init(
	  const _detail::swizzle<T1, D, i1, i2, i3, i4>& v,
	  const Ts&... vs){
		if(offset >= S)
			return;
		basic_vector<T1, v.length, D> tmp = v;
		size_t ln = (S - offset) > tmp.length ? tmp.length :
		  (S - offset);
		size_t i = 0;
		for(; i < ln; ++i)
			this->data[i + offset] = tmp[i];
		init<offset + tmp.length>(vs...);
	}

	template <typename T, size_t S, uint8_t D>
	template <size_t offset>
	void basic_vector<T, S, D, true>::init(
	  basic_vector<T, S, D, true>::Terminator){
		for(size_t i = offset; i < S; ++i)
			this->data[i] = 0;
	}
}

#endif
