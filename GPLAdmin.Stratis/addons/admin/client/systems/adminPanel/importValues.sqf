// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.0
//	@file Name: importValues.sqf
//	@file Author: [404] Deadbeat
//	@file Created: 20/11/2012 05:19
//	@file Args:

#define playerMenuDialog 55500
#define playerMenuPlayerList 55505
/*
#define playerMenuPlayerSkin 55501
#define playerMenuPlayerGun 55502
#define playerMenuPlayerItems 55503
#define playerMenuPlayerPos 55504
#define playerMenuPlayerObject 55507
#define playerMenuPlayerHealth 55508
*/
disableSerialization;

private ["_index1","_type1","_data1","_target"];
_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	_index1 = _this select 1;
	_type1 = _this select 0;
	
	_dialogPlayer = findDisplay playerMenuDialog;
	_playerListBox = _dialogPlayer displayCtrl playerMenuPlayerList;
	
	_targetOutput = _dialogPlayer displayCtrl 55528;
	_UIDOutput = _dialogPlayer displayCtrl 55511;
	_HealthOutput = _dialogPlayer displayCtrl 55520;
	_weaponsOutput = _dialogPlayer displayCtrl 55521;
	_vehicleOutput = _dialogPlayer displayCtrl 55522;
	_positionOutput = _dialogPlayer displayCtrl 55523;
	_sideOutput = _dialogPlayer displayCtrl 55524;
	_killsOutput = _dialogPlayer displayCtrl 55525;
	_deathsOutput = _dialogPlayer displayCtrl 55526;
	_squadOutput = _dialogPlayer displayCtrl 55527;
	_squadList = _dialogPlayer displayCtrl 55529;

	    _data1 = _playerListBox lbData _index1;
	    {
	        if (str(_x) == _data1) exitwith {
	            _targetOutput ctrlSetText (name _x);
				_UIDOutput ctrlSetText (getPlayerUID _x);
				_decimalPlaces = 2;
				_health = damage _x;
				_health = round (_health * (10 ^ _decimalPlaces)) / (10 ^ _decimalPlaces);
				_health = 100 - (_health * 100);
	            _healthOutput ctrlSetText format["%1",_health];
				_weaponsOutput ctrlSetText str (weapons _x);
				_positionOutput ctrlSetText str (position _x);
				_sideOutput ctrlSetText str (side _x);
				_killsOutput ctrlSetText str (score _x);
				_deaths = getPlayerScores _x;
				_deaths = _deaths select 4;
				_deathsOutput ctrlSetText str _deaths;
				_squadOutput ctrlSetText str (group _x);
				_vehicleOutput ctrlSetText (typeOf vehicle _x);
				_target = _x;
				
	        };
	    } foreach playableUnits;
		lbClear _squadList;
		{
		_uid = getPlayerUID _x;
		_namestr = name(_x);
		_index = _squadList lbAdd _namestr;
		_squadList lbSetData [_index, str(_x)];
	} forEach units group _target;
		
};
