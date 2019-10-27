
isprime <- function(n) n <= 3L || all(n %% 2L:floor(sqrt(n)) != 0)

primes <- function(n){
    sum <- 1
    x <- -1
    for (i in 1:n) {
        repeat {
            x <- x + 2
            if (isprime(x)) {
                break
            }
        }
        sum <- sum + x
    }
    sum
}

cat(primes(1000))
# cat(primes(5))
