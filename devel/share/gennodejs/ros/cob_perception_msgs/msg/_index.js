
"use strict";

let PositionMeasurement = require('./PositionMeasurement.js');
let Rect = require('./Rect.js');
let ColorDepthImage = require('./ColorDepthImage.js');
let People = require('./People.js');
let PersonStamped = require('./PersonStamped.js');
let ColorDepthImageArray = require('./ColorDepthImageArray.js');
let Skeleton = require('./Skeleton.js');
let Detection = require('./Detection.js');
let PositionMeasurementArray = require('./PositionMeasurementArray.js');
let DetectionArray = require('./DetectionArray.js');
let Float64ArrayStamped = require('./Float64ArrayStamped.js');
let PointCloud2Array = require('./PointCloud2Array.js');
let Person = require('./Person.js');
let Mask = require('./Mask.js');

module.exports = {
  PositionMeasurement: PositionMeasurement,
  Rect: Rect,
  ColorDepthImage: ColorDepthImage,
  People: People,
  PersonStamped: PersonStamped,
  ColorDepthImageArray: ColorDepthImageArray,
  Skeleton: Skeleton,
  Detection: Detection,
  PositionMeasurementArray: PositionMeasurementArray,
  DetectionArray: DetectionArray,
  Float64ArrayStamped: Float64ArrayStamped,
  PointCloud2Array: PointCloud2Array,
  Person: Person,
  Mask: Mask,
};
