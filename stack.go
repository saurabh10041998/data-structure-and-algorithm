package main

import "fmt"

type stack struct {
	st []byte
}

func (s *stack) push(ele byte) {
	s.st = append(s.st, ele)
}

func (s *stack) pop() {
	s.st = s.st[:len(s.st)-1]
}

func (s *stack) top() byte {
	return s.st[len(s.st)-1]
}

func prec(x byte) int {
	if x == '^' {
		return 3
	}
	if x == '*' || x == '/' {
		return 2
	}
	if x == '+' || x == '-' {
		return 1
	}
	return -1
}

func main() {
	var t int
	fmt.Scanf("%d", &t)

	for t > 0 {
		var s string
		fmt.Scanln(&s)
		n := len(s)
		st := stack{}
		st.push('$')
		ns := []byte{}
		for i := 0; i < n; i++ {
			if s[i] >= 'a' && s[i] <= 'z' {
				ns = append(ns, s[i])
			} else if s[i] == '(' {
				st.push('(')
			} else if s[i] == ')' {
				for st.top() != '$' && st.top() != '(' {
					c := st.top()
					ns = append(ns, c)
					st.pop()
				}
				if st.top() == '(' {
					st.pop()
				}
			} else {
				for st.top() != '$' && prec(s[i]) <= prec(st.top()) {
					c := st.top()
					ns = append(ns, c)
					st.pop()
				}
				st.push(s[i])
			}
		}
		for st.top() != '$' {
			c := st.top()
			ns = append(ns, c)
			st.pop()
		}
		fmt.Println(string(ns))
		t--
	}

}
