/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
# include <stdio.h>
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return (~x & y) | (x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return !(0x7FFFFFFF ^ x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // 先用掩码提取出所有奇数位
  int mask = 0xaaaaaaaa;
  x = mask & x;
  // 【重要】二进制判断两个数是否相等可以采用这种异或 + 逻辑非的形式
  return !(x ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // 取反码 + 1
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 减法运算也通过二进制，通过异或运算判断是不是在范围内
  // 这里的思路主要还是x - 0x30 >= 0, x - 0x3A < 0，这里采用0x3A而不是0x39主要是考虑到边界条件
  return !((((x + ~0x30 + 1) >> 31) ^ 0) | (((x + ~0x3A + 1) >> 31) ^ 0xFFFFFFFF));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // 这个flag的含义是说，先通过!!x得到x对应的逻辑值，然后对逻辑值取补码，因为0的补码还是0，即全0，但是1的补码是-1，即全1，
  // 我们需要用到全0和全1去得到结果（全0和全1适合用于条件判断，因为只需要取反码就可以得到对方。）
  int flag = ~(!!x) + 1;
  return (flag & y) | (~(flag) & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // 情况一：x和y符号不同，y为正数，x为负数
  // 情况二：x和y符号相同，y - x >= 0（符号相同不会出现溢出）
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int x_y_same_sign = sign_x ^ sign_y; // 相同为全0，不同为全1
  return !((~x_y_same_sign & ((y + ~x + 1) >> 31)) | (x_y_same_sign & (sign_y ^ 0) & (sign_x ^ 0xFFFFFFFF)));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 判断x是否为0即可
  return !(x ^ 0);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 先判断x的正负：如果为负数，需要先取反，最后需要在计算出来的位数上加一位符号位
  int sign = x >> 31;
  x = sign ^ x;

  // 采用二分的思路计算位数，每次都判断位移后的整数是否为零，逐步定位位数，说起来比较复杂，举几个例子就会了
  int bit_16 = (!!(x >> 16 ^ 0) << 4);
  x >>= bit_16;
  int bit_8 = (!!(x >> 8 ^ 0) << 3);
  x >>= bit_8;
  int bit_4 = (!!(x >> 4 ^ 0) << 2);
  x >>= bit_4;
  int bit_2 = (!!(x >> 2 ^ 0) << 1);
  x >>= bit_2;
  int bit_1 = !!(x >> 1 ^ 0);
  x >>= bit_1;
  // 最后还需要检查下最后一个比特是否为1
  int bit_0 = !!(x ^ 0);
  
  // 最后一个1是符号位
  return bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + bit_0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 二进制通过掩码获取s, exp以及frac是最合适的，不应该想着用循环，麻烦
  unsigned exp_mask = 0x7F800000u;
  unsigned frac_mask = 0x007FFFFFu;
  unsigned s_mask = 0x80000000u;

  unsigned exp = (exp_mask & uf) >> 23;
  unsigned frac = frac_mask & uf;
  // 如果exp == 111...1，则直接返回uf，这包括无穷和NaN的情况
  if (exp == 255) return uf;
  else if (exp == 0) {
    // 如果exp == 000...0，需要做特殊处理
    if (frac == 0u) return uf; // 正负0直接返回0本身
    else {
      // 否则需要左移frac部分，如果超过23位，则变为nomalized的形式
      frac <<= 1;
      // 提取第24位比特，判断第二十四位比特是否为1
      unsigned mask_24_bit = 0x00800000u;
      // ！！！ 我真服了， !=的优先级大于&，打括号！
      if ((mask_24_bit & frac) != 0) {
        exp += 1u;
      }
      return (s_mask & uf) + (exp << 23) + (frac_mask & frac);
    }
  } 
  // normalized的情况直接exp + 1就好了
  exp += 1u;
  // !!!踩了大坑，&的优先级比+更低，建议还是老实打括号
  return (s_mask & uf) + (exp << 23) + frac;

}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned exp_mask = 0x7F800000u;
  unsigned s_mask = 0x80000000u;

  int exp = (exp_mask & uf) >> 23;
  int s = (s_mask & uf) >> 31;
  if (exp == 255) return 0x80000000u;
  else if (exp < 127) return 0; // 靠近0的时候直接返回0，这同时包括denorm的情况和norm的情况

  // int精度溢出的情况，根据题意，返回0x80000000u
  if ((s > 0 && exp - 127 > 31) || (s == 0 && exp - 127 >= 31)) return 0x80000000u;

  // 大于1且不会出现精度溢出的情况直接截断
  return s > 0 ? -1 * (1 <<(exp - 127)) : 1 <<(exp - 127);

}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // 理解下E和exp的区别，容易弄混
  if (x < -126) return 0u;
  else if (x >= 128) return 0x7F800000u;
  else{
    unsigned exp_unsigned = x + 127;
    return exp_unsigned << 23;
  }
}
