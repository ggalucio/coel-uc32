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
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x65, 0x76, 0x61, 0x70, 0x6f, 0x72, 0x61, 0x64, 0x6f, 0x72, 0xa, 0x68, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x20, 0x64, 0x65, 0x20, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @833 "Temperatura evaporador?habilitar de gelo (?C)"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x53, 0x75, 0x70, 0x65, 0x72, 0x69, 0x6f, 0x72, 0xa, 0x62, 0x6c, 0x6f, 0x71, 0x75, 0x65, 0x69, 0x6f, 0x20, 0x76, 0x65, 0x6e, 0x74, 0x69, 0x6c, 0x61, 0x64, 0x6f, 0x72, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @879 "Temperatura Superior?bloqueio ventilador (?C)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x2d, 0x48, 0x41, 0x4e, 0x44, 0x20, 0x46, 0x31, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @925 "SP RESFRIAR SONDA -HAND F1?(SONDA ESPETO)"
    0x49, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x20, 0x75, 0x6c, 0x74, 0x69, 0x6d, 0x6f, 0x20, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x6f, 0xa, 0x61, 0x75, 0x74, 0x6f, 0x6d, 0x61, 0x74, 0x69, 0x63, 0x61, 0x6d, 0x65, 0x6e, 0x74, 0x65, 0x3f, 0x0, // @967 "Inicia ultimo processo?automaticamente?"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x20, 0x65, 0x76, 0x61, 0x70, 0x6f, 0x72, 0x61, 0x64, 0x6f, 0x72, 0xa, 0x66, 0x69, 0x6d, 0x20, 0x64, 0x65, 0x20, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0xb0, 0x43, 0x29, 0x0, // @1007 "Temperatura evaporador?fim de gelo (?C)"
    0x53, 0x50, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x46, 0x31, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1047 "SP RESFRIAR - HARD F1?(SONDA AMBIENTE)"
    0x50, 0x4f, 0x52, 0x43, 0x45, 0x4e, 0x54, 0x41, 0x47, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0xa, 0x46, 0x31, 0x20, 0x3e, 0x20, 0x46, 0x32, 0x0, // @1086 "PORCENTAG RESFRIAR TEMP - HARD?F1 > F2"
    0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x61, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0xa, 0x70, 0x61, 0x72, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x72, 0x20, 0x6e, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x29, 0x0, // @1125 "Status da porta?para entrar no degelo)"
    0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x20, 0x64, 0x61, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x61, 0xa, 0x70, 0x61, 0x72, 0x61, 0x20, 0x65, 0x6e, 0x74, 0x72, 0x61, 0x72, 0x20, 0x6e, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x0, // @1164 "Status da porta?para entrar no degelo"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1202 "SP CONGELAR SONDA?(SONDA AMBIENTE)"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x41, 0x4d, 0x42, 0x49, 0x45, 0x4e, 0x54, 0x45, 0x29, 0x0, // @1237 "SP CONGELAR TEMPO?(SONDA AMBIENTE)"
    0x44, 0x49, 0x46, 0x45, 0x52, 0x45, 0x4e, 0x43, 0x49, 0x41, 0x4c, 0x20, 0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x20, 0x2d, 0x20, 0x48, 0x41, 0x52, 0x44, 0x2f, 0x53, 0x4f, 0x46, 0x54, 0x0, // @1272 "DIFERENCIAL RESFRIAR - HARD/SOFT"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x20, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0xa, 0x28, 0x53, 0x4f, 0x4e, 0x44, 0x41, 0x20, 0x45, 0x53, 0x50, 0x45, 0x54, 0x4f, 0x29, 0x0, // @1305 "SP CONGELAR SONDA?(SONDA ESPETO)"
    0x44, 0x45, 0x53, 0x45, 0x4a, 0x41, 0x20, 0x43, 0x41, 0x4e, 0x43, 0x45, 0x4c, 0x41, 0x52, 0xa, 0x41, 0x20, 0x48, 0x49, 0x47, 0x49, 0x45, 0x4e, 0x49, 0x5a, 0x41, 0xc7, 0xc3, 0x4f, 0x3f, 0x0, // @1338 "DESEJA CANCELAR?A HIGIENIZA??O?"
    0x52, 0x65, 0x74, 0x61, 0x72, 0x64, 0x6f, 0x20, 0x73, 0x61, 0xed, 0x64, 0x61, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x65, 0xa, 0x28, 0x6d, 0x6d, 0x2e, 0x73, 0x73, 0x29, 0x0, // @1370 "Retardo sa?da controle?(mm.ss)"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x67, 0x6f, 0x74, 0x65, 0x6a, 0x61, 0x6d, 0x65, 0x6e, 0x74, 0x6f, 0xa, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x73, 0x65, 0x64, 0x29, 0x0, // @1401 "Tempo de gotejamento?(min.sed)"
    0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x61, 0x75, 0x74, 0x6f, 0x6d, 0x2e, 0xa, 0x61, 0x70, 0xf3, 0x73, 0x20, 0x72, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x3a, 0x0, // @1432 "Conservar autom.?ap?s receita:"
    0x44, 0x69, 0x66, 0x2e, 0x20, 0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x28, 0x52, 0x65, 0x73, 0x66, 0x72, 0x69, 0x61, 0x72, 0x29, 0x0, // @1463 "Dif. Conservar (Resfriar)"
    0x44, 0x69, 0x66, 0x2e, 0x20, 0x43, 0x6f, 0x6e, 0x73, 0x65, 0x72, 0x76, 0x61, 0x72, 0x20, 0x28, 0x43, 0x6f, 0x6e, 0x67, 0x65, 0x6c, 0x61, 0x72, 0x29, 0x0, // @1489 "Dif. Conservar (Congelar)"
    0x45, 0x64, 0x69, 0xe7, 0xe3, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x20, 0x2, 0x0, // @1515 "Edi??o de Receita <>"
    0x41, 0x42, 0x52, 0x49, 0x52, 0x20, 0x50, 0x4f, 0x52, 0x54, 0x41, 0xa, 0x50, 0x41, 0x52, 0x41, 0x20, 0x43, 0x4f, 0x4d, 0x45, 0xc7, 0x41, 0x52, 0x0, // @1535 "ABRIR PORTA?PARA COME?AR"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0xc7, 0xc3, 0x4f, 0x20, 0x28, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2e, 0x29, 0x0, // @1560 "SP CONSERVA??O (Config.)"
    0x44, 0x45, 0x53, 0x45, 0x4a, 0x41, 0x20, 0x53, 0x41, 0x49, 0x52, 0xa, 0x44, 0x4f, 0x20, 0x50, 0x52, 0x4f, 0x43, 0x45, 0x53, 0x53, 0x4f, 0x3f, 0x0, // @1585 "DESEJA SAIR?DO PROCESSO?"
    0x44, 0x65, 0x73, 0x63, 0x72, 0x69, 0xe7, 0xe3, 0x6f, 0x20, 0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x0, // @1610 "Descri??o Alarme Externo"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x72, 0x65, 0x63, 0x69, 0x74, 0x61, 0x20, 0x65, 0x6d, 0x20, 0x5a, 0x45, 0x52, 0x4f, 0x21, 0x0, // @1635 "Tempo de recita em ZERO!"
    0x44, 0x75, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x64, 0x6f, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x20, 0x28, 0x6d, 0x69, 0x6e, 0x2e, 0x29, 0x0, // @1660 "Dura??o do degelo (min.)"
    0x53, 0x50, 0x20, 0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0xc7, 0xc3, 0x4f, 0x20, 0x28, 0x52, 0x65, 0x73, 0x66, 0x72, 0x2e, 0x29, 0x0, // @1685 "SP CONSERVA??O (Resfr.)"
    0x44, 0x45, 0x53, 0x45, 0x4a, 0x41, 0x20, 0x53, 0x41, 0x49, 0x52, 0xa, 0x44, 0x4f, 0x20, 0x44, 0x45, 0x47, 0x45, 0x4c, 0x4f, 0x3f, 0x0, // @1709 "DESEJA SAIR?DO DEGELO?"
    0x43, 0x4f, 0x4e, 0x54, 0x52, 0x41, 0x53, 0x45, 0x4e, 0x41, 0x20, 0x49, 0x4e, 0x43, 0x4f, 0x52, 0x52, 0x45, 0x43, 0x54, 0x41, 0x0, // @1732 "CONTRASENA INCORRECTA"
    0x44, 0x49, 0x46, 0x45, 0x52, 0x45, 0x4e, 0x43, 0x49, 0x41, 0x4c, 0x20, 0x43, 0x4f, 0x4e, 0x47, 0x45, 0x4c, 0x41, 0x52, 0x0, // @1754 "DIFERENCIAL CONGELAR"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x0, // @1775 "ABCDEFGHIJKLMNOPQRST"
    0x4d, 0x41, 0x55, 0x56, 0x41, 0x49, 0x53, 0x20, 0x4d, 0x4f, 0x54, 0x20, 0x44, 0x45, 0x20, 0x50, 0x41, 0x53, 0x53, 0x45, 0x0, // @1796 "MAUVAIS MOT DE PASSE"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x33, 0x0, // @1817 "Calibra??o Sonda 3"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x31, 0x0, // @1836 "Calibra??o Sonda 1"
    0x43, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0xe7, 0xe3, 0x6f, 0x20, 0x53, 0x6f, 0x6e, 0x64, 0x61, 0x20, 0x32, 0x0, // @1855 "Calibra??o Sonda 2"
    0x50, 0x4f, 0x52, 0x54, 0x41, 0x20, 0x41, 0x42, 0x45, 0x52, 0x54, 0x41, 0xa, 0xa, 0x4f, 0x4b, 0x21, 0x0, // @1874 "PORTA ABERTA??OK!"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0x20, 0x45, 0x56, 0x41, 0x50, 0x4f, 0x52, 0x41, 0x44, 0x4f, 0x52, 0x0, // @1892 "TEMP. EVAPORADOR"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0x20, 0x44, 0x45, 0x43, 0x4f, 0x52, 0x52, 0x49, 0x44, 0x4f, 0x0, // @1909 "TEMPO DECORRIDO"
    0x4c, 0x49, 0x4d, 0x49, 0x54, 0x49, 0x20, 0x53, 0x55, 0x50, 0x45, 0x52, 0x41, 0x54, 0x49, 0x0, // @1925 "LIMITI SUPERATI"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x44, 0x45, 0x43, 0x4f, 0x52, 0x52, 0x49, 0x44, 0x4f, 0x0, // @1941 "TEMPO?DECORRIDO"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x39, 0x2d, 0x52, 0x31, 0x32, 0x0, // @1957 "RECEITAS R9-R12"
    0x41, 0x6c, 0x61, 0x72, 0x6d, 0x65, 0x20, 0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x6f, 0x21, 0x0, // @1973 "Alarme Externo!"
    0x53, 0x65, 0x6e, 0x68, 0x61, 0x20, 0x64, 0x65, 0x20, 0x61, 0x63, 0x65, 0x73, 0x73, 0x6f, 0x0, // @1989 "Senha de acesso"
    0x49, 0x6e, 0x69, 0x63, 0x69, 0x61, 0x72, 0x20, 0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x0, // @2005 "Iniciar Receita"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x0, // @2021 "ABCDEFGHIIJKLMN"
    0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44, 0x20, 0x45, 0x52, 0x52, 0x41, 0x54, 0x41, 0x0, // @2037 "PASSWORD ERRATA"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x31, 0x2d, 0x52, 0x34, 0x0, // @2053 "RECEITAS R1-R4"
    0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x0, // @2068 "ABCDEFGHIJKLMN"
    0x52, 0x45, 0x43, 0x45, 0x49, 0x54, 0x41, 0x53, 0x20, 0x52, 0x35, 0x2d, 0x52, 0x38, 0x0, // @2083 "RECEITAS R5-R8"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x45, 0x53, 0x54, 0x49, 0x4d, 0x41, 0x44, 0x4f, 0x0, // @2098 "TEMPO?ESTIMADO"
    0x46, 0x55, 0x45, 0x52, 0x41, 0x20, 0x44, 0x45, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x4f, 0x0, // @2113 "FUERA DE RANGO"
    0x48, 0x4f, 0x52, 0x53, 0x20, 0x44, 0x45, 0x20, 0x50, 0x4f, 0x52, 0x54, 0xc9, 0x45, 0x0, // @2128 "HORS DE PORT?E"
    0x54, 0x69, 0x70, 0x6f, 0x20, 0x64, 0x65, 0x20, 0x64, 0x65, 0x67, 0x65, 0x6c, 0x6f, 0x0, // @2143 "Tipo de degelo"
    0x57, 0x52, 0x4f, 0x4e, 0x47, 0x20, 0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44, 0x0, // @2158 "WRONG PASSWORD"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0xa, 0x49, 0x4e, 0x54, 0x45, 0x52, 0x4e, 0x41, 0x0, // @2173 "TEMP.?INTERNA"
    0x54, 0x45, 0x4d, 0x50, 0x2e, 0xa, 0x50, 0x52, 0x4f, 0x44, 0x55, 0x54, 0x4f, 0x0, // @2187 "TEMP.?PRODUTO"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x20, 0x46, 0xe1, 0x62, 0x72, 0x69, 0x63, 0x61, 0x0, // @2201 "Reset F?brica"
    0x54, 0x45, 0x4d, 0x50, 0x4f, 0xa, 0x43, 0x4f, 0x4e, 0x46, 0x49, 0x47, 0x2e, 0x0, // @2215 "TEMPO?CONFIG."
    0x49, 0x6e, 0x73, 0x65, 0x72, 0x69, 0x72, 0x20, 0x53, 0x65, 0x6e, 0x68, 0x61, 0x0, // @2229 "Inserir Senha"
    0x53, 0x6f, 0x6d, 0x20, 0x64, 0x6f, 0x20, 0x42, 0x75, 0x7a, 0x7a, 0x65, 0x72, 0x0, // @2243 "Som do Buzzer"
    0x41, 0x42, 0x52, 0x49, 0x52, 0x20, 0x50, 0x4f, 0x52, 0x54, 0x41, 0x20, 0x21, 0x0, // @2257 "ABRIR PORTA !"
    0x44, 0x65, 0x73, 0x61, 0x62, 0x6c, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x0, // @2271 "Desablilitar"
    0x48, 0x49, 0x47, 0x49, 0x45, 0x4e, 0x49, 0x5a, 0x41, 0xc7, 0xc3, 0x4f, 0x0, // @2284 "HIGIENIZA??O"
    0x4f, 0x55, 0x54, 0x20, 0x4f, 0x46, 0x20, 0x52, 0x41, 0x4e, 0x47, 0x45, 0x0, // @2297 "OUT OF RANGE"
    0x46, 0x69, 0x6e, 0x61, 0x6c, 0x69, 0x7a, 0x61, 0x64, 0x6f, 0x21, 0x0, // @2310 "Finalizado!"
    0x4d, 0x6f, 0x64, 0x6f, 0x3a, 0xa, 0x66, 0x75, 0x6e, 0x63, 0x2e, 0x0, // @2322 "Modo:?func."
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x61, 0x0, // @2334 "Temperatura"
    0x4d, 0x6f, 0x64, 0x6f, 0xa, 0x66, 0x69, 0x6e, 0x61, 0x6c, 0x2e, 0x0, // @2346 "Modo?final."
    0x44, 0x65, 0x73, 0x61, 0x62, 0x69, 0x6c, 0x69, 0x74, 0x61, 0x72, 0x0, // @2358 "Desabilitar"
    0x54, 0x65, 0x6d, 0x70, 0x6f, 0xa, 0x5a, 0x65, 0x72, 0x6f, 0x21, 0x0, // @2370 "Tempo?Zero!"
    0x43, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x61, 0x72, 0x0, // @2382 "Confirmar"
    0x43, 0x4f, 0x4e, 0x53, 0x45, 0x52, 0x56, 0x41, 0x52, 0x0, // @2392 "CONSERVAR"
    0x4e, 0x65, 0x77, 0x20, 0x54, 0x65, 0x78, 0x74, 0x0, // @2402 "New Text"
    0x52, 0x65, 0x63, 0x65, 0x69, 0x74, 0x61, 0x3a, 0x0, // @2411 "Receita:"
    0x49, 0x4e, 0x44, 0x49, 0x45, 0x54, 0x52, 0x4f, 0x0, // @2420 "INDIETRO"
    0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c, 0x61, 0x72, 0x0, // @2429 "Cancelar"
    0x52, 0x45, 0x53, 0x46, 0x52, 0x49, 0x41, 0x52, 0x0, // @2438 "RESFRIAR"
    0x49, 0x6e, 0x76, 0x65, 0x72, 0x74, 0x65, 0x72, 0x0, // @2447 "Inverter"
    0x43, 0x41, 0x4e, 0x43, 0x45, 0x4c, 0x41, 0x52, 0x0, // @2456 "CANCELAR"
    0x2, 0x2e, 0x0, // @2465 "<>."
    0x45, 0x6e, 0x74, 0x65, 0x72, 0xa, 0xa, 0x0, // @2468 "Enter??"
    0x38, 0x38, 0x38, 0x38, 0x2e, 0x38, 0x0, // @2476 "8888.8"
    0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c, 0x0, // @2483 "Cancel"
    0x32, 0x30, 0x30, 0x30, 0x2e, 0x30, 0x0, // @2490 "2000.0"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0xa, 0x0, // @2497 "Enter?"
    0x53, 0x41, 0x4c, 0x56, 0x41, 0x52, 0x0, // @2504 "SALVAR"
    0x4e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x0, // @2511 "Normal"
    0x44, 0x45, 0x47, 0x45, 0x4c, 0x4f, 0x0, // @2518 "DEGELO"
    0x38, 0x38, 0x38, 0x2e, 0x38, 0x38, 0x0, // @2525 "888.88"
    0x43, 0x4c, 0x45, 0x41, 0x52, 0x0, // @2532 "CLEAR"
    0x38, 0x38, 0x38, 0x38, 0x38, 0x0, // @2538 "88888"
    0x45, 0x4e, 0x54, 0x45, 0x52, 0x0, // @2544 "ENTER"
    0x41, 0x54, 0x52, 0xc1, 0x53, 0x0, // @2550 "ATR?S"
    0x43, 0x61, 0x70, 0x73, 0xa, 0x0, // @2556 "Caps?"
    0x43, 0x70, 0x61, 0x73, 0xa, 0x0, // @2562 "Cpas?"
    0x44, 0x65, 0x6c, 0xa, 0xa, 0x0, // @2568 "Del??"
    0x52, 0x65, 0x73, 0x65, 0x74, 0x0, // @2574 "Reset"
    0x4e, 0x6f, 0x6d, 0x65, 0x3a, 0x0, // @2580 "Nome:"
    0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x0, // @2586 "*****"
    0x42, 0x41, 0x43, 0x4b, 0x0, // @2592 "BACK"
    0x4d, 0x69, 0x6e, 0x2e, 0x0, // @2597 "Min."
    0x3f, 0x31, 0x32, 0x33, 0x0, // @2602 "?123"
    0x31, 0x32, 0x33, 0xa, 0x0, // @2607 "123?"
    0x45, 0x73, 0x63, 0xa, 0x0, // @2612 "Esc?"
    0x44, 0x65, 0x6c, 0xa, 0x0, // @2617 "Del?"
    0x43, 0x6f, 0x65, 0x6c, 0x0, // @2622 "Coel"
    0x2b, 0x2f, 0x2d, 0x0, // @2627 "+/-"
    0x6d, 0x69, 0x6e, 0x0, // @2631 "min"
    0x53, 0x49, 0x4d, 0x0, // @2635 "SIM"
    0x41, 0x42, 0x43, 0x0, // @2639 "ABC"
    0x4e, 0xc3, 0x4f, 0x0, // @2643 "N?O"
    0x4d, 0x61, 0x78, 0x0, // @2647 "Max"
    0x45, 0x53, 0x43, 0x0, // @2651 "ESC"
    0x4d, 0x69, 0x6e, 0x0, // @2655 "Min"
    0x44, 0x4f, 0x53, 0x0, // @2659 "DOS"
    0x30, 0x30, 0x0, // @2663 "00"
    0xb0, 0x43, 0x0, // @2666 "?C"
    0x4f, 0x6b, 0x0, // @2669 "Ok"
    0x2d, 0x2d, 0x0, // @2672 "--"
    0x20, 0x0, // @2675 " "
    0x57, 0x0, // @2677 "W"
    0x71, 0x0, // @2679 "q"
    0x77, 0x0, // @2681 "w"
    0x59, 0x0, // @2683 "Y"
    0x79, 0x0, // @2685 "y"
    0x55, 0x0, // @2687 "U"
    0x75, 0x0, // @2689 "u"
    0x69, 0x0, // @2691 "i"
    0x50, 0x0, // @2693 "P"
    0x70, 0x0, // @2695 "p"
    0x2f, 0x0, // @2697 "/"
    0x64, 0x0, // @2699 "d"
    0x46, 0x0, // @2701 "F"
    0x66, 0x0, // @2703 "f"
    0x51, 0x0, // @2705 "Q"
    0x47, 0x0, // @2707 "G"
    0x67, 0x0, // @2709 "g"
    0x48, 0x0, // @2711 "H"
    0x68, 0x0, // @2713 "h"
    0x39, 0x0, // @2715 "9"
    0x4a, 0x0, // @2717 "J"
    0x6a, 0x0, // @2719 "j"
    0x37, 0x0, // @2721 "7"
    0x36, 0x0, // @2723 "6"
    0x4c, 0x0, // @2725 "L"
    0x35, 0x0, // @2727 "5"
    0x5a, 0x0, // @2729 "Z"
    0x7a, 0x0, // @2731 "z"
    0x58, 0x0, // @2733 "X"
    0x63, 0x0, // @2735 "c"
    0x56, 0x0, // @2737 "V"
    0x76, 0x0, // @2739 "v"
    0x42, 0x0, // @2741 "B"
    0x62, 0x0, // @2743 "b"
    0x2b, 0x0, // @2745 "+"
    0x27, 0x0, // @2747 "'"
    0x22, 0x0, // @2749 """
    0x28, 0x0, // @2751 "("
    0x5f, 0x0, // @2753 "_"
    0x26, 0x0, // @2755 "&"
    0x25, 0x0, // @2757 "%"
    0x24, 0x0, // @2759 "$"
    0x23, 0x0, // @2761 "#"
    0x40, 0x0, // @2763 "@"
    0x3b, 0x0, // @2765 ";"
    0x2c, 0x0, // @2767 ","
    0x73, 0x0, // @2769 "s"
    0x6d, 0x0 // @2771 "m"
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
