require('N2ScriptBin')
local fscr, err = Create('sg00_01')
if not fscr then
    print(err)
    return -1
end

chapter('main')
SetEntry('chapter.main')
OP_C8()
OP_D1('$GameStart')
OP_D0('INT', '1')
OP_C1()
OP_98('label.if.111')
OP_C8()
OP_68()
OP_B0('$GameName')
OP_8E()
OP_D0('INT', '1')
OP_B0('$GameContiune')
OP_8E()
OP_5B()
OP_8E()
OP_C9()
OP_CF('label.if.end11')
label('if.111')
label('if.end11')
OP_C9()
OP_D4('chapter.main')
scene('sg00_01.nss_MAIN')
OP_95('scene.sg00_01.nss_MAIN')
OP_C8()
OP_D0('STRING', 'NO_TARGET')
OP_B0('$SW_RNDMAIL_CRS')
OP_8E()
OP_D0('STRING', 'NO_TARGET')
OP_B0('$SW_RNDMAIL_MAY')
OP_8E()
OP_D0('STRING', 'NO_TARGET')
OP_B0('$SW_RNDMAIL_RUK')
OP_8E()
OP_D0('STRING', 'NO_TARGET')
OP_B0('$SW_RNDMAIL_SUZ')
OP_8E()
OP_D0('STRING', 'NO_TARGET')
OP_B0('$SW_RNDMAIL_FEI')
OP_8E()
OP_D1('$SYSTEM_skip')
OP_D1('#SYSTEM_skip_express')
OP_C6()
OP_D1('$AllRead')
OP_C6()
OP_D1('$SYSTEM_skip')
OP_D1('#SYSTEM_skip_express')
OP_C6()
OP_D1('#SYSTEM_skip_absolute')
OP_C6()
OP_C7()
OP_98('label.if.211')
OP_C8()
OP_CE('SkipOut')
OP_8E()
OP_C9()
OP_CF('label.if.end21')
label('if.211')
OP_C8()
OP_D0('STRING', '@->')
OP_D1('$GameName')
OP_A5()
OP_B0('$MainGameName')
OP_8E()
OP_CE('GameMainSet')
OP_8E()
OP_A3('$MainGameName')
OP_CE('GameMainSet2')
OP_8E()
OP_C9()
label('if.end21')
OP_D1('$GameName')
OP_B0('$PreGameName')
OP_8E()
OP_D0('STRING', 'sg01_01.nss')
OP_B0('$GameName')
OP_8E()
OP_C9()
OP_D5('scene.sg00_01.nss_MAIN')
scene('sg00_01.nss')
OP_95('scene.sg00_01.nss')
OP_C8()
OP_D0('STRING', '  Version $Revision: $')
OP_B0('$�X�N���v�g�o�[�W����')
OP_8E()
OP_68()
OP_B0('$�\����')
OP_8E()
OP_D1('$SYSTEM_present_process')
OP_B0('$�\����')
OP_8E()
OP_CE('SystemInit')
OP_8E()
OP_CE('InitSG')
OP_8E()
OP_D0('STRING', 'true')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('STRING', 'START_GAME')
OP_CE('AchievementOn', 'START_GAME')
OP_8E()
OP_D0('INT', '0728')
OP_B0('$LR_DATE')
OP_8E()
OP_D0('STRING', '�P�D�P�R�O�Q�S�U')
OP_B0('$DGMP')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_SYSTEMCHIP_HIDE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SYSTEM_backlog_lock')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SYSTEM_save_lock')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_CE('SetChapterHeadBacklog')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '9900')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'prologue01')
OP_CE('CreateMovieSG', '���[�r�[', '9900', '0', '0', 'false', 'false', 'true', 'prologue01')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[', 'Play')
OP_8E()
OP_CE('MovieWaitSG')
OP_8E()
OP_D0('INT', '0728')
OP_B0('$LR_DATE')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG_WHITE.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG_WHITE.jpg')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '�G�F��')
OP_D0('INT', '10000')
OP_D0('STRING', '#000000')
OP_CE('CreateColorSP', '�G�F��', '10000', '#000000')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '9900')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'prologue02')
OP_CE('CreateMovieSG', '���[�r�[', '9900', '0', '0', 'false', 'false', 'true', 'prologue02')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUFEX')
OP_D0('INT', '9890')
OP_D0('STRING', 'cg/bg/bg_white.jpg')
OP_CE('BgLoad', 'BGBUFEX', '9890', 'cg/bg/bg_white.jpg')
OP_8E()
OP_D0('STRING', 'BGBUFEX')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUFEX', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '�G�F��')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_CE('FadeDelete', '�G�F��', '1000', 'null', 'false')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[', 'Play')
OP_8E()
OP_CE('MovieWaitSG')
OP_8E()
OP_D0('STRING', '@���[�r�[*')
OP_24('@���[�r�[*')
OP_8E()
OP_D0('STRING', '�G�F��')
OP_24('�G�F��')
OP_8E()
OP_D0('STRING', 'false')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#FFFFFF')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#FFFFFF', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG13A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG13A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG13A1')
OP_CE('SetCharaColor', 'BG13A1')
OP_8E()
OP_D0('INT', '3000')
OP_B0('$SW_PHONE_PRI')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
OP_D0('STRING', 'PhoneMode_PowerOff')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '266')
OP_39('266')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2200')
OP_D0('STRING', 'cg/ibg/ibg001.png')
OP_CE('BgLoad', 'BGBUF2', '2200', 'cg/ibg/ibg001.png')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '900')
OP_CE('CreatePlainSP', 'BGBUF3', '900')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF3', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('STRING', 'AddRender')
OP_23('BGBUF2', 'AddRender')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '4000')
OP_D0('STRING', '#ffffff')
OP_CE('CreateColorEX', 'MASKBUF2', '4000', '#ffffff')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('MASKBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'sgse004l')
OP_D0('INT', '2133')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SeExPlay', 'SE01', 'sgse004l', '2133', '1000', 'true')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('STRING', 'sgse007l')
OP_D0('INT', '2133')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SeExPlay', 'SE02', 'sgse007l', '2133', '1000', 'true')
OP_8E()
OP_D0('INT', '800')
OP_3A('800')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUFEX*')
OP_24('BGBUFEX*')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '2133')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_CE('FadeDelete', 'MASKBUF2', '2133', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2133')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_25('BGBUF2', '2133', '0', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2133')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '144')
OP_D2()
OP_91()
OP_D0('STRING', 'Dxl1')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '2133', '@', '@', 'Dxl1', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_SYSTEMCHIP_HIDE')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SYSTEM_backlog_lock')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SYSTEM_save_lock')
OP_8E()
OP_D0('INT', '4900')
OP_B0('$SW_PHONE_PRI')
OP_8E()
SetText(
    'text00010',
    '@box00',
    [[
<PRE @box00>[text00010]
<voice name="�H�H�H" class="VID_MAY" src="voice/MAY_0000" mode="on">
�u�˂��˂��B�ȂɃu�c�u�c�����Ă�́[�H�v

�E���ɓ��ĂĂ���P�[�^�C�d�b�B�ʘb������͂Ȃɂ��������Ă��Ȃ��B�m�C�Y����Ȃ��B���S�ɖ����B

�Ă̋���ȓ��˂����󂯂āB

�ۂ���ƁA����<RUBY text="��������">�{��</RUBY>���犾��<RUBY text="�ЂƂ�����">��H</RUBY>�����A�A�X�t�@���g�ɐ��݂�������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMA04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMA04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00020',
    '@box00',
    [[
<PRE @box00>[text00020]
<voice name="�H�H�H" class="VID_MAY" src="voice/MAY_0001" mode="on">
�u�I�J�����H�@�˂����Ă΁[�v

�ڂ̑O�ɂ͏����B

����X���Ȃ��牴�ɌĂт����Ă���B

�ǂ����Ă����w���ɂ��������Ȃ����ǂ��Ȃ��̎c��������́A���܂��ɓG�n�ɐ������悤�Ƃ��Ă���ɂ�������炸�A�ْ�����<RUBY text="�݂���">���o</RUBY>���������Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
SetText(
    'text00030',
    '@box00',
    [[
<PRE @box00>[text00030]
�P�[�^�C�̒ʘb������ŉ������Ă���A���͏����Ɍ�������l�����w�����ɓY�����B

������Ɩق�A�̃[�X�`���[�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMB03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMB03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00040',
    '@box00',
    [[
<PRE @box00>[text00040]
<voice name="�H�H�H" class="VID_MAY" src="voice/MAY_0002" mode="on">
�u�N���Ɠd�b���H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
OP_D0('STRING', 'PhoneMode_PowerOff')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_Phone_Open')
OP_8E()
SetText(
    'text00050',
    '@box00',
    [[
<PRE @box00>[text00050]
���Ȃ����Ă���A���߂ăP�[�^�C���E���ցB

�d�b�̌���������͂�͂��؂̉����������Ă��Ȃ������B

������Ă͂܂�����b�����Ă���̂�����A���������C�𗘂����Ėق����̂��낤�B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0027" mode="on">
�u�c�c����A������̘b���B���Ȃ��A��������ɐ�������v

���ς�炸����͖����B

�񍐂𕷂������ɂ����炵���B

�����I�Ȕ��f���B

���̏�ł��ꂱ��G�k����̂͊댯������B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0028" mode="on">
�u�����A�h�N�^�[<RUBY text="�Ȃ��΂�">����</RUBY>�͔����삯�������B�����Ղ�Ƃ��̍l���ɂ��ĕ������Ă��炤���肳�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'TIPS_KIKAN')
OP_CE('TipsOn', 'TIPS_KIKAN')
OP_8E()
SetText(
    'text00060',
    '@box00',
    [[
<PRE @box00>[text00060]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0029" mode="on">
�u�c�c�ȂɁI�H�@�g<FONT incolor="#ff7080" outcolor="#000000">�@��</FONT>�h�������o���Ă��邾�ƁI�H�v

���͖ڂ����J���A�������悤�Ȑ��������Ă݂��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMB02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMB02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '133')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '133', 'true')
OP_8E()
OP_D0('STRING', '@STBUF5*')
OP_D0('INT', '150')
OP_D0('INT', '10')
OP_D0('INT', '6')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_28('@STBUF5*', '150', '10', '6', '0', '0', '1000', 'null', 'true')
OP_8E()
SetText(
    'text00070',
    '@box00',
    [[
<PRE @box00>[text00070]
�������A������ɍ��킹�ăr�N�b�Ɛg�������܂��Ă���B

�Ƃ������A�������������ƌ��Ă�񂶂�Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00080',
    '@box00',
    [[
<PRE @box00>[text00080]
���͂����ɐ[�X�Ƃ��ߑ������A���߂��݂��w�ŉ������Ȃ��珬�������U�����B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0030" mode="on">
�u�������A���ꂪ<RUBY text="�V���^�C���Y�Q�[�g">�^���΂̔�</RUBY>�̑I�����B�G���E�v�T�C�E�R���O���D�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
SetText(
    'text00090',
    '@box00',
    [[
<PRE @box00>[text00090]
�ʂ�̍������t���Ō�ɁA�[���Ȋ�̂܂܃P�[�^�C�������痣���āA���ɂ��܂����B

<RUBY text="�V���^�C���Y�Q�[�g">�^���΂̔�</RUBY>�B

����͂���΁g�_�X�̈ӎu�h���邢�́g�^���h�Ɠ����Ӗ���\���B

���̑��݂�m��҂́A���E���ł�������قǂ��낤�B

���ĂƁA����ł͑����A��������Ƃ��悤�B

���͉w�̂����ׂɂ��郉�W�قɌ������đ��𓥂ݏo�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE01', '1066', '0', 'null')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE02', '1066', '0', 'null')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG07A1')
OP_CE('SetCharaColor', 'BG07A1')
OP_8E()
OP_D0('INT', '266')
OP_39('266')
OP_8E()
OP_D0('INT', '800')
OP_3A('800')
OP_8E()
OP_D0('STRING', '@BGM07')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM07', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00100',
    '@box00',
    [[
<PRE @box00>[text00100]
�G�n�ւ̐������A�o�J�����ɐ��ʂ���˓�����悤�ȋ����A���͖`������͂��Ȃ��B

�G���x�[�^��G�X�J���[�^�͎g�킸�A�K�i������čŏ�K�ł���W�K�Ɍ������B

�����V�K�܂ŗ����Ƃ���ŗ͐s�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
SetText(
    'text00110',
    '@box00',
    [[
<PRE @box00>[text00110]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0003" mode="on">
�u�������A�P�[�^�C�ŒN�Ƙb���Ă��́[�H�v

���̌������Ă��鏭���\�\<RUBY text="������">�Ŗ�</RUBY>�܂�肪�A����؂炵���l�q���Ȃ����������Ă����B

���͊K�i�����؂����Ƃ���ŕG�Ɏ��u���A�ꑧ���B

�K�i���g���ׂ�����Ȃ��������������c�c�B�L�c�����c�c�B

�z�ɟ��ފ�����Ő@���A�܂��ւƌ����������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00120',
    '@box00',
    [[
<PRE @box00>[text00120]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0031" mode="on">
�u�����ȁB���ꂪ�܂��̂��߂ł�����v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00130',
    '@box00',
    [[
<PRE @box00>[text00130]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0004" mode="on">
�u�����Ȃ񂾁[�B�I�J�����A���肪�Ɓ[�v

�܂��͊��������ɔ��΂񂾁B

�����͎��ɕ������肪�����B

���̗�����킫�܂��Ă���Ă��āA�[���˂�����ł��邱�Ƃ��Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '990')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '990', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '910')
OP_D0('STRING', '#000000')
OP_CE('CreateColorEX', 'MASKBUF2', '910', '#000000')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('MASKBUF2', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_24('GRASHADE')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_D0('INT', '900')
OP_D0('STRING', 'SEMIHEAVY')
OP_CE('SetShadeSG', 'GRASHADE', '900', 'SEMIHEAVY')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '500')
OP_D0('STRING', 'Axl2')
OP_D0('STRING', 'false')
OP_25('MASKBUF2', '1066', '500', 'Axl2', 'false')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_D0('INT', '1066')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_25('GRASHADE', '1066', '1000', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('INT', '250')
OP_D0('INT', '250')
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'mask17')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawTransitionSG', 'BGBUF2', '1066', '0', '250', '250', 'DxlAuto', 'mask17', 'true', 'true')
OP_8E()
SetText(
    'text00140',
    '@box00',
    [[
<PRE @box00>[text00140]
�ޏ��͉��̗c�Ȃ��݂ł���B

�N��͉����Q���\�\�P�U�΂̏��q�����Ȃ̂ŁA�c�Ȃ��݂ƌ�����薅�̂悤�ȗ���ɋ߂��B

�Ƃ��ߏ��Ȃ̂Ő̂���悭���b�����Ă���Ă����B

�܂��ɂ́A<RUBY text="�V���^�C���Y�Q�[�g">�^���΂̔�</RUBY>�̌��Ƃ����ߍ��ȏh����w�������Ƃ̂ł���f��������̂ł͂Ȃ����B�ȑO�̉��͂���Ȃ��Ƃ��l��������������A���͂�������߂Ă���B

�ޏ��ɂ͂��܂ł����ʂł��Ăق����B

���ꂪ�A���̉��̂����₩�Ȋ肢���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '1066')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_CE('FadeDelete', 'MASKBUF2', '1066', 'null', 'false')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_D0('INT', '1066')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_CE('FadeDelete', 'GRASHADE', '1066', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '250')
OP_D0('INT', '0')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask17')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawTransitionSG', 'BGBUF2', '1066', '250', '0', '250', 'null', 'mask17', 'true', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_24('GRASHADE')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '1066')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF1', '1066', '2000', '2000', 'AxlDxl', 'true', 'Smoothing')
OP_8E()
OP_D0('INT', '266')
OP_3A('266')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '5100')
OP_D0('STRING', '#000000')
OP_CE('CreateColorEX', 'MASKBUF2', '5100', '#000000')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_25('MASKBUF2', '1066', '1000', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '1066')
OP_D0('INT', '512')
OP_91()
OP_D0('INT', '288')
OP_91()
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_20('BGBUF1', '1066', '@', '@', 'AxlDxl', 'true')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '5100')
OP_D0('STRING', '#000000')
OP_CE('CreateColorEX', 'MASKBUF2', '5100', '#000000')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('MASKBUF2', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG06A4.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG06A4.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG06A4')
OP_CE('SetCharaColor', 'BG06A4')
OP_8E()
OP_D0('INT', '533')
OP_3A('533')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00150',
    '@box00',
    [[
<PRE @box00>[text00150]
�W�K�܂ŏオ���ĉ��ɓ���ƁA�����ۂ��Z�b�g������Ă����B

�h�N�^�[�����^�C���}�V�����������L�O��Ɩ��ł���Ă���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00160',
    '@box00',
    [[
<PRE @box00>[text00160]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0005" mode="on">
�u������I�J�����I�J�����v

�I�J�����Ƃ���������₽��A�Ă���Ă��邪�A����͕ʂɉ��̖{���ł��Ȃ���΃R�[�h�l�[���ł��Ȃ��B�����g�����܂�C�ɓ����Ă��Ȃ��������Ƃ������c���B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0032" mode="on">
�u�܂���A���������Ă��邾�낤�B���̂��Ƃ��I�J�����ƌĂԂȂƁv

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0006" mode="on">
�u���[�H�@�ł��̂��炻���Ă�ł���H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0033" mode="on">
�u����̘͐̂b���B���̉��́g<RUBY text="�ق���������">�P���@</RUBY><RUBY text="���傤��">���^</RUBY>�h�B���E���̔閧�g�D����_����A���C�̃}�b�h�T�C�G���e�B�X�g���B�t�D�[�n�n�n�I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00170',
    '@box00',
    [[
<PRE @box00>[text00170]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0007" mode="on">
�u�����āA����Ċo�����Ȃ����v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'TIPS_MANA')
OP_CE('TipsOn', 'TIPS_MANA')
OP_8E()
SetText(
    'text00180',
    '@box00',
    [[
<PRE @box00>[text00180]
�Ƃɂ����P���@���^�͉���<FONT incolor="#ff7080" outcolor="#000000"><RUBY text="�܂�">�^��</RUBY></FONT>�Ȃ̂��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00190',
    '@box00',
    [[
<PRE @box00>[text00190]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0008" mode="on">
�u����ɁA<RUBY text="������">����</RUBY><RUBY text="��񂽂낤">�ϑ��Y</RUBY>�ƂP�����������ĂȂ���[�H�@���������ˁA�����ւց[�v

���[�ށA���ɍK�������ɏ΂��Ă�������Ⴂ�₪��B

���Ȃ݂ɉ����ϑ��Y�Ƃ������̖{���́A�Ԕ����Ȋ��������čD���ł͂Ȃ��B

�Ȃ̂ł������������������ł���g�I�J�����h�������������Ȃ̂��B

�Ƃ������I�J�������āB

�K���ɒu���Ă��鉩�F�����݂�������Ȃ����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALB01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALB01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00200',
    '@box00',
    [[
<PRE @box00>[text00200]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0009" mode="on">
�u�łˁA�I�J�����B�����ƁA�����Ăق����񂾂��ǁv

�ǂ����܂��ɂ͌����Ă��ʂ��Ȃ��悤�������B

���ꂱ��T�N�͌��������Ă��Ă��ꂾ����A���Β��߂Ă͂��邪�B

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0010" mode="on">
�u���ꂩ�炱���ŁA�Ȃɂ��n�܂�́[�H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0034" mode="on">
�u���O�́A������m�炸�����܂ŉ��ɂ��Ă����Ƃ����̂��v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00210',
    '@box00',
    [[
<PRE @box00>[text00210]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0011" mode="on">
�u����v

�ɂ��₩�ɂ��Ȃ����Ă���B

�����͓����A�H�t���ɂ��郉�W�فB

���̂W�K�́A�C�x���g�X�y�[�X�ɂȂ��Ă���B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0035" mode="on">
�u���ꂩ�炱���Ŏn�܂�̂́A�h�N�^�[�����̋L�҉���v

�h�N�^�[�����Ƃ����͔̂����Ƃł���B�e���r�Ȃǂɂ��悭�o�ꂷ��L���Ȑl���ŁA������������Ȃ�Ɏ����Ă���B�Ƃ͂������Ԉ�ʂ̖ڂ���͏��F�g�F���m�h�Ƃ��������Ă��Ȃ����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALB03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALB03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00220',
    '@box00',
    [[
<PRE @box00>[text00220]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0012" mode="on">
�u�L�҉�H�@�ł��[�A�L�҂���Ȃ�Č�������Ȃ��C�������H�v

�܂��̌����ʂ肾�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00230',
    '@box00',
    [[
<PRE @box00>[text00230]
�����ɉ��ɂ�������̂����Ă݂����A�L�҂炵���l�Ԃ��J�����}���炵���l�Ԃ��A�P�l�Ƃ��Ă����ɂ͂��Ȃ��B���̎��_�ŋL�҉�ł͂Ȃ������̔��\��Ɖ����Ă��܂��Ă���B

���ɂ���̂́A�����܂߂Ď莝���Ԃ����œ˂������Ă���P�O�l���x�̒j�����B

�����A�������̂P�O�l�B

�����̒m���x�͂���Ȃ�̂͂������A�^�C���}�V���J���ɐ��������Ƃ����G�ꍞ�݂Ȃ�A�����ƏW�܂��Ă������͂������B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0036" mode="on">
�u���邢�́A�g�@�ցh�ɂ��Ȃ�炩�̖W�Q���󂯂��̂�������Ȃ��ȁv

���͎��}�C���ɂԂ₫�A�킴�Ƃ炵���O��c�߂��B

�����͌��X�\�\�ʎ��͂Ȃ����\�\���Ɠ������ɂ���l�Ԃ������͂����B

�����������������Ė�ɉ������B

���̃^�C�~���O���g�@�ցh���������͂����Ȃ��B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0037" mode="on">
�u�������܂��̂́A���ق����ȁv

�Ƃ͂����A���c���Ȃɂ����̂��ɂ͋���������B

�����炱�����͂킴�킴�ċx�݂̒�������Ƃ����M�d�Ȏ��Ԃ������āA�����ɗ����̂��B

�����Ԃ₢���Ƃ茾�ɁA�܂��͂��΂炭�l�����񂾌�A���Ȃ�Ԃ�u���Ă܂�����X�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF8')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF8', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF8')
OP_D0('INT', '1200')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALB03')
OP_CE('St', 'STBUF8', '1200', '@', '@', 'MAY_ALB03')
OP_8E()
OP_D0('STRING', 'STBUF8')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF8', '267', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('STRING', '���W')
OP_D0('STRING', 'xx')
OP_DE('$StA', '3')
OP_D0('STRING', 'STBUF8')
OP_D0('STRING', '���W')
OP_D0('STRING', 'xx')
OP_DE('$StA', '3')
OP_B0('__array_variable__')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('STRING', '���W')
OP_D0('STRING', 'xx')
OP_DE('$StA', '3')
OP_B0('$SgMoveX')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D1('$SgMoveX')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '$SgMoveX', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA02')
OP_8E()
OP_D0('STRING', 'ProFaceChange')
OP_D0('STRING', 'sg00_01_Thd_IM_MAY_01')
OP_CE('CreateProcessSG', 'ProFaceChange', 'sg00_01_Thd_IM_MAY_01')
OP_8E()
OP_D0('STRING', 'ProFaceChange')
OP_D0('STRING', 'Start')
OP_23('ProFaceChange', 'Start')
OP_8E()
SetText(
    'text00240',
    '@box00',
    [[
<PRE @box00>[text00240]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0013" mode="on">
�u���������g�J�Q�H�@���A����������Ȃ�G�������g�J�Q���ˁ[�B�����ւց[�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'ProFaceChange')
OP_D0('INT', '5000')
OP_CE('ProcessRequest', 'ProFaceChange', '5000')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '0', 'true')
OP_8E()
OP_CE('ProcessRequestDelete')
OP_8E()
SetText(
    'text00250',
    '@box00',
    [[
<PRE @box00>[text00250]
���͂��ߑ������Ă��܂��B

�P�l�{�P�c�b�R�~�΂��Ƃ͎��ɔ]�V�C�Ȃ��Ƃ��B

�܂��A�܂��͐̂��炱��Ȋ��������B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0038" mode="on">
�u�܂��A�C��t����B�����炭���̋L�҉�A�Ȃ�炩�̎������N���\�\�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '1')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '1', '0', 'null')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE002')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE01', 'SGSE002', '0', '1000', 'false')
OP_8E()
OP_D0('INT', '1066')
OP_3A('1066')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('STRING', 'SGSE115')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE02', 'SGSE115', '0', '1000', 'false')
OP_8E()
OP_D0('INT', '2133')
OP_3A('2133')
OP_8E()
SetText(
    'text00260',
    '@box00',
    [[
<PRE @box00>[text00260]
�����Ă��邻�΂��痈���I

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'TIPS_EMR')
OP_CE('TipsOn', 'TIPS_EMR')
OP_8E()
SetText(
    'text00270',
    '@box00',
    [[
<PRE @box00>[text00270]
���A���̉��͂Ȃ񂾁I�H�@<FONT incolor="#ff7080" outcolor="#000000">�d���g</FONT>�U�����I�H

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE003')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE01', 'SGSE003', '0', '1000', 'false')
OP_8E()
OP_D0('INT', '5000')
OP_D0('INT', '19')
OP_D0('INT', '6')
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'true')
OP_CE('AllShake', '5000', '19', '6', 'DxlAuto', 'true')
OP_8E()
OP_D0('STRING', 'SE01')
OP_CE('WaitPlayHalfSG', 'SE01')
OP_8E()
OP_D0('STRING', '@BGM08')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM08', '0', '1000', 'true')
OP_8E()
SetText(
    'text00280',
    '@box00',
    [[
<PRE @box00>[text00280]
�킸���ɑ������h�ꂽ�B

�m���ȏՌ��B

�ォ�炾�B

����������������W�K�͍ŏ�K�B

��������ƂȂ�ƁA���サ���Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALB03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALB03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00290',
    '@box00',
    [[
<PRE @box00>[text00290]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0014" mode="on">
�u�n�k���Ȃ��H�@�k�x�Q�H�@�}�O�j�`���[�h�Q�H�@�k�x�ƃ}�O�j�`���[�h���Ăǂ��Ⴄ�񂾂����[�c�c�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00300',
    '@box00',
    [[
<PRE @box00>[text00300]
�Y�ݑ��������̂��Ƃ͕����Ă����B

���������o���A���͉����яo�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
SetText(
    'text00310',
    '@box00',
    [[
<PRE @box00>[text00310]
��������֎~�Ȃ̂𖳎����āA����ւ̊K�i���삯�オ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bgef/bg11a2_ove.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bgef/bg11a2_ove.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG11A2')
OP_CE('SetCharaColor', 'BG11A2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2010')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '2010', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '2000')
OP_D0('STRING', '#ffffff')
OP_CE('CreateColorEX', 'MASKBUF2', '2000', '#ffffff')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('MASKBUF2', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('INT', '700')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawTransitionSG', 'BGBUF2', '0', '1000', '700', '250', 'null', 'mask02', 'true', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '1900')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_D0('STRING', 'false')
OP_D0('STRING', 'imv038')
OP_CE('CreateBGMovieSG', '���[�r�[', '1900', '0', '0', 'true', 'true', 'false', 'imv038')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[', 'Play')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE084')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE01', 'SGSE084', '0', '1000', 'false')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00320',
    '@box00',
    [[
<PRE @box00>[text00320]
����̔��͂Ȃ����J���Ă����B�Ƃ������A�����󂳂�Ă����B

�����J����ƁA���n���Ȃ��Ă��������������̂ڂ��Ă���̂��������B

����ɁA�Ȃ������F�̗ӌ��̂悤�Ȃ��̂��L���L���Ƌ󒆂𕑂��Ă���B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0039" mode="on">
�u�����c�c���ƁI�H�v

�J�b�R���ċ����Ă݂����ǁA���A�E�\�A�}�W�Ŕ����H

�܂����A���������Ă����B

�h�L�h�L����B

�����ƁA�ǁA�ǂ�����ׂ����낤�B

���������������H

�Ƃ������Ȃ�Ŕ����H�@�e���H

����A����Ȃ��̂ł͂Ȃ��悤�ȋC������B

�Ȃ��Ȃ�A���̖ڂ̑O�\�\����̃K�����Ƃ����X�y�[�X�̂ǐ^�񒆂ɁA��ȕ��̂��������Ă������炾�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '533')
OP_D0('INT', '700')
OP_D0('INT', '0')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'true')
OP_D0('STRING', 'false')
OP_CE('DrawTransitionSG', 'BGBUF2', '533', '700', '0', '250', 'null', 'mask02', 'true', 'false')
OP_8E()
OP_D0('INT', '2000')
OP_D0('STRING', '#FFFFFF')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '2000', '#FFFFFF', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_24('MASKBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG11A2.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG11A2.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('INT', '200')
OP_3A('200')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00330',
    '@box00',
    [[
<PRE @box00>[text00330]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0040" mode="on">
�u�Ȃ񂾁c�c����́H�v

�����ɂ͓�̋@�킪�������Ă����B

���Ȃ�傫���B�����͂R���[�g���ȏ゠��̂ł͂Ȃ����낤���B

����́c�c�l�H�q���H

����ӌ��A����ɂ������̗h��̌����́A����Ȃ̂��H

����ȕ��A�N�������ɒu�����񂾂낤�H

����Ƃ��A�������p�ӂ������̂��Ƃł������̂��H�@�����̉�Ɗ֌W���������肷��H

�����A�������ɂ������Ƃ��āA�������������܂łǂ�����Ď����Ă����񂾁H

�����͂W�K���ăr���̉��ゾ���H

���̒��͋^�₾�炯�������B

�����Ă��̎���ɂ́A���R�Ȃ��瓚���͏o�Ȃ��B

��̋@��ɋߕt���ׂ����ǂ���<RUBY text="���イ����">�S�O</RUBY>���Ă���ƁA���ɑ����悤�ɂ��āA���l�����\�\�����炭���W�ق̊֌W�҂��A�L�҉�̌W�����\�\�K�i���オ���Ă����B

�����ĒN�����A���Ɠ����悤�ɍ��f�����������B

<voice name="��" class="VID_SUZ" src="voice/SUZ_0000" mode="on">
�u�ߊ��Ȃ��ł������[���I�v

�ƁA�W���̂����̂P�l�Ǝv���鏗�������傫���U��Ȃ���A�������̑O�ւƕ��ݏo�Ă����B

<voice name="��" class="VID_SUZ" src="voice/SUZ_0001" mode="on">
�u�L�҉�͗\��ʂ�n�߂܂��̂ŁA�������΂炭���҂��������[���I�v

�Ȃɂ����B�����Ƃ��Ă���H

�Ή����₯�ɑf�����B����l�H�q���炵�����̂��牓���������炵���B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0041" mode="on">
�u����͓����B�A�d�̓������B�Ȃɂ��B�������񂾁H�@�������̔����͂Ȃ񂾁H�v

�u�c�u�c�Ɛ��ɏo���čl�������点�Ă݂�B

�C�ɂȂ�c�c�B

�C�ɂȂ邪�A����ȏ�ߕt���댯�͔��������������B

�����ăr�r�����킯�ł͂Ȃ����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', '@���[�r�[*')
OP_24('@���[�r�[*')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
SetText(
    'text00340',
    '@box00',
    [[
<PRE @box00>[text00340]
�W���ɗU�������܂܂ɂW�K�ɖ߂�B

�܂��̎p���Ȃ������B�C�x���g���ɂ����Ȃ��B

�T���Ă݂�ƁA�V�K�̗x���ɂ����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG07A1')
OP_CE('SetCharaColor', 'BG07A1')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'TIPS_GACHA')
OP_CE('TipsOn', 'TIPS_GACHA')
OP_8E()
SetText(
    'text00350',
    '@box00',
    [[
<PRE @box00>[text00350]
���{�ɂ�����o�b���˂̒n�������v���[�g�����邻�̉��ɁA<FONT incolor="#ff7080" outcolor="#000000">�J�v�Z���g�C</FONT>��������ƕ���ł���B

����𕨗~�������Ȋ�Œ��߂Ă����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
OP_D0('STRING', 'PhoneMode_PowerOff')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_Phone_Open')
OP_8E()
SetText(
    'text00360',
    '@box00',
    [[
<PRE @box00>[text00360]
�ЂƂ܂��z�b�ƈ���S���Ă���A���̓P�[�^�C�����o�����B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0042" mode="on">
�u�����B�ǂ����C���ȗ\��������B���������m��Ȃ��Ƃ���łȂɂ����N�����Ă���悤���v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0043" mode="on">
�u�c�c�����A�������Ă�B�����͂��Ȃ����B�������͐ɂ�������ȁB�G���E�v�T�C�E�R���O���D�v

���߂ĕʂ�̍������t�Œ��߂���A�z�ɟ��񂾊�����̍b�Ő@�����B

����ׁB���Ȃ��⊾�����Ă�B

�{���ɂȂɂ��N��������ǂ����悤�B

���Ҕ����A�s�������Ƃ����Ƃ��낾�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
SetText(
    'text00370',
    '@box00',
    [[
<PRE @box00>[text00370]
�P�[�^�C�����܂��A���߂Ă܂�������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgCopy', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'GRAOW', '5000')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF1', '0', '2000', '2000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'GRAOW', '533', 'null', 'true')
OP_8E()
SetText(
    'text00380',
    '@box00',
    [[
<PRE @box00>[text00380]
�����͂Ȃɂ����Ă���񂾁H

���������ăJ�v�Z���g�C�ɖ����Ȃ̂��H

���������ɂ��܂����������Ă��Ȃ��Ƃ́B

�Ƃ�ł��Ȃ��啨���A�Ƃ�ł��Ȃ��o�J���̂ǂ��炩���ȁB

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0044" mode="on">
�u�܂��A�Ȃɂ����Ă���H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMB03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMB03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '534')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '534', '0', 'null')
OP_8E()
OP_D0('STRING', '@BGM13')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM13', '0', '1000', 'true')
OP_8E()
SetText(
    'text00390',
    '@box00',
    [[
<PRE @box00>[text00390]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0015" mode="on">
�u��[�H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMB01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMB01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00400',
    '@box00',
    [[
<PRE @box00>[text00400]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0016" mode="on">
�u���̂ˁA�w���[�ρx���ق����Ȃ����āv

�\�z�ʂ肩�c�c�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2200')
OP_D0('STRING', 'cg/ibg/ibg003.png')
OP_CE('BgLoad', 'BGBUF2', '2200', 'cg/ibg/ibg003.png')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '128')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', '@STBUF5*')
OP_D0('INT', '1066')
OP_D0('INT', '285')
OP_D2()
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'false')
OP_20('@STBUF5*', '1066', '@', '@', 'AxlDxl', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '1066', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_CE('PosSetSt', 'STBUF5')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '227')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '227', '@')
OP_8E()
SetText(
    'text00410',
    '@box00',
    [[
<PRE @box00>[text00410]
�܂�肪�w�������J�v�Z���g�C�̃}�V���ɂ́A�w<RUBY text="�炢">��</RUBY>�l�b�g<RUBY text="������">��</RUBY>�@���̃L�����N�^�[�h�[���V���[�Y�x�Ƃ����`�[�v�ȃf�B�X�v���C���{����Ă����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'TIPS_SHOW')
OP_CE('TipsOn', 'TIPS_SHOW')
OP_8E()
SetText(
    'text00420',
    '@box00',
    [[
<PRE @box00>[text00420]
����q�������l�܂Œm��Ȃ��҂͂��Ȃ��A�j���w<FONT incolor="#ff7080" outcolor="#000000">���l�b�g��</FONT>�x�B

�X�s���A�E�g�����J�[�h�Q�[���w���l�b�g�E�A�N�Z�X�o�g���[�Y�x�͊C�O�ɂ܂Ől�C����щ΂��A���E�K�͂̑��J�����قǂ��B

���Ȃ݂ɂ܂�肪�����w���[�ρx�Ƃ́A���́w���l�b�g�āx�̒��ōł��l�C������A�}�X�R�b�g�I�L�����N�^�[�ł���B

�����ڂƂ��ẮA���̂悤�ȑȉ~�`�ł����Ɏ葫�������������ۂ��������A�ƌ����΂������낤���B

������A���L�����Ƃ������̂ɕ��ނ����Ǝv����B

���q�����ɐl�C���o�Ă����������Ȃ��B���������΋��N���A�L�����J�G���̃L�����N�^�[�����s���Ă����ȁB���O�͖Y�ꂽ���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '533', '0', 'null', 'true')
OP_8E()
SetText(
    'text00430',
    '@box00',
    [[
<PRE @box00>[text00430]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0045" mode="on">
�u���΂����B�w���[�ρx�������邩�ǂ����͕ۏ؂ł��Ȃ����ȁv

�����܂��͍������悤�ȏ΂݂𕂂��ׂ��܂܂��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00440',
    '@box00',
    [[
<PRE @box00>[text00440]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0017" mode="on">
�u�ł��ˁA�܂䂵���͍��A�P�O�O�~�ʂ�؂炵������Ă���̂ł��v

�܂��͎����̂��Ƃ��g�܂䂵���h�ƌĂԁB

�����ƌ����Ɍ����Ȃ�g�܂䂵���h�̌�ɂ́����t���炵���B

���Ȃ킿�g�܂䂵�����h�B

�܂��ɂǂ��ł��������Ƃ����B

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0018" mode="on">
�u������A�I�J�����I�J�����A�P�O�O�~�݂��ā[�H�v

�˂���悤�ɁA���Ɍ����Ď�̕��������Ă���B

�ǂ����ŏ����炻������҂��Ă����炵���B

�g���傤�����h�ƌ����Ă��Ȃ������܂��}�V�����B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0046" mode="on">
�u�Â������Ȃ܂��B���݂͑���B�������O�ɐl���̌������������Ă��v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '533')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '533', '1000', 'null', 'true')
OP_8E()
SetText(
    'text00450',
    '@box00',
    [[
<PRE @box00>[text00450]
���͌������ƁA�T�C�t����P�O�O�~�ʂ����o���ăR�C���}�����ɃZ�b�g�����B�����悭���o�[���񂷁B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE188')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE01', 'SGSE188', '0', '1000', 'false')
OP_8E()
OP_D0('STRING', 'SE01')
OP_CE('WaitPlayHalfSG', 'SE01')
OP_8E()
SetText(
    'text00460',
    '@box00',
    [[
<PRE @box00>[text00460]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0019" mode="on">
�u���A�����[�c�c�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF2', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
SetText(
    'text00470',
    '@box00',
    [[
<PRE @box00>[text00470]
�o�Ă����J�v�Z���������Ē��g�����o�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '133')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '133', 'true')
OP_8E()
SetText(
    'text00480',
    '@box00',
    [[
<PRE @box00>[text00480]
�܂����Ȃɂ��o�����C�ɂȂ�悤�ŁA���̎茳���̂�������ł���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALB02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALB02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00490',
    '@box00',
    [[
<PRE @box00>[text00490]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0020" mode="on">
�u�����A�w���[�ρx����B���������^���B�w���^�����[�ρx�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0047" mode="on">
�u����̓��A�Ȃ̂��H�v

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0021" mode="on">
�u�������I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'GRAOW', '5000')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2000')
OP_CE('BgCopy', 'BGBUF1', 'BGBUF2', '2000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF2', '0', '1000', '1000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'GRAOW', '533', 'null', 'true')
OP_8E()
SetText(
    'text00500',
    '@box00',
    [[
<PRE @box00>[text00500]
���́w���^�����[�ρx�����������ƒ��߂Ȃ���A�J�v�Z���g�C�̑O���痣�ꂽ�B

�������̌��Ō��Ă������w�����炢�̒j�̎q���A�����ē����w���l�b�g�āx�̃J�v�Z���g�C�ɒ��킵�Ă���B

<voice name="�j�̎q" class="VID_ETC" src="voice/BOY_0000" mode="on">
�u���[�A���ʂ́w���[�ρx���c�c�v

���̓��Ă��w���^�����[�ρx�����߂����Ɍ��߂Ă���B

���̉��ł͂܂�肪�ڂ��P�����Ă���B

�������q�����B���w���j���Ɠ����x�������c�c�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'EV_M01A')
OP_CE('ChkAchieveEVRead', 'EV_M01A')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', '�G��', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '3200')
OP_D0('STRING', 'cg/ev/EV_M01A.jpg')
OP_CE('BgLoad', 'BGBUF2', '3200', 'cg/ev/EV_M01A.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', '�G��', '533', 'null', 'true')
OP_8E()
SetText(
    'text00510',
    '@box00',
    [[
<PRE @box00>[text00510]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0048" mode="on">
�u�t���A�ł͂܂��ɂ���Ă�낤�v

�͂����茾���đS�R�������Ȃ������B

�܂��̎�Ɂw���^�����[�ρx�����点�Ă��B

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0022" mode="on">
�u�z���g�[�H�@�����́H�@�I�J�����v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0049" mode="on">
�u�P���@���^���v

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0023" mode="on">
�u�����ւց[�A���肪�Ɓ[�I�J������v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0050" mode="on">
�u�c�c�c�c�v

���������Ă킴�Ƃ��������������ĂȂ����H

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF2', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
SetText(
    'text00520',
    '@box00',
    [[
<PRE @box00>[text00520]
<voice name="�i���" class="VID_ETC" src="voice/MCA_0000" mode="on">
�u�\�\�{���́A�h�N�^�[�����ɂ��^�C���}�V�����������L�O��ɂ��W�܂肢�������A�܂��Ƃɂ��肪�Ƃ��������܂��v

��̊K����A�������ɂ���ȃ}�C�N�̐����������Ă����B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0051" mode="on">
�u�ǂ����n�܂�悤���ȁv

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF1', '0', '1000', '1000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF1', '0', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '1066')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF1', '1066', '2000', '2000', 'AxlDxl', 'true', 'Smoothing')
OP_8E()
OP_D0('INT', '266')
OP_3A('266')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '5100')
OP_D0('STRING', '#000000')
OP_CE('CreateColorEX', 'MASKBUF2', '5100', '#000000')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_25('MASKBUF2', '1066', '1000', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '1066')
OP_D0('INT', '512')
OP_91()
OP_D0('INT', '288')
OP_91()
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_20('BGBUF1', '1066', '@', '@', 'AxlDxl', 'true')
OP_8E()
SetText(
    'text00530',
    '@box00',
    [[
<PRE @box00>[text00530]
�W�K�ւƌ������B

�����܂�肪���Ă��Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'MASKBUF2')
OP_D0('INT', '1066')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_CE('FadeDelete', 'MASKBUF2', '1066', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_20('BGBUF1', '1066', '0', '0', 'AxlDxl', 'true')
OP_8E()
SetText(
    'text00540',
    '@box00',
    [[
<PRE @box00>[text00540]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0052" mode="on">
�u�s�����܂��v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00550',
    '@box00',
    [[
<PRE @box00>[text00550]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0024" mode="on">
�u��[�A�҂��đ҂��āB���O�����Ȃ�����v

�ǂ����w���^�����[�ρx�ɖ����炵���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG06A3.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG06A3.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG06A3')
OP_CE('SetCharaColor', 'BG06A3')
OP_8E()
OP_D0('INT', '533')
OP_3A('533')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00560',
    '@box00',
    [[
<PRE @box00>[text00560]
<voice name="�i���" class="VID_ETC" src="voice/MCA_0001" mode="on">
�u����ł́A�����o�ꂵ�Ă��������܂��傤�B�����ƁA�h�N�^�[��������ł��I�@�F����A����Ȕ���ł��}�����������I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE001')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE01', 'SGSE001', '0', '1000', 'false')
OP_8E()
OP_D0('STRING', 'SE01')
OP_CE('WaitPlayHalfSG', 'SE01')
OP_8E()
SetText(
    'text00570',
    '@box00',
    [[
<PRE @box00>[text00570]
�܂΂�\�\�ǂ��납�ق�̐��l�����̔���Ɍ}�����āA���������ꂽ�B

���̉��ɐݒu���ꂽ�d�Ɍ������B

���������Ȃ�̕����ʂ��B�s�@�������S�g������o���Ă���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', '�G��', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '1000')
OP_CE('BgCopy', 'BGBUF1', 'BGBUF2', '1000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF2', '0', '2000', '2000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'STBUF6')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF6', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF6')
OP_D0('INT', '1600')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'NAK_ASA02')
OP_CE('St', 'STBUF6', '1600', '@', '@', 'NAK_ASA02')
OP_8E()
OP_D0('STRING', 'STBUF6')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF6', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF1', '0', '2000', '2000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', '�G��', '533', 'null', 'true')
OP_8E()
SetText(
    'text00580',
    '@box00',
    [[
<PRE @box00>[text00580]
<voice name="����" class="VID_NAK" src="voice/NAK_0000" mode="on">
�u�h�N�^�[�������B�ǂ�����낵���v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF6')
OP_D0('INT', '1600')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'NAK_ASA01')
OP_CE('St', 'STBUF6', '1600', '@', '@', 'NAK_ASA01')
OP_8E()
OP_D0('STRING', 'STBUF6')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF6', '267', 'true')
OP_8E()
SetText(
    'text00590',
    '@box00',
    [[
<PRE @box00>[text00590]
<voice name="����" class="VID_NAK" src="voice/NAK_0001" mode="on">
�u����ł́A�����ɏW�܂��Ă���������N�����ɁA�l�ގj�Ɏc�鐢�I�̑唭���A�^�C���}�V���ɂ��Ă̗��_�����������悤�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'BGBUF4', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF4', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgCopy', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALC02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALC02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'STBUF6')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF6', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgSwap', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('INT', '5')
OP_D0('INT', '6')
OP_D0('INT', '7')
OP_D0('INT', '8')
OP_CE('CharaPrio4', '5', '6', '7', '8')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF4', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
SetText(
    'text00600',
    '@box00',
    [[
<PRE @box00>[text00600]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0025" mode="on">
�u�^�C���}�V���H�@���̐l��������́[�H�v

�w���^�����[�ρx�ɖ��O�������I������炵���܂�肪����ė��āA������Ȃ���Ȃ��Ƃ������Ă���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00610',
    '@box00',
    [[
<PRE @box00>[text00610]
�����́A�}�C�N��Ў�ɁA���M���X�Ƃ����ԓx���݂Ȃ��点�Ęb���n�߂��B

���O�͉������Ă��������Q�O�l�قǂ��B��������菭�������������B

������͂�A�L�҂�J�����}���炵���l���͌�������Ȃ��B

���ꂪ���Ԃ̃h�N�^�[�����ւ̒��ړx���Ɨ��������B

�F���m�����Ƃ��g�^�C���}�V���𔭖������h�Ɣ��\�����Ƃ���ŁA���Ԃ́g�Ȃɂ������Ă�񂾂��h�Ƃ������΂ŕԂ������B

�����A���̒j����邱�Ƃɋ����͂��������A����قǊ��҂��Ă����킯�ł͂Ȃ��B

�����Ă���́A�h�N�^�[�����������^�C���}�V���̗��_�ɂ��Č��o�����Ƃ��Ɏ��]�ƂȂ�A���Ԃ��o�ɂ�ē{��ւƕς�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', '�G��', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgCopy', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF2', '0', '2000', '2000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'NAK_ASA01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'NAK_ASA01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '0', 'true')
OP_8E()
OP_D0('STRING', '@BGM08')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM08', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF1', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '133')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', '�G��', '133', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgSwap', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF1', '0', '2000', '2000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
SetText(
    'text00620',
    '@box00',
    [[
<PRE @box00>[text00620]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0053" mode="on">
�u�h�������N�������^�[���������I�v

�L�҉���ɂ�������炸�A���͋���ł��܂��Ă����B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0054" mode="on">
�u�o�J�ɂ���ɂ��قǂ����邼�I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'NAK_ASA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'NAK_ASA02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00630',
    '@box00',
    [[
<PRE @box00>[text00630]
<voice name="����" class="VID_NAK" src="voice/NAK_0002" mode="on">
�u�Ȃ񂾂ˌN�́I�H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0055" mode="on">
�u�����N�Ȃ̂��͂ǂ��ł������I�@������A���M����������^�C���}�V���̗��_�͂��������Ȃ񂾁I�H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'TIPS_TITOR')
OP_CE('TipsOn', 'TIPS_TITOR')
OP_8E()
SetText(
    'text00640',
    '@box00',
    [[
<PRE @box00>[text00640]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0056" mode="on">
�u<FONT incolor="#ff7080" outcolor="#000000">�W�����E�^�C�^�[</FONT>�̃p�N���ł͂Ȃ����I�@�M���͂���ł������Ƃ����I�v

<voice name="����" class="VID_NAK" src="voice/NAK_0003" mode="on">
�u���A�N���A���̒j���܂ݏo���v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0057" mode="on">
�u�o�Ă����̂͋M�����A�h�N�^�[�I�@�p��m��I�@<RUBY text="�����񂴂�">���֍�</RUBY>�A�M���ɂ͔����Ƃ𖼏�鎑�i�͂Ȃ������I�v

<voice name="����" class="VID_NAK" src="voice/NAK_0004" mode="on">
�u���邳���A�ق���I�@���ӋC�Ȏᑢ�߂��I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '900')
OP_D0('INT', '13')
OP_D0('INT', '6')
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'true')
OP_CE('AllShake', '900', '13', '6', 'DxlAuto', 'true')
OP_8E()
SetText(
    'text00650',
    '@box00',
    [[
<PRE @box00>[text00650]
�ƁA�w�ォ�牴�̎�����҂������񂾁B

�Ă����艴���܂ݏo�����Ƃ���W�����Ǝv���A�ɂ�݂��鐨���ŐU��Ԃ�B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0058" mode="on">
�u�́A�ȁA�����c�c���H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'EV_C01A')
OP_CE('ChkAchieveEVRead', 'EV_C01A')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '3200')
OP_D0('STRING', 'cg/ev/EV_C01A.jpg')
OP_CE('BgLoad', 'BGBUF2', '3200', 'cg/ev/EV_C01A.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '0', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '133')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask18')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '133', '100', 'null', 'mask18', 'true', 'true')
OP_8E()
SetText(
    'text00660',
    '@box00',
    [[
<PRE @box00>[text00660]
<voice name="�H�H�H" class="VID_CRS" src="voice/CRS_0000" mode="on">
�u�c�c�c�c�v

���Ɠ����N���炢�̏��������B

���݂������Ă��邩�̂悤�ȁA�����፷���B

�^���ʂ��畨�|�������Ɍ����Ă��邻�̎����ɁA���͂����낮�B

���̊�ɂ͌��o�����������B�O�ɁA�ǂ����Łc�c�H

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0059" mode="on">
�u���c�c�v

<RUBY text="�܂���">�q��</RUBY><RUBY text="���肷">�g仐�</RUBY>���B

��������Ƃ͂Ȃ�����͒m���Ă���B

�����O�A���̗F�l�ł���_���\�\<RUBY text="�͂���">���c</RUBY><RUBY text="������">��</RUBY>���G���������Ă��ꂽ�B

���̒��̋L���Ɂg�V�ˏ������H�t���ōu���h�Ƃ������e���������B

�Ȃ�ł��A���N�̏t�ɂ킸���P�V�΂ŃA�����J�̑�w���ы��ő��Ƃ��A�����_�����A�����J�̊w�p�G���w�T�C�G���X�x�ɍڂ����Ƃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '2300')
OP_D0('STRING', 'cg/ibg/ibg004.jpg')
OP_CE('BgLoad', 'BGBUF3', '2300', 'cg/ibg/ibg004.jpg')
OP_8E()
OP_D0('STRING', '@BGM19')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM19', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'GRAOW', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '3200')
OP_D0('STRING', 'cg/ibg/ibg004.jpg')
OP_CE('BgLoad', 'BGBUF2', '3200', 'cg/ibg/ibg004.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'GRAOW', '533', 'null', 'true')
OP_8E()
SetText(
    'text00670',
    '@box00',
    [[
<PRE @box00>[text00670]
�L���Ŗq���g仐��ƏЉ��Ă����V�ˏ����B

�f�ڂ���Ă����ʐ^�Ɏʂ��Ă����̂��A���ڂ̑O�ɂ��邱�̐��ӋC�����ȏ��������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'BGBUF4', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF4', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '4000')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF3', '4000', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('INT', '500')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask12')
OP_D0('STRING', 'true')
OP_D0('STRING', 'false')
OP_CE('DrawTransitionSG', 'BGBUF3', '0', '0', '500', '250', 'null', 'mask12', 'true', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF3', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_24('BGBUF5')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '0')
OP_CE('BgCopy', 'BGBUF2', 'BGBUF5', '0')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '0')
OP_D0('INT', '2000')
OP_D0('INT', '2000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF5', '0', '2000', '2000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '0')
OP_D0('INT', '656')
OP_D2()
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF5', '0', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF5', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF4', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
SetText(
    'text00680',
    '@box00',
    [[
<PRE @box00>[text00680]
���̎ʐ^�ł��A���Ɠ����悤�ɕs�@�����ۏo���̊炾�����̂���ۂɎc���Ă���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'BGBUF4', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF4', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgCopy', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '640')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '640', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALB04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALB04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_24('BGBUF5')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_CE('BgSwap', 'BGBUF1', 'BGBUF2', '0')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('INT', '5')
OP_D0('INT', '6')
OP_D0('INT', '7')
OP_D0('INT', '8')
OP_CE('CharaPrio4', '5', '6', '7', '8')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF4', '533', 'null', 'true')
OP_8E()
SetText(
    'text00690',
    '@box00',
    [[
<PRE @box00>[text00690]
����ȓV�˂��A�Ȃ����ɐ��������Ă����H

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0001" mode="on">
�u������Ɨ��Ă���܂��񂩁v

�������\��̂܂܎��͂ɑf���������𑖂点�A�����Ŏ��ł����Ă����B

�Ȃ񂾁A���̑ԓx�́B

�q���g仐������̌W�����Ƃ͎v���Ȃ��B

���Ƃ����ăh�N�^�[�����̊֌W�҂ł���͂����Ȃ��B

�ƂȂ�Ɓc�c�܂����c�c�I

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0060" mode="on">
�u���A�M�l�A�g�@�ցh�̐l�Ԃ��I�H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALC05')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALC05')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00700',
    '@box00',
    [[
<PRE @box00>[text00700]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0002" mode="on">
�u�͂��H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0061" mode="on">
�u�����A�܂��������܂Ŏ肪����Ă���Ƃ́c�c�B���Ƃ������Ƃ��v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALB03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALB03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00710',
    '@box00',
    [[
<PRE @box00>[text00710]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0003" mode="on">
�u�ӂ����ĂȂ��ŁA������Ɨ��Ă��������v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0062" mode="on">
�u�c�c�c�c�v

�����͖ق��ď]�����Ƃɂ����B

���̉��́A�h�N�^�[�����ɃP���J�𔄂������ƂŖ��炩�ɒ��ڂ𗁂тĂ��܂��Ă���B

�Ƃ��������������������܂��������łɂ�݂��Ă��Ă���킯�����B

���̂悤�Ȏᑢ�ɐ}�����w����A�����������̂��낤�B

�Ƃɂ�������ȏ㒍�ڂ����킯�ɂ͂����Ȃ��B

���͋��C�̃}�b�h�T�C�G���e�B�X�g�B�g�@�ցh����ǂ��Ă���g�Ȃ̂��B

���̂܂܂��Ɗ댯�Ȏ��ԂɂȂ肻���ȗ\��������B

�܂�����͂̒��O���A����Ȏ��ԂɊ������ނ킯�ɂ͂����Ȃ������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00720',
    '@box00',
    [[
<PRE @box00>[text00720]
�q���g仐��́A���ƂȂ����Ȃ������̎�������āA���̊O�ɏo���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '533')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '533', '100', 'null', 'mask02', 'true', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF*')
OP_24('BGBUF*')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG07A1')
OP_CE('SetCharaColor', 'BG07A1')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMA04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMA04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '0', 'true')
OP_8E()
OP_D0('INT', '533')
OP_3A('533')
OP_8E()
OP_D0('STRING', '@BGM07')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM07', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00730',
    '@box00',
    [[
<PRE @box00>[text00730]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0063" mode="on">
�u�����ŉ��ɂȂɂ�����ΐl�ڂɕt�����B�����Ȃ�΋M�l���F�X�܂������낤�v

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0004" mode="on">
�u�Ȃɂ����ĂȂ�ł����A�l�����̈����v

�ɂ�܂ꂽ�B�Ȃ��Ȃ��̔��́B

�[���Ȋ痧�������Ă�̂ɁA���킢���̌��Ђ��Ȃ��B

�⍓����̔������G�[�W�F���g���c�c�B

�g���̗\�������A�Ȃ����S�����������Ă��鎩���������B

��͂艴�́A���ׂɐg��u�����Ƃ��D���炵���A�N�N�N�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMA01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMA01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00740',
    '@box00',
    [[
<PRE @box00>[text00740]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0005" mode="on">
�u���́A���Ȃ��ɕ����������Ƃ����邾���ł��v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0064" mode="on">
�u����ɓ�����`���͂Ȃ��B�g�@�ցh�̂����͕������Ă���v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMC05')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMC05')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00750',
    '@box00',
    [[
<PRE @box00>[text00750]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0006" mode="on">
�u������g�@�ցh���āH�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
OP_D0('STRING', 'PhoneMode_PowerOff')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_Phone_Open')
OP_8E()
SetText(
    'text00760',
    '@box00',
    [[
<PRE @box00>[text00760]
���̖₢�͖������Ă��������P�[�^�C�����o���A���ɓY�����B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0065" mode="on">
�u�����B�g�@�ցh�̃G�[�W�F���g�ɕ߂܂����B�c�c�����A�q���g仐����A���̏��ɂ͋C��t����c�c������Ȃ��A�����͂Ȃ�Ƃ��؂蔲���\�\�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00770',
    '@box00',
    [[
<PRE @box00>[text00770]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0007" mode="on">
�u�c�c�c�c���v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '133')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '133', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'BGBUF4', '5000')
OP_8E()
OP_D0('INT', '32')
OP_39('32')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '0', 'true')
OP_8E()
OP_D0('INT', '10')
OP_B0('$SW_PHONE_PRI')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '266')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF4', '266', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00780',
    '@box00',
    [[
<PRE @box00>[text00780]
�����Ȃ�g仐��͉��̃P�[�^�C�����グ�Ă��܂����B

�Ȃ�Ƃ������ƁB���܂�ɉؗ�Ȋ�P�U�����������߁A���͒�R���邱�Ƃ���ł��Ȃ������B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0066" mode="on">
�u�����A�Ȃɂ�����I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMC04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMC04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00790',
    '@box00',
    [[
<PRE @box00>[text00790]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0008" mode="on">
�u����H�@���̃P�[�^�C�A�d���؂�Ă�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0067" mode="on">
�u�c�c�c�c�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMB04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMB04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00800',
    '@box00',
    [[
<PRE @box00>[text00800]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0009" mode="on">
�u�c�c�N�Ƙb���Ă�����ł����H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00810',
    '@box00',
    [[
<PRE @box00>[text00810]
�T��悤�Ȏ������������A���͍Q�ĂĖڂ���炵���B

�����c�c�ł���B���̃A�C�f���e�B�e�B�������������_�����U���C���B

���Ē����B���͂��̒��x�ŗh�炬�͂��Ȃ����I

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0068" mode="on">
�u���A�M�l�ɓ�����`���͂Ȃ����ꉞ�����Ă�낤�B����͉��ȊO���G��Ǝ����I�ɓd�����I�t�ɂȂ�A���ʐ��̃P�[�^�C�Ȃ̂����B�t�D�[�n�n�n�I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_AMB04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_AMB04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00820',
    '@box00',
    [[
<PRE @box00>[text00820]
����ȓ��ʐ��������Ă���̂����ׂċ@���ێ��̂��߁B

����������悤�ɃP�[�^�C�����߂��ƁA���͊z�ɟ��񂾗�⊾�������Ɛ@�����B

�ӂ��A�ł������B

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0010" mode="on">
�u�c�c�����B�Ƃ茾�������̂ˁv

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0069" mode="on">
�u�c�c���v

�܂����B�q���g仐��͓V�ˏ����ƌĂ΂�邾�������Ĉ�ؓ�ł͂����Ȃ��B

����ǂ��납���ɐ��_�I�h���Ԃ�������Ă��Ă���I

�����A�����͂ЂƂ܂��헪�I�P�ނ����������悳�������B

�Ȃ�Ƃ�����˂��Ȃ���΁c�c�I

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALA01')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALA01')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00830',
    '@box00',
    [[
<PRE @box00>[text00830]
�ƁA�\����������߂��g仐����A�����Ȃ艴�ɋl�ߊ���Ă����B

���ߋ�������A����ࣁX�Ƃ�����傫�ȓ��ł܂������Ɍ������Ă���B

�Ȃ�Ƌ����ӎu�ɖ�����ꂽ��̋P���Ȃ񂾁B

���͎v�킸������Ă��܂����B

����قǂ̂܂������ŏ����ȓ��̎����傪�A�{���Ɂg�@�ցh�̃G�[�W�F���g�Ȃ̂��c�c�H

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM11')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM11', '0', '1000', 'true')
OP_8E()
SetText(
    'text00840',
    '@box00',
    [[
<PRE @box00>[text00840]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0011" mode="on">
�u�������A���ɂȂɂ��������Ƃ�����ł����H�v

�c�c�������H

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0070" mode="on">
�u�������Ƃ͂��̂��Ƃ��H�v

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0012" mode="on">
�u�ق�̂P�T�����炢�O�B����n�܂�O�Ɂv

�Ȃɂ��o�J�ȁB���������Ɖ�����͍̂������߂Ă����B

�P�T���O�ɂ͂܂��Ɓw���[�ρx�̃J�v�Z���g�C�Ő���オ���Ă����̂��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALC06')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALC06')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00850',
    '@box00',
    [[
<PRE @box00>[text00850]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0013" mode="on">
�u���ɁA�Ȃɂ��������Ƃ��܂�����ˁH�@�������߂������Ȋ�����āv

㩂��H�@�����ɂ��������g�@�ցh�̂�肻���Ȃ��Ƃ����B

���������̏������A����Ȏ���g�����낤���B

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0014" mode="on">
�u�܂�ŁA���ɂ������o�������ŁA����ɂ������h�����ł����v

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0015" mode="on">
�u�c�c�ǂ����āH�@���A�O�ɂ��Ȃ��Ɖ�������Ƃ���܂����H�v

�q���g仐��͏�k�������Ă���悤�ɂ͌����Ȃ��B

�����炱���A���ɂƂ��Ă��̏��́A���̂��m��Ȃ��B

�������A����x�����ȁI

�����͗⍓����ȃG�[�W�F���g�B

�����ł�����������Ε�����c�c�I

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'CRS_ALC05')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'CRS_ALC05')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text00860',
    '@box00',
    [[
<PRE @box00>[text00860]
<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0016" mode="on">
�u���������΂Ȃ�Ŏ��̖��O�A�m���Ă��ł��H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0071" mode="on">
�u���͂��ׂĂ����ʂ��Ȃ̂��v

�Ȃɂ���}�b�h�T�C�G���e�B�X�g������ȁB

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0072" mode="on">
�u�V�ˏ�����A����Ƃ��͓G���m���ȁI�v

<voice name="�g仐�" class="VID_CRS" src="voice/CRS_0017" mode="on">
�u�͂��c�c�H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0073" mode="on">
�u����΂��A�t�D�[�n�n�n�I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text00870',
    '@box00',
    [[
<PRE @box00>[text00870]
���͂��̏�łP�W�O�x�t�^�[������ƁA�D�u�Ƃ��������ŊK�i���삯���肽�B

�q���g仐��̌Ăю~�߂鐺���w�ォ��ǂ��Ă������A�G�̌������Ƃ𕷂��킯�ɂ͂����Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('INT', '4900')
OP_B0('$SW_PHONE_PRI')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A3.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A3.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG07A3')
OP_CE('SetCharaColor', 'BG07A3')
OP_8E()
OP_D0('INT', '266')
OP_39('266')
OP_8E()
OP_D0('INT', '800')
OP_3A('800')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text00880',
    '@box00',
    [[
<PRE @box00>[text00880]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0074" mode="on">
�u���A�g�@�ցh�߁A����قǂ̃G�[�W�F���g�𑗂荞��ł���Ƃ́A���ɖ{�C�ɂȂ����悤���ȁc�c�I�v

��C�ɂS�K�܂ŋ삯���肽�Ƃ���Ō���U��Ԃ�A�q���g仐����ǂ������Ă��Ȃ��Ƃ����m�M�𓾂��Ƃ���ŁA���͂��߂��݂��w�ŉ������A�[�X�Ƒ��������B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0075" mode="on">
�u���A�����A���͂܂����c��ɕ߂܂�킯�ɂ͂�����̂��c�c�v

���ĂƁA���ꂩ��ǂ����ׂ����B

�����̖ړI�ł������h�N�^�[�����̉���e�ɂ��ẮA�P�Ȃ�p�N�����ƕ��������B�����牴�����̉��֖߂�Ӗ��͂����Ȃ��B

�������ƋA�낤�B

���ꂪ�ł��Ó��ȑI�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '1066')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '1066', '100', 'null', 'mask02', 'true', 'true')
OP_8E()
SetText(
    'text00890',
    '@box00',
    [[
<PRE @box00>[text00890]
�����łӂƁA�d��ȂȂɂ���Y��Ă��邱�ƂɋC�t�����B

�͂āA�Ȃ񂾂������낤�ƍl���Ă݂�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG07A3.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG07A3.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF2', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '1066')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '1066', '100', 'null', 'mask02', 'false', 'true')
OP_8E()
SetText(
    'text00900',
    '@box00',
    [[
<PRE @box00>[text00900]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0076" mode="on">
�u�`�B�b�I�@�܂���u���Ă����c�c�I�v

���̑���܂Ƃ��߁B

�A��Ă���ׂ��ł͂Ȃ������B

�����̈��S����Ԃɍl���Ă�������Ȃ̂ɁA���͖��f���Ă����悤���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
SetText(
    'text00910',
    '@box00',
    [[
<PRE @box00>[text00910]
�ЂƂ܂��P�[�^�C�ɓd�b���Ă݂悤�B�ꍇ�ɂ���Ă͂����ɌĂт���΂����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
OP_D0('STRING', 'PhoneMode_PowerOff')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '533')
OP_39('533')
OP_8E()
OP_D0('STRING', 'PhoneMode_Default')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
SetText(
    'text00920',
    '@box00',
    [[
<PRE @box00>[text00920]
�����v���Ď����̃P�[�^�C�����o�����B�d��������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'PhoneMode_ReceivingMail')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '1000')
OP_3A('1000')
OP_8E()
SetText(
    'text00930',
    '@box00',
    [[
<PRE @box00>[text00930]
�r�[�ɒ��M���������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'FM_From_XXX0001')
OP_B0('$LR_TARGET_MAILNO')
OP_8E()
OP_CE('macrosys2_RECEIVE_NEW_MAIL')
OP_8E()
SetText(
    'text00940',
    '@box00',
    [[
<PRE @box00>[text00940]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0077" mode="on">
�u��c�c�H�@���[�����H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_E4()
OP_8E()
OP_D0('STRING', 'SE03')
OP_D0('INT', '133')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE03', '133', '0', 'null')
OP_8E()
OP_CE('macrosys2_DISP_RECEIVEBOX')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '1000')
OP_3A('1000')
OP_8E()
OP_CE('macrosys2_DISP_RECEIVED_MAIL_DIRECT')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '1000')
OP_3A('1000')
OP_8E()
SetText(
    'text00950',
    '@box00',
    [[
<PRE @box00>[text00950]
����͕��ʂ̃��[���ł͂Ȃ��A����t���̃��[�r�[���[�����B

���M�҂́A���o���̂Ȃ��A�h���X�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'PhoneMode_MailSubMenu')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
SetText(
    'text00960',
    '@box00',
    [[
<PRE @box00>[text00960]
�s�R�Ɏv���A���[�r�[���Đ����Ă݂�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('INT', '133')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE01', '133', '0', 'null')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('INT', '133')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE02', '133', '0', 'null')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '20000')
OP_CE('CreatePlainSP', '�G��', '20000')
OP_8E()
OP_D0('STRING', '�G�w�i')
OP_D0('INT', '10010')
OP_D0('STRING', 'Center')
OP_D0('STRING', 'Middle')
OP_D0('STRING', 'cg/ibg/ibg778.jpg')
OP_CE('CreateTextureSP', '�G�w�i', '10010', 'Center', 'Middle', 'cg/ibg/ibg778.jpg')
OP_8E()
OP_D0('STRING', '���[�r�[�E�B���h�E')
OP_D0('INT', '0')
OP_D0('INT', '290')
OP_D0('INT', '38')
OP_D0('INT', '442')
OP_D0('INT', '501')
OP_D0('STRING', 'false')
OP_14('���[�r�[�E�B���h�E', '0', '290', '38', '442', '501', 'false')
OP_8E()
OP_D0('STRING', '���[�r�[�E�B���h�E')
OP_D0('STRING', '���[�r�[�E�B���h�E')
OP_2B('���[�r�[�E�B���h�E', '���[�r�[�E�B���h�E')
OP_8E()
OP_D0('STRING', '���[�r�[�E�B���h�E/���[�r�[')
OP_D0('INT', '10100')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_D0('STRING', 'false')
OP_D0('STRING', 'dx/imv001.ngs')
OP_D0('STRING', 'false')
OP_12('���[�r�[�E�B���h�E/���[�r�[', '10100', '0', '0', 'true', 'false', 'dx/imv001.ngs', 'false')
OP_8E()
OP_D0('STRING', '���[�r�[�E�B���h�E/���[�r�[')
OP_D0('STRING', '���[�r�[�E�B���h�E/���[�r�[')
OP_2B('���[�r�[�E�B���h�E/���[�r�[', '���[�r�[�E�B���h�E/���[�r�[')
OP_8E()
OP_D0('STRING', '���[�r�[�E�B���h�E/���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[�E�B���h�E/���[�r�[', 'Play')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE005L')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SePlay', 'SE01', 'SGSE005L', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '266')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', '�G��', '266', 'null', 'true')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '3000')
OP_3A('3000')
OP_8E()
SetText(
    'text00970',
    '@box00',
    [[
<PRE @box00>[text00970]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0078" mode="on">
�u�c�c�H�v

�m�C�Y�̂悤�ȉ��Ɖf�������X�Ɛ��ꗬ����邾���������B

���������ăC�^�Y�����H�@���邢�͖q���g仐��ɂ��Ȃ�炩�̍U�����H�@���̃m�C�Y�͎��͐l��������������������g�������肷��Ƃ��B

�c�c����A���̏��ɃA�h���X���������o���͂Ȃ��̂ŁA����͂������ɍl���������낤�B

�f���ɍĐ����Ă��܂����Ԕ������Ղ�ɁA���͏�������ł������B

�����������͂���Ȃ��̂ɍ\���Ă���ꍇ�ł͂Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'FM_From_XXX0001')
OP_B0('$SW_PHONE_MAILCURMNO')
OP_8E()
OP_D0('STRING', 'PhoneMode_ReceivedMail')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('STRING', '@���[�r�[�E�B���h�E/���[�r�[')
OP_24('@���[�r�[�E�B���h�E/���[�r�[')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('INT', '1')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE01', '1', '0', 'null')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '11000')
OP_CE('CreatePlainSP', '�G��', '11000')
OP_8E()
OP_D0('STRING', '���[�r�[�E�B���h�E')
OP_24('���[�r�[�E�B���h�E')
OP_8E()
OP_D0('STRING', '�G�w�i')
OP_24('�G�w�i')
OP_8E()
OP_D0('STRING', '�G��')
OP_D0('INT', '267')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', '�G��', '267', 'null', 'true')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_CE('macrosys2_RETURN_RECEIVEBOX_FUN')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SW_PHONE_MAILMENUCUR')
OP_8E()
OP_D0('STRING', 'PhoneMode_MailMenu')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SW_PHONE_SUBWIN_ALPHA')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SW_PHONE_MENUCUR')
OP_8E()
OP_D0('STRING', 'PhoneMode_DefaultOperatable')
OP_B0('$SW_PHONE_MODE')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SW_PHONE_MENUCUR')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_CE('macrosys2_SELECT_ADDRESSBOOK')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_D0('STRING', 'PhID_MAY')
OP_B0('$LR_TARGET_PhID')
OP_8E()
OP_CE('macrosys2_SELECT_PhID')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_CE('macrosys2_PHONE_ADRSUBMENU_CALL')
OP_8E()
SetText(
    'text00980',
    '@box00',
    [[
<PRE @box00>[text00980]
���[�r�[���[���̍Đ���r���Ŏ~�߁A�A�h���X������܂��̃P�[�^�C���Ăяo���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('macrosys2_PHONE_CALL_EXEC')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '2000')
OP_3A('2000')
OP_8E()
SetText(
    'text00990',
    '@box00',
    [[
<PRE @box00>[text00990]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0079" mode="on">
�u�����A�܂��B�Ȃ��o�Ȃ��v

�����Ȃ�ƁA���ɖ߂炴��𓾂Ȃ��B

���������ł܂��q���g仐��Ɣ����킹������A�ʓ|�Ȃ��ƂɂȂ�B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM12')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM12', '0', '1000', 'true')
OP_8E()
SetText(
    'text01000',
    '@box00',
    [[
<PRE @box00>[text01000]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0080" mode="on">
�u�n�b�A�܂����q���g仐��߁A�܂�����������ȁc�c�I�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0081" mode="on">
�u���̂ꂥ���B���ꂪ�g�@�ցh�̂������c�c�I�v

�܂���u���Ă����Ƃ����I�����́A���ɂ͂Ȃ������B

�ߕی�Ƃ͎v�����A�ǂ����Ă��ڂ������Ȃ��̂��B���̖��I���݂́A�����Ă����Ə���Ƀt���t���Ƃǂ����֍s���Ă��܂������Ȋ낤��������B

�ǂ����Ƃ͂��Ȃ킿�A�����ł͂Ȃ��ǂ����B

�̂���A�܂��ɂ͂��������Ƃ��낪�������B

�c�c�����P���@���^�ƂȂ����̂��A����Ȃ܂��́g�낤���h�������������肷��B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0082" mode="on">
�u�߂邵���Ȃ����c�c�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '3000')
OP_B0('$SW_PHONE_PRI')
OP_8E()
OP_CE('macrosys2_CANCEL_PHONE_CALL')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '1000')
OP_3A('1000')
OP_8E()
OP_CE('macrosys2_CLOSE_PHONE_WINDOW')
OP_8E()
SetText(
    'text01010',
    '@box00',
    [[
<PRE @box00>[text01010]
�܂��W�K�܂ŊK�i����邩�Ǝv���ƁA����Ȃ肵���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG06A3.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG06A3.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG06A3')
OP_CE('SetCharaColor', 'BG06A3')
OP_8E()
OP_D0('INT', '266')
OP_39('266')
OP_8E()
OP_D0('INT', '800')
OP_3A('800')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
OP_D0('INT', '4900')
OP_B0('$SW_PHONE_PRI')
OP_8E()
SetText(
    'text01020',
    '@box00',
    [[
<PRE @box00>[text01020]
���ւƖ߂�ƁA�h�N�^�[�����̉�����傤�ǏI������Ƃ��낾�����B

�d��͖��l�ŁA���łɃG�Z�����Ƃ͑ސȂ����ゾ�����B

�Q�O�l�قǂ̒��O���A���̂��̋A��x�x���n�߂悤�Ƃ��Ă���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
SetText(
    'text01030',
    '@box00',
    [[
<PRE @box00>[text01030]
�܂��͂����Ɍ��������B

���̋��ŁA�P�l�ŃL�����L�����Ǝ��͂����񂵂Ă���B

�ǂ����f�v���ꂽ�킯�ł͂Ȃ������炵���B

�߂��ɖq���g仐��̎p�͌�������Ȃ��B

����͉��ɂƂ��čD�s���������B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0083" mode="on">
�u�������A���̏��A���ɕ|���C�Â������v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0084" mode="on">
�u�悩�낤�B�����̂Ƃ���͌������Ă��Ƃ��悤�v

�Ƃ����킯�Ŏ��͂��x�����A�܂��̌��֋삯������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALC04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALC04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', '@BGM13')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM13', '0', '1000', 'true')
OP_8E()
SetText(
    'text01040',
    '@box00',
    [[
<PRE @box00>[text01040]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0085" mode="on">
�u�܂��A�Ȃ��d�b�ɏo�Ȃ��B���낻��A�邼�v

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0026" mode="on">
�u���A�I�J�����B�w���^�����[�ρx�����Ȃ��Ȃ���������v

�����ڂ��ŉ��ɑi���Ă���B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0086" mode="on">
�u���Ȃ��Ȃ����H�@����ɓ����o�����̂��B����͎��Ƀt�@���^�W�[���ȁv

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0027" mode="on">
�u���Ƃ����݂����c�c�v

�Ȃ�قǁA����ŒT���Ă����̂��B

���ɂǂ��ł��������Ƃ��B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0087" mode="on">
�u������Ȃ��Ȃ���߂�B�܂����Ă�΂����v

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0028" mode="on">
�u����������Ȃ���B�����ĂˁA�w���^�����[�ρx�̓l�b�g�I�[�N�V�����ŁA�P���~�߂��v���~�A���t���Ă�񂾂�H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0088" mode="on">
�u�ȁc�c�Ɂc�c�H�v

���A����Ȓl�����̏����ȃI���`���Ɂc�c�H

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0089" mode="on">
�u�܂���A���������ǂ��ŗ��Ƃ����̂��I�H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01050',
    '@box00',
    [[
<PRE @box00>[text01050]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0029" mode="on">
�u������Ȃ�����T���Ă�񂾂患�c�c�B���ƁA�����Ă��A����Ȃ�����ˁ[�H�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0090" mode="on">
�u�t�n�n�A���̂P���~�A���̉��̌��������ɂ��Ă��v

<voice name="�܂��" class="VID_MAY" src="voice/MAY_0030" mode="on">
�u������A����Ȃ����Ă΁[�B�܂䂵���̖��O��������������v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text01060',
    '@box00',
    [[
<PRE @box00>[text01060]
�Ƃ����킯�ŁA�ڂ��M�̂悤�ɂ��āw���^�����[�ρx��T�����Ƃɂ����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
SetText(
    'text01070',
    '@box00',
    [[
<PRE @box00>[text01070]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0031" mode="on">
�u�g�D�b�g�D���[��@���[�ς��񂤁[�ς���A�o�Ă����Ł[�v

�܂�肪����ȕ��ɌĂт����Ă��邪�A�o�Ă���킯���Ȃ��B

���Ȃ݂Ɂg�g�D�b�g�D���[��h�Ƃ͂܂��̍D���ȃt���[�Y�ŁA�F�X�ȏ�ʂŌ��ɂ���B

�Ӗ��́c�c���������Ƃ͂Ȃ��B

�w���^�����[�ρx�́A�Ȃ��Ȃ�������Ȃ������B

�Ƃ������Ƃ͗��Ƃ����͉̂����ł͂Ȃ��A�J�v�Z���g�C���u���Ă���V�K�̗x���̕��Ȃ̂��낤���B

���邢�́A�����Ă���w���^�����[�ρx���E�����l�����A�v���~�A���i�ɖڂ�����ݎ����A�����\��������B

�����z������Ɖ��͉������ɐg�ウ�邵���Ȃ������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
SetText(
    'text01080',
    '@box00',
    [[
<PRE @box00>[text01080]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0091" mode="on">
�u���̂�A���ɂ��������̂Ȃ�����ȃ��c�߁A�p��m��c�c�I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '896')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '896', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ASA02')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ASA02')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01090',
    '@box00',
    [[
<PRE @box00>[text01090]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0032" mode="on">
�u�I�J�������ˁ[�v

�����A�܂��Ƀc�b�R�~��������Ƃ́B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('INT', '2133')
OP_3A('2133')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
SetText(
    'text01100',
    '@box00',
    [[
<PRE @box00>[text01100]
<voice name="�H�H�H" class="VID_OKA" src="voice/OKA_0092" mode="on">
�u�������������������������\�\�\�\�I�v

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0093" mode="on">
�u�I�H�v

�ȁA�Ȃ񂾁A���̐��́H

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '384')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '384', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01110',
    '@box00',
    [[
<PRE @box00>[text01110]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0033" mode="on">
�u�ߖc�c���ȁH�v

���ʂ���Ȃ��B

���łɉ��Ɏc���Ă���̂́A�i��҂␔�l�̌W���Ȃǐ�����قǂ��B

������ɗ��Ă����A���͂��̂قƂ�ǂ��A���Ă��܂��Ă��āA���Ƃ܂����܂ߔ����قǂ������Ȃ��B

�S�����A���̔ߖ𕷂��Đg�������܂��Ă����B

�s�����ɁA���݂��̊�������킹�Ă���B

�������������A���܂�ɏ�O���킵���ߖ𕷂��āA�S�g�����ї����Ă����B

�܂��Ȃ̂��c�c�H�@�������̔��������ɑ����āA�܂��Ȃɂ��N�����̂��H

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01120',
    '@box00',
    [[
<PRE @box00>[text01120]
�܂�肪�A�M���b�Ɖ��̎�����肵�߂Ă���B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0094" mode="on">
�u�܂��A�����ɂ���v

���͈�x�S�N���Ƒ���ۂނƁA�o������߂Đ��̂������ւƌ��������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2000')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '2000', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '533')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '533', '100', 'null', 'mask02', 'true', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF*')
OP_24('BGBUF*')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG09A.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG09A.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG09A')
OP_CE('SetCharaColor', 'BG09A')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text01130',
    '@box00',
    [[
<PRE @box00>[text01130]
�K�i�̕��ł͂Ȃ��A����ɉ��̕��ւƑ����ʘH�B�d�C�͏�����A���Â��B

������̕����琺�͕��������C�������B

����Ⴍ���A���͂��x�����Ȃ���T�d�ɕ���i�߂�B

�p���Ȃ����Ă����ɁA�g����h���ڂɓ������B

�ʘH�̉��B

�Ȃɂ����A�������ɓ|��Ă���B

�N�����A�������ɓ|��Ă���B

�s�N���Ƃ������Ȃ��B

�����ɂ͌��o�����������B

���ꂪ�Ȃ�Ȃ̂��B

���ꂪ�N�Ȃ̂��B

�����ɗ��������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM23')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM23', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF8')
OP_24('BGBUF8')
OP_8E()
OP_D0('STRING', '�G��')
OP_24('�G��')
OP_8E()
OP_D0('STRING', 'BGBUF8')
OP_D0('INT', '4000')
OP_D0('STRING', 'cg/bg/BG_CHI.jpg')
OP_CE('BgLoad', 'BGBUF8', '4000', 'cg/bg/BG_CHI.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF8')
OP_D0('INT', '533')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF8', '533', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '3200')
OP_D0('STRING', 'cg/ev/EV_C02C.jpg')
OP_CE('BgLoad', 'BGBUF2', '3200', 'cg/ev/EV_C02C.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '3300')
OP_D0('STRING', 'cg/ev/EV_C02B2.png')
OP_CE('BgLoad', 'BGBUF3', '3300', 'cg/ev/EV_C02B2.png')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '96')
OP_D2()
OP_D0('INT', '11')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF3', '0', '0', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF3', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_24('BGBUF7')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF7', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '3210')
OP_D0('STRING', 'cg/ev/EV_C02C.jpg')
OP_CE('BgLoad', 'BGBUF4', '3210', 'cg/ev/EV_C02C.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF4', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4EX')
OP_D0('INT', '3211')
OP_D0('STRING', 'cg/ev/EV_C02C.jpg')
OP_CE('BgLoad', 'BGBUF4EX', '3211', 'cg/ev/EV_C02C.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF4EX')
OP_D0('STRING', 'SEMIHEAVY')
OP_2D('BGBUF4EX', 'SEMIHEAVY')
OP_8E()
OP_D0('STRING', 'BGBUF4EX')
OP_D0('STRING', 'Passive')
OP_23('BGBUF4EX', 'Passive')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_24('BGBUF5')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '3500')
OP_D0('STRING', 'cg/ev/EV_C02B1.png')
OP_CE('BgLoad', 'BGBUF5', '3500', 'cg/ev/EV_C02B1.png')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '0')
OP_D0('INT', '96')
OP_D2()
OP_D0('INT', '11')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF5', '0', '0', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF5', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF6')
OP_24('BGBUF6')
OP_8E()
OP_D0('STRING', 'BGBUF6')
OP_D0('INT', '3600')
OP_D0('STRING', 'cg/ev/EV_C02D.jpg')
OP_CE('BgLoad', 'BGBUF6', '3600', 'cg/ev/EV_C02D.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF6', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '�v���Z�X')
OP_D0('STRING', 'sg00_01_Thd_NEGAPOSI')
OP_CE('CreateProcessSG', '�v���Z�X', 'sg00_01_Thd_NEGAPOSI')
OP_8E()
OP_D0('STRING', 'BGBUF8')
OP_D0('INT', '534')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask01')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', 'BGBUF8', '534', '100', 'null', 'mask01', 'false', 'true')
OP_8E()
OP_D0('STRING', '�v���Z�X')
OP_D0('STRING', 'Start')
OP_23('�v���Z�X', 'Start')
OP_8E()
OP_D0('STRING', 'BGBUF4*')
OP_D0('INT', '4264')
OP_D0('INT', '96')
OP_D2()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'false')
OP_20('BGBUF4*', '4264', '4264', '@', 'DxlAuto', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF4EX')
OP_D0('INT', '4264')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_25('BGBUF4EX', '4264', '1000', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '4264')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_25('BGBUF5', '4264', '0', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_D0('INT', '4264')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'false')
OP_20('BGBUF5', '4264', '0', '@', 'DxlAuto', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '4264')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'true')
OP_20('BGBUF3', '4264', '0', '@', 'DxlAuto', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF8')
OP_24('BGBUF8')
OP_8E()
OP_D0('STRING', '�G��')
OP_24('�G��')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_24('BGBUF7')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF5')
OP_24('BGBUF5')
OP_8E()
OP_D0('STRING', '�v���Z�X')
OP_24('�v���Z�X')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '96')
OP_D2()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '0', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF3', '0', '@', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF3', '0', '@', '@', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF6')
OP_24('BGBUF6')
OP_8E()
OP_D0('STRING', 'EV_C02A')
OP_CE('ChkAchieveEVRead', 'EV_C02A')
OP_8E()
SetText(
    'text01140',
    '@box00',
    [[
<PRE @box00>[text01140]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0095" mode="on">
�u�Ђ��c�c�v

�q���g仐��c�c�B

��͂͂����茩���Ȃ����B

�ԈႢ�Ȃ��B

���P�O���قǑO�ɁA���ɗ���ł����A���̐��ӋC�ȓV�ˏ������B

�N�₩�Ȃقǂ̍g�������܂�̒��ɁA�|��Ă����B

����ł���c�c�B

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0096" mode="on">
�u���A�ȁA�Ȃ�Łc�c�H�v

�C���t���Ή��͐g��k�킹�Ă����B

�ǂ����悤�B���������B�����o�������B

�킴�킴���ɗ����肷��񂶂�Ȃ������B

����́A���炩�Ɉُ킾�B

���ʂ���Ȃ��B

�q���g仐��́A�N���ɎE���ꂽ�悤�ɂ��������Ȃ��B

�N�Ɂ\�\�H

���ɂ́A�l�̎p�͂Ȃ��\�\

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
SetText(
    'text01150',
    '@box00',
    [[
<PRE @box00>[text01150]
<voice name="�i���" class="VID_ETC" src="voice/MCA_0002" mode="on">
�u���A���킠���c�c�I�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'BGBUF4', '5000')
OP_8E()
OP_D0('INT', '32')
OP_39('32')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'BGBUF4', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF4', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF4EX')
OP_24('BGBUF4EX')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF4', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
SetText(
    'text01160',
    '@box00',
    [[
<PRE @box00>[text01160]
�M�N���Ƃ��ĐU��Ԃ����B

�������łȂ��A���l�̒j���������ɂ��Ă��Ă����B

�݂�Ȋ�ʂ𑓔��ɂ��āA�g仐��̎��̂����Ă���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', '@BGM09')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM09', '0', '1000', 'true')
OP_8E()
SetText(
    'text01170',
    '@box00',
    [[
<PRE @box00>[text01170]
<voice name="�i���" class="VID_ETC" src="voice/MCA_0003" mode="on">
�u�x�@���ĂׁI�v

�k���鐺�ŋ��񂾂̂́A�������̉�Ŏi������Ă����j�������B

���̐����؂�ɁA�݂�Ȕߖ��グ�A��Ăɓ����o���Ă����B

������񉴂��ނ�ɑ������B���̏�Ɏc�闝�R�ȂǁA�Ȃɂ��Ȃ������B

�q���g仐��ɓ������A�g�����o�������h�g�|���h�Ƃ�������̕��������Ă����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'GRAOW', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG06A4.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG06A4.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG06A4.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG06A4.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'GRAOW', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG06A4')
OP_CE('SetCharaColor', 'BG06A4')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
SetText(
    'text01180',
    '@box00',
    [[
<PRE @box00>[text01180]
���ɖ߂�ƁA�܂�肪���������Ȋ�ő҂��Ă����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '294')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '294', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_AMC04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_AMC04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01190',
    '@box00',
    [[
<PRE @box00>[text01190]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0034" mode="on">
�u�I�J�����A�ǂ������́c�c�H�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteSt', 'STBUF5', '267', 'true')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALC04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALC04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01200',
    '@box00',
    [[
<PRE @box00>[text01200]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0097" mode="on">
�u�ŁA�o�邼���v

�܂��̎�������āA�ꍏ���������̏ꂩ�痣��邱�Ƃɂ����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2000')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF2', '2000', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '533')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'true')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '533', '100', 'null', 'mask02', 'true', 'true')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF*')
OP_24('BGBUF*')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
SetText(
    'text01210',
    '@box00',
    [[
<PRE @box00>[text01210]
�K�i���삯����Ȃ���A�K���Ő�قǌ����g仐��̈�̂̉f����]������ǂ��������Ƃ����B

�ł��A�_�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '2000')
OP_D0('STRING', 'cg/bg/BG_CHI.jpg')
OP_CE('BgLoad', 'BGBUF2', '2000', 'cg/bg/BG_CHI.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '133')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '133', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '3100')
OP_D0('STRING', 'cg/ev/EV_C02A.jpg')
OP_CE('BgLoad', 'BGBUF1', '3100', 'cg/ev/EV_C02A.jpg')
OP_8E()
OP_D0('STRING', 'EV_C02A')
OP_CE('ChkAchieveEVRead', 'EV_C02A')
OP_8E()
SetText(
    'text01220',
    '@box00',
    [[
<PRE @box00>[text01220]
���̂ƌ������A�ޏ��̐g�̂̉��ɍL�����Ă��������܂�̑N��ȍg���A�ڂɏĂ��t���ė���Ȃ��B

�l�̎��̂Ƃ������̂��A���߂Č����B

�K���A���͂���܂œ��e�̎��ɂ͗�����������Ƃ��Ȃ���������B

�N���̑����ɏo�����Ƃ��Ȃ���������B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#FFFFFF')
OP_D0('INT', '133')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#FFFFFF', '133', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '4000')
OP_D0('STRING', 'cg/bg/BG_WHITE.jpg')
OP_CE('BgLoad', 'BGBUF2', '4000', 'cg/bg/BG_WHITE.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '133')
OP_D0('INT', '1000')
OP_D0('INT', '0')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask06')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawTransitionSG', '��w�i', '133', '1000', '0', '250', 'null', 'mask06', 'false', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '133')
OP_D0('INT', '1000')
OP_D0('INT', '0')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask06')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawTransitionSG', '��w�i', '133', '1000', '0', '250', 'null', 'mask06', 'false', 'true')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#FFFFFF')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#FFFFFF', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG_CHI.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG_CHI.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
SetText(
    'text01230',
    '@box00',
    [[
<PRE @box00>[text01230]
���̂������̂́A���߂ĂŁB

���|�\�\�ƌ������͋C�����������o���āA�]�N���Ɣw�؂�����������������ǁB

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '533', 'null', 'true')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF*')
OP_24('BGBUF*')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG_BLACK.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG_BLACK.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
SetText(
    'text01240',
    '@box00',
    [[
<PRE @box00>[text01240]
���̒��x�̊��z�����A�����Ȃ������B

����ȏ�̊��z�́A�����΂Ȃ������B

���Ɩq���g仐��̊֌W�́A���F���̒��x�̂��̂ł����Ȃ��\�\

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('INT', '533')
OP_3A('533')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG40A.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG40A.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG40A')
OP_CE('SetCharaColor', 'BG40A')
OP_8E()
OP_D0('INT', '1066')
OP_3A('1066')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('STRING', 'SGSE008')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'false')
OP_CE('SePlay', 'SE01', 'SGSE008', '0', '1000', 'false')
OP_8E()
OP_D0('STRING', 'SE01')
OP_CE('WaitPlayHalfSG', 'SE01')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
SetText(
    'text01250',
    '@box00',
    [[
<PRE @box00>[text01250]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0098" mode="on">
�u�͂��A�͂��c�c�v

�����ʂ�܂ŏo�āA����Ɖ��͗����~�܂����B

�S���͂ŊK�i���삯����Ă������Ƃ�����A�����؂�ċꂵ���B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '512')
OP_D0('INT', '0')
OP_91()
OP_CE('PosSt', 'STBUF5', '512', '@')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA03')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA03')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01260',
    '@box00',
    [[
<PRE @box00>[text01260]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0035" mode="on">
�u�˂��˂��A�Ȃɂ��������́[�H�@��F�A�������������ǁc�c�v

�܂��̓P���b�Ƃ��Ă���B

���̌�������Ă��Ȃ����炾�낤�B

����ɂ��Ă�������؂�Ă��Ȃ��Ƃ́B

�������āA�݂��������Ɍ����Ď��͉^���_�o�͂����񂾂�ȁB

<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0099" mode="on">
�u�l���c�c����ł��v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '1800')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '0')
OP_91()
OP_D0('STRING', 'MAY_ALA04')
OP_CE('St', 'STBUF5', '1800', '@', '@', 'MAY_ALA04')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
SetText(
    'text01270',
    '@box00',
    [[
<PRE @box00>[text01270]
<voice name="�܂��" class="VID_MAY" src="voice/MAY_0036" mode="on">
�u���c�c�v

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '267', 'true')
OP_8E()
SetText(
    'text01280',
    '@box00',
    [[
<PRE @box00>[text01280]
���x���A�[�ċz�B

�܂��]���ɂ��̌��̐F�͎c���Ă��邪�B

����ł��A�����ԗ��������Ă����B

�q���g仐��͎E���ꂽ�B

�N���Ɛl���͕�����Ȃ��B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '5000')
OP_CE('CreatePlainSP', 'GRAOW', '5000')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG13A1.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG13A1.jpg')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('DeleteAllSt', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '100')
OP_D0('STRING', 'cg/bg/BG13A1.jpg')
OP_CE('BgLoad', 'BGBUF1', '100', 'cg/bg/BG13A1.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'GRAOW')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'GRAOW', '533', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BG13A1')
OP_CE('SetCharaColor', 'BG13A1')
OP_8E()
SetText(
    'text01290',
    '@box00',
    [[
<PRE @box00>[text01290]
�T�C�����������ŕ������邩��A���������~�}�Ԃ����邾�낤�B

���̌�A�x�@�����������Ă��āA�����͑呛���ɂȂ�B

�ł����͂܂��A�ċx�݂̏H�t������������̐l�������A���̎����ɋC�t���Ă��Ȃ��B

�݂�ȁA�����Ɠ����悤�ɕ����Ă���B

�Ɠd��A�G����A�G�������߂āA�����Ă���B

�����́A�H�t�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('macrosys2_OPEN_PHONE_WINDOW')
OP_8E()
SetText(
    'text01300',
    '@box00',
    [[
<PRE @box00>[text01300]
���́A�Ȃ�ƂȂ��A�|�P�b�g�̒�����P�[�^�C�����o���Ă����B

���ɖړI���������킯����Ȃ������B

���A�������A�q���g仐��̂��Ƃ������Ă��ꂽ�_���ɁA�������������������ׂ�������`���Ă�낤�B�����v�����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_E4()
OP_8E()
OP_CE('macrosys2_SELECT_ADDRESSBOOK')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_D0('STRING', 'PhID_DAR')
OP_B0('$LR_TARGET_PhID')
OP_8E()
OP_CE('macrosys2_SELECT_PhID')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_CE('macrosys2_PHONE_ADRSUBMENU_MAIL')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('INT', '500')
OP_3A('500')
OP_8E()
OP_D0('STRING', 'FM_To_DAR0001_0')
OP_B0('$SW_PHONE_SENDMAILNO')
OP_8E()
OP_D0('STRING', 'NO_TARGET')
OP_B0('$SW_PHONE_MAILCURMNO')
OP_8E()
OP_CE('macrosys2_START_SendMailEdit')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_PhoneSendMail')
OP_8E()
SetText(
    'text01310',
    '@box00',
    [[
<PRE @box00>[text01310]
�s�ސT�ƌ����΁A�s�ސT���B

���͋������Ă����B���Ɍ�������Ă����̂����B

����ȏo���������̖ڂŌ��Ă��܂����ザ��A��ÂȔ��f�Ȃǂł��Ȃ��B

�l�ԂȂ�āA���F����Ȃ��́B

����قǍ����ȑ��݂���Ȃ��B

�����A�������Ă��邳�A���ǂ̂Ƃ���\�\

�w�h���ɂ������q�ꂽ�����琬�藧���B

�q�{�̒��ŕ��藎���鐸�t�̂��Ƃ��^�񂾐��_���h���B

���ꂪ�l�ԂȂ񂾁B

�ȂǂƂ�����҂芴���ɐZ��A�P�[�^�C�ŕ��͂���͂��Ă����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'FM_To_DAR0001')
OP_B0('$LR_TARGET_MAILNO')
OP_8E()
OP_CE('macrosys2_SendMailEdit_NEXT')
OP_8E()
SetText(
    'text01320',
    '@box00',
    [[
<PRE @box00>[text01320]
�w�q���g仐����j�Ɏh���ꂽ�݂������B�j���N���͒m��Ȃ����ǂ��B���o�������B���v���ȁx

�Ɛl���j���ǂ����͕�����Ȃ��B�����Ȃ�ƂȂ��A�����͒j�̕��������I���ȁA�Ƃ����C�����������ŁA���̒P�Ȃ鉯�����B

���łɌ����ƁA�h�E���ǂ������z���B

�e���͂��Ȃ��������A���ꂾ���̌����܂肪�ł��Ă������炻���v���������B

����ŁA���m�Ɂw�E���ꂽ�x�Ə����̂͂�߂��B

�Ȃ��Ȃ̂��A���R�͎����ł��͂����肵�����̂͂Ȃ������B

�����Č����΁A�������Ƃł��ꂪ�g�m��h���Ă��܂������ȋC����������A���낤���B

�ƂĂ����߂����C���ɂȂ肻���������̂��B

�ʂɁA�����E�����킯����Ȃ��̂ɁB����Ȏ����̊�ȐS����Ԃ��l���āA��΂����B

���������A�P�l�̐l�Ԃ̎���ڂ̓�����ɂ��Ă��Ȃ���A�ق�̐�����ɂ́A�΂��Ă�����B

����ȉ��́A�c���ŗ₽���l�ԂȂ̂��낤���B

�����I�ȋ��C�̃}�b�h�T�C�G���e�B�X�g�Ƃ��Ă͂����������B

�e�w���A�P�[�^�C�̑��M�{�^���ɓY����B

���́A

���̎w�ɁA

�y���͂����߂āA

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('STRING', 'PhoneMode_Sending')
OP_B0('$SW_PHONE_MODE')
OP_8E()
SetText(
    'text01330',
    '@box00',
    [[
<PRE @box00>[text01330]
���[���𑗐M�����\�\

���́A����\�\

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SYSTEM_backlog_lock')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SYSTEM_save_lock')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_SYSTEMCHIP_HIDE')
OP_8E()
OP_D0('INT', '4000')
OP_B0('$SW_PHONE_PRI')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('STRING', 'cg/bg/BG13A3.jpg')
OP_CE('BgLoad', 'BGBUF2', '200', 'cg/bg/BG13A3.jpg')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('INT', '266')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE01', '266', '0', 'null')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('INT', '266')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE02', '266', '0', 'null')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '266')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '266', '0', 'null')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '20000')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'imv005')
OP_CE('CreateMovieSG', '���[�r�[', '20000', '0', '0', 'false', 'false', 'true', 'imv005')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[', 'Play')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_Phone_Open')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_CE('MovieWaitSG')
OP_8E()
OP_D0('INT', '4900')
OP_B0('$SW_PHONE_PRI')
OP_8E()
OP_D0('INT', '0')
OP_D0('STRING', 'true')
OP_CE('StDeleteAll', '0', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_24('BGBUF1')
OP_8E()
OP_CE('MovieMain')
OP_8E()
OP_D0('INT', '16')
OP_39('16')
OP_8E()
OP_D0('STRING', '@���[�r�[*')
OP_24('@���[�r�[*')
OP_8E()
OP_D0('STRING', 'false')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '20000')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'imv002')
OP_CE('CreateMovieSG', '���[�r�[', '20000', '0', '0', 'false', 'false', 'true', 'imv002')
OP_8E()
OP_D0('STRING', 'WDCOV')
OP_D0('INT', '19990')
OP_D0('STRING', '#000000')
OP_CE('CreateColorSP', 'WDCOV', '19990', '#000000')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[', 'Play')
OP_8E()
OP_CE('macrosys2_Init_Phone')
OP_8E()
OP_D0('STRING', 'WDCOV')
OP_24('WDCOV')
OP_8E()
OP_CE('MovieWaitSG')
OP_8E()
OP_CE('macrosys2_DELETE_MAIL_SG00_01')
OP_8E()
OP_D0('STRING', '�O�D�T�V�P�O�Q�S')
OP_B0('$DGMP')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_CE('BgCopy', 'BGBUF2', 'BGBUF1', '0')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SYSTEM_backlog_lock')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SYSTEM_save_lock')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_SYSTEMCHIP_HIDE')
OP_8E()
OP_D0('STRING', '@���[�r�[*')
OP_24('@���[�r�[*')
OP_8E()
OP_D0('STRING', 'false')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
SetText(
    'text01340',
    '@box00',
    [[
<PRE @box00>[text01340]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0100" mode="on">
�u�\�\���v

�Ȃ񂾁A���́A���o�́c�c�H

����A����Ȃ��Ƃ����c�c�I

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'EV_Z01A')
OP_CE('ChkAchieveEVRead', 'EV_Z01A')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '3200')
OP_D0('STRING', 'cg/ev/EV_Z01A.jpg')
OP_CE('BgLoad', 'BGBUF2', '3200', 'cg/ev/EV_Z01A.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '210')
OP_D0('INT', '70')
OP_D2()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '210', '210', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '306')
OP_D0('INT', '404')
OP_2C('BGBUF2', '306', '404')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '5000')
OP_D0('INT', '5000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF2', '0', '5000', '5000', 'null', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_D0('INT', '3210')
OP_D0('STRING', 'SEMIHEAVY')
OP_CE('SetShadeSG', 'GRASHADE', '3210', 'SEMIHEAVY')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_D0('STRING', 'Passive')
OP_23('GRASHADE', 'Passive')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '4000')
OP_D0('STRING', 'cg/bg/BG_WHITE.jpg')
OP_CE('BgLoad', 'BGBUF3', '4000', 'cg/bg/BG_WHITE.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('STRING', 'AddRender')
OP_23('BGBUF3', 'AddRender')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '0')
OP_D0('INT', '500')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF3', '0', '500', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_24('BGBUF7')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF7', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF7', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '133')
OP_D0('INT', '100')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask18')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '133', '100', 'null', 'mask18', 'false', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '133')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'Axl2')
OP_D0('STRING', 'false')
OP_20('BGBUF2', '133', '0', '0', 'Axl2', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '133')
OP_D0('INT', '1050')
OP_D0('INT', '1050')
OP_D0('STRING', 'Axl2')
OP_D0('STRING', 'false')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF2', '133', '1050', '1050', 'Axl2', 'false', 'Smoothing')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_D0('INT', '133')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'BGBUF3', '133', 'null', 'true')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_D0('INT', '1066')
OP_D0('STRING', 'null')
OP_D0('STRING', 'false')
OP_CE('FadeDelete', 'GRASHADE', '1066', 'null', 'false')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '1000')
OP_D0('INT', '1000')
OP_D0('STRING', 'Dxl2')
OP_D0('STRING', 'true')
OP_D0('STRING', 'Smoothing')
OP_CE('ZoomSG', 'BGBUF2', '1066', '1000', '1000', 'Dxl2', 'true', 'Smoothing')
OP_8E()
OP_D0('STRING', 'GRASHADE')
OP_24('GRASHADE')
OP_8E()
OP_D0('STRING', 'BGBUF3')
OP_24('BGBUF3')
OP_8E()
OP_D0('STRING', 'BGBUF7')
OP_24('BGBUF7')
OP_8E()
SetText(
    'text01350',
    '@box00',
    [[
<PRE @box00>[text01350]
<voice name="�ϑ��Y" class="VID_OKA" src="voice/OKA_0101" mode="on">
�u�������c�c�v

�ċx�݁B

���߁B

�H�t���B

�w����k���P���́A�����ʂ�B

��������\�\

��u�ɂ��ā\�\

����l�Ƃ����ʍs�l���\�\

���̎��E����\�\

��ĂɁ\�\

���������B

����́A�����H�@���o�ł����Ă���̂��H

������Ȃ��B

�ł��A�������񂾁B

���̏u�Ԃ��A�m���Ɍ����񂾁B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'BGBUF1')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF1', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('INT', '1')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_D0('INT', '0')
OP_CE('PhoneOperation', '0')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '1066')
OP_D0('INT', '1000')
OP_D0('INT', '0')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask02')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawTransitionSG', 'BGBUF2', '1066', '1000', '0', '250', 'null', 'mask02', 'false', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_24('BGBUF2')
OP_8E()
SetText(
    'text01360',
    '@box00',
    [[
<PRE @box00>[text01360]
���͂����A���t���o���A���R�ƂȂ��āA

���l�Ɖ������H�t���ɁA

�����P�l�A

�����s�����Ă��āB

�������A�ӂƌ��グ��΁A

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneOperation', '1')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'GRABGLINK')
OP_D0('INT', '1024')
OP_D0('INT', '1310')
OP_D0('STRING', '#FF00FF')
OP_1B('GRABGLINK', '1024', '1310', '#FF00FF')
OP_8E()
OP_D0('STRING', 'GRABGLINK')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'cg/bg/BG10A2U.jpg')
OP_30('GRABGLINK', '0', '0', 'cg/bg/BG10A2U.jpg')
OP_8E()
OP_D0('STRING', 'GRABGLINK')
OP_D0('INT', '0')
OP_D0('INT', '655')
OP_D0('STRING', 'cg/bg/BG10A2D.jpg')
OP_30('GRABGLINK', '0', '655', 'cg/bg/BG10A2D.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '200')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'GRABGLINK')
OP_CE('CreateTextureEX', 'BGBUF2', '200', '0', '0', 'GRABGLINK')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '732')
OP_D2()
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '0', 'null', 'true')
OP_8E()
OP_D0('STRING', '@BGM25')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'true')
OP_CE('SoundPlay', '@BGM25', '0', '1000', 'true')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '533')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF2', '533', '1000', 'null', 'true')
OP_8E()
SetText(
    'text01370',
    '@box00',
    [[
<PRE @box00>[text01370]
���W�ق̃r���Ɂ\�\

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '2133')
OP_B0('$MTime')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D1('$MTime')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '489')
OP_D2()
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'false')
OP_20('BGBUF2', '$MTime', '@', '0', 'AxlDxl', 'false')
OP_8E()
OP_D1('$MTime')
OP_3A('$MTime')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '489')
OP_D2()
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '0', 'AxlDxl', 'true')
OP_8E()
SetText(
    'text01380',
    '@box00',
    [[
<PRE @box00>[text01380]
�����������������܂ł����A�W�K������Ɂ\�\

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('INT', '2133')
OP_B0('$MTime')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D1('$MTime')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '64')
OP_D2()
OP_D0('STRING', 'AxlDxl')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '$MTime', '@', '0', 'AxlDxl', 'true')
OP_8E()
OP_D1('$MTime')
OP_3A('$MTime')
OP_8E()
OP_D0('STRING', 'BGBUF2')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_91()
OP_D0('INT', '64')
OP_D2()
OP_D0('STRING', 'DxlAuto')
OP_D0('STRING', 'true')
OP_20('BGBUF2', '0', '@', '0', 'DxlAuto', 'true')
OP_8E()
OP_D0('INT', '1')
OP_CE('PhoneAutoOperation', '1')
OP_8E()
SetText(
    'text01390',
    '@box00',
    [[
<PRE @box00>[text01390]
�l�H�q�����A�˂��h�����Ă����B

</PRE>]]
)
OP_CE('SetText')
OP_8E()
OP_CE('TypeBegin')
OP_8E()
OP_D0('INT', '0')
OP_B0('$SF_PhoneSD_Disp')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '10000')
OP_CE('PrintGO', '��w�i', '10000')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_24('BGBUF4')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '400')
OP_D0('STRING', 'cg/bg/BG_WHITE.jpg')
OP_CE('BgLoad', 'BGBUF4', '400', 'cg/bg/BG_WHITE.jpg')
OP_8E()
OP_D0('STRING', 'BGBUF4')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('BGBUF4', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '��w�i')
OP_D0('INT', '1066')
OP_D0('INT', '250')
OP_D0('STRING', 'null')
OP_D0('STRING', 'mask10')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_CE('DrawDeleteSG', '��w�i', '1066', '250', 'null', 'mask10', 'false', 'true')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#FFFFFF')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#FFFFFF', '0', 'null', 'true')
OP_8E()
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'BG_LINK_OFF')
OP_CE('BGsetLink', '0', '0', 'BG_LINK_OFF')
OP_8E()
OP_D0('INT', '266')
OP_39('266')
OP_8E()
OP_D0('STRING', 'BGBUF*')
OP_24('BGBUF*')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '533')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '533', '0', 'null')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '533')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '533', 'null', 'true')
OP_8E()
OP_CE('SetPlayModeNormal')
OP_8E()
OP_D1('#CLEAR_CRS')
OP_D1('#CLEAR_MAY')
OP_C7()
OP_D1('#CLEAR_OKA')
OP_D0('STRING', 'true')
OP_C0()
OP_C7()
OP_98('label.if.311')
OP_C8()
OP_D1('#OPChoice')
OP_D0('STRING', 'demo')
OP_C0()
OP_98('label.if.421')
OP_C8()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '9900')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'op')
OP_CE('CreateMovieSG', '���[�r�[', '9900', '0', '0', 'false', 'false', 'true', 'op')
OP_8E()
OP_D0('STRING', 'op')
OP_B0('#OPChoice')
OP_8E()
OP_C9()
OP_CF('label.if.end42')
label('if.421')
OP_C8()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '9900')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'demo')
OP_CE('CreateMovieSG', '���[�r�[', '9900', '0', '0', 'false', 'false', 'true', 'demo')
OP_8E()
OP_D0('STRING', 'demo')
OP_B0('#OPChoice')
OP_8E()
OP_C9()
label('if.end42')
OP_C9()
OP_CF('label.if.end31')
label('if.311')
OP_C8()
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '9900')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'false')
OP_D0('STRING', 'false')
OP_D0('STRING', 'true')
OP_D0('STRING', 'op')
OP_CE('CreateMovieSG', '���[�r�[', '9900', '0', '0', 'false', 'false', 'true', 'op')
OP_8E()
OP_D0('STRING', 'op')
OP_B0('#OPChoice')
OP_8E()
OP_C9()
label('if.end31')
OP_D0('STRING', '���[�r�[')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('���[�r�[', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('STRING', '���[�r�[')
OP_D0('STRING', 'Play')
OP_23('���[�r�[', 'Play')
OP_8E()
OP_CE('MovieWaitSG')
OP_8E()
OP_D0('STRING', '@���[�r�[*')
OP_24('@���[�r�[*')
OP_8E()
OP_D0('STRING', 'END_SG00')
OP_CE('AchievementOn', 'END_SG00')
OP_8E()
OP_D0('STRING', 'false')
OP_B0('$SYSTEM_menu_lock')
OP_8E()
OP_CE('TextBoxDelete')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE01', '1066', '0', 'null')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE02', '1066', '0', 'null')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '1066')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '1066', '0', 'null')
OP_8E()
OP_D0('INT', '9000')
OP_D0('STRING', '#000000')
OP_D0('INT', '2133')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('ColorOut', '9000', '#000000', '2133', 'null', 'true')
OP_8E()
OP_D0('STRING', 'SE01')
OP_D0('INT', '266')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE01', '266', '0', 'null')
OP_8E()
OP_D0('STRING', 'SE02')
OP_D0('INT', '266')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('SE02', '266', '0', 'null')
OP_8E()
OP_D0('STRING', '@BGM*')
OP_D0('INT', '266')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_43('@BGM*', '266', '0', 'null')
OP_8E()
OP_D0('STRING', 'OnColor*')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_CE('FadeDelete', 'OnColor*', '0', 'null', 'true')
OP_8E()
OP_C9()
OP_D5('scene.sg00_01.nss')

BeginFunction('sg00_01_Thd_IM_MAY_01')
OP_97('function.sg00_01_Thd_IM_MAY_01')
OP_C8()
OP_D0('INT', '4000')
OP_39('4000')
OP_8E()
OP_D0('STRING', 'STBUF8')
OP_D0('INT', '267')
OP_D0('STRING', 'false')
OP_CE('DeleteSt', 'STBUF8', '267', 'false')
OP_8E()
OP_D0('STRING', 'STBUF5')
OP_D0('INT', '267')
OP_D0('STRING', 'true')
OP_CE('FadeSt', 'STBUF5', '267', 'true')
OP_8E()
OP_C9()
OP_D7()

BeginFunction('sg00_01_Thd_NEGAPOSI')
OP_97('function.sg00_01_Thd_NEGAPOSI')
OP_C8()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '0', 'null', 'true')
OP_8E()
OP_D0('INT', '1266')
OP_39('1266')
OP_8E()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('INT', '100')
OP_39('100')
OP_8E()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '0', 'null', 'true')
OP_8E()
OP_D0('INT', '100')
OP_39('100')
OP_8E()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('INT', '100')
OP_39('100')
OP_8E()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '0', 'null', 'true')
OP_8E()
OP_D0('INT', '666')
OP_39('666')
OP_8E()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '1000')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '1000', 'null', 'true')
OP_8E()
OP_D0('INT', '100')
OP_39('100')
OP_8E()
OP_D0('STRING', '@BGBUF6')
OP_D0('INT', '0')
OP_D0('INT', '0')
OP_D0('STRING', 'null')
OP_D0('STRING', 'true')
OP_25('@BGBUF6', '0', '0', 'null', 'true')
OP_8E()
OP_C9()
OP_D7()
UpdateFunctionMap()
