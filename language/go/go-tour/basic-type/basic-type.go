package main

import (
	"fmt"
	"math/cmplx"
)

var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

func main() {
	fmt.Printf("Type:%T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type:%T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type:%T Value: %v\n", z, z)
}

// bool

// string

// int  int8  int16  int32  int64
// uint uint8 uint16 uint32 uint64 uintptr

// byte // uint8의 별칭

// rune // int32의 별칭
//      // 유니코드에서 code point를 의미합니다.

// float32 float64

// complex64 complex128
// 명시적인 초깃값 없이 선언된 변수는 그것의 zero value 가 주어집니다.

// zero value 는 다음과 같습니다.

// 숫자 type에는 0
// boolean type에는 false
// string에는 "" (빈 문자열)
