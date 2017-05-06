// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: playerTags.sqf
//	@file Author: NRZ7
//	@file Created: 30/04/2017 05:19
//	@file Desc: This file toggle 3D and 2D markers to players

_uid = getPlayerUID player;
if (_uid call isAdmin) then
{
	if (isNil "adminPlayerMarkers") then { adminPlayerMarkers = false };

	if (!adminPlayerMarkers) then
	{
		adminPlayerMarkers = true;
		hint "Player Markers ON";
		
		NR_EH_PlayerDraw = findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw", {  
		 private ["_iconColor"];
		 {
		 switch (side _x) do
			{
				case WEST:      { _iconColor = [0, 0, 1, 1] }; 
				case EAST:       { _iconColor = [1, 0, 0, 1] };
				case resistance: { _iconColor = [0.118,1,0,1] };
				default           { _iconColor = [1, 1, 1, 1] };
			};
		  
		_this select 0 drawIcon [  
		  'iconMan',  
		  _iconColor,  
		  getPos _x,  
		  24,  
		  24,  
		  getDir _x,  
		  name player,  
		  1,  
		  0.05,  
		  'TahomaB',  
		  'right'  
		 ] 
		} foreach allPlayers;  
		}];
		
		//3D Markers
		nr_EH_Draw3DPlayers =addMissionEventHandler ["Draw3D", 
		{ 
			private["_vis","_pos","_groupIcon","_iconColor"]; 
			{ 
				if(isPlayer _x && player distance _x < 2500 && _x != player) then 
				{ 
					_groupIcon = "\a3\ui_f\data\map\Markers\Military\arrow2_CA.paa";
					switch (side _x) do
								{
									case WEST:      	{ _iconColor = [0, 0, 1, 1] }; 
									case EAST:       	{ _iconColor = [1, 0, 0, 1] };
									case resistance: 	{ _iconColor = [1, 1, 0, 1] };
									default           	{ _iconColor = [1, 1, 1, 1] };
								};
							   _pos = visiblePosition _x; 
							   _pos set[2,(getPosATL _x select 2) + 2.2]; 
							   drawIcon3D [_groupIcon,_iconColor,_pos,0.5,0.5,180,format ["[%1] %2",round (_x distance player),name _x],0,0.04]; 
				}; 
			} foreach allPlayers; 
		}];
	}
	else
	{
		adminPlayerMarkers = false;
		hint "Player Markers OFF";
		removeMissionEventHandler ["Draw3D",nr_EH_Draw3DPlayers];
		findDisplay 12 displayCtrl 51 ctrlRemoveEventHandler ["Draw", NR_EH_PlayerDraw];
	};

};