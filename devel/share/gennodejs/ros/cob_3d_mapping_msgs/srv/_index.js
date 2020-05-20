
"use strict";

let GetTables = require('./GetTables.js')
let UpdateMap = require('./UpdateMap.js')
let GetApproachPoseForPolygon = require('./GetApproachPoseForPolygon.js')
let SetBoundingBoxes = require('./SetBoundingBoxes.js')
let GetObjectsOfClass = require('./GetObjectsOfClass.js')
let ModifyMap = require('./ModifyMap.js')
let SetGeometryMap = require('./SetGeometryMap.js')
let MoveToTable = require('./MoveToTable.js')
let GetPointMap = require('./GetPointMap.js')
let GetPlane = require('./GetPlane.js')
let SetPointMap = require('./SetPointMap.js')
let GetGeometryMap = require('./GetGeometryMap.js')
let GetBoundingBoxes = require('./GetBoundingBoxes.js')

module.exports = {
  GetTables: GetTables,
  UpdateMap: UpdateMap,
  GetApproachPoseForPolygon: GetApproachPoseForPolygon,
  SetBoundingBoxes: SetBoundingBoxes,
  GetObjectsOfClass: GetObjectsOfClass,
  ModifyMap: ModifyMap,
  SetGeometryMap: SetGeometryMap,
  MoveToTable: MoveToTable,
  GetPointMap: GetPointMap,
  GetPlane: GetPlane,
  SetPointMap: SetPointMap,
  GetGeometryMap: GetGeometryMap,
  GetBoundingBoxes: GetBoundingBoxes,
};
