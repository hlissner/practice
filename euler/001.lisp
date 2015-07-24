; 001: Multiples of 3 and 5 - Common Lisp
; https://projecteuler.net/problem=1
;
; If we list all the natural numbers below 10 that are multiples of 3 or 5, we
; get 3, 5, 6 and 9. The sum of these multiples is 23.
;
; Find the sum of all the multiples of 3 or 5 below 1000.

(defun sum-multiples (i)
  (if (zerop i) i
    (+ (if (member 0 (list (mod i 3) (mod i 5))) i 0)
       (sum-multiples (1- i)))))

(write (sum-multiples 999))
