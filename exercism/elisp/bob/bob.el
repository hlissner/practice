;;; bob.el --- Bob exercise (exercism)

;; I intentionally avoid the subr-x library

(defun yelling-p (sentence)
  (and (string= (upcase sentence) sentence)
       (not (string= (downcase sentence) sentence))))

(defun response-for (sentence)
  (let ((sentence (replace-regexp-in-string "\\(?:^\\s-+\\|\\s-+$\\)" "" sentence)))
    (cond ((string= "" sentence)
           "Fine. Be that way!")
          ((string= (substring sentence -1) "?")
           (if (yelling-p sentence)
               "Calm down, I know what I'm doing!"
             "Sure."))
          ((yelling-p sentence)
           "Whoa, chill out!")
          ("Whatever."))))

(provide 'bob)
;;; bob.el ends here
