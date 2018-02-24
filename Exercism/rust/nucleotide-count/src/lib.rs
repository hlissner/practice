use std::collections::HashMap;

const ALLOWED: [char; 4] = ['A', 'T', 'C', 'G'];

fn is_valid_char(c: char) -> bool {
    ALLOWED.contains(&c)
}

fn is_valid_str(str: &str) -> bool {
    str.chars().all(is_valid_char)
}

pub fn count(c: char, str: &str) -> Result<usize, ()> {
    if !(is_valid_char(c) && is_valid_str(&str)) {
        return Err(())
    }

    let mut count: usize = 0;
    for ch in str.chars() {
        if c == ch {
            count += 1;
        }
    }
    Ok(count)
}

pub fn nucleotide_counts(str: &str) -> Result<HashMap<char, usize>, ()> {
    if !is_valid_str(&str) {
        return Err(())
    }

    let mut result = HashMap::new();
    for ch in ALLOWED.iter() {
        result.insert(*ch, count(*ch, &str).unwrap());
    }
    Ok(result)
}
