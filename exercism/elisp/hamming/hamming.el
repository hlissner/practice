;;; hamming.el --- Hamming (exercism)

(defun hamming-distance (a b)
  (unless (= (length a)
             (length b))
    (error nil))
  (cl-count nil (cl-mapcar #'= a b)))

(provide 'hamming)
;;; hamming.el ends here
