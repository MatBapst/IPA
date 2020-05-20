
"use strict";

let BaTestEnvironment = require('./BaTestEnvironment.js')
let StartObjectRecording = require('./StartObjectRecording.js')
let DetectObjects = require('./DetectObjects.js')
let BagTrainObject = require('./BagTrainObject.js')
let SaveRecordedObject = require('./SaveRecordedObject.js')
let TrainObject = require('./TrainObject.js')
let StopObjectRecording = require('./StopObjectRecording.js')
let AcquireObjectImage = require('./AcquireObjectImage.js')

module.exports = {
  BaTestEnvironment: BaTestEnvironment,
  StartObjectRecording: StartObjectRecording,
  DetectObjects: DetectObjects,
  BagTrainObject: BagTrainObject,
  SaveRecordedObject: SaveRecordedObject,
  TrainObject: TrainObject,
  StopObjectRecording: StopObjectRecording,
  AcquireObjectImage: AcquireObjectImage,
};
