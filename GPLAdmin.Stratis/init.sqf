#ifdef A3W_DEBUG
#define DEBUG true
#else
#define DEBUG false
#endif


[] execVM "addons\proving_ground\init.sqf";

if (hasInterface) then
{
	nrz_onKeyPress = execVM "addons\admin\client\nrz_fnc_onKeyPress.sqf";					// On Key Press Event Handlers
	execVM "addons\admin\client\init.sqf";
};

if (isServer) then
{
	diag_log "A3WAdmin - Initializing";
	[] execVM "addons\admin\server\init.sqf";
};

[DEBUG] call compile preprocessFileLineNumbers "addons\admin\client\globalCompile.sqf";