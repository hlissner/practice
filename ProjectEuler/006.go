// 006: Sum square difference - Go
// https://projecteuler.net/problem=6
//
// The sum of the squares of the first ten natural numbers is,
//
//     12 + 22 + ... + 102 = 385
//
// The square of the sum of the first ten natural numbers is,
//
//     (1 + 2 + ... + 10)2 = 552 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers
// and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural
// numbers and the square of the sum.

package main
import "fmt"

func main() {
	sumSq := 0
	sqSum := 0
	for i := 1; i <= 100; i++ {
		sumSq += i * i;
		sqSum += i;
	}
	sqSum = sqSum * sqSum
	fmt.Printf("%d - %d = %d\n", sqSum, sumSq, sqSum - sumSq)
}

