// 005: Smallest multiple - Rust
// https://projecteuler.net/problem=5
//
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10
// without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the numbers
// from 1 to 20?

fn even_div(n: &i32) -> bool {
    (3..20).find(|x| n*20 % x > 0) == None
}

fn main() {
    let n = (200..).filter(|n| even_div(n)).take(1).nth(0).unwrap();
    println!("{}", n * 20);
}
