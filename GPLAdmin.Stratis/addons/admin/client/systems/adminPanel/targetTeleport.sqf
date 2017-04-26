// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: targetTeleport.sqf
//	@file Author: NRZ7
//	@file Created: 25/04/2017

private ["_target","_targetName","_deleteMarkersOnExit"];

if(isNil "NR_togglePlayerMarkers") then	{	NR_togglePlayerMarkers = false;	};

_target = _this select 0;
_targetName = name _target;

openMap true;

hint format ["Click on map to teleport %1",_targetName];

_target onMapSingleClick "_this setPos _pos; onMapSingleClick '';true;";

if (!NR_togglePlayerMarkers) then
{
	execVM "addons\admin\client\systems\adminPanel\togglePlayerMarkers.sqf";
	mapAnimAdd [1, 0.1, _target]; 
	mapAnimCommit;
	waitUntil {!visibleMap}; onMapSingleClick "";
	execVM "addons\admin\client\systems\adminPanel\togglePlayerMarkers.sqf";

} else {
	mapAnimAdd [1, 0.1, _target]; 
	mapAnimCommit;
	waitUntil {!visibleMap}; onMapSingleClick "";

};
