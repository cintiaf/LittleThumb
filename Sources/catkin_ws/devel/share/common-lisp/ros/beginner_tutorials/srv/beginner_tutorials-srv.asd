
(cl:in-package :asdf)

(defsystem "beginner_tutorials-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "javaClient" :depends-on ("_package_javaClient"))
    (:file "_package_javaClient" :depends-on ("_package"))
    (:file "graphicClient" :depends-on ("_package_graphicClient"))
    (:file "_package_graphicClient" :depends-on ("_package"))
    (:file "AddTwoInts" :depends-on ("_package_AddTwoInts"))
    (:file "_package_AddTwoInts" :depends-on ("_package"))
  ))