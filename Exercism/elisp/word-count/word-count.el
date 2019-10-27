;;; word-count.el --- word-count Exercise (exercism)

(defun word-count (text)
  (let (alist)
    (with-temp-buffer
      (save-excursion
        (insert text))
      (while (re-search-forward "[[:alnum:]]+" nil t)
        (let* ((word (downcase (match-string 0))))
          (setf (alist-get word alist nil nil #'equal)
                (1+ (or (cdr (assoc word alist)) 0))))))
    alist))

(provide 'word-count)
;;; word-count.el ends here
