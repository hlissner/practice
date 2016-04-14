#!/usr/bin/env ruby

class Squares
  VERSION = 2

  def initialize(n)
    @n = n
  end

  def square_of_sum
    (@n * (@n + 1) / 2) ** 2
  end

  def sum_of_squares
    ((2 * @n) + 1) * (@n + 1) * @n / 6
  end

  def difference
    square_of_sum - sum_of_squares
  end
end
