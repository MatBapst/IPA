// Auto-generated. Do not edit!

// (in-package seher_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class distances {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.head = null;
      this.left_shoulder = null;
      this.right_shoulder = null;
      this.left_elbow = null;
      this.right_elbow = null;
      this.left_hand = null;
      this.right_hand = null;
      this.torso = null;
      this.minimal = null;
    }
    else {
      if (initObj.hasOwnProperty('head')) {
        this.head = initObj.head
      }
      else {
        this.head = 0.0;
      }
      if (initObj.hasOwnProperty('left_shoulder')) {
        this.left_shoulder = initObj.left_shoulder
      }
      else {
        this.left_shoulder = 0.0;
      }
      if (initObj.hasOwnProperty('right_shoulder')) {
        this.right_shoulder = initObj.right_shoulder
      }
      else {
        this.right_shoulder = 0.0;
      }
      if (initObj.hasOwnProperty('left_elbow')) {
        this.left_elbow = initObj.left_elbow
      }
      else {
        this.left_elbow = 0.0;
      }
      if (initObj.hasOwnProperty('right_elbow')) {
        this.right_elbow = initObj.right_elbow
      }
      else {
        this.right_elbow = 0.0;
      }
      if (initObj.hasOwnProperty('left_hand')) {
        this.left_hand = initObj.left_hand
      }
      else {
        this.left_hand = 0.0;
      }
      if (initObj.hasOwnProperty('right_hand')) {
        this.right_hand = initObj.right_hand
      }
      else {
        this.right_hand = 0.0;
      }
      if (initObj.hasOwnProperty('torso')) {
        this.torso = initObj.torso
      }
      else {
        this.torso = 0.0;
      }
      if (initObj.hasOwnProperty('minimal')) {
        this.minimal = initObj.minimal
      }
      else {
        this.minimal = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type distances
    // Serialize message field [head]
    bufferOffset = _serializer.float32(obj.head, buffer, bufferOffset);
    // Serialize message field [left_shoulder]
    bufferOffset = _serializer.float32(obj.left_shoulder, buffer, bufferOffset);
    // Serialize message field [right_shoulder]
    bufferOffset = _serializer.float32(obj.right_shoulder, buffer, bufferOffset);
    // Serialize message field [left_elbow]
    bufferOffset = _serializer.float32(obj.left_elbow, buffer, bufferOffset);
    // Serialize message field [right_elbow]
    bufferOffset = _serializer.float32(obj.right_elbow, buffer, bufferOffset);
    // Serialize message field [left_hand]
    bufferOffset = _serializer.float32(obj.left_hand, buffer, bufferOffset);
    // Serialize message field [right_hand]
    bufferOffset = _serializer.float32(obj.right_hand, buffer, bufferOffset);
    // Serialize message field [torso]
    bufferOffset = _serializer.float32(obj.torso, buffer, bufferOffset);
    // Serialize message field [minimal]
    bufferOffset = _serializer.float32(obj.minimal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type distances
    let len;
    let data = new distances(null);
    // Deserialize message field [head]
    data.head = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_shoulder]
    data.left_shoulder = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_shoulder]
    data.right_shoulder = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_elbow]
    data.left_elbow = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_elbow]
    data.right_elbow = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_hand]
    data.left_hand = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_hand]
    data.right_hand = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [torso]
    data.torso = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [minimal]
    data.minimal = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'seher_msgs/distances';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bddb02bb0596d089d8172f7a50bef87e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #distances between TCP and human body parts
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new distances(null);
    if (msg.head !== undefined) {
      resolved.head = msg.head;
    }
    else {
      resolved.head = 0.0
    }

    if (msg.left_shoulder !== undefined) {
      resolved.left_shoulder = msg.left_shoulder;
    }
    else {
      resolved.left_shoulder = 0.0
    }

    if (msg.right_shoulder !== undefined) {
      resolved.right_shoulder = msg.right_shoulder;
    }
    else {
      resolved.right_shoulder = 0.0
    }

    if (msg.left_elbow !== undefined) {
      resolved.left_elbow = msg.left_elbow;
    }
    else {
      resolved.left_elbow = 0.0
    }

    if (msg.right_elbow !== undefined) {
      resolved.right_elbow = msg.right_elbow;
    }
    else {
      resolved.right_elbow = 0.0
    }

    if (msg.left_hand !== undefined) {
      resolved.left_hand = msg.left_hand;
    }
    else {
      resolved.left_hand = 0.0
    }

    if (msg.right_hand !== undefined) {
      resolved.right_hand = msg.right_hand;
    }
    else {
      resolved.right_hand = 0.0
    }

    if (msg.torso !== undefined) {
      resolved.torso = msg.torso;
    }
    else {
      resolved.torso = 0.0
    }

    if (msg.minimal !== undefined) {
      resolved.minimal = msg.minimal;
    }
    else {
      resolved.minimal = 0.0
    }

    return resolved;
    }
};

module.exports = distances;
