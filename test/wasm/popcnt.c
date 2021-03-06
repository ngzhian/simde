/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TESTS_CURRENT_ISAX simd128
#include <simde/wasm/simd128.h>
#include <test/wasm/test-simd128.h>

static int
test_simde_wasm_i8x16_popcnt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {      INT8_MIN,      INT8_MAX, -INT8_C(   1), -INT8_C(  95), -INT8_C(  76), -INT8_C(  48), -INT8_C( 125),  INT8_C(  33),
           INT8_C(   2), -INT8_C(   5),  INT8_C(  70), -INT8_C(  29), -INT8_C(  96),  INT8_C(  45), -INT8_C(   8), -INT8_C( 120) },
        {  INT8_C(   1),  INT8_C(   7),  INT8_C(   8),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   2),
           INT8_C(   1),  INT8_C(   7),  INT8_C(   3),  INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2) } },
      { {  INT8_C(  22),  INT8_C(  98),  INT8_C(  72), -INT8_C( 101),  INT8_C(  91), -INT8_C(  71), -INT8_C(  76), -INT8_C( 124),
               INT8_MIN, -INT8_C( 109), -INT8_C( 122), -INT8_C(  35),  INT8_C(  15),  INT8_C(  39),  INT8_C(  35), -INT8_C(  84) },
        {  INT8_C(   3),  INT8_C(   3),  INT8_C(   2),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2),
           INT8_C(   1),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4) } },
      { { -INT8_C( 111),  INT8_C(   1),  INT8_C( 111), -INT8_C(  71), -INT8_C(  19), -INT8_C(  72), -INT8_C( 107), -INT8_C(  33),
          -INT8_C(  20), -INT8_C(  47), -INT8_C(  34), -INT8_C(  28),  INT8_C( 126),  INT8_C( 117),  INT8_C(  90), -INT8_C(   6) },
        {  INT8_C(   3),  INT8_C(   1),  INT8_C(   6),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   7),
           INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   4),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6) } },
      { { -INT8_C(  21),  INT8_C(  48), -INT8_C(  93),  INT8_C(  34), -INT8_C(   5), -INT8_C(  34),  INT8_C(  49), -INT8_C(  85),
          -INT8_C(   8), -INT8_C(  87), -INT8_C(  43),  INT8_C(  10), -INT8_C( 109), -INT8_C(  19), -INT8_C(  74),  INT8_C(  45) },
        {  INT8_C(   6),  INT8_C(   2),  INT8_C(   4),  INT8_C(   2),  INT8_C(   7),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5),
           INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4) } },
      { {  INT8_C(  56),  INT8_C(  37), -INT8_C( 119),  INT8_C(   4),  INT8_C(  74), -INT8_C( 124),  INT8_C(  88), -INT8_C(   5),
          -INT8_C( 112),  INT8_C(  61),  INT8_C( 120), -INT8_C(  12),  INT8_C(   8), -INT8_C(  36),  INT8_C(  75),  INT8_C(  24) },
        {  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   1),  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   7),
           INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   1),  INT8_C(   5),  INT8_C(   4),  INT8_C(   2) } },
      { {  INT8_C(  49),  INT8_C(  77), -INT8_C(  25),  INT8_C(  30),  INT8_C(  84), -INT8_C(  41), -INT8_C(  48), -INT8_C(  67),
           INT8_C( 107), -INT8_C(  78),  INT8_C(  25),  INT8_C( 120),  INT8_C(  18), -INT8_C( 114), -INT8_C(  30), -INT8_C(  85) },
        {  INT8_C(   3),  INT8_C(   4),  INT8_C(   6),  INT8_C(   4),  INT8_C(   3),  INT8_C(   6),  INT8_C(   3),  INT8_C(   6),
           INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5) } },
      { { -INT8_C(  83),  INT8_C(  87),  INT8_C(  98), -INT8_C(  56),  INT8_C( 118), -INT8_C(  75), -INT8_C( 127), -INT8_C(  34),
           INT8_C(  67), -INT8_C(  51), -INT8_C(  32),  INT8_C( 107),  INT8_C(  73), -INT8_C(  13),  INT8_C( 103), -INT8_C( 121) },
        {  INT8_C(   5),  INT8_C(   5),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   5),  INT8_C(   2),  INT8_C(   6),
           INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   4) } },
      { {  INT8_C( 107), -INT8_C(  64), -INT8_C(  70), -INT8_C(  17),  INT8_C( 109),      INT8_MAX,  INT8_C(   6), -INT8_C(  67),
           INT8_C(  29), -INT8_C(  45), -INT8_C(  97),  INT8_C(  37), -INT8_C( 118), -INT8_C(  15), -INT8_C( 124), -INT8_C(  78) },
        {  INT8_C(   5),  INT8_C(   2),  INT8_C(   5),  INT8_C(   7),  INT8_C(   5),  INT8_C(   7),  INT8_C(   2),  INT8_C(   6),
           INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   2),  INT8_C(   4) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i8x16_popcnt(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a_[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t a, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      if (i == 0) {
        a_[0] = INT8_MIN;
        a_[1] = INT8_MAX;
        a_[2] = 0;
        a_[2] = ~INT8_C(0);
      }

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i8x16_popcnt(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_popcnt)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
