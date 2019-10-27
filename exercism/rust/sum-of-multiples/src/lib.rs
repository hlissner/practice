fn is_multiple(n: u32, of: u32) -> bool {
    of != 0 && n % of == 0
}

pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    (1..limit).filter(|&i| factors.iter().any(|&j| is_multiple(i, j)))
              .sum()
}
