; 001: Multiples of 3 and 5 - Common Lisp
; https://projecteuler.net/problem=1
;
; If we list all the natural numbers below 10 that are multiples of 3 or 5, we
; get 3, 5, 6 and 9. The sum of these multiples is 23.
;
; Find the sum of all the multiples of 3 or 5 below 1000.

(defun sum-multiples (d ai max)
  (let ((af (* (floor (/ (1- max) d)) d)))
    (/ (* (/ af d) (+ ai af)) 2)))

(let ((a 3)
      (b 5)
      (max 1000))
  (write (+ (sum-multiples a a max)
            (sum-multiples b b max)
            (- (sum-multiples (* a b) (* a b) max)))))

