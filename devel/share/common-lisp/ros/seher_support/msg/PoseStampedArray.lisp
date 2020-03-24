; Auto-generated. Do not edit!


(cl:in-package seher_support-msg)


;//! \htmlinclude PoseStampedArray.msg.html

(cl:defclass <PoseStampedArray> (roslisp-msg-protocol:ros-message)
  ((stamped_poses
    :reader stamped_poses
    :initarg :stamped_poses
    :type (cl:vector geometry_msgs-msg:PoseStamped)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:PoseStamped :initial-element (cl:make-instance 'geometry_msgs-msg:PoseStamped))))
)

(cl:defclass PoseStampedArray (<PoseStampedArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PoseStampedArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PoseStampedArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name seher_support-msg:<PoseStampedArray> is deprecated: use seher_support-msg:PoseStampedArray instead.")))

(cl:ensure-generic-function 'stamped_poses-val :lambda-list '(m))
(cl:defmethod stamped_poses-val ((m <PoseStampedArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader seher_support-msg:stamped_poses-val is deprecated.  Use seher_support-msg:stamped_poses instead.")
  (stamped_poses m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PoseStampedArray>) ostream)
  "Serializes a message object of type '<PoseStampedArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'stamped_poses))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'stamped_poses))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PoseStampedArray>) istream)
  "Deserializes a message object of type '<PoseStampedArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'stamped_poses) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'stamped_poses)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:PoseStamped))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PoseStampedArray>)))
  "Returns string type for a message object of type '<PoseStampedArray>"
  "seher_support/PoseStampedArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PoseStampedArray)))
  "Returns string type for a message object of type 'PoseStampedArray"
  "seher_support/PoseStampedArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PoseStampedArray>)))
  "Returns md5sum for a message object of type '<PoseStampedArray>"
  "06f872dd9a9374c503dfaed9499d3a21")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PoseStampedArray)))
  "Returns md5sum for a message object of type 'PoseStampedArray"
  "06f872dd9a9374c503dfaed9499d3a21")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PoseStampedArray>)))
  "Returns full string definition for message of type '<PoseStampedArray>"
  (cl:format cl:nil "geometry_msgs/PoseStamped[] stamped_poses~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PoseStampedArray)))
  "Returns full string definition for message of type 'PoseStampedArray"
  (cl:format cl:nil "geometry_msgs/PoseStamped[] stamped_poses~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PoseStampedArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'stamped_poses) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PoseStampedArray>))
  "Converts a ROS message object to a list"
  (cl:list 'PoseStampedArray
    (cl:cons ':stamped_poses (stamped_poses msg))
))
