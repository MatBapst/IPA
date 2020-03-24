;; Auto-generated. Do not edit!


(when (boundp 'seher_support::PoseStampedArray)
  (if (not (find-package "SEHER_SUPPORT"))
    (make-package "SEHER_SUPPORT"))
  (shadow 'PoseStampedArray (find-package "SEHER_SUPPORT")))
(unless (find-package "SEHER_SUPPORT::POSESTAMPEDARRAY")
  (make-package "SEHER_SUPPORT::POSESTAMPEDARRAY"))

(in-package "ROS")
;;//! \htmlinclude PoseStampedArray.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass seher_support::PoseStampedArray
  :super ros::object
  :slots (_stamped_poses ))

(defmethod seher_support::PoseStampedArray
  (:init
   (&key
    ((:stamped_poses __stamped_poses) (let (r) (dotimes (i 0) (push (instance geometry_msgs::PoseStamped :init) r)) r))
    )
   (send-super :init)
   (setq _stamped_poses __stamped_poses)
   self)
  (:stamped_poses
   (&rest __stamped_poses)
   (if (keywordp (car __stamped_poses))
       (send* _stamped_poses __stamped_poses)
     (progn
       (if __stamped_poses (setq _stamped_poses (car __stamped_poses)))
       _stamped_poses)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PoseStamped[] _stamped_poses
    (apply #'+ (send-all _stamped_poses :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PoseStamped[] _stamped_poses
     (write-long (length _stamped_poses) s)
     (dolist (elem _stamped_poses)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PoseStamped[] _stamped_poses
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _stamped_poses (let (r) (dotimes (i n) (push (instance geometry_msgs::PoseStamped :init) r)) r))
     (dolist (elem- _stamped_poses)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get seher_support::PoseStampedArray :md5sum-) "06f872dd9a9374c503dfaed9499d3a21")
(setf (get seher_support::PoseStampedArray :datatype-) "seher_support/PoseStampedArray")
(setf (get seher_support::PoseStampedArray :definition-)
      "geometry_msgs/PoseStamped[] stamped_poses

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :seher_support/PoseStampedArray "06f872dd9a9374c503dfaed9499d3a21")


