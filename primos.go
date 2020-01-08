package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	var i uint64
	fmt.Println("Dame un numero mayor a 2:")
	fmt.Scanf("%d", &i)
	start := time.Now()
	buscarprimos(i)
	t := time.Now()
	fmt.Println(t.Sub(start))
}
func buscarprimos(limite uint64) {
	var lp = []int{2}
	var i = 3
	for ; uint64(i) < limite; i += 2 {
		esPrimo := true
		sqrtLimite := int(math.Sqrt(float64(i)))
		for j := 0; j < len(lp); j++ {
			if i%lp[j] == 0 {
				esPrimo = false
				break
			}
			if lp[j] >= sqrtLimite {
				break
			}
		}
		if esPrimo {
			lp = append(lp, i)
		}
	}
	//fmt.Println(lp) //Descomentar para imprimir los numeros
}
