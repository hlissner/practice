;;; anagram.el --- Anagram (exercism)

(defun anagrams-for (word candidates)
  (cl-loop with sorted = (cl-sort (downcase word) #'<)
           for cand in candidates
           if (and (not (string= word cand))
                   (string= (cl-sort (downcase cand) #'<)
                            sorted))
           collect cand))

(provide 'anagram)
;;; anagram.el ends here
