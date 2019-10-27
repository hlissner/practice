;;; robot-name.el --- Robot Name (exercism)

;;; Commentary:
;;
;; Build a robot with a name like AA000, that can be reset
;; to a new name. Instructions are in README.md
;;

;;; Code:

(defun build-robot ()
  (reset-robot (cons 'robot nil)))

(defun robot-name (robot)
  (cdr robot))

(defun reset-robot (robot)
  (setcdr robot (format "%c%c%d"
                        (+ ?A (random 26))
                        (+ ?A (random 26))
                        (random 1000)))
  robot)

(provide 'robot-name)
;;; robot-name.el ends here
