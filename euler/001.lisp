; 001: Multiples of 3 and 5 - Common Lisp
; https://projecteuler.net/problem=1

(defun sum-multiples (i)
  (if (zerop i) i
    (+ (if (member 0 (list (mod i 3) (mod i 5))) i 0)
       (sum-multiples (1- i)))))

(write (sum-multiples 999))
