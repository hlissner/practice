;;; gigasecond.el --- Gigasecond exercise (exercism)

(defun from (s m h D M Y)
  (nbutlast ; discard dow, dst & utcoff
   (decode-time (encode-time (+ s (expt 10 9)) m h D M Y 0)
                0)
   3))

(provide 'gigasecond)
;;; gigasecond.el ends here
