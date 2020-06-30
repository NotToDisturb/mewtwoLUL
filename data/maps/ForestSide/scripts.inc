ForestSide_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ForestSide_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ForestSide_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ForestSide_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_FOREST_STATE, 4, ForestSide_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

ForestSide_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FOREST_SIDE
	compare VAR_RESULT, 0
	goto_if_eq ForestSide_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1
	setvar VAR_FOREST_STATE, 6
	return

ForestSide_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
	setvar VAR_FOREST_STATE, 5
	return

ForestSide_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FOREST_STATE, 5, ForestSide_NoticeUp
	map_script_2 VAR_FOREST_STATE, 6, ForestSide_NoticeDown
	.2byte 0


ForestSide_NoticeUp::
	turnobject 3, DIR_SOUTH
	applymovement 3, Common_Movement_ExclamationMark
	turnobject 4, DIR_SOUTH
	applymovement 4, Common_Movement_ExclamationMark
	delay 32
	msgbox ForestSide_NoticeUp_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 16
	turnobject 4, DIR_NORTH
	msgbox ForestSide_NoticeUp_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox ForestSide_NoticeUp_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Child1UpRunDown
	applymovement 4, Child2UpRunDown
	waitmovement 3
	setvar VAR_FOREST_STATE, 7
	end


Child1UpRunDown:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Child2UpRunDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ForestSide_NoticeDown::
	turnobject 1, DIR_NORTH
	applymovement 1, Common_Movement_ExclamationMark
	turnobject 2, DIR_NORTH
	applymovement 2, Common_Movement_ExclamationMark
	delay 32
	msgbox ForestSide_NoticeDown_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 16
	turnobject 1, DIR_SOUTH
	msgbox ForestSide_NoticeDown_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox ForestSide_NoticeDown_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Child1DownRunUp
	applymovement 2, Child2DownRunUp
	waitmovement 2
	setvar VAR_FOREST_STATE, 7
	end


Child1DownRunUp:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Child2DownRunUp:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ForestSide_NoticeUp_Text_0:
	.string "{COLOR GREEN}Johnny: {COLOR DARK_GREY}¿Has oído eso?$"

ForestSide_NoticeUp_Text_1:
	.string "{COLOR GREEN}María: {COLOR DARK_GREY}No me ha gustado nada ese grito.\nCreo que Benito tiene problemas.$"

ForestSide_NoticeUp_Text_2:
	.string "{COLOR GREEN}Johnny: {COLOR DARK_GREY}Creo que deberíamos ir a ver.\nY rápido.$"

ForestSide_NoticeDown_Text_0:
	.string "{COLOR GREEN}María: {COLOR DARK_GREY}Johnny, esa era la voz de Benito.$"

ForestSide_NoticeDown_Text_1:
	.string "{COLOR GREEN}Johnny: {COLOR DARK_GREY}No cabe duda...\nNo sonaba nada bien.$"

ForestSide_NoticeDown_Text_2:
	.string "{COLOR GREEN}María: {COLOR DARK_GREY}Venga, vamos a ver si se\nha hecho daño.$"
