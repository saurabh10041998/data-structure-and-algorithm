package main

import "fmt"

const K int = 2

type matrix [K + 1][K + 1]int

var p int = int(1e9) + 7

// matrix multiplication

func matmul(a matrix, b matrix) matrix {
	c := matrix{}
	for i := 1; i <= K; i++ {
		for j := 1; j <= K; j++ {
			c[i][j] = 0
			for k := 1; k <= K; k++ {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % p
			}
		}
	}
	return c
}

// binary exp
func binaryExp(x matrix, n int) matrix {
	if n == 1 {
		return x
	}
	if n%2 == 1 {
		return matmul(x, binaryExp(x, n-1))
	}
	temp := binaryExp(x, n/2)
	return matmul(temp, temp)
}
func main() {

	// step 1: Initial matrix
	var F [K + 1]int
	F[1] = 1
	F[2] = 1

	// step 2 : Transformation matrix
	T := matrix{}
	T[1][1] = 0
	T[1][2] = 1
	T[2][1] = 1
	T[2][2] = 1

	//step 3 : find pow
	T = binaryExp(T, 4-1)

	//get the term
	res := 0
	for i := 1; i <= K; i++ {
		res = (res + T[1][i]*F[i]) % p
	}
	fmt.Println(res)

}
