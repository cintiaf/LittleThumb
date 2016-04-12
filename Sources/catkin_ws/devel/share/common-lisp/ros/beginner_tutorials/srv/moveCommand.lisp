; Auto-generated. Do not edit!


(cl:in-package beginner_tutorials-srv)


;//! \htmlinclude moveCommand-request.msg.html

(cl:defclass <moveCommand-request> (roslisp-msg-protocol:ros-message)
  ((dir1
    :reader dir1
    :initarg :dir1
    :type cl:string
    :initform "")
   (dir2
    :reader dir2
    :initarg :dir2
    :type cl:string
    :initform "")
   (speed
    :reader speed
    :initarg :speed
    :type cl:integer
    :initform 0))
)

(cl:defclass moveCommand-request (<moveCommand-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <moveCommand-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'moveCommand-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-srv:<moveCommand-request> is deprecated: use beginner_tutorials-srv:moveCommand-request instead.")))

(cl:ensure-generic-function 'dir1-val :lambda-list '(m))
(cl:defmethod dir1-val ((m <moveCommand-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-srv:dir1-val is deprecated.  Use beginner_tutorials-srv:dir1 instead.")
  (dir1 m))

(cl:ensure-generic-function 'dir2-val :lambda-list '(m))
(cl:defmethod dir2-val ((m <moveCommand-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-srv:dir2-val is deprecated.  Use beginner_tutorials-srv:dir2 instead.")
  (dir2 m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <moveCommand-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-srv:speed-val is deprecated.  Use beginner_tutorials-srv:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <moveCommand-request>) ostream)
  "Serializes a message object of type '<moveCommand-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dir1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dir1))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dir2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dir2))
  (cl:let* ((signed (cl:slot-value msg 'speed)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <moveCommand-request>) istream)
  "Deserializes a message object of type '<moveCommand-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dir1) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dir1) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dir2) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dir2) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'speed) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<moveCommand-request>)))
  "Returns string type for a service object of type '<moveCommand-request>"
  "beginner_tutorials/moveCommandRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'moveCommand-request)))
  "Returns string type for a service object of type 'moveCommand-request"
  "beginner_tutorials/moveCommandRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<moveCommand-request>)))
  "Returns md5sum for a message object of type '<moveCommand-request>"
  "79e4b5ff2a556e0eba818274612c4f67")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'moveCommand-request)))
  "Returns md5sum for a message object of type 'moveCommand-request"
  "79e4b5ff2a556e0eba818274612c4f67")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<moveCommand-request>)))
  "Returns full string definition for message of type '<moveCommand-request>"
  (cl:format cl:nil "string dir1~%string dir2~%int64 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'moveCommand-request)))
  "Returns full string definition for message of type 'moveCommand-request"
  (cl:format cl:nil "string dir1~%string dir2~%int64 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <moveCommand-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'dir1))
     4 (cl:length (cl:slot-value msg 'dir2))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <moveCommand-request>))
  "Converts a ROS message object to a list"
  (cl:list 'moveCommand-request
    (cl:cons ':dir1 (dir1 msg))
    (cl:cons ':dir2 (dir2 msg))
    (cl:cons ':speed (speed msg))
))
;//! \htmlinclude moveCommand-response.msg.html

(cl:defclass <moveCommand-response> (roslisp-msg-protocol:ros-message)
  ((ret
    :reader ret
    :initarg :ret
    :type cl:integer
    :initform 0))
)

(cl:defclass moveCommand-response (<moveCommand-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <moveCommand-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'moveCommand-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-srv:<moveCommand-response> is deprecated: use beginner_tutorials-srv:moveCommand-response instead.")))

(cl:ensure-generic-function 'ret-val :lambda-list '(m))
(cl:defmethod ret-val ((m <moveCommand-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-srv:ret-val is deprecated.  Use beginner_tutorials-srv:ret instead.")
  (ret m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <moveCommand-response>) ostream)
  "Serializes a message object of type '<moveCommand-response>"
  (cl:let* ((signed (cl:slot-value msg 'ret)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <moveCommand-response>) istream)
  "Deserializes a message object of type '<moveCommand-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ret) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<moveCommand-response>)))
  "Returns string type for a service object of type '<moveCommand-response>"
  "beginner_tutorials/moveCommandResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'moveCommand-response)))
  "Returns string type for a service object of type 'moveCommand-response"
  "beginner_tutorials/moveCommandResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<moveCommand-response>)))
  "Returns md5sum for a message object of type '<moveCommand-response>"
  "79e4b5ff2a556e0eba818274612c4f67")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'moveCommand-response)))
  "Returns md5sum for a message object of type 'moveCommand-response"
  "79e4b5ff2a556e0eba818274612c4f67")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<moveCommand-response>)))
  "Returns full string definition for message of type '<moveCommand-response>"
  (cl:format cl:nil "int64 ret~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'moveCommand-response)))
  "Returns full string definition for message of type 'moveCommand-response"
  (cl:format cl:nil "int64 ret~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <moveCommand-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <moveCommand-response>))
  "Converts a ROS message object to a list"
  (cl:list 'moveCommand-response
    (cl:cons ':ret (ret msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'moveCommand)))
  'moveCommand-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'moveCommand)))
  'moveCommand-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'moveCommand)))
  "Returns string type for a service object of type '<moveCommand>"
  "beginner_tutorials/moveCommand")