#include "test-simd128.h"
#include "run-tests.h"

static MunitSuite suites[] = {
  #define SIMDE_TEST_DECLARE_SUITE(name) \
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE }, \
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE }, \
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE }, \
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE
  { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE },
  { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

static MunitSuite suite = { "/wasm/simd128", NULL, suites, 1, MUNIT_SUITE_OPTION_NONE };

MunitSuite*
simde_tests_x86_get_suite(void) {
  int i = 0;

  #define SIMDE_TEST_DECLARE_SUITE(name) \
    suites[i++] = *HEDLEY_CONCAT3(simde_test_x86_get_suite_, name, _native_c)(); \
    suites[i++] = *HEDLEY_CONCAT3(simde_test_x86_get_suite_, name, _native_cpp)(); \
    suites[i++] = *HEDLEY_CONCAT3(simde_test_x86_get_suite_, name, _emul_c)(); \
    suites[i++] = *HEDLEY_CONCAT3(simde_test_x86_get_suite_, name, _emul_cpp)();
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE
  suites[i++] = *simde_tests_x86_avx512_get_suite();

  return &suite;
}
