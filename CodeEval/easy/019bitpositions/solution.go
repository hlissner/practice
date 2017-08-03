package main

import "fmt"
import "bufio"
import "os"
import "strings"
import "strconv"

func main() {
    file, _ := os.Open(os.Args[1])
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
		s := strings.Split(scanner.Text(), ",")
		n, _ := strconv.ParseUint(s[0], 10, 16)
		i, _ := strconv.ParseUint(s[1], 10, 16)
		j, _ := strconv.ParseUint(s[2], 10, 16)
		
		if (n >> (i-1)) & 1 == (n >> (j-1)) & 1 {
			fmt.Println("true")
		} else {
			fmt.Println("false")
		}
    }
}
