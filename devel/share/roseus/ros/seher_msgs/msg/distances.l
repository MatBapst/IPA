;; Auto-generated. Do not edit!


(when (boundp 'seher_msgs::distances)
  (if (not (find-package "SEHER_MSGS"))
    (make-package "SEHER_MSGS"))
  (shadow 'distances (find-package "SEHER_MSGS")))
(unless (find-package "SEHER_MSGS::DISTANCES")
  (make-package "SEHER_MSGS::DISTANCES"))

(in-package "ROS")
;;//! \htmlinclude distances.msg.html


(defclass seher_msgs::distances
  :super ros::object
  :slots (_head _left_shoulder _right_shoulder _left_elbow _right_elbow _left_hand _right_hand _torso _minimal ))

(defmethod seher_msgs::distances
  (:init
   (&key
    ((:head __head) 0.0)
    ((:left_shoulder __left_shoulder) 0.0)
    ((:right_shoulder __right_shoulder) 0.0)
    ((:left_elbow __left_elbow) 0.0)
    ((:right_elbow __right_elbow) 0.0)
    ((:left_hand __left_hand) 0.0)
    ((:right_hand __right_hand) 0.0)
    ((:torso __torso) 0.0)
    ((:minimal __minimal) 0.0)
    )
   (send-super :init)
   (setq _head (float __head))
   (setq _left_shoulder (float __left_shoulder))
   (setq _right_shoulder (float __right_shoulder))
   (setq _left_elbow (float __left_elbow))
   (setq _right_elbow (float __right_elbow))
   (setq _left_hand (float __left_hand))
   (setq _right_hand (float __right_hand))
   (setq _torso (float __torso))
   (setq _minimal (float __minimal))
   self)
  (:head
   (&optional __head)
   (if __head (setq _head __head)) _head)
  (:left_shoulder
   (&optional __left_shoulder)
   (if __left_shoulder (setq _left_shoulder __left_shoulder)) _left_shoulder)
  (:right_shoulder
   (&optional __right_shoulder)
   (if __right_shoulder (setq _right_shoulder __right_shoulder)) _right_shoulder)
  (:left_elbow
   (&optional __left_elbow)
   (if __left_elbow (setq _left_elbow __left_elbow)) _left_elbow)
  (:right_elbow
   (&optional __right_elbow)
   (if __right_elbow (setq _right_elbow __right_elbow)) _right_elbow)
  (:left_hand
   (&optional __left_hand)
   (if __left_hand (setq _left_hand __left_hand)) _left_hand)
  (:right_hand
   (&optional __right_hand)
   (if __right_hand (setq _right_hand __right_hand)) _right_hand)
  (:torso
   (&optional __torso)
   (if __torso (setq _torso __torso)) _torso)
  (:minimal
   (&optional __minimal)
   (if __minimal (setq _minimal __minimal)) _minimal)
  (:serialization-length
   ()
   (+
    ;; float32 _head
    4
    ;; float32 _left_shoulder
    4
    ;; float32 _right_shoulder
    4
    ;; float32 _left_elbow
    4
    ;; float32 _right_elbow
    4
    ;; float32 _left_hand
    4
    ;; float32 _right_hand
    4
    ;; float32 _torso
    4
    ;; float32 _minimal
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _head
       (sys::poke _head (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _left_shoulder
       (sys::poke _left_shoulder (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_shoulder
       (sys::poke _right_shoulder (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _left_elbow
       (sys::poke _left_elbow (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_elbow
       (sys::poke _right_elbow (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _left_hand
       (sys::poke _left_hand (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_hand
       (sys::poke _right_hand (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _torso
       (sys::poke _torso (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _minimal
       (sys::poke _minimal (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _head
     (setq _head (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _left_shoulder
     (setq _left_shoulder (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_shoulder
     (setq _right_shoulder (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _left_elbow
     (setq _left_elbow (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_elbow
     (setq _right_elbow (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _left_hand
     (setq _left_hand (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_hand
     (setq _right_hand (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _torso
     (setq _torso (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _minimal
     (setq _minimal (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get seher_msgs::distances :md5sum-) "bddb02bb0596d089d8172f7a50bef87e")
(setf (get seher_msgs::distances :datatype-) "seher_msgs/distances")
(setf (get seher_msgs::distances :definition-)
      "#distances between TCP and human body parts
#respectively head, left_shoulder, right_shoulder,left_elbow
#right_elbow, left_hand, right_hand , torso

float32 head
float32 left_shoulder
float32 right_shoulder
float32 left_elbow
float32 right_elbow
float32 left_hand
float32 right_hand
float32 torso
float32 minimal

")



(provide :seher_msgs/distances "bddb02bb0596d089d8172f7a50bef87e")


