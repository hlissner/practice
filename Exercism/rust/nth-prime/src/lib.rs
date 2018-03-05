#![feature(iterator_step_by)]  // eh, just do it

fn is_prime(n: i32) -> bool {
    match n {
        _ if n < 2       => false,
        _ if n < 4       => true,
        _ if n & 1 == 0  => false,
        _ => {
            let max = (n as f32).sqrt() as i32;
            !(3..max + 1).step_by(2).any(|i| n % i == 0)
        }
    }
}

pub fn nth(n: usize) -> Result<i32,()> {
    match n {
        _ if n < 1 => Err(()),
        _ if n < 3 => Ok([2,3][n-1]),
        _ => Ok((5..).step_by(2)
                     .filter(|&x| is_prime(x))
                     .nth(n - 3)
                     .unwrap())
    }
}
