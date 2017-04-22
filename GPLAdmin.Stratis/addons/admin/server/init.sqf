// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.1
//	@file Name: init.sqf
//	@file Author: [404] Deadbeat, [GoT] JoSchaap, AgentRev
//	@file Created: 20/11/2012 05:19
//	@file Description: The server init.
//	@file Args:
// bAdmin Exile by Biabock

// All the "hasInterface" and "isServer" checks are to allow this file to be executed on a headless client to offload object saving

if (!isServer && hasInterface) exitWith {};

externalConfigFolder = "\GPLAdmin_settings";

if (isServer) then
{
	[] execVM "addons\admin\server\admins.sqf";
	[] execVM "addons\admin\server\broadcaster.sqf";
};

nr_fnc_daynight =
{
	if ((daytime > 8) && (daytime < 22)) then 
	{ 
		skipTime (22 - daytime + 24 ) % 24; 
	} else 
	{ 
		skipTime (8 - daytime + 24 ) % 24; 
	};
};

NR_fnc_weatherChange = {
	_UID = _this select 7;
	_NR_weather_Over = _this select 0;
	_NR_weather_Fog = _this select 1;
	_NR_weather_Rain = _this select 2;
	_NR_weather_Waves = _this select 3;
	_NR_weather_Lightnings = _this select 4;
	_NR_weather_windEast = _this select 5;
	_NR_weather_windNorth = _this select 6;

	10 setOvercast _NR_weather_Over;
	10 setFog _NR_weather_Fog;
	10 setRain _NR_weather_Rain;
	10 setWaves _NR_weather_Waves;
	10 setLightnings _NR_weather_Lightnings;
	setWind [_NR_weather_windEast, _NR_weather_windNorth, true];
	forceWeatherChange;

};

NR_fnc_serverViewDistance = {
	//_UID = _this select 1;
	//if (_UID call isAdmin) then
	//{
		_NR_serverView = _this select 0;
		setViewDistance _NR_serverView;
	//};
};

NR_fnc_serverInvisAdmin = {
		_player = _this select 0;
		_state = _this select 1;
		
		_player hideObjectGlobal _state;
};

fn_aj_s_refreshZeus = {
	if (isServer) then {
		// Refresh map objects if zeus ui is opened
		
		private "_zeusUID";
		_zeusUID = _this select 0;
		_zeusUID = missionnamespace  getvariable[_zeusUID,0];
		
			{
			_zeusUID addCuratorEditableObjects [[_x],true];
			} 
			foreach (allMissionObjects "All");

		
	};
};

NR_fnc_remoteExecution = {
	_codeToExec = _this select 0;
	_callerUID = _this select 1;
	//if (_callerUID call isAdmin) then
	//{
		call _codeToExec;
		
	//};
};

diag_log "Admin - Server Compile Finished";