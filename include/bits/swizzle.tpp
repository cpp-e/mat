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
 * @file bits/swizzle.tpp
 * This is an internal header implementation. Do not attempt to use it
 * directly.
 */

#ifndef _CPPE_SWIZZLE_TPP_
#define _CPPE_SWIZZLE_TPP_

namespace CPPE{
	namespace _detail{
		template<typename T, uint8_t D>
		T& swizzle_base<T, D>::at(uint8_t i){
			return (reinterpret_cast<T*>(buffer))[i];
		}
		
		template<typename T, uint8_t D>
		const T& swizzle_base<T, D>::at(uint8_t i) const{
			return (reinterpret_cast<const T*>(buffer))[i];
		}
		
		template<typename T, uint8_t D, int8_t i1, int8_t i2, int8_t i3,
		  int8_t i4, size_t S>
		swizzle<T, D, i1, i2, i3, i4, S>
		  ::operator basic_vector<T, S, D>(){
			const int8_t indices[] = {i1, i2, i3, i4};
			basic_vector<T, S, D> out;
			for(size_t i = 0; i < S; ++i)
				out[i] = this->at(indices[i]);
			return out;
		}
		 
		template<typename T, uint8_t D, int8_t i1, int8_t i2, int8_t i3,
		  int8_t i4, size_t S>
		swizzle<T, D, i1, i2, i3, i4, S>
		  ::operator const basic_vector<T, S, D>() const{
			 const int8_t indices[] = {i1, i2, i3, i4};
			 basic_vector<T, S, D> out;
			 for(size_t i = 0; i < S; ++i)
				out[i] = this->at(indices[i]);
			return out;
		}
	}
}

#endif
