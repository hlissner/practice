pub fn raindrops(n: usize) -> String {
    let factors = vec![(3, "Pling"), (5, "Plang"), (7, "Plong")]
        .iter()
        .filter_map(|&(f,s)| if n % f == 0 {Some(s)} else {None})
        .collect::<String>();
    if factors.is_empty() {n.to_string()} else {factors}
}
