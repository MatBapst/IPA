; Auto-generated. Do not edit!


(cl:in-package seher_msgs-msg)


;//! \htmlinclude distances.msg.html

(cl:defclass <distances> (roslisp-msg-protocol:ros-message)
  ((head
    :reader head
    :initarg :head
    :type cl:float
    :initform 0.0)
   (left_shoulder
    :reader left_shoulder
    :initarg :left_shoulder
    :type cl:float
    :initform 0.0)
   (right_shoulder
    :reader right_shoulder
    :initarg :right_shoulder
    :type cl:float
    :initform 0.0)
   (left_elbow
    :reader left_elbow
    :initarg :left_elbow
    :type cl:float
    :initform 0.0)
   (right_elbow
    :reader right_elbow
    :initarg :right_elbow
    :type cl:float
    :initform 0.0)
   (left_hand
    :reader left_hand
    :initarg :left_hand
    :type cl:float
    :initform 0.0)
   (right_hand
    :reader right_hand
    :initarg :right_hand
    :type cl:float
    :initform 0.0)
   (torso
    :reader torso
    :initarg :torso
    :type cl:float
    :initform 0.0)
   (minimal
    :reader minimal
    :initarg :minimal
    :type cl:float
    :initform 0.0))
)

(cl:defclass distances (<distances>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <distances>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'distances)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name seher_msgs-msg:<distances> is deprecated: use seher_msgs-msg:distances instead.")))

(cl:ensure-generic-function 'head-val :lambda-list '(m))
(cl:defmethod head-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:head-val is deprecated.  Use seher_msgs-msg:head instead.")
  (head m))

(cl:ensure-generic-function 'left_shoulder-val :lambda-list '(m))
(cl:defmethod left_shoulder-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:left_shoulder-val is deprecated.  Use seher_msgs-msg:left_shoulder instead.")
  (left_shoulder m))

(cl:ensure-generic-function 'right_shoulder-val :lambda-list '(m))
(cl:defmethod right_shoulder-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:right_shoulder-val is deprecated.  Use seher_msgs-msg:right_shoulder instead.")
  (right_shoulder m))

(cl:ensure-generic-function 'left_elbow-val :lambda-list '(m))
(cl:defmethod left_elbow-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:left_elbow-val is deprecated.  Use seher_msgs-msg:left_elbow instead.")
  (left_elbow m))

(cl:ensure-generic-function 'right_elbow-val :lambda-list '(m))
(cl:defmethod right_elbow-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:right_elbow-val is deprecated.  Use seher_msgs-msg:right_elbow instead.")
  (right_elbow m))

(cl:ensure-generic-function 'left_hand-val :lambda-list '(m))
(cl:defmethod left_hand-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:left_hand-val is deprecated.  Use seher_msgs-msg:left_hand instead.")
  (left_hand m))

(cl:ensure-generic-function 'right_hand-val :lambda-list '(m))
(cl:defmethod right_hand-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:right_hand-val is deprecated.  Use seher_msgs-msg:right_hand instead.")
  (right_hand m))

(cl:ensure-generic-function 'torso-val :lambda-list '(m))
(cl:defmethod torso-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:torso-val is deprecated.  Use seher_msgs-msg:torso instead.")
  (torso m))

(cl:ensure-generic-function 'minimal-val :lambda-list '(m))
(cl:defmethod minimal-val ((m <distances>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_msgs-msg:minimal-val is deprecated.  Use seher_msgs-msg:minimal instead.")
  (minimal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <distances>) ostream)
  "Serializes a message object of type '<distances>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'head))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_shoulder))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_shoulder))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_elbow))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_elbow))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_hand))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_hand))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'torso))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'minimal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <distances>) istream)
  "Deserializes a message object of type '<distances>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'head) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_shoulder) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_shoulder) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_elbow) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_elbow) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_hand) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_hand) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'torso) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'minimal) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<distances>)))
  "Returns string type for a message object of type '<distances>"
  "seher_msgs/distances")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'distances)))
  "Returns string type for a message object of type 'distances"
  "seher_msgs/distances")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<distances>)))
  "Returns md5sum for a message object of type '<distances>"
  "bddb02bb0596d089d8172f7a50bef87e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'distances)))
  "Returns md5sum for a message object of type 'distances"
  "bddb02bb0596d089d8172f7a50bef87e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<distances>)))
  "Returns full string definition for message of type '<distances>"
  (cl:format cl:nil "#distances between TCP and human body parts~%#respectively head, left_shoulder, right_shoulder,left_elbow~%#right_elbow, left_hand, right_hand , torso~%~%float32 head~%float32 left_shoulder~%float32 right_shoulder~%float32 left_elbow~%float32 right_elbow~%float32 left_hand~%float32 right_hand~%float32 torso~%float32 minimal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'distances)))
  "Returns full string definition for message of type 'distances"
  (cl:format cl:nil "#distances between TCP and human body parts~%#respectively head, left_shoulder, right_shoulder,left_elbow~%#right_elbow, left_hand, right_hand , torso~%~%float32 head~%float32 left_shoulder~%float32 right_shoulder~%float32 left_elbow~%float32 right_elbow~%float32 left_hand~%float32 right_hand~%float32 torso~%float32 minimal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <distances>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <distances>))
  "Converts a ROS message object to a list"
  (cl:list 'distances
    (cl:cons ':head (head msg))
    (cl:cons ':left_shoulder (left_shoulder msg))
    (cl:cons ':right_shoulder (right_shoulder msg))
    (cl:cons ':left_elbow (left_elbow msg))
    (cl:cons ':right_elbow (right_elbow msg))
    (cl:cons ':left_hand (left_hand msg))
    (cl:cons ':right_hand (right_hand msg))
    (cl:cons ':torso (torso msg))
    (cl:cons ':minimal (minimal msg))
))
