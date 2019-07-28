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
 * @file bits/swizzle.hpp
 * This is an internal header included by other header libraries. Do
 * not attempt to use it directly.
 */

#ifndef _CPPE_SWIZZLE_HPP_
#define _CPPE_SWIZZLE_HPP_

namespace CPPE{	
	namespace _detail{
		template<typename T, uint8_t D>
		struct swizzle_base{
			inline T& at(uint8_t i);
			inline const T& at(uint8_t i) const;
			T buffer[1];
		};
		
		template<typename T, uint8_t D, int8_t i1, int8_t i2 = -1,
		  int8_t i3 = -1, int8_t i4 = -1, size_t S = 1 + (i2 > -1) +
		  (i3 > -1) + (i4 > -1)>
		struct swizzle : public swizzle_base<T, D>{
			static const size_t length = S;
			operator basic_vector<T, S, D>();
			operator const basic_vector<T, S, D>() const;
		};
		
		template <typename T, size_t S, uint8_t D>
		struct vector_base{
			T data[S];
		};
		
		template<typename T, uint8_t D>
		struct vector_base<T, 1, D> {
			union {
				T data[1];
				struct {T x;};
				struct {T r;};
				struct {T s;};
				swizzle<T, D, 0, 0> xx, rr, ss;
				swizzle<T, D, 0, 0, 0> xxx, rrr, sss;
				swizzle<T, D, 0, 0, 0, 0> xxxx, rrrr, ssss;
			};
		};
		
		template<typename T, uint8_t D>
		struct vector_base<T, 2, D> {
			union {
				T data[2];
				struct {T x, y;};
				struct {T r, g;};
				struct {T s, t;};
				swizzle<T, D, 0, 0> xx, rr, ss;
				swizzle<T, D, 0, 1> xy, rg, st;
				swizzle<T, D, 1, 0> yx, gr, ts;
				swizzle<T, D, 1, 1> yy, gg, tt;
				swizzle<T, D, 0, 0, 0> xxx, rrr, sss;
				swizzle<T, D, 0, 0, 1> xxy, rrg, sst;
				swizzle<T, D, 0, 1, 0> xyx, rgr, sts;
				swizzle<T, D, 0, 1, 1> xyy, rgg, stt;
				swizzle<T, D, 1, 0, 0> yxx, grr, tss;
				swizzle<T, D, 1, 0, 1> yxy, grg, tst;
				swizzle<T, D, 1, 1, 0> yyx, ggr, tts;
				swizzle<T, D, 1, 1, 1> yyy, ggg, ttt;
				swizzle<T, D, 0, 0, 0, 0> xxxx, rrrr, ssss;
				swizzle<T, D, 0, 0, 0, 1> xxxy, rrrg, ssst;
				swizzle<T, D, 0, 0, 1, 0> xxyx, rrgr, ssts;
				swizzle<T, D, 0, 0, 1, 1> xxyy, rrgg, sstt;
				swizzle<T, D, 0, 1, 0, 0> xyxx, rgrr, stss;
				swizzle<T, D, 0, 1, 0, 1> xyxy, rgrg, stst;
				swizzle<T, D, 0, 1, 1, 0> xyyx, rggr, stts;
				swizzle<T, D, 0, 1, 1, 1> xyyy, rggg, sttt;
				swizzle<T, D, 1, 0, 0, 0> yxxx, grrr, tsss;
				swizzle<T, D, 1, 0, 0, 1> yxxy, grrg, tsst;
				swizzle<T, D, 1, 0, 1, 0> yxyx, grgr, tsts;
				swizzle<T, D, 1, 0, 1, 1> yxyy, grgg, tstt;
				swizzle<T, D, 1, 1, 0, 0> yyxx, ggrr, ttss;
				swizzle<T, D, 1, 1, 0, 1> yyxy, ggrg, ttst;
				swizzle<T, D, 1, 1, 1, 0> yyyx, gggr, ttts;
				swizzle<T, D, 1, 1, 1, 1> yyyy, gggg, tttt;
			};
		};
		
		template<typename T, uint8_t D>
		struct vector_base<T, 3, D> {
			union {
				T data[3];
				struct {T x, y, z;};
				struct {T r, g, b;};
				struct {T s, t, p;};
				swizzle<T, D, 0, 0> xx, rr, ss;
				swizzle<T, D, 0, 1> xy, rg, st;
				swizzle<T, D, 0, 2> xz, rb, sp;
				swizzle<T, D, 1, 0> yx, gr, ts;
				swizzle<T, D, 1, 1> yy, gg, tt;
				swizzle<T, D, 1, 2> yz, gb, tp;
				swizzle<T, D, 2, 0> zx, br, ps;
				swizzle<T, D, 2, 1> zy, bg, pt;
				swizzle<T, D, 2, 2> zz, bb, pp;
				swizzle<T, D, 0, 0, 0> xxx, rrr, sss;
				swizzle<T, D, 0, 0, 1> xxy, rrg, sst;
				swizzle<T, D, 0, 0, 2> xxz, rrb, ssp;
				swizzle<T, D, 0, 1, 0> xyx, rgr, sts;
				swizzle<T, D, 0, 1, 1> xyy, rgg, stt;
				swizzle<T, D, 0, 1, 2> xyz, rgb, stp;
				swizzle<T, D, 0, 2, 0> xzx, rbr, sps;
				swizzle<T, D, 0, 2, 1> xzy, rbg, spt;
				swizzle<T, D, 0, 2, 2> xzz, rbb, spp;
				swizzle<T, D, 1, 0, 0> yxx, grr, tss;
				swizzle<T, D, 1, 0, 1> yxy, grg, tst;
				swizzle<T, D, 1, 0, 2> yxz, grb, tsp;
				swizzle<T, D, 1, 1, 0> yyx, ggr, tts;
				swizzle<T, D, 1, 1, 1> yyy, ggg, ttt;
				swizzle<T, D, 1, 1, 2> yyz, ggb, ttp;
				swizzle<T, D, 1, 2, 0> yzx, gbr, tps;
				swizzle<T, D, 1, 2, 1> yzy, gbg, tpt;
				swizzle<T, D, 1, 2, 2> yzz, gbb, tpp;
				swizzle<T, D, 2, 0, 0> zxx, brr, pss;
				swizzle<T, D, 2, 0, 1> zxy, brg, pst;
				swizzle<T, D, 2, 0, 2> zxz, brb, psp;
				swizzle<T, D, 2, 1, 0> zyx, bgr, pts;
				swizzle<T, D, 2, 1, 1> zyy, bgg, ptt;
				swizzle<T, D, 2, 1, 2> zyz, bgb, ptp;
				swizzle<T, D, 2, 2, 0> zzx, bbr, pps;
				swizzle<T, D, 2, 2, 1> zzy, bbg, ppt;
				swizzle<T, D, 2, 2, 2> zzz, bbb, ppp;
				swizzle<T, D, 0, 0, 0, 0> xxxx, rrrr, ssss;
				swizzle<T, D, 0, 0, 0, 1> xxxy, rrrg, ssst;
				swizzle<T, D, 0, 0, 0, 2> xxxz, rrrb, sssp;
				swizzle<T, D, 0, 0, 1, 0> xxyx, rrgr, ssts;
				swizzle<T, D, 0, 0, 1, 1> xxyy, rrgg, sstt;
				swizzle<T, D, 0, 0, 1, 2> xxyz, rrgb, sstp;
				swizzle<T, D, 0, 0, 2, 0> xxzx, rrbr, ssps;
				swizzle<T, D, 0, 0, 2, 1> xxzy, rrbg, sspt;
				swizzle<T, D, 0, 0, 2, 2> xxzz, rrbb, sspp;
				swizzle<T, D, 0, 1, 0, 0> xyxx, rgrr, stss;
				swizzle<T, D, 0, 1, 0, 1> xyxy, rgrg, stst;
				swizzle<T, D, 0, 1, 0, 2> xyxz, rgrb, stsp;
				swizzle<T, D, 0, 1, 1, 0> xyyx, rggr, stts;
				swizzle<T, D, 0, 1, 1, 1> xyyy, rggg, sttt;
				swizzle<T, D, 0, 1, 1, 2> xyyz, rggb, sttp;
				swizzle<T, D, 0, 1, 2, 0> xyzx, rgbr, stps;
				swizzle<T, D, 0, 1, 2, 1> xyzy, rgbg, stpt;
				swizzle<T, D, 0, 1, 2, 2> xyzz, rgbb, stpp;
				swizzle<T, D, 0, 2, 0, 0> xzxx, rbrr, spss;
				swizzle<T, D, 0, 2, 0, 1> xzxy, rbrg, spst;
				swizzle<T, D, 0, 2, 0, 2> xzxz, rbrb, spsp;
				swizzle<T, D, 0, 2, 1, 0> xzyx, rbgr, spts;
				swizzle<T, D, 0, 2, 1, 1> xzyy, rbgg, sptt;
				swizzle<T, D, 0, 2, 1, 2> xzyz, rbgb, sptp;
				swizzle<T, D, 0, 2, 2, 0> xzzx, rbbr, spps;
				swizzle<T, D, 0, 2, 2, 1> xzzy, rbbg, sppt;
				swizzle<T, D, 0, 2, 2, 2> xzzz, rbbb, sppp;
				swizzle<T, D, 1, 0, 0, 0> yxxx, grrr, tsss;
				swizzle<T, D, 1, 0, 0, 1> yxxy, grrg, tsst;
				swizzle<T, D, 1, 0, 0, 2> yxxz, grrb, tssp;
				swizzle<T, D, 1, 0, 1, 0> yxyx, grgr, tsts;
				swizzle<T, D, 1, 0, 1, 1> yxyy, grgg, tstt;
				swizzle<T, D, 1, 0, 1, 2> yxyz, grgb, tstp;
				swizzle<T, D, 1, 0, 2, 0> yxzx, grbr, tsps;
				swizzle<T, D, 1, 0, 2, 1> yxzy, grbg, tspt;
				swizzle<T, D, 1, 0, 2, 2> yxzz, grbb, tspp;
				swizzle<T, D, 1, 1, 0, 0> yyxx, ggrr, ttss;
				swizzle<T, D, 1, 1, 0, 1> yyxy, ggrg, ttst;
				swizzle<T, D, 1, 1, 0, 2> yyxz, ggrb, ttsp;
				swizzle<T, D, 1, 1, 1, 0> yyyx, gggr, ttts;
				swizzle<T, D, 1, 1, 1, 1> yyyy, gggg, tttt;
				swizzle<T, D, 1, 1, 1, 2> yyyz, gggb, tttp;
				swizzle<T, D, 1, 1, 2, 0> yyzx, ggbr, ttps;
				swizzle<T, D, 1, 1, 2, 1> yyzy, ggbg, ttpt;
				swizzle<T, D, 1, 1, 2, 2> yyzz, ggbb, ttpp;
				swizzle<T, D, 1, 2, 0, 0> yzxx, gbrr, tpss;
				swizzle<T, D, 1, 2, 0, 1> yzxy, gbrg, tpst;
				swizzle<T, D, 1, 2, 0, 2> yzxz, gbrb, tpsp;
				swizzle<T, D, 1, 2, 1, 0> yzyx, gbgr, tpts;
				swizzle<T, D, 1, 2, 1, 1> yzyy, gbgg, tptt;
				swizzle<T, D, 1, 2, 1, 2> yzyz, gbgb, tptp;
				swizzle<T, D, 1, 2, 2, 0> yzzx, gbbr, tpps;
				swizzle<T, D, 1, 2, 2, 1> yzzy, gbbg, tppt;
				swizzle<T, D, 1, 2, 2, 2> yzzz, gbbb, tppp;
				swizzle<T, D, 2, 0, 0, 0> zxxx, brrr, psss;
				swizzle<T, D, 2, 0, 0, 1> zxxy, brrg, psst;
				swizzle<T, D, 2, 0, 0, 2> zxxz, brrb, pssp;
				swizzle<T, D, 2, 0, 1, 0> zxyx, brgr, psts;
				swizzle<T, D, 2, 0, 1, 1> zxyy, brgg, pstt;
				swizzle<T, D, 2, 0, 1, 2> zxyz, brgb, pstp;
				swizzle<T, D, 2, 0, 2, 0> zxzx, brbr, psps;
				swizzle<T, D, 2, 0, 2, 1> zxzy, brbg, pspt;
				swizzle<T, D, 2, 0, 2, 2> zxzz, brbb, pspp;
				swizzle<T, D, 2, 1, 0, 0> zyxx, bgrr, ptss;
				swizzle<T, D, 2, 1, 0, 1> zyxy, bgrg, ptst;
				swizzle<T, D, 2, 1, 0, 2> zyxz, bgrb, ptsp;
				swizzle<T, D, 2, 1, 1, 0> zyyx, bggr, ptts;
				swizzle<T, D, 2, 1, 1, 1> zyyy, bggg, pttt;
				swizzle<T, D, 2, 1, 1, 2> zyyz, bggb, pttp;
				swizzle<T, D, 2, 1, 2, 0> zyzx, bgbr, ptps;
				swizzle<T, D, 2, 1, 2, 1> zyzy, bgbg, ptpt;
				swizzle<T, D, 2, 1, 2, 2> zyzz, bgbb, ptpp;
				swizzle<T, D, 2, 2, 0, 0> zzxx, bbrr, ppss;
				swizzle<T, D, 2, 2, 0, 1> zzxy, bbrg, ppst;
				swizzle<T, D, 2, 2, 0, 2> zzxz, bbrb, ppsp;
				swizzle<T, D, 2, 2, 1, 0> zzyx, bbgr, ppts;
				swizzle<T, D, 2, 2, 1, 1> zzyy, bbgg, pptt;
				swizzle<T, D, 2, 2, 1, 2> zzyz, bbgb, pptp;
				swizzle<T, D, 2, 2, 2, 0> zzzx, bbbr, ppps;
				swizzle<T, D, 2, 2, 2, 1> zzzy, bbbg, pppt;
				swizzle<T, D, 2, 2, 2, 2> zzzz, bbbb, pppp;
			};
		};
		
		template<typename T, uint8_t D>
		struct vector_base<T, 4, D> {
			union {
				T data[4];
				struct {T x, y, z, w;};
				struct {T r, g, b ,a;};
				struct {T s, t, p, q;};
				swizzle<T, D, 0, 0> xx, rr, ss;
				swizzle<T, D, 0, 1> xy, rg, st;
				swizzle<T, D, 0, 2> xz, rb, sp;
				swizzle<T, D, 0, 3> xw, ra, sq;
				swizzle<T, D, 1, 0> yx, gr, ts;
				swizzle<T, D, 1, 1> yy, gg, tt;
				swizzle<T, D, 1, 2> yz, gb, tp;
				swizzle<T, D, 1, 3> yw, ga, tq;
				swizzle<T, D, 2, 0> zx, br, ps;
				swizzle<T, D, 2, 1> zy, bg, pt;
				swizzle<T, D, 2, 2> zz, bb, pp;
				swizzle<T, D, 2, 3> zw, ba, pq;
				swizzle<T, D, 3, 0> wx, ar, qs;
				swizzle<T, D, 3, 1> wy, ag, qt;
				swizzle<T, D, 3, 2> wz, ab, qp;
				swizzle<T, D, 3, 3> ww, aa, qq;
				swizzle<T, D, 0, 0, 0> xxx, rrr, sss;
				swizzle<T, D, 0, 0, 1> xxy, rrg, sst;
				swizzle<T, D, 0, 0, 2> xxz, rrb, ssp;
				swizzle<T, D, 0, 0, 3> xxw, rra, ssq;
				swizzle<T, D, 0, 1, 0> xyx, rgr, sts;
				swizzle<T, D, 0, 1, 1> xyy, rgg, stt;
				swizzle<T, D, 0, 1, 2> xyz, rgb, stp;
				swizzle<T, D, 0, 1, 3> xyw, rga, stq;
				swizzle<T, D, 0, 2, 0> xzx, rbr, sps;
				swizzle<T, D, 0, 2, 1> xzy, rbg, spt;
				swizzle<T, D, 0, 2, 2> xzz, rbb, spp;
				swizzle<T, D, 0, 2, 3> xzw, rba, spq;
				swizzle<T, D, 0, 3, 0> xwx, rar, sqs;
				swizzle<T, D, 0, 3, 1> xwy, rag, sqt;
				swizzle<T, D, 0, 3, 2> xwz, rab, sqp;
				swizzle<T, D, 0, 3, 3> xww, raa, sqq;
				swizzle<T, D, 1, 0, 0> yxx, grr, tss;
				swizzle<T, D, 1, 0, 1> yxy, grg, tst;
				swizzle<T, D, 1, 0, 2> yxz, grb, tsp;
				swizzle<T, D, 1, 0, 3> yxw, gra, tsq;
				swizzle<T, D, 1, 1, 0> yyx, ggr, tts;
				swizzle<T, D, 1, 1, 1> yyy, ggg, ttt;
				swizzle<T, D, 1, 1, 2> yyz, ggb, ttp;
				swizzle<T, D, 1, 1, 3> yyw, gga, ttq;
				swizzle<T, D, 1, 2, 0> yzx, gbr, tps;
				swizzle<T, D, 1, 2, 1> yzy, gbg, tpt;
				swizzle<T, D, 1, 2, 2> yzz, gbb, tpp;
				swizzle<T, D, 1, 2, 3> yzw, gba, tpq;
				swizzle<T, D, 1, 3, 0> ywx, gar, tqs;
				swizzle<T, D, 1, 3, 1> ywy, gag, tqt;
				swizzle<T, D, 1, 3, 2> ywz, gab, tqp;
				swizzle<T, D, 1, 3, 3> yww, gaa, tqq;
				swizzle<T, D, 2, 0, 0> zxx, brr, pss;
				swizzle<T, D, 2, 0, 1> zxy, brg, pst;
				swizzle<T, D, 2, 0, 2> zxz, brb, psp;
				swizzle<T, D, 2, 0, 3> zxw, bra, psq;
				swizzle<T, D, 2, 1, 0> zyx, bgr, pts;
				swizzle<T, D, 2, 1, 1> zyy, bgg, ptt;
				swizzle<T, D, 2, 1, 2> zyz, bgb, ptp;
				swizzle<T, D, 2, 1, 3> zyw, bga, ptq;
				swizzle<T, D, 2, 2, 0> zzx, bbr, pps;
				swizzle<T, D, 2, 2, 1> zzy, bbg, ppt;
				swizzle<T, D, 2, 2, 2> zzz, bbb, ppp;
				swizzle<T, D, 2, 2, 3> zzw, bba, ppq;
				swizzle<T, D, 2, 3, 0> zwx, bar, pqs;
				swizzle<T, D, 2, 3, 1> zwy, bag, pqt;
				swizzle<T, D, 2, 3, 2> zwz, bab, pqp;
				swizzle<T, D, 2, 3, 3> zww, baa, pqq;
				swizzle<T, D, 3, 0, 0> wxx, arr, qss;
				swizzle<T, D, 3, 0, 1> wxy, arg, qst;
				swizzle<T, D, 3, 0, 2> wxz, arb, qsp;
				swizzle<T, D, 3, 0, 3> wxw, ara, qsq;
				swizzle<T, D, 3, 1, 0> wyx, agr, qts;
				swizzle<T, D, 3, 1, 1> wyy, agg, qtt;
				swizzle<T, D, 3, 1, 2> wyz, agb, qtp;
				swizzle<T, D, 3, 1, 3> wyw, aga, qtq;
				swizzle<T, D, 3, 2, 0> wzx, abr, qps;
				swizzle<T, D, 3, 2, 1> wzy, abg, qpt;
				swizzle<T, D, 3, 2, 2> wzz, abb, qpp;
				swizzle<T, D, 3, 2, 3> wzw, aba, qpq;
				swizzle<T, D, 3, 3, 0> wwx, aar, qqs;
				swizzle<T, D, 3, 3, 1> wwy, aag, qqt;
				swizzle<T, D, 3, 3, 2> wwz, aab, qqp;
				swizzle<T, D, 3, 3, 3> www, aaa, qqq;
				swizzle<T, D, 0, 0, 0, 0> xxxx, rrrr, ssss;
				swizzle<T, D, 0, 0, 0, 1> xxxy, rrrg, ssst;
				swizzle<T, D, 0, 0, 0, 2> xxxz, rrrb, sssp;
				swizzle<T, D, 0, 0, 0, 3> xxxw, rrra, sssq;
				swizzle<T, D, 0, 0, 1, 0> xxyx, rrgr, ssts;
				swizzle<T, D, 0, 0, 1, 1> xxyy, rrgg, sstt;
				swizzle<T, D, 0, 0, 1, 2> xxyz, rrgb, sstp;
				swizzle<T, D, 0, 0, 1, 3> xxyw, rrga, sstq;
				swizzle<T, D, 0, 0, 2, 0> xxzx, rrbr, ssps;
				swizzle<T, D, 0, 0, 2, 1> xxzy, rrbg, sspt;
				swizzle<T, D, 0, 0, 2, 2> xxzz, rrbb, sspp;
				swizzle<T, D, 0, 0, 2, 3> xxzw, rrba, sspq;
				swizzle<T, D, 0, 0, 3, 0> xxwx, rrar, ssqs;
				swizzle<T, D, 0, 0, 3, 1> xxwy, rrag, ssqt;
				swizzle<T, D, 0, 0, 3, 2> xxwz, rrab, ssqp;
				swizzle<T, D, 0, 0, 3, 3> xxww, rraa, ssqq;
				swizzle<T, D, 0, 1, 0, 0> xyxx, rgrr, stss;
				swizzle<T, D, 0, 1, 0, 1> xyxy, rgrg, stst;
				swizzle<T, D, 0, 1, 0, 2> xyxz, rgrb, stsp;
				swizzle<T, D, 0, 1, 0, 3> xyxw, rgra, stsq;
				swizzle<T, D, 0, 1, 1, 0> xyyx, rggr, stts;
				swizzle<T, D, 0, 1, 1, 1> xyyy, rggg, sttt;
				swizzle<T, D, 0, 1, 1, 2> xyyz, rggb, sttp;
				swizzle<T, D, 0, 1, 1, 3> xyyw, rgga, sttq;
				swizzle<T, D, 0, 1, 2, 0> xyzx, rgbr, stps;
				swizzle<T, D, 0, 1, 2, 1> xyzy, rgbg, stpt;
				swizzle<T, D, 0, 1, 2, 2> xyzz, rgbb, stpp;
				swizzle<T, D, 0, 1, 2, 3> xyzw, rgba, stpq;
				swizzle<T, D, 0, 1, 3, 0> xywx, rgar, stqs;
				swizzle<T, D, 0, 1, 3, 1> xywy, rgag, stqt;
				swizzle<T, D, 0, 1, 3, 2> xywz, rgab, stqp;
				swizzle<T, D, 0, 1, 3, 3> xyww, rgaa, stqq;
				swizzle<T, D, 0, 2, 0, 0> xzxx, rbrr, spss;
				swizzle<T, D, 0, 2, 0, 1> xzxy, rbrg, spst;
				swizzle<T, D, 0, 2, 0, 2> xzxz, rbrb, spsp;
				swizzle<T, D, 0, 2, 0, 3> xzxw, rbra, spsq;
				swizzle<T, D, 0, 2, 1, 0> xzyx, rbgr, spts;
				swizzle<T, D, 0, 2, 1, 1> xzyy, rbgg, sptt;
				swizzle<T, D, 0, 2, 1, 2> xzyz, rbgb, sptp;
				swizzle<T, D, 0, 2, 1, 3> xzyw, rbga, sptq;
				swizzle<T, D, 0, 2, 2, 0> xzzx, rbbr, spps;
				swizzle<T, D, 0, 2, 2, 1> xzzy, rbbg, sppt;
				swizzle<T, D, 0, 2, 2, 2> xzzz, rbbb, sppp;
				swizzle<T, D, 0, 2, 2, 3> xzzw, rbba, sppq;
				swizzle<T, D, 0, 2, 3, 0> xzwx, rbar, spqs;
				swizzle<T, D, 0, 2, 3, 1> xzwy, rbag, spqt;
				swizzle<T, D, 0, 2, 3, 2> xzwz, rbab, spqp;
				swizzle<T, D, 0, 2, 3, 3> xzww, rbaa, spqq;
				swizzle<T, D, 0, 3, 0, 0> xwxx, rarr, sqss;
				swizzle<T, D, 0, 3, 0, 1> xwxy, rarg, sqst;
				swizzle<T, D, 0, 3, 0, 2> xwxz, rarb, sqsp;
				swizzle<T, D, 0, 3, 0, 3> xwxw, rara, sqsq;
				swizzle<T, D, 0, 3, 1, 0> xwyx, ragr, sqts;
				swizzle<T, D, 0, 3, 1, 1> xwyy, ragg, sqtt;
				swizzle<T, D, 0, 3, 1, 2> xwyz, ragb, sqtp;
				swizzle<T, D, 0, 3, 1, 3> xwyw, raga, sqtq;
				swizzle<T, D, 0, 3, 2, 0> xwzx, rabr, sqps;
				swizzle<T, D, 0, 3, 2, 1> xwzy, rabg, sqpt;
				swizzle<T, D, 0, 3, 2, 2> xwzz, rabb, sqpp;
				swizzle<T, D, 0, 3, 2, 3> xwzw, raba, sqpq;
				swizzle<T, D, 0, 3, 3, 0> xwwx, raar, sqqs;
				swizzle<T, D, 0, 3, 3, 1> xwwy, raag, sqqt;
				swizzle<T, D, 0, 3, 3, 2> xwwz, raab, sqqp;
				swizzle<T, D, 0, 3, 3, 3> xwww, raaa, sqqq;
				swizzle<T, D, 1, 0, 0, 0> yxxx, grrr, tsss;
				swizzle<T, D, 1, 0, 0, 1> yxxy, grrg, tsst;
				swizzle<T, D, 1, 0, 0, 2> yxxz, grrb, tssp;
				swizzle<T, D, 1, 0, 0, 3> yxxw, grra, tssq;
				swizzle<T, D, 1, 0, 1, 0> yxyx, grgr, tsts;
				swizzle<T, D, 1, 0, 1, 1> yxyy, grgg, tstt;
				swizzle<T, D, 1, 0, 1, 2> yxyz, grgb, tstp;
				swizzle<T, D, 1, 0, 1, 3> yxyw, grga, tstq;
				swizzle<T, D, 1, 0, 2, 0> yxzx, grbr, tsps;
				swizzle<T, D, 1, 0, 2, 1> yxzy, grbg, tspt;
				swizzle<T, D, 1, 0, 2, 2> yxzz, grbb, tspp;
				swizzle<T, D, 1, 0, 2, 3> yxzw, grba, tspq;
				swizzle<T, D, 1, 0, 3, 0> yxwx, grar, tsqs;
				swizzle<T, D, 1, 0, 3, 1> yxwy, grag, tsqt;
				swizzle<T, D, 1, 0, 3, 2> yxwz, grab, tsqp;
				swizzle<T, D, 1, 0, 3, 3> yxww, graa, tsqq;
				swizzle<T, D, 1, 1, 0, 0> yyxx, ggrr, ttss;
				swizzle<T, D, 1, 1, 0, 1> yyxy, ggrg, ttst;
				swizzle<T, D, 1, 1, 0, 2> yyxz, ggrb, ttsp;
				swizzle<T, D, 1, 1, 0, 3> yyxw, ggra, ttsq;
				swizzle<T, D, 1, 1, 1, 0> yyyx, gggr, ttts;
				swizzle<T, D, 1, 1, 1, 1> yyyy, gggg, tttt;
				swizzle<T, D, 1, 1, 1, 2> yyyz, gggb, tttp;
				swizzle<T, D, 1, 1, 1, 3> yyyw, ggga, tttq;
				swizzle<T, D, 1, 1, 2, 0> yyzx, ggbr, ttps;
				swizzle<T, D, 1, 1, 2, 1> yyzy, ggbg, ttpt;
				swizzle<T, D, 1, 1, 2, 2> yyzz, ggbb, ttpp;
				swizzle<T, D, 1, 1, 2, 3> yyzw, ggba, ttpq;
				swizzle<T, D, 1, 1, 3, 0> yywx, ggar, ttqs;
				swizzle<T, D, 1, 1, 3, 1> yywy, ggag, ttqt;
				swizzle<T, D, 1, 1, 3, 2> yywz, ggab, ttqp;
				swizzle<T, D, 1, 1, 3, 3> yyww, ggaa, ttqq;
				swizzle<T, D, 1, 2, 0, 0> yzxx, gbrr, tpss;
				swizzle<T, D, 1, 2, 0, 1> yzxy, gbrg, tpst;
				swizzle<T, D, 1, 2, 0, 2> yzxz, gbrb, tpsp;
				swizzle<T, D, 1, 2, 0, 3> yzxw, gbra, tpsq;
				swizzle<T, D, 1, 2, 1, 0> yzyx, gbgr, tpts;
				swizzle<T, D, 1, 2, 1, 1> yzyy, gbgg, tptt;
				swizzle<T, D, 1, 2, 1, 2> yzyz, gbgb, tptp;
				swizzle<T, D, 1, 2, 1, 3> yzyw, gbga, tptq;
				swizzle<T, D, 1, 2, 2, 0> yzzx, gbbr, tpps;
				swizzle<T, D, 1, 2, 2, 1> yzzy, gbbg, tppt;
				swizzle<T, D, 1, 2, 2, 2> yzzz, gbbb, tppp;
				swizzle<T, D, 1, 2, 2, 3> yzzw, gbba, tppq;
				swizzle<T, D, 1, 2, 3, 0> yzwx, gbar, tpqs;
				swizzle<T, D, 1, 2, 3, 1> yzwy, gbag, tpqt;
				swizzle<T, D, 1, 2, 3, 2> yzwz, gbab, tpqp;
				swizzle<T, D, 1, 2, 3, 3> yzww, gbaa, tpqq;
				swizzle<T, D, 1, 3, 0, 0> ywxx, garr, tqss;
				swizzle<T, D, 1, 3, 0, 1> ywxy, garg, tqst;
				swizzle<T, D, 1, 3, 0, 2> ywxz, garb, tqsp;
				swizzle<T, D, 1, 3, 0, 3> ywxw, gara, tqsq;
				swizzle<T, D, 1, 3, 1, 0> ywyx, gagr, tqts;
				swizzle<T, D, 1, 3, 1, 1> ywyy, gagg, tqtt;
				swizzle<T, D, 1, 3, 1, 2> ywyz, gagb, tqtp;
				swizzle<T, D, 1, 3, 1, 3> ywyw, gaga, tqtq;
				swizzle<T, D, 1, 3, 2, 0> ywzx, gabr, tqps;
				swizzle<T, D, 1, 3, 2, 1> ywzy, gabg, tqpt;
				swizzle<T, D, 1, 3, 2, 2> ywzz, gabb, tqpp;
				swizzle<T, D, 1, 3, 2, 3> ywzw, gaba, tqpq;
				swizzle<T, D, 1, 3, 3, 0> ywwx, gaar, tqqs;
				swizzle<T, D, 1, 3, 3, 1> ywwy, gaag, tqqt;
				swizzle<T, D, 1, 3, 3, 2> ywwz, gaab, tqqp;
				swizzle<T, D, 1, 3, 3, 3> ywww, gaaa, tqqq;
				swizzle<T, D, 2, 0, 0, 0> zxxx, brrr, psss;
				swizzle<T, D, 2, 0, 0, 1> zxxy, brrg, psst;
				swizzle<T, D, 2, 0, 0, 2> zxxz, brrb, pssp;
				swizzle<T, D, 2, 0, 0, 3> zxxw, brra, pssq;
				swizzle<T, D, 2, 0, 1, 0> zxyx, brgr, psts;
				swizzle<T, D, 2, 0, 1, 1> zxyy, brgg, pstt;
				swizzle<T, D, 2, 0, 1, 2> zxyz, brgb, pstp;
				swizzle<T, D, 2, 0, 1, 3> zxyw, brga, pstq;
				swizzle<T, D, 2, 0, 2, 0> zxzx, brbr, psps;
				swizzle<T, D, 2, 0, 2, 1> zxzy, brbg, pspt;
				swizzle<T, D, 2, 0, 2, 2> zxzz, brbb, pspp;
				swizzle<T, D, 2, 0, 2, 3> zxzw, brba, pspq;
				swizzle<T, D, 2, 0, 3, 0> zxwx, brar, psqs;
				swizzle<T, D, 2, 0, 3, 1> zxwy, brag, psqt;
				swizzle<T, D, 2, 0, 3, 2> zxwz, brab, psqp;
				swizzle<T, D, 2, 0, 3, 3> zxww, braa, psqq;
				swizzle<T, D, 2, 1, 0, 0> zyxx, bgrr, ptss;
				swizzle<T, D, 2, 1, 0, 1> zyxy, bgrg, ptst;
				swizzle<T, D, 2, 1, 0, 2> zyxz, bgrb, ptsp;
				swizzle<T, D, 2, 1, 0, 3> zyxw, bgra, ptsq;
				swizzle<T, D, 2, 1, 1, 0> zyyx, bggr, ptts;
				swizzle<T, D, 2, 1, 1, 1> zyyy, bggg, pttt;
				swizzle<T, D, 2, 1, 1, 2> zyyz, bggb, pttp;
				swizzle<T, D, 2, 1, 1, 3> zyyw, bgga, pttq;
				swizzle<T, D, 2, 1, 2, 0> zyzx, bgbr, ptps;
				swizzle<T, D, 2, 1, 2, 1> zyzy, bgbg, ptpt;
				swizzle<T, D, 2, 1, 2, 2> zyzz, bgbb, ptpp;
				swizzle<T, D, 2, 1, 2, 3> zyzw, bgba, ptpq;
				swizzle<T, D, 2, 1, 3, 0> zywx, bgar, ptqs;
				swizzle<T, D, 2, 1, 3, 1> zywy, bgag, ptqt;
				swizzle<T, D, 2, 1, 3, 2> zywz, bgab, ptqp;
				swizzle<T, D, 2, 1, 3, 3> zyww, bgaa, ptqq;
				swizzle<T, D, 2, 2, 0, 0> zzxx, bbrr, ppss;
				swizzle<T, D, 2, 2, 0, 1> zzxy, bbrg, ppst;
				swizzle<T, D, 2, 2, 0, 2> zzxz, bbrb, ppsp;
				swizzle<T, D, 2, 2, 0, 3> zzxw, bbra, ppsq;
				swizzle<T, D, 2, 2, 1, 0> zzyx, bbgr, ppts;
				swizzle<T, D, 2, 2, 1, 1> zzyy, bbgg, pptt;
				swizzle<T, D, 2, 2, 1, 2> zzyz, bbgb, pptp;
				swizzle<T, D, 2, 2, 1, 3> zzyw, bbga, pptq;
				swizzle<T, D, 2, 2, 2, 0> zzzx, bbbr, ppps;
				swizzle<T, D, 2, 2, 2, 1> zzzy, bbbg, pppt;
				swizzle<T, D, 2, 2, 2, 2> zzzz, bbbb, pppp;
				swizzle<T, D, 2, 2, 2, 3> zzzw, bbba, pppq;
				swizzle<T, D, 2, 2, 3, 0> zzwx, bbar, ppqs;
				swizzle<T, D, 2, 2, 3, 1> zzwy, bbag, ppqt;
				swizzle<T, D, 2, 2, 3, 2> zzwz, bbab, ppqp;
				swizzle<T, D, 2, 2, 3, 3> zzww, bbaa, ppqq;
				swizzle<T, D, 2, 3, 0, 0> zwxx, barr, pqss;
				swizzle<T, D, 2, 3, 0, 1> zwxy, barg, pqst;
				swizzle<T, D, 2, 3, 0, 2> zwxz, barb, pqsp;
				swizzle<T, D, 2, 3, 0, 3> zwxw, bara, pqsq;
				swizzle<T, D, 2, 3, 1, 0> zwyx, bagr, pqts;
				swizzle<T, D, 2, 3, 1, 1> zwyy, bagg, pqtt;
				swizzle<T, D, 2, 3, 1, 2> zwyz, bagb, pqtp;
				swizzle<T, D, 2, 3, 1, 3> zwyw, baga, pqtq;
				swizzle<T, D, 2, 3, 2, 0> zwzx, babr, pqps;
				swizzle<T, D, 2, 3, 2, 1> zwzy, babg, pqpt;
				swizzle<T, D, 2, 3, 2, 2> zwzz, babb, pqpp;
				swizzle<T, D, 2, 3, 2, 3> zwzw, baba, pqpq;
				swizzle<T, D, 2, 3, 3, 0> zwwx, baar, pqqs;
				swizzle<T, D, 2, 3, 3, 1> zwwy, baag, pqqt;
				swizzle<T, D, 2, 3, 3, 2> zwwz, baab, pqqp;
				swizzle<T, D, 2, 3, 3, 3> zwww, baaa, pqqq;
				swizzle<T, D, 3, 0, 0, 0> wxxx, arrr, qsss;
				swizzle<T, D, 3, 0, 0, 1> wxxy, arrg, qsst;
				swizzle<T, D, 3, 0, 0, 2> wxxz, arrb, qssp;
				swizzle<T, D, 3, 0, 0, 3> wxxw, arra, qssq;
				swizzle<T, D, 3, 0, 1, 0> wxyx, argr, qsts;
				swizzle<T, D, 3, 0, 1, 1> wxyy, argg, qstt;
				swizzle<T, D, 3, 0, 1, 2> wxyz, argb, qstp;
				swizzle<T, D, 3, 0, 1, 3> wxyw, arga, qstq;
				swizzle<T, D, 3, 0, 2, 0> wxzx, arbr, qsps;
				swizzle<T, D, 3, 0, 2, 1> wxzy, arbg, qspt;
				swizzle<T, D, 3, 0, 2, 2> wxzz, arbb, qspp;
				swizzle<T, D, 3, 0, 2, 3> wxzw, arba, qspq;
				swizzle<T, D, 3, 0, 3, 0> wxwx, arar, qsqs;
				swizzle<T, D, 3, 0, 3, 1> wxwy, arag, qsqt;
				swizzle<T, D, 3, 0, 3, 2> wxwz, arab, qsqp;
				swizzle<T, D, 3, 0, 3, 3> wxww, araa, qsqq;
				swizzle<T, D, 3, 1, 0, 0> wyxx, agrr, qtss;
				swizzle<T, D, 3, 1, 0, 1> wyxy, agrg, qtst;
				swizzle<T, D, 3, 1, 0, 2> wyxz, agrb, qtsp;
				swizzle<T, D, 3, 1, 0, 3> wyxw, agra, qtsq;
				swizzle<T, D, 3, 1, 1, 0> wyyx, aggr, qtts;
				swizzle<T, D, 3, 1, 1, 1> wyyy, aggg, qttt;
				swizzle<T, D, 3, 1, 1, 2> wyyz, aggb, qttp;
				swizzle<T, D, 3, 1, 1, 3> wyyw, agga, qttq;
				swizzle<T, D, 3, 1, 2, 0> wyzx, agbr, qtps;
				swizzle<T, D, 3, 1, 2, 1> wyzy, agbg, qtpt;
				swizzle<T, D, 3, 1, 2, 2> wyzz, agbb, qtpp;
				swizzle<T, D, 3, 1, 2, 3> wyzw, agba, qtpq;
				swizzle<T, D, 3, 1, 3, 0> wywx, agar, qtqs;
				swizzle<T, D, 3, 1, 3, 1> wywy, agag, qtqt;
				swizzle<T, D, 3, 1, 3, 2> wywz, agab, qtqp;
				swizzle<T, D, 3, 1, 3, 3> wyww, agaa, qtqq;
				swizzle<T, D, 3, 2, 0, 0> wzxx, abrr, qpss;
				swizzle<T, D, 3, 2, 0, 1> wzxy, abrg, qpst;
				swizzle<T, D, 3, 2, 0, 2> wzxz, abrb, qpsp;
				swizzle<T, D, 3, 2, 0, 3> wzxw, abra, qpsq;
				swizzle<T, D, 3, 2, 1, 0> wzyx, abgr, qpts;
				swizzle<T, D, 3, 2, 1, 1> wzyy, abgg, qptt;
				swizzle<T, D, 3, 2, 1, 2> wzyz, abgb, qptp;
				swizzle<T, D, 3, 2, 1, 3> wzyw, abga, qptq;
				swizzle<T, D, 3, 2, 2, 0> wzzx, abbr, qpps;
				swizzle<T, D, 3, 2, 2, 1> wzzy, abbg, qppt;
				swizzle<T, D, 3, 2, 2, 2> wzzz, abbb, qppp;
				swizzle<T, D, 3, 2, 2, 3> wzzw, abba, qppq;
				swizzle<T, D, 3, 2, 3, 0> wzwx, abar, qpqs;
				swizzle<T, D, 3, 2, 3, 1> wzwy, abag, qpqt;
				swizzle<T, D, 3, 2, 3, 2> wzwz, abab, qpqp;
				swizzle<T, D, 3, 2, 3, 3> wzww, abaa, qpqq;
				swizzle<T, D, 3, 3, 0, 0> wwxx, aarr, qqss;
				swizzle<T, D, 3, 3, 0, 1> wwxy, aarg, qqst;
				swizzle<T, D, 3, 3, 0, 2> wwxz, aarb, qqsp;
				swizzle<T, D, 3, 3, 0, 3> wwxw, aara, qqsq;
				swizzle<T, D, 3, 3, 1, 0> wwyx, aagr, qqts;
				swizzle<T, D, 3, 3, 1, 1> wwyy, aagg, qqtt;
				swizzle<T, D, 3, 3, 1, 2> wwyz, aagb, qqtp;
				swizzle<T, D, 3, 3, 1, 3> wwyw, aaga, qqtq;
				swizzle<T, D, 3, 3, 2, 0> wwzx, aabr, qqps;
				swizzle<T, D, 3, 3, 2, 1> wwzy, aabg, qqpt;
				swizzle<T, D, 3, 3, 2, 2> wwzz, aabb, qqpp;
				swizzle<T, D, 3, 3, 2, 3> wwzw, aaba, qqpq;
				swizzle<T, D, 3, 3, 3, 0> wwwx, aaar, qqqs;
				swizzle<T, D, 3, 3, 3, 1> wwwy, aaag, qqqt;
				swizzle<T, D, 3, 3, 3, 2> wwwz, aaab, qqqp;
				swizzle<T, D, 3, 3, 3, 3> wwww, aaaa, qqqq;
			};
		};
	}
}

#include <bits/swizzle.tpp>

#endif
