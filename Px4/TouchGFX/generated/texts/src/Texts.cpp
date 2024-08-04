/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) //Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

//Default typed text database
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x50, 0x61, 0x73, 0x73, 0x6f, 0x20, 0x61, 0x20, 0x70, 0x61, 0x73, 0x73, 0x6f, 0x20, 0x72, 0x65, 0x73, 0x65, 0x74, 0x20, 0x64, 0x65, 0x20, 0x66, 0xe1, 0x62, 0x72, 0x69, 0x63, 0x61, 0x3a, 0xa, 0xa, 0x31, 0x29, 0x20, 0x41, 0x70, 0x65, 0x72, 0x74, 0x65, 0x20, 0x65, 0x20, 0x73, 0x65, 0x67, 0x75, 0x72, 0x65, 0x20, 0x6f, 0x20, 0x50, 0x20, 0x70, 0x6f, 0x72, 0x20, 0x73, 0x65, 0x67, 0x2e, 0xa, 0x32, 0x29, 0x20, 0x51, 0x75, 0x61, 0x6e, 0x64, 0x6f, 0x20, 0x61, 0x70, 0x61, 0x72, 0x65, 0x63, 0x65, 0x72, 0x20, 0x72, 0x50, 0x20, 0x61, 0x70, 0x65, 0x72, 0x74, 0x65, 0x20, 0x50, 0x20, 0x75, 0x6d, 0x61, 0x20, 0x76, 0x65, 0x7a, 0xa, 0x33, 0x29, 0x20, 0x49, 0x6e, 0x73, 0x69, 0x72, 0x61, 0x20, 0x61, 0x20, 0x73, 0x65, 0x6e, 0x68, 0x61, 0x20, 0x2d, 0x34, 0x38, 0x20, 0x65, 0x20, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x65, 0x20, 0x63, 0x6f, 0x6d, 0x20, 0x50, 0xa, 0x34, 0x29, 0x20, 0x45, 0x73, 0x70, 0x65, 0x72, 0x65, 0x20, 0x6f, 0x20, 0x58, 0x33, 0x34, 0x20, 0x72, 0x65, 0x69, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x72, 0xa, 0x35, 0x29, 0x20, 0x41, 0x70, 0x65, 0x72, 0x74, 0x65, 0x20, 0x6f, 0x20, 0x62, 0x6f, 0x74, 0xe3, 0x6f, 0x20, 0x61, 0x62, 0x61, 0x69, 0x78, 0x6f, 0x0, // @0 "Passo a passo reset de f?brica:??1) Aperte e segure o P por seg.?2) Quando aparecer rP aperte P uma vez?3) Insira a senha -48 e confirme com P?4) Espere o X34 reiniciar?5) Aperte o bot?o abaixo"
    0x4c, 0x6f, 0x67, 0x69, 0x63, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x32, 0x20, 0x2d, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0xa, 0x30, 0x20, 0x3d, 0x20, 0x64, 0x65, 0x73, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x64, 0x6f, 0xa, 0x31, 0x20, 0x3d, 0x20, 0x22, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x22, 0x20, 0x3d, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x61, 0x74, 0x6f, 0x20, 0x3e, 0x20, 0x61, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0xa, 0x2d, 0x31, 0x20, 0x3d, 0x20, 0x22, 0x69, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x69, 0x64, 0x6f, 0x22, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x65, 0x72, 0x74, 0x6f, 0x20, 0x3e, 0x20, 0x61, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x0, // @194 "Logica entrada Digital 2 - Alarme Externo?0 = desabilitado?1 = "normal" = contato > alarme?-1 = "invertido" = aberto > alarme"
    0x4c, 0x6f, 0x67, 0x69, 0x63, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x31, 0xa, 0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x6f, 0x20, 0x73, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x20, 0x64, 0x65, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0x20, 0x28, 0x31, 0x20, 0x3d, 0x20, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x20, 0x2f, 0x20, 0x2d, 0x31, 0x20, 0x3d, 0x20, 0x69, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x69, 0x64, 0x6f, 0x29, 0x0, // @320 "Logica entrada Digital 1?Status do sensor de porta (1 = normal / -1 = invertido)"
    0x50, 0x4f, 0x52, 0x43, 0x45, 0x4e, 0x54, 0x41, 0x47, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0xa, 0x46, 0x31, 0x20, 0x3e, 0x20, 0x46, 0x32, 0xa, 0x28, 0x45, 0x78, 0x2e, 0x20, 0x36, 0x20, 0x3d, 0x20, 0x36, 0x30, 0x25, 0x20, 0x46, 0x31, 0x20, 0x2f, 0x20, 0x34, 0x30, 0x25, 0x20, 0x46, 0x32, 0x29, 0x0, // @401 "PORCENTAG RESFRIAR TEMP - HARD?F1 > F2?(Ex. 6 = 60% F1 / 40% F2)"
    0x4c, 0x6f, 0x67, 0x69, 0x63, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x32, 0x20, 0x2d, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0xa, 0x30, 0x20, 0x3d, 0x20, 0x64, 0x65, 0x73, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x64, 0x6f, 0x0, // @466 "Logica entrada Digital 2 - Alarme Externo?0 = desabilitado"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x74, 0x6f, 0x72, 0x6e, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0xa, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x29, 0x20, 0x2d, 0x20, 0x6d, 0xe1, 0x78, 0x20, 0x33, 0x30, 0x20, 0x6d, 0x69, 0x6e, 0x2e, 0x0, // @525 "Tempo de Retorno do Alarme?Externo (min.) - m?x 30 min."
    0x52, 0x65, 0x74, 0x61, 0x72, 0x64, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x76, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x61, 0x70, 0xf3, 0x73, 0xa, 0x74, 0xe9, 0x6d, 0x69, 0x6e, 0x69, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x73, 0x65, 0x67, 0x29, 0x0, // @581 "Retardo do ventilador ap?s?t?minio do degelo (min.seg)"
    0x45, 0x6e, 0x74, 0x72, 0x61, 0x64, 0x61, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x34, 0x20, 0x28, 0x4f, 0x4e, 0x2f, 0x4f, 0x46, 0x46, 0x29, 0xa, 0x54, 0x65, 0x63, 0x6c, 0x61, 0x20, 0x52, 0x65, 0x64, 0x69, 0x61, 0x6c, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x0, // @636 "Entrada Digital 4 (ON/OFF)?Tecla Redial de Receita"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x32, 0x20, 0x2f, 0x20, 0x53, 0x4f, 0x46, 0x54, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @687 "SP RESFRIAR SONDA - HARD F2 / SOFT?(SONDA ESPETO)"
    0x56, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x6c, 0x69, 0x67, 0x61, 0x64, 0x6f, 0x20, 0x6e, 0x6f, 0x20, 0x44, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x3f, 0xa, 0x28, 0x30, 0x20, 0x3d, 0x20, 0x4e, 0xe3, 0x6f, 0x20, 0x2f, 0x20, 0x31, 0x20, 0x3d, 0x20, 0x53, 0x69, 0x6d, 0x29, 0x0, // @737 "Ventilador ligado no Degelo ??(0 = N?o / 1 = Sim)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x32, 0x20, 0x2f, 0x20, 0x53, 0x4f, 0x46, 0x54, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @787 "SP RESFRIAR - HARD F2 / SOFT?(SONDA AMBIENTE)"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x53, 0x75, 0x70, 0x65, 0x72, 0x69, 0x6f, 0x72, 0xa, 0x62, 0x6c, 0x6f, 0x71, 0x75, 0x65, 0x69, 0x6f, 0x20, 0x76, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @833 "Temperatura Superior?bloqueio ventilador (?C)"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x65, 0x76, 0x61, 0x70, 0x6f, 0x72, 0x61, 0x64, 0x6f, 0x72, 0xa, 0x68, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x20, 0x64, 0x65, 0x20, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @879 "Temperatura evaporador?habilitar de gelo (?C)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x2d, 0x48, 0x41, 0x4e, 0x44, 0x20, 0x46, 0x31, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @925 "SP RESFRIAR SONDA -HAND F1?(SONDA ESPETO)"
    0x49, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x20, 0x75, 0x6c, 0x74, 0x69, 0x6d, 0x6f, 0x20, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x6f, 0xa, 0x61, 0x75, 0x74, 0x6f, 0x6d, 0x61, 0x74, 0x69, 0x63, 0x61, 0x6d, 0x65, 0x6e, 0x74, 0x65, 0x3f, 0x0, // @967 "Inicia ultimo processo?automaticamente?"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x65, 0x76, 0x61, 0x70, 0x6f, 0x72, 0x61, 0x64, 0x6f, 0x72, 0xa, 0x66, 0x69, 0x6d, 0x20, 0x64, 0x65, 0x20, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @1007 "Temperatura evaporador?fim de gelo (?C)"
    0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x61, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0xa, 0x70, 0x61, 0x72, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x72, 0x20, 0x6e, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x29, 0x0, // @1047 "Status da porta?para entrar no degelo)"
    0x50, 0x4f, 0x52, 0x43, 0x45, 0x4e, 0x54, 0x41, 0x47, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0xa, 0x46, 0x31, 0x20, 0x3e, 0x20, 0x46, 0x32, 0x0, // @1086 "PORCENTAG RESFRIAR TEMP - HARD?F1 > F2"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x31, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1125 "SP RESFRIAR - HARD F1?(SONDA AMBIENTE)"
    0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x61, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0xa, 0x70, 0x61, 0x72, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x72, 0x20, 0x6e, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x0, // @1164 "Status da porta?para entrar no degelo"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1202 "SP CONGELAR SONDA?(SONDA AMBIENTE)"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1237 "SP CONGELAR TEMPO?(SONDA AMBIENTE)"
    0x44, 0x49, 0x46, 0x45, 0x52, 0x45, 0x4e, 0x43, 0x49, 0x41, 0x4c, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x2f, 0x53, 0x4f, 0x46, 0x54, 0x0, // @1272 "DIFERENCIAL RESFRIAR - HARD/SOFT"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @1305 "SP CONGELAR SONDA?(SONDA ESPETO)"
    0x44, 0x45, 0x53, 0x45, 0x4a, 0x41, 0x20, 0x43, 0x41, 0x4e, 0x43, 0x45, 0x4c, 0x41, 0x52, 0xa, 0x41, 0x20, 0x48, 0x49, 0x47, 0x49, 0x45, 0x4e, 0x49, 0x5a, 0x41, 0xc7, 0xc3, 0x4f, 0x3f, 0x0, // @1338 "DESEJA CANCELAR?A HIGIENIZA??O?"
    0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x61, 0x75, 0x74, 0x6f, 0x6d, 0x2e, 0xa, 0x61, 0x70, 0xf3, 0x73, 0x20, 0x72, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x3a, 0x0, // @1370 "Conservar autom.?ap?s receita:"
    0x52, 0x65, 0x74, 0x61, 0x72, 0x64, 0x6f, 0x20, 0x73, 0x61, 0xed, 0x64, 0x61, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x65, 0xa, 0x28, 0x6d, 0x6d, 0x2e, 0x73, 0x73, 0x29, 0x0, // @1401 "Retardo sa?da controle?(mm.ss)"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x67, 0x6f, 0x74, 0x65, 0x6a, 0x61, 0x6d, 0x65, 0x6e, 0x74, 0x6f, 0xa, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x73, 0x65, 0x64, 0x29, 0x0, // @1432 "Tempo de gotejamento?(min.sed)"
    0x44, 0x69, 0x66, 0x2e, 0x20, 0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x28, 0x43, 0x6f, 0x6e, 0x67, 0x65, 0x6c, 0x61, 0x72, 0x29, 0x0, // @1463 "Dif. Conservar (Congelar)"
    0x45, 0x64, 0x69, 0xe7, 0xe3, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x20, 0x2, 0x0, // @1489 "Edi??o de Receita <>"
    0x44, 0x69, 0x66, 0x2e, 0x20, 0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x28, 0x52, 0x65, 0x73, 0x66, 0x72, 0x69, 0x61, 0x72, 0x29, 0x0, // @1509 "Dif. Conservar (Resfriar)"
    0x44, 0x75, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x29, 0x0, // @1535 "Dura??o do degelo (min.)"
    0x44, 0x45, 0x53, 0x45, 0x4a, 0x41, 0x20, 0x53, 0x41, 0x49, 0x52, 0xa, 0x44, 0x4f, 0x20, 0x50, 0x52, 0x4f, 0x43, 0x45, 0x53, 0x53, 0x4f, 0x3f, 0x0, // @1560 "DESEJA SAIR?DO PROCESSO?"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0xc7, 0xc3, 0x4f, 0x20, 0x28, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2e, 0x29, 0x0, // @1585 "SP CONSERVA??O (Config.)"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x72, 0x65, 0x63, 0x69, 0x74, 0x61, 0x20, 0x65, 0x6d, 0x20, 0x5a, 0x45, 0x52, 0x4f, 0x21, 0x0, // @1610 "Tempo de recita em ZERO!"
    0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0xe7, 0xe3, 0x6f, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x0, // @1635 "Descri??o Alarme Externo"
    0x41, 0x42, 0x52, 0x49, 0x52, 0x20, 0x50, 0x4f, 0x52, 0x54, 0x41, 0xa, 0x50, 0x41, 0x52, 0x41, 0x20, 0x43, 0x4f, 0x4d, 0x45, 0xc7, 0x41, 0x52, 0x0, // @1660 "ABRIR PORTA?PARA COME?AR"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0xc7, 0xc3, 0x4f, 0x20, 0x28, 0x52, 0x65, 0x73, 0x66, 0x72, 0x2e, 0x29, 0x0, // @1685 "SP CONSERVA??O (Resfr.)"
    0x44, 0x45, 0x53, 0x45, 0x4a, 0x41, 0x20, 0x53, 0x41, 0x49, 0x52, 0xa, 0x44, 0x4f, 0x20, 0x44, 0x45, 0x47, 0x45, 0x4c, 0x4f, 0x3f, 0x0, // @1709 "DESEJA SAIR?DO DEGELO?"
    0x43, 0x4f, 0x4e, 0x54, 0x52, 0x41, 0x53, 0x45, 0x4e, 0x41, 0x20, 0x49, 0x4e, 0x43, 0x4f, 0x52, 0x52, 0x45, 0x43, 0x54, 0x41, 0x0, // @1732 "CONTRASENA INCORRECTA"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x0, // @1754 "ABCDEFGHIJKLMNOPQRST"
    0x4d, 0x41, 0x55, 0x56, 0x41, 0x49, 0x53, 0x20, 0x4d, 0x4f, 0x54, 0x20, 0x44, 0x45, 0x20, 0x50, 0x41, 0x53, 0x53, 0x45, 0x0, // @1775 "MAUVAIS MOT DE PASSE"
    0x44, 0x49, 0x46, 0x45, 0x52, 0x45, 0x4e, 0x43, 0x49, 0x41, 0x4c, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x0, // @1796 "DIFERENCIAL CONGELAR"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x33, 0x0, // @1817 "Calibra??o Sonda 3"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x32, 0x0, // @1836 "Calibra??o Sonda 2"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x31, 0x0, // @1855 "Calibra??o Sonda 1"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0x20, 0x45, 0x56, 0x41, 0x50, 0x4f, 0x52, 0x41, 0x44, 0x4f, 0x52, 0x0, // @1874 "TEMP. EVAPORADOR"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x44, 0x45, 0x43, 0x4f, 0x52, 0x52, 0x49, 0x44, 0x4f, 0x0, // @1891 "TEMPO?DECORRIDO"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0x20, 0x44, 0x45, 0x43, 0x4f, 0x52, 0x52, 0x49, 0x44, 0x4f, 0x0, // @1907 "TEMPO DECORRIDO"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x39, 0x2d, 0x52, 0x31, 0x32, 0x0, // @1923 "RECEITAS R9-R12"
    0x4c, 0x49, 0x4d, 0x49, 0x54, 0x49, 0x20, 0x53, 0x55, 0x50, 0x45, 0x52, 0x41, 0x54, 0x49, 0x0, // @1939 "LIMITI SUPERATI"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x0, // @1955 "ABCDEFGHIIJKLMN"
    0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44, 0x20, 0x45, 0x52, 0x52, 0x41, 0x54, 0x41, 0x0, // @1971 "PASSWORD ERRATA"
    0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x21, 0x0, // @1987 "Alarme Externo!"
    0x53, 0x65, 0x6e, 0x68, 0x61, 0x20, 0x64, 0x65, 0x20, 0x61, 0x63, 0x65, 0x73, 0x73, 0x6f, 0x0, // @2003 "Senha de acesso"
    0x49, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x72, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x0, // @2019 "Iniciar Receita"
    0x48, 0x4f, 0x52, 0x53, 0x20, 0x44, 0x45, 0x20, 0x50, 0x4f, 0x52, 0x54, 0xc9, 0x45, 0x0, // @2035 "HORS DE PORT?E"
    0x46, 0x55, 0x45, 0x52, 0x41, 0x20, 0x44, 0x45, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x4f, 0x0, // @2050 "FUERA DE RANGO"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x0, // @2065 "ABCDEFGHIJKLMN"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x31, 0x2d, 0x52, 0x34, 0x0, // @2080 "RECEITAS R1-R4"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x45, 0x53, 0x54, 0x49, 0x4d, 0x41, 0x44, 0x4f, 0x0, // @2095 "TEMPO?ESTIMADO"
    0x54, 0x69, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x0, // @2110 "Tipo de degelo"
    0x57, 0x52, 0x4f, 0x4e, 0x47, 0x20, 0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44, 0x0, // @2125 "WRONG PASSWORD"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x35, 0x2d, 0x52, 0x38, 0x0, // @2140 "RECEITAS R5-R8"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0xa, 0x50, 0x52, 0x4f, 0x44, 0x55, 0x54, 0x4f, 0x0, // @2155 "TEMP.?PRODUTO"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x43, 0x4f, 0x4e, 0x46, 0x49, 0x47, 0x2e, 0x0, // @2169 "TEMPO?CONFIG."
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0xa, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x4e, 0x41, 0x0, // @2183 "TEMP.?INTERNA"
    0x53, 0x6f, 0x6d, 0x20, 0x64, 0x6f, 0x20, 0x42, 0x75, 0x7a, 0x7a, 0x65, 0x72, 0x0, // @2197 "Som do Buzzer"
    0x49, 0x6e, 0x73, 0x65, 0x72, 0x69, 0x72, 0x20, 0x53, 0x65, 0x6e, 0x68, 0x61, 0x0, // @2211 "Inserir Senha"
    0x41, 0x42, 0x52, 0x49, 0x52, 0x20, 0x50, 0x4f, 0x52, 0x54, 0x41, 0x20, 0x21, 0x0, // @2225 "ABRIR PORTA !"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x20, 0x46, 0xe1, 0x62, 0x72, 0x69, 0x63, 0x61, 0x0, // @2239 "Reset F?brica"
    0x48, 0x49, 0x47, 0x49, 0x45, 0x4e, 0x49, 0x5a, 0x41, 0xc7, 0xc3, 0x4f, 0x0, // @2253 "HIGIENIZA??O"
    0x44, 0x65, 0x73, 0x61, 0x62, 0x6c, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x0, // @2266 "Desablilitar"
    0x4f, 0x55, 0x54, 0x20, 0x4f, 0x46, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0, // @2279 "OUT OF RANGE"
    0x46, 0x69, 0x6e, 0x61, 0x6c, 0x69, 0x7a, 0x61, 0x64, 0x6f, 0x21, 0x0, // @2292 "Finalizado!"
    0x4d, 0x6f, 0x64, 0x6f, 0x3a, 0xa, 0x66, 0x75, 0x6e, 0x63, 0x2e, 0x0, // @2304 "Modo:?func."
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x0, // @2316 "Temperatura"
    0x4d, 0x6f, 0x64, 0x6f, 0xa, 0x66, 0x69, 0x6e, 0x61, 0x6c, 0x2e, 0x0, // @2328 "Modo?final."
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0xa, 0x5a, 0x65, 0x72, 0x6f, 0x21, 0x0, // @2340 "Tempo?Zero!"
    0x44, 0x65, 0x73, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x0, // @2352 "Desabilitar"
    0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0x52, 0x0, // @2364 "CONSERVAR"
    0x43, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x61, 0x72, 0x0, // @2374 "Confirmar"
    0x4e, 0x65, 0x77, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0, // @2384 "New Text"
    0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x0, // @2393 "RESFRIAR"
    0x49, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x65, 0x72, 0x0, // @2402 "Inverter"
    0x49, 0x4e, 0x44, 0x49, 0x45, 0x54, 0x52, 0x4f, 0x0, // @2411 "INDIETRO"
    0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c, 0x61, 0x72, 0x0, // @2420 "Cancelar"
    0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x3a, 0x0, // @2429 "Receita:"
    0x43, 0x41, 0x4e, 0x43, 0x45, 0x4c, 0x41, 0x52, 0x0, // @2438 "CANCELAR"
    0x2, 0x2e, 0x0, // @2447 "<>."
    0x45, 0x6e, 0x74, 0x65, 0x72, 0xa, 0xa, 0x0, // @2450 "Enter??"
    0x38, 0x38, 0x38, 0x38, 0x2e, 0x38, 0x0, // @2458 "8888.8"
    0x38, 0x38, 0x38, 0x2e, 0x38, 0x38, 0x0, // @2465 "888.88"
    0x4e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x0, // @2472 "Normal"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0xa, 0x0, // @2479 "Enter?"
    0x32, 0x30, 0x30, 0x30, 0x2e, 0x30, 0x0, // @2486 "2000.0"
    0x53, 0x41, 0x4c, 0x56, 0x41, 0x52, 0x0, // @2493 "SALVAR"
    0x44, 0x45, 0x47, 0x45, 0x4c, 0x4f, 0x0, // @2500 "DEGELO"
    0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c, 0x0, // @2507 "Cancel"
    0x44, 0x65, 0x6c, 0xa, 0xa, 0x0, // @2514 "Del??"
    0x43, 0x70, 0x61, 0x73, 0xa, 0x0, // @2520 "Cpas?"
    0x43, 0x61, 0x70, 0x73, 0xa, 0x0, // @2526 "Caps?"
    0x38, 0x38, 0x38, 0x38, 0x38, 0x0, // @2532 "88888"
    0x43, 0x4c, 0x45, 0x41, 0x52, 0x0, // @2538 "CLEAR"
    0x45, 0x4e, 0x54, 0x45, 0x52, 0x0, // @2544 "ENTER"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x0, // @2550 "Reset"
    0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x0, // @2556 "*****"
    0x41, 0x54, 0x52, 0xc1, 0x53, 0x0, // @2562 "ATR?S"
    0x4e, 0x6f, 0x6d, 0x65, 0x3a, 0x0, // @2568 "Nome:"
    0x4d, 0x69, 0x6e, 0x2e, 0x0, // @2574 "Min."
    0x42, 0x41, 0x43, 0x4b, 0x0, // @2579 "BACK"
    0x43, 0x6f, 0x65, 0x6c, 0x0, // @2584 "Coel"
    0x31, 0x32, 0x33, 0xa, 0x0, // @2589 "123?"
    0x3f, 0x31, 0x32, 0x33, 0x0, // @2594 "?123"
    0x44, 0x65, 0x6c, 0xa, 0x0, // @2599 "Del?"
    0x45, 0x73, 0x63, 0xa, 0x0, // @2604 "Esc?"
    0x2b, 0x2f, 0x2d, 0x0, // @2609 "+/-"
    0x45, 0x53, 0x43, 0x0, // @2613 "ESC"
    0x6d, 0x69, 0x6e, 0x0, // @2617 "min"
    0x41, 0x42, 0x43, 0x0, // @2621 "ABC"
    0x44, 0x4f, 0x53, 0x0, // @2625 "DOS"
    0x53, 0x49, 0x4d, 0x0, // @2629 "SIM"
    0x4e, 0xc3, 0x4f, 0x0, // @2633 "N?O"
    0x4d, 0x61, 0x78, 0x0, // @2637 "Max"
    0x4d, 0x69, 0x6e, 0x0, // @2641 "Min"
    0xb0, 0x43, 0x0, // @2645 "?C"
    0x2d, 0x2d, 0x0, // @2648 "--"
    0x30, 0x30, 0x0, // @2651 "00"
    0x4f, 0x6b, 0x0, // @2654 "Ok"
    0x48, 0x0, // @2657 "H"
    0x27, 0x0, // @2659 "'"
    0x22, 0x0, // @2661 """
    0x28, 0x0, // @2663 "("
    0x2b, 0x0, // @2665 "+"
    0x5f, 0x0, // @2667 "_"
    0x26, 0x0, // @2669 "&"
    0x25, 0x0, // @2671 "%"
    0x24, 0x0, // @2673 "$"
    0x23, 0x0, // @2675 "#"
    0x40, 0x0, // @2677 "@"
    0x39, 0x0, // @2679 "9"
    0x37, 0x0, // @2681 "7"
    0x36, 0x0, // @2683 "6"
    0x35, 0x0, // @2685 "5"
    0x20, 0x0, // @2687 " "
    0x3b, 0x0, // @2689 ";"
    0x2c, 0x0, // @2691 ","
    0x73, 0x0, // @2693 "s"
    0x6d, 0x0, // @2695 "m"
    0x62, 0x0, // @2697 "b"
    0x42, 0x0, // @2699 "B"
    0x76, 0x0, // @2701 "v"
    0x56, 0x0, // @2703 "V"
    0x63, 0x0, // @2705 "c"
    0x58, 0x0, // @2707 "X"
    0x7a, 0x0, // @2709 "z"
    0x5a, 0x0, // @2711 "Z"
    0x4c, 0x0, // @2713 "L"
    0x6a, 0x0, // @2715 "j"
    0x4a, 0x0, // @2717 "J"
    0x68, 0x0, // @2719 "h"
    0x67, 0x0, // @2721 "g"
    0x47, 0x0, // @2723 "G"
    0x66, 0x0, // @2725 "f"
    0x46, 0x0, // @2727 "F"
    0x64, 0x0, // @2729 "d"
    0x2f, 0x0, // @2731 "/"
    0x70, 0x0, // @2733 "p"
    0x50, 0x0, // @2735 "P"
    0x69, 0x0, // @2737 "i"
    0x75, 0x0, // @2739 "u"
    0x55, 0x0, // @2741 "U"
    0x79, 0x0, // @2743 "y"
    0x59, 0x0, // @2745 "Y"
    0x77, 0x0, // @2747 "w"
    0x71, 0x0, // @2749 "q"
    0x57, 0x0, // @2751 "W"
    0x51, 0x0 // @2753 "Q"
};
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesIt[] TEXT_LOCATION_FLASH_ATTRIBUTE;
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesEs[] TEXT_LOCATION_FLASH_ATTRIBUTE;
TEXT_LOCATION_FLASH_PRAGMA
KEEP extern uint32_t const indicesFr[] TEXT_LOCATION_FLASH_ATTRIBUTE;

//array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[4] = { 0 };

//Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb,
    indicesIt,
    indicesEs,
    indicesFr
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 4)
    {
        if (languagesArray[id] != 0)
        {
            //dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            //compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
