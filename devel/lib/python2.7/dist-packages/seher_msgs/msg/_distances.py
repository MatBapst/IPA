# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from seher_msgs/distances.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class distances(genpy.Message):
  _md5sum = "bddb02bb0596d089d8172f7a50bef87e"
  _type = "seher_msgs/distances"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """#distances between TCP and human body parts
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
"""
  __slots__ = ['head','left_shoulder','right_shoulder','left_elbow','right_elbow','left_hand','right_hand','torso','minimal']
  _slot_types = ['float32','float32','float32','float32','float32','float32','float32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       head,left_shoulder,right_shoulder,left_elbow,right_elbow,left_hand,right_hand,torso,minimal

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(distances, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.head is None:
        self.head = 0.
      if self.left_shoulder is None:
        self.left_shoulder = 0.
      if self.right_shoulder is None:
        self.right_shoulder = 0.
      if self.left_elbow is None:
        self.left_elbow = 0.
      if self.right_elbow is None:
        self.right_elbow = 0.
      if self.left_hand is None:
        self.left_hand = 0.
      if self.right_hand is None:
        self.right_hand = 0.
      if self.torso is None:
        self.torso = 0.
      if self.minimal is None:
        self.minimal = 0.
    else:
      self.head = 0.
      self.left_shoulder = 0.
      self.right_shoulder = 0.
      self.left_elbow = 0.
      self.right_elbow = 0.
      self.left_hand = 0.
      self.right_hand = 0.
      self.torso = 0.
      self.minimal = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_9f().pack(_x.head, _x.left_shoulder, _x.right_shoulder, _x.left_elbow, _x.right_elbow, _x.left_hand, _x.right_hand, _x.torso, _x.minimal))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 36
      (_x.head, _x.left_shoulder, _x.right_shoulder, _x.left_elbow, _x.right_elbow, _x.left_hand, _x.right_hand, _x.torso, _x.minimal,) = _get_struct_9f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_9f().pack(_x.head, _x.left_shoulder, _x.right_shoulder, _x.left_elbow, _x.right_elbow, _x.left_hand, _x.right_hand, _x.torso, _x.minimal))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 36
      (_x.head, _x.left_shoulder, _x.right_shoulder, _x.left_elbow, _x.right_elbow, _x.left_hand, _x.right_hand, _x.torso, _x.minimal,) = _get_struct_9f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_9f = None
def _get_struct_9f():
    global _struct_9f
    if _struct_9f is None:
        _struct_9f = struct.Struct("<9f")
    return _struct_9f
