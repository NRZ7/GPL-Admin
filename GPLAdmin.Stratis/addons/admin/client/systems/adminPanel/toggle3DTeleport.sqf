// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2017 NRZ7 *
// ******************************************************************************************
//	@file Version: 1.0
//	@file Name: toggle3DTeleport.sqf
//	@file Author: NRZ7
//	@file Created: 15/04/2017
//	@file Args:

if ((getPlayerUID player) call isAdmin) then
{
	if(isNil "NR_toggle3DT") then
	{
		NR_toggle3DT = false;
	};
	if (!NR_toggle3DT) then 
	{ 
		NR_toggle3DT = true;
		waituntil {!IsNull (findDisplay 46)}; 
		hint "Press T for 3D Teleport";
		NR_KeyDownEHId = (findDisplay 46) displayAddEventHandler ["KeyDown", "if (_this select 1 == 20) then {_pos = screenToWorld [0.5,0.5]; player setPos _pos;}"];
	} else 
	{ 
		hint "3D Teleport OFF";
		(findDisplay 46) displayRemoveEventHandler ["KeyDown",NR_KeyDownEHId];
		NR_toggle3DT = false;
	};
};
	

