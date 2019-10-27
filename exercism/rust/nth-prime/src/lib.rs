fn is_prime(n: u32) -> bool {
    ! (2..3).chain((3..(n as f32).sqrt() as u32 + 1).step_by(2))
            .any(|x| n % x == 0)
}

pub fn nth(n: u32) -> u32 {
    (2..3).chain((3..).filter(|x| is_prime(*x)))
          .nth(n as usize)
          .unwrap()
}
