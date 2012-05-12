#include<cstdlib>

#ifndef __UNITTEST_TIME_CALC_ENABLE

#define __UNITTEST_TIME_CALC_ENABLE
#define __UNITTEST_TIME_CALC_BEGIN(_func)\
	  struct timezone _tz##_func; \
struct timeval __tvStart##_func; \
gettimeofday(&__tvStart##_func,&_tz##_func);

#define __UNITTEST_TIME_CALC_END(_func)   \
	      struct timeval __tvEnd##_func; \
gettimeofday(&__tvEnd##_func,&_tz##_func); \
float __func_dif_##_func; \
__func_dif_##_func= (__tvEnd##_func.tv_sec-__tvStart##_func.tv_sec)+(__tvEnd##_func.tv_usec-__tvStart##_func.tv_usec)/1000000.0; \

#endif

float elased_time = 0;

__UNITTEST_TIME_CALC_BEGIN(put)

	...

__UNITTEST_TIME_CALC_END(put)
elased_time += __func_dif_put;


