// *****************************************************************************************
// * This script is licensed under the GNU Affero GPL v3. Copyright © 2017 A3Wasteland.com *
// *****************************************************************************************
//	@file Version: 1.0
//	@file Name: debugSelect.sqf
//	@file Author: NRZ7, based on [404] Deadbeat playerSelect.sqf
//	@file Created: 20/11/2012 05:19
//	@file Args:

#define debugDialog 60001

disableSerialization;

private ["_dialog","_playerListBox","_spectateButton","_switch","_index","_modSelect","_playerData","_target","_check","_spectating","_camadm","_rnum","_warnText","_targetUID","_playerName"];
_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	_dialog = findDisplay debugDialog;
	_switch = _this select 0;
};

	switch (_switch) do
	{
		case 0: //Option Disabled
		{
			hint "Option Disabled";
		};
		
		////////////////////////////////////////
		//	FIRST COLUMN. PLAYER 	[0-20]
		////////////////////////////////////////
		case 1: //Arsenal
		{
			closeDialog 0;
			["Open",true] spawn BIS_fnc_arsenal;
		};
		case 2: //Teleport
		{
			closeDialog 0;
			openmap true;
			onMapSingleClick "vehicle player setPos _pos; onMapSingleClick '';true;";
			hint "Click on map to teleport";
			waitUntil {!visibleMap}; onMapSingleClick "";			
		};
		case 3: //God mode
		{
			execVM "addons\admin\client\systems\adminPanel\toggleGodMode.sqf";
		};
		case 4: //Invisible
		{
			execVM "addons\admin\client\systems\adminPanel\toggleInvisMode.sqf";
		};
		case 5: //Unlimited Ammo
		{
			//closeDialog 0;
			execVM "addons\admin\client\systems\adminPanel\toggleUnlimAmmo.sqf";
		};
		case 6: //Stamina
		{
			execVM "addons\admin\client\systems\adminPanel\toggleStamina.sqf";
		};
		case 7: //3D Teleport
		{
			execVM "addons\admin\client\systems\adminPanel\toggle3DTeleport.sqf";
		};
		
		case 8: // Zeus
		{
			closeDialog 0;
			execVM "addons\aj\zeus\refreshzeus.sqf";
			openCuratorInterface;
		};
		
		case 9: // delete cursorTarget
		{
			deleteVehicle cursorTarget;
		};
		
		case 10: //Client View Distance
		{
		
		};
		
		case 11: //3D Teleport
		{
			
		};
		
		case 12: //Enable Environment
		{
			
		};
		
		case 13: //Zeus
		{
			
		};
		
		////////////////////////////////////////
		//	SECOND COLUMN. VEHICLES 	[21-40]
		////////////////////////////////////////
		case 21: //Garage
		{
			 closeDialog 0; createDialog "balca_debug_veh_creator"; ['You may get kicked if BattlEye is monitoring createVehicle.','WARNING'] spawn BIS_fnc_guiMessage; [0,2] call c_proving_ground_fnc_create_vehicle; 
			
			/*
			closeDialog 0;
			_pos = player getPos [30,getDir player];
			_vehicle = createVehicle [ "Land_HelipadEmpty_F", _pos, [], 0, "CAN_COLLIDE" ]; 
			["Open",[ true, _vehicle ]] call BIS_fnc_garage;
			*/
		};
		
		case 22: //Vehicle Manager
		{
			closeDialog 0;
			execVM "addons\admin\client\systems\adminPanel\vehicleManagement.sqf";
		};
		
		case 23: //Flip
		{
			execVM "addons\admin\client\systems\adminPanel\flipVehicle.sqf";
		};
		
		case 24: //Repair Refuel Rearm
		{
			//closeDialog 0;
			if ((vehicle player) == player) then {
			cursorTarget setVehicleAmmo 1; cursorTarget setFuel 1; cursorTarget setDamage 0;
			} else {
			(vehicle player) setVehicleAmmo 1;(vehicle player) setfuel 1;(vehicle player) setDamage 0;
			};
		};
		
		case 25: //Player ESP
		{
			execVM "addons\admin\client\systems\adminPanel\playerTags.sqf";
		};
		
		case 26: //AI ESP
		{
			execVM "addons\admin\client\systems\adminPanel\toggleAIESP.sqf";
		};
		
		case 27: //Object Search
		{
			//closeDialog 0;
			execVM "addons\admin\client\systems\adminPanel\loadObjectSearch.sqf";
		};
		
		case 28: //NPC Markers
		{
			//closeDialog 0;
			execVM "addons\admin\client\systems\adminPanel\toggleAIMarkers.sqf";
		};
		
		////////////////////////////////////////
		//	THIRD COLUMN. SERVER	[41-60]
		////////////////////////////////////////
		
		case 41: //SERVER MONITOR
		{
			execVM "addons\admin\client\systems\adminPanel\toggleServerFPS.sqf";
		};
		
		case 42: //CHANGE WHEATHER
		{
			[1] execVM "addons\admin\client\systems\adminPanel\dialog\debugMenuCtrlShow.sqf";
		};
		
		case 43: //Set Global View Distance
		{
			[3] execVM "addons\admin\client\systems\adminPanel\dialog\debugMenuCtrlShow.sqf";
		};
		
		case 44: //Day/Night
		{
			execVM "addons\admin\client\systems\adminPanel\toggleDayNight.sqf";
		};
		
		case 45: //Global Message
		{
			[2] execVM "addons\admin\client\systems\adminPanel\dialog\debugMenuCtrlShow.sqf";
		};
		
		////////////////////////////////////////
		//	FOURTH COLUMN. TOOLS	[61-80]
		////////////////////////////////////////
		case 61: //Debug Console
		{
			closeDialog 0;
			(finddisplay 46) createdisplay "RscDisplayDebugPublic";
		};
		
		case 62: //Spectator
		{
			closeDialog 0;
			hint "Press ESC to close Spectator";
			["Initialize", [player, [], false, true, true, true, true, true, true, true]] call BIS_fnc_EGSpectator;
			waituntil {!IsNull (findDisplay 60492)}; 
			_keyDown = (findDisplay 60492) displayAddEventHandler ["KeyDown", "if (_this select 1 == 1) then {['Terminate'] call BIS_fnc_EGSpectator;}"];
		};
		
		case 63: //Splendid Camera (Free Cam)
		{
			[] call BIS_fnc_camera;
		};
		
		case 64: //Config Viewer
		{
			[] call BIS_fnc_configViewer;
		};
		
		case 65: //Function Viewer
		{
			[] call BIS_fnc_help;
		};
		
		case 66: //Animations
		{
			closeDialog 0;
			[] call BIS_fnc_animViewer;
		};
		
		case 67: //Gui Editor
		{
			[] call BIS_fnc_GUIeditor;
		};
		
		case 68: //Proving Ground
		{
			//closeDialog 0;
			createDialog "balca_debug_main";
		};
		
		////////////////////////////////////////
		//	DYNAMIC MENU	[81-99]
		////////////////////////////////////////
		
		case 81: // Change View Distance
		{
			_NR_ViewDistance = _this select 1;
			if(_NR_ViewDistance <= 199) exitWith
			{
				hint "ERROR: Please, put a value > 199";
			};
			if(_NR_ViewDistance > 10000) exitWith
			{
				hint "ERROR: Max. value is 10000.";
			};

			[_NR_ViewDistance] remoteExec ["NR_fnc_ViewDistance",0];
		};
		
		case 82: // Global Message
		{
			_NR_GlobalMessage = _this select 1;
	
			if(_NR_GlobalMessage == "") exitWith
			{
				hint "ERROR: Message can't be empty";
			};
			if(_NR_GlobalMessage == "Write your global message here") exitWith
			{
				hint "ERROR: Please write something...";
			};

			[_NR_GlobalMessage] remoteExec ["NR_fnc_globalMessage",0];
		};
		
		case 83: // Global Message
		{
			_NR_GlobalMessage = _this select 1;
	
			if(_NR_GlobalMessage == "") exitWith
			{
				hint "ERROR: Message can't be empty";
			};
			if(_NR_GlobalMessage == "Write your global message here") exitWith
			{
				hint "ERROR: Please write something...";
			};

			[_NR_GlobalMessage] remoteExec ["NR_fnc_globalMessage",0];
		};
		
		case 84: // Change Weather
		{
			_NR_overcast = _this select 1;
			_NR_fog = _this select 2;
			_NR_rain = _this select 3;
			_NR_waves = _this select 4;
			_NR_Lightnings = _this select 5;
			_NR_windEast = _this select 6;
			_NR_windNorth = _this select 7;
			
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

			[_NR_overcast,_NR_fog,_NR_rain,_NR_Waves,_NR_Lightnings,_NR_windEast,_NR_windNorth] remoteExec ["NR_fnc_weatherChange",0];
		};
		
		case 85: // Change Time Multiplier
		{
			_timeMultiplier = _this select 1;
			_timeMultiplier remoteExec ["NR_fnc_timeMultiplier",2];
		};
		
		case 86: // About
		{
			[5] execVM "addons\admin\client\systems\adminPanel\dialog\debugMenuCtrlShow.sqf";
		};
	};

