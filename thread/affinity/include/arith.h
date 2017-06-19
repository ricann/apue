#ifndef __ARITH_H__
#define __ARITH_H__

/*
 * R = A*b + c
 * A : 1 x size
 * b : size x 1
 * c : size x 1
 * R : 1 x 1
 */
float vecxvec_add_vec_s8ff(const signed char *vecA, const float *vecB, const float *vecC, int size);
float vecxvec_add_vec_s8ff_c(const signed char *vecA, const float *vecB, const float *vecC, int size);
float vecxvec_add_vec_s8ff_intr(const signed char *vecA, const float *vecB, const float *vecC, int size);

float vecxvec_add_vec_fff(const float *vecA, const float *vecB, const float *vecC, int size);
float vecxvec_add_vec_fff_c(const float *vecA, const float *vecB, const float *vecC, int size);
float vecxvec_add_vec_fff_intr(const float *vecA, const float *vecB, const float *vecC, int size);

/*
 * dst[i] = src[i]*scale
 */
void vec_scale_s8f(signed char *src, int size, float scale, float *dst);
void vec_scale_s8f_c(signed char *src, int size, float scale, float *dst);
void vec_scale_s8f_intr(signed char *src, int size, float scale, float *dst);


#endif /* __ARITH_H__ */
