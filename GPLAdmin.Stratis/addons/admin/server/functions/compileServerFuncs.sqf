nr_fnc_daynight =
{
	if ((daytime > 8) && (daytime < 22)) then 
	{ 
		skipTime (22 - daytime + 24 ) % 24; 
	} else 
	{ 
		skipTime (8 - daytime + 24 ) % 24; 
	};
} call mf_compile;


NR_fnc_weatherChange = {
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

} call mf_compile;


NR_fnc_ViewDistance = {
		_NR_ViewDistance = _this select 0;
		setViewDistance _NR_ViewDistance;
} call mf_compile;


NR_fnc_serverInvisAdmin = {
		_player = _this select 0;
		_state = _this select 1;
		
		_player hideObjectGlobal _state;
} call mf_compile;


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
} call mf_compile;


NR_fnc_remoteExecution = {
	_codeToExec = _this select 0;
	_callerUID = _this select 1;
	//if (_callerUID call isAdmin) then
	//{
		call _codeToExec;
		
	//};
} call mf_compile;


NR_fnc_tempBanServer = {
	_targetUID = _this select 0;
	_adminName = _this select 1;
	banList pushBack _targetUID;
	publicVariable "banList";
	[_targetUID,_adminName] remoteExec ["nr_fnc_tempBanClient",0,false];
} call mf_compile;


NR_fnc_kickTarget = {
	_target = _this;
	_name = name _target;
	gpl_CommandPassword serverCommand format ['#exec kick "%1"',_name];
} call mf_compile;


NR_fnc_banTarget = {
	_target = _this;
	_name = name _target;
	gpl_CommandPassword serverCommand format ['#exec ban "%1"',_name];
} call mf_compile;


NR_fnc_timeMultiplier = {
	_timeMultiplier = _this;
	setTimeMultiplier _timeMultiplier;
} call mf_compile;