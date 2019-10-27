;;; raindrops.el --- Raindrops (exercism)

(defun convert (n)
  "Convert integer N to its raindrops string."
  (let ((str (concat (if (= 0 (% n 3)) "Pling")
                     (if (= 0 (% n 5)) "Plang")
                     (if (= 0 (% n 7)) "Plong"))))
    (if (string= str "")
        (number-to-string n)
      str)))

(provide 'raindrops)
;;; raindrops.el ends here
