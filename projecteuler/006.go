// 006: Sum square difference - Go
// https://projecteuler.net/problem=6
//
// The sum of the squares of the first ten natural numbers is,
//
//     1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is,
//
//     (1 + 2 + ... + 10)^2 = 55^2 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers
// and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred natural
// numbers and the square of the sum.

package main
import "fmt"

// O(n)
func naive(limit int) int {
	sumSq := 0
	sqSum := 0
	for i := 1; i <= limit; i++ {
		sumSq += i * i;
		sqSum += i;
	}
	return (sqSum * sqSum) - sumSq
}

// O(1)
func fast(limit int) int {
	sumSq := ((2 * limit) + 1) * (limit + 1) * limit / 6
	sqSum := limit * (limit + 1) / 2
	return (sqSum * sqSum) - sumSq
}

func main() {
	fmt.Printf("%d\n", naive(100))
	fmt.Printf("%d\n", fast(100))
}

