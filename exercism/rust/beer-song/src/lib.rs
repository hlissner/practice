fn head(n: i32, cap: bool) -> String {
    match n {
        0  => format!("{}o more bottles", if cap { 'N' } else { 'n' }),
        1  => "1 bottle".to_string(),
        -1 => "99 bottles".to_string(),
        _  => format!("{} bottles", n)
    }
}

fn tail(n: i32) -> String {
    match n {
        0 => "Go to the store and buy some more,".to_string(),
        _ => format!("Take {} down and pass it around,", if n == 1 { "it" } else { "one" })
    }
}

pub fn verse(n: i32) -> String {
    format!("{} of beer on the wall, {} of beer.\n{} {} of beer on the wall.\n",
            head(n, true),
            head(n, false),
            tail(n),
            head(n-1, false))
}

pub fn sing(start: i32, end: i32) -> String {
    (end..start+1)
        .rev()
        .map(verse)
        .collect::<Vec<_>>()
        .join("\n")
}
