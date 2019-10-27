;;; pangram.el --- Pangram (exercism)

(defun is-pangram (str)
  (cl-loop with chars = (string-to-list (downcase str))
           for i from ?a to ?z
           unless (memq i chars) return nil
           finally return t))

(provide 'pangram)
;;; pangram.el ends here
