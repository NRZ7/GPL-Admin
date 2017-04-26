// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: TogglePlayerMarkers.sqf
//	@file Author: NRZ7
//	@file Created: 25/04/2017



if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_togglePlayerMarkers") then
	{
		NR_togglePlayerMarkers = false;
	};
	if (!NR_togglePlayerMarkers) then
	{
		NR_togglePlayerMarkers = true;
		hint "Player Markers ON";
		[] spawn {
			private["_dir","_pos","_name","_iconColor","_marker","_markerArray"];
			_markerArray = [];
			while {NR_togglePlayerMarkers} do {	
				{
					if(isPlayer _x  && alive _x) then 
					{
						
						_pos = getPos _x;
						_dir = getDir _x;
						_name = name _x;
						
						switch (side _x) do
						{
							case WEST:      	{ _iconColor = "ColorBlue" }; 
							case EAST:       	{ _iconColor = "ColorRed" };
							case resistance: 	{ _iconColor = "ColorGreen" };
							default           	{ _iconColor = "ColorWhite" };
						};
						_marker = createMarkerLocal [_name, _pos];
						_marker setMarkerDirLocal _dir;
						_marker setMarkerShapeLocal "ICON"; 
						_marker setMarkerColorLocal _iconColor;
						_marker setMarkerTypeLocal "mil_start"; 
						_marker setMarkerTextLocal _name;
						_markerArray pushBack _name;
					};
				} foreach allPlayers; sleep 0.5; { deleteMarkerLocal _x } forEach _markerArray; _markerArray = [];
			};
		};
	} else {
		NR_togglePlayerMarkers=false;
		hint "Player Markers OFF";
	};
};