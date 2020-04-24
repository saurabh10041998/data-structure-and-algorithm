package main

import "fmt"

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for t > 0 {
		var x int
		fmt.Scanf("%d", &x)
		var a [200]int
		m, flag := 0, x
		for flag != 0 {
			a[m] = flag % 10
			flag = flag / 10
			m++
		}

		//calculating the fact
		temp, k, index := 0, 0, 0
		for i := 2; i < x; i++ {
			for index = 0; index < m; index++ {
				k = a[index]*i + temp
				a[index] = k % 10
				temp = k / 10
			}
			for temp != 0 {
				a[index] = temp % 10
				temp = temp / 10
				index++
				m++
			}
		}

		for i := m - 1; i >= 0; i-- {
			fmt.Print(a[i])
		}
		fmt.Println()
		t--

	}
}
