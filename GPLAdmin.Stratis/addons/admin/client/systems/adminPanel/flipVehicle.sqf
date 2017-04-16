// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: flipVehicle.sqf
//	@file Author: NRZ7
//	@file Created: 16/04/2017
//	@file Desc: This scripts flip the cursorTarget vehicle or the vehicle player instead.

private ["_obj","_pos","_xPos","_yPos","_zPos"];

if ((vehicle player) == player) then {
	_obj = cursorobject;
} else {
	_obj = vehicle player;
};
	_pos = getPos _obj;
	_xPos = _pos select 0;
	_yPos = _pos select 1;
	_zPos = _pos select 2;
	_zPos = _zPos +1;
	_obj setPos [_xPos,_yPos,_zPos];
	_obj setVectorUp [0,0,1];