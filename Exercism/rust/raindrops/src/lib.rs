pub fn raindrops(n: usize) -> String {
    let factors = vec![(3, "Pling"), (5, "Plang"), (7, "Plong")]
        .iter()
        .map(|&(f,s)| if n % f == 0 {s} else {""})
        .collect::<String>();
    match factors {
        _ if factors.is_empty() => n.to_string(),
        _ => factors
    }
}
