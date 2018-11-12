#include <stdio.h>
#include <assert.h>
#include <math.h> 

extern FILE *cunit_log; 
extern double cunit_dmacheps;

int cunit_init();

#define cunit_open(log) { \
    if((cunit_log=fopen( log, "w") == NULL ) { \
      cunit_log = stderr; \
    } \
}
#define cunit_close fclose(cunit_log)
#define cunit_flush() fflush(cunit_log)
#define cunit_date(str) { \
    fprintf(cunit_log, "%s  LINE %d:  DATE:%s TIME:%s :%s\n", \
              __FILE__ , __LINE__ , __DATE__ , __TIME__ , str ); \
}
#define cunit_print(str) { \
    fprintf(cunit_log, "%s\n", str ); \
}

#define assert_true(str, a) { \
  if( !( a ) ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d != TRUE\n", \
              __FILE__ , __LINE__ , str ,  a ); \
  } \
}

#define assert_false(str, a) { \
  if( a ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d != FALSE\n", \
              __FILE__ , __LINE__ , str ,  a ); \
  } \
}

#define assert_eq(str,a,b) { \
  if( a != b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !== %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_neq(str,a,b) { \
  if( a == b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !!= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_ge(str,a,b) { \
  if( a < b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !>= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_gt(str,a,b) { \
  if( a <= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !> %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_le(str,a,b) { \
  if( a > b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !<= %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_lt(str,a,b) { \
  if( a >= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %d !< %d\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_feq(str,a,b) { \
  if( a != b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !== %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
// eq subject to absolute error
#define assert_feqaerr(str,a,b,aerr) { \
  if( fabs(a - b) > aerr ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !== %24.16f err=%10.6e\n", \
              __FILE__ , __LINE__ , str , a , b , err); \
  } \
}
// eq subject to relative error
// Perhaps it should check if a == b == 0.0 
#define assert_feqrerr(str,a,b,rerr) { \
  if( fabs(a - b)/(fabs(a) + fabs(b)) > rerr ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !>= %24.16f rerr=%10.6e\n", \
              __FILE__ , __LINE__ , str , a , b , rerr ); \
  } \
}
#define assert_fgt(str,a,b) { \
  if( a <= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !> %24.16f\n", \
              __FILE__ , __LINE__ , str ,  a , b ); \
  } \
}
#define assert_fle(str,a,b) { \
  if( a > b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !<= %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
#define assert_flt(str,a,b) { \
  if( a >= b ) { \
    fprintf(cunit_log, "%s  LINE %d: %s, %24.16f !< %24.16f\n", \
              __FILE__ , __LINE__ , str , a , b ); \
  } \
}
