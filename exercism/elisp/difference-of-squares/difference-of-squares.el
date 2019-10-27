;;; difference-of-squares.el --- Difference of Squares (exercism)

(defun sum-of-squares (n)
  (/ (* (1+ (* 2 n)) (1+ n) n) 6))

(defun square-of-sum (n)
  (expt (/ (* n (1+ n)) 2) 2))

(defun difference (n)
  (- (square-of-sum n)
     (sum-of-squares n)))

(provide 'difference-of-squares)
;;; difference-of-squares.el ends here
