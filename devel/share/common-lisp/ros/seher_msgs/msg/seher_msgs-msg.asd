
(cl:in-package :asdf)

(defsystem "seher_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "distances" :depends-on ("_package_distances"))
    (:file "_package_distances" :depends-on ("_package"))
  ))