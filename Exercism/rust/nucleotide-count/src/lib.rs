use std::collections::HashMap;

const ALLOWED: [char; 4] = ['A', 'T', 'C', 'G'];

type DNAResult<T> = Result<T, ()>;

fn is_valid_char(c: char) -> bool {
    ALLOWED.contains(&c)
}

fn is_valid_str(str: &str) -> bool {
    str.chars().all(is_valid_char)
}

pub fn count(c: char, s: &str) -> DNAResult<usize> {
    if is_valid_char(c) && is_valid_str(&s) {
        Ok(s.matches(c).count())
    } else {
        Err(())
    }
}

pub fn nucleotide_counts(s: &str) -> DNAResult<HashMap<char, usize>> {
    if is_valid_str(&s) {
        Ok(ALLOWED.into_iter().map(|ch| (*ch, count(*ch, &s).unwrap())).collect())
    } else {
        Err(())
    }
}
