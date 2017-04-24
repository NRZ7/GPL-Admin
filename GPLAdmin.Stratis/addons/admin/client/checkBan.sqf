// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// *****************************************************************************************
//@file Version: 1
//@file Name: checkBan.sqf
//@file Author: NRZ7
//@file Created: 24/04/2017 21:03
//@file Description: Check if the user is baned and kick off.

private ["_uid"]; 
 
_uid = getPlayerUID player; 

if (_uid in banList) then 
{ 
 _kick = [] spawn  
 { 
   titleText ["", "BLACK FADED"];
   ["banned",false,0.5] call BIS_fnc_endMission;
 }; 
};
