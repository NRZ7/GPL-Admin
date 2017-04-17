// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: clientWeather.sqf
//	@file Author: NRZ7
//	@file Created: 17/04/2017 15:53


_UID = getPlayerUID player;
if (_UID call isAdmin) then
{
	_NR_overcast = _this select 0;
	_NR_fog = _this select 1;
	_NR_rain = _this select 2;
	_NR_waves = _this select 3;
	_NR_Lightnings = _this select 4;
	_NR_windEast = _this select 5;
	_NR_windNorth = _this select 6;
	
	if(isNil "_NR_overcast") then
	{
		_NR_overcast = 0;
	};
	if(isNil "_NR_fog") then
	{
		_NR_fog = 0;
	};
	if(isNil "_NR_rain") then
	{
		_NR_rain = 0;
	};
	if(isNil "_NR_waves") then
	{
		_NR_waves = 0;
	};
	if(isNil "_NR_Lightnings") then
	{
		_NR_Lightnings = 0;
	};
	if(isNil "_NR_windEast") then
	{
		_NR_windEast = 0;
	};
	if(isNil "_NR_windNorth") then
	{
		_NR_windNorth = 0;
	};

	hint format ["%1, %2, %3, %4, %5, %6, %7, %8",_NR_overcast,_NR_fog,_NR_rain,_NR_Waves,_NR_Lightnings,_NR_windEast,_NR_windNorth,_UID];

	[_NR_overcast,_NR_fog,_NR_rain,_NR_Waves,_NR_Lightnings,_NR_windEast,_NR_windNorth,_UID] remoteExec ["NR_fnc_weatherChange"];
};